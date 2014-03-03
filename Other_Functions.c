float SlopeFilter(int MotorValue, int LastMotorValue, float SlopeLimit)	//////////////////////////////////////////
{																		//This function limits the derivative	//
	int Delta = MotorValue-LastMotorValue;								//of the motor values, whitch are then	//
	if (Delta >=  SlopeLimit) Delta =  SlopeLimit;						//integrated and sent to the motors.	//
	if (Delta <= -SlopeLimit) Delta = -SlopeLimit;						//////////////////////////////////////////
	return Delta;
}

void LogEncoders()
{
	#ifdef LOGENCODERS
		writeDebugStreamLine(
		"SenLeft:%d , SenRight:%d , nMotEncLeft:%d , nMotEncRight:%d",
		SensorValue[BackLeftEncoder], SensorValue[BackRightEncoder], nMotorEncoder[DriveBR], nMotorEncoder[DriveBL] );
	#endif
}

int PotPosition(int NumOfPostions)
{
	int Position = (SenAutoPot / ((float)4096/NumOfPostions));
	CapValue(0, Position, NumOfPostions - 1);
	return Position;
}

void UpdateAutonomousRoutine()
{
	AutonomousRoutine = PotPosition(NumOfAutoRoutines) + 1;
	CapValue(1, AutonomousRoutine, NumOfAutoRoutines);
}

void UpdateBatteryLevels()
{
	StringFormat(BatteryLevel[0],  "Main:%1.3f  ",   (float)nAvgBatteryLevel  /1000);
	StringFormat(BatteryLevel[1],  "Backup:%1.3f   ",(float)BackupBatteryLevel/1000);
}


void UpdateCustomTimers()
{
	DiffMasterTimer = time1[T3] - LastMasterTimer;
	if (AutonIsOnTheClock) TimerAutonomous += DiffMasterTimer;
	TimerLCDScroll	+= DiffMasterTimer;
	TimerPIDEnd		+= DiffMasterTimer;
	LastMasterTimer = time1[T3];
}

void UpdateAbsoluteGyro()
{
	if (LastGyro > 3000 && SenGyro < 600)  AddToAbsGyro+=3600;
	if (LastGyro < 600  && SenGyro > 3000) AddToAbsGyro-=3600;
	AbsoluteGyro = AddToAbsGyro + SenGyro;
	LastGyro = SenGyro;
}

void SoundControl()
{
	#ifdef PLAYSOUNDS
		if (SlewedMotor[SpatulaL]>40  && !bSoundActive)	PlaySoundFile("GunLoad.wav");
		if (SlewedMotor[Conveyor]>40  && !bSoundActive)	PlaySoundFile("LaserFire.wav");
		if (SlewedMotor[Descorer]<-40 && !bSoundActive)	PlaySoundFile("Inception.wav");
	#endif
}

void ConstantLoopDelay()
{
	MainNonDelayedLoopTime = time1[T4];
	while (time1[T4] < MinLoopMS) {}
	MainLoopTime = time1[T4];
	ClearTimer(T4);
}

bool JoystickActivated(bool CheckCh1) //Check if no buttons are pressed and the joysticks are in their "Dead Zones"
{
	bool ControlActivated = false;
	if(vexRT[Btn5D]		||vexRT[Btn5U]		||vexRT[Btn6D]		||vexRT[Btn6U])			ControlActivated = true;
	if(vexRT[Btn5DXmtr2]||vexRT[Btn5UXmtr2]	||vexRT[Btn6DXmtr2]	||vexRT[Btn6UXmtr2])	ControlActivated = true;
	if(sqrt(pow(vexRT[Ch4],     2) + pow(vexRT[Ch3],     2)) > JoystickDZ) ControlActivated = true;
	if(sqrt(pow(vexRT[Ch4Xmtr2],2) + pow(vexRT[Ch3Xmtr2],2)) > JoystickDZ) ControlActivated = true;
	if(CheckCh1 && sqrt(pow(vexRT[Ch1],     2))				 > JoystickDZ) ControlActivated = true;

	return ControlActivated;
}

int UpdatePIDController(TPID &PIDController, int Error)
{
	PIDController.Error = Error;
	PIDController.Integral = (PIDController.Integral * (3 / 4)) + PIDController.Error;
	PIDController.Derivative = PIDController.Error - PIDController.LastError;
	PIDController.LastError = PIDController.Error;
	PIDController.Output = ((float) PIDController.Error * PIDController.Kp)
						 + (PIDController.Integral * PIDController.Ki)
						 + (PIDController.Derivative * PIDController.Kd);
	return PIDController.Output;
}

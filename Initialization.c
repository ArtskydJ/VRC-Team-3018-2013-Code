void InitializePIDControllers()
{
	PIDLineFollower.Kp = 0.08;
	PIDLineFollower.Ki = 0;
	PIDLineFollower.Kd = 0;
	PIDDescorer.Kp = 0.04;
	PIDDescorer.Ki = 0.01;
	PIDDescorer.Kd = 0.03;
	PIDWallFollower.Kp = 0.1;
	PIDWallFollower.Ki = 0;
	PIDWallFollower.Kd = 0;
	PIDLift.Kp = 0.50;
	PIDLift.Ki = 0.04;
	PIDLift.Kd = 0.02;
	PIDSpatula.Kp = 0.2;
	PIDSpatula.Ki = 0.00;
	PIDSpatula.Kd = 0.05;
	PIDDriveStraight.Kp = 0.2;
	PIDDriveStraight.Ki = 0.0;
	PIDDriveStraight.Kd = 0;
	PIDDriveGyro.Kp = 0.65;
	PIDDriveGyro.Ki = 0.0;
	PIDDriveGyro.Kd = 0.5;
}

void InitializeEncoders()
{
	SensorValue[BackRightQuad] = 0;
}

void InitializeLCDScreen()
{
	bLCDBacklight = true;
}

void InitializeTimers()
{
	ClearTimer(T1);
	ClearTimer(T2);
	ClearTimer(T3);
	ClearTimer(T4);
}

void InitializeDebugStream()
{
	writeDebugStreamLine("===============");
}

void InitializeAutonomousPotentiometer()
{
	SenAutoPot = SensorValue[AutoSelector];
}

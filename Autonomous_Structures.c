//This function logs time, sets or resets values, and beeps before each new autonomous step
void AutoNextStep()
{
	//Log autonomous step times
	if (AutonomousStep < NumOfTimeRecords)
	{
		AutoTimeRecord[AutonomousStep] = time1[T1];
		writeDebugStreamLine("%d, %d.",AutonomousStep, AutoTimeRecord[AutonomousStep]);
	}
	else writeDebugStreamLine("AutoStep is too big");

	//Set or reset values
	DriveEncoderStartAvg = SenDriveEncoderAvg;
	DriveEncoderStartDif = SenDriveEncoderDif;
	HaveFoundLeftEdge = false;
	HaveFoundRightEdge = false;
	AddToAbsGyro += SensorValue[Gyro];
	SensorValue[Gyro] = 0;
	StepStartGyro = SensorValue[Gyro];
	AutonomousStep++;
	HitTarget = false;
	ClearTimer(T1);
	ClearTimer(T2);

	//Beep, if feature enabled
	#ifdef BEEP
		if (AutonomousStep % 3 == 0) //Every third step...
			PlayTone(880,10);		// Make a higher tone
		else
			PlayTone(440,10);
	#endif
}

void AutoPIDDelay()
{
	if (!HitTarget)
	{
		HitTarget = true;
		ClearTimer(T2);
	}
}

//This function resets all the motors and will prepare for either the start or the end of autonomous mode.
void AutonomousReset(int StepNumber)
{
	MtrLift		= 0;
	MtrDrvFL	= 0;
	MtrDrvBL	= 0;
	MtrDrvFR	= 0;
	MtrDrvBR	= 0;
	MtrSpatula	= 0;
	MtrConveyor	= 0;

	if(StepNumber == 0) //Runs at start of Autonomous
	{
		AutoNextStep();
		AutonIsOnTheClock = true;
		TimerAutonomous = 0;
	}
	else //Runs at end of Autonomous
	{
		DriverMode = DriverJoystickControl;
		AutonIsOnTheClock = false;
	}
}

void AutonomousStructure(int *INAutoStep)
{
	int INlift			= INAutoStep[0];
	int INconveyor		= INAutoStep[1];
	int INspatula		= INAutoStep[2];
	int INdescorer		= INAutoStep[3];
	int INdl			= INAutoStep[4];
	int INdr			= INAutoStep[5];
	int INstrafe		= INAutoStep[6]; //Also used for Line and Wall following trigger
	int INtarget		= INAutoStep[7];
	int INdurationType	= INAutoStep[8];

	if      (INdurationType == ENCODSTRA || INdurationType == PIDSTRAIG) DriveEncoderError = SenDriveEncoderAvg - DriveEncoderStartAvg;
	else if (INdurationType == ENCODTURN || INdurationType == GYRSTRAFE) DriveEncoderError = SenDriveEncoderDif - DriveEncoderStartDif;

	if (INstrafe==LINE && INdurationType!=RELTRNGYR && INdurationType!=ENCODTURN && INdurationType!=PIDSTRAIG) //LINE FOLLOWING...Don't allow: drivegyro encodturn pidstraig
	{
		PIDLineFollower.Output = UpdatePIDController(PIDLineFollower, ( LeftLineFolScaled + RightLineFolScaled));
		MtrDrvFL = INdl + PIDLineFollower.Output;
		MtrDrvBL = INdl + PIDLineFollower.Output;
		MtrDrvFR = INdr - PIDLineFollower.Output;
		MtrDrvBR = INdr - PIDLineFollower.Output;
	}
	else if ((INstrafe==WALL_L || INstrafe==WALL_R)
		&& (INdurationType!=RELTRNGYR && INdurationType!=ENCODTURN && INdurationType!=PIDSTRAIG)) //WALL FOLLOWING...Don't allow: drivegyro encodturn pidstraig
	{
		if (INstrafe==WALL_L) PIDWallFollower.Error = (SenLeftUltrasonic  - INtarget);
		if (INstrafe==WALL_R) PIDWallFollower.Error = (SenRightUltrasonic - INtarget);
		PIDWallFollower.Output = UpdatePIDController(PIDWallFollower, PIDWallFollower.Error);
		MtrDrvFL = 75 - PIDWallFollower.Output;
		MtrDrvBL = 75 - PIDWallFollower.Output;
		MtrDrvFR = 75 + PIDWallFollower.Output;
		MtrDrvBR = 75 + PIDWallFollower.Output;
	}
	else //NORMAL DRIVING
	{
		CapValue(-127,INstrafe,127);
		MtrDrvFL = INdl+INstrafe;
		MtrDrvBL = INdl-INstrafe;
		MtrDrvFR = INdr-INstrafe;
		MtrDrvBR = INdr+INstrafe;
	}
	if (SenLeftEdge  > FloorEdgeLineup) HaveFoundLeftEdge  = true; //Have we found the left edge?
	if (SenRightEdge > FloorEdgeLineup) HaveFoundRightEdge = true; //Have we found the right edge?

	if (INdurationType == WHITELINE) //If we're wanting to line up with a white line...
	{
		if (HaveFoundLeftEdge)	//If we have found the left edge...
		{
			MtrDrvFL /= -6; 	//Make the left motors stop
			MtrDrvBL /= -6;
		}
		if (HaveFoundRightEdge) //If we have found the right edge...
		{
			MtrDrvFR /= -6; 	//Make the right motors stop
			MtrDrvBR /= -6;
		}
	}
	else if (INdurationType == PIDSTRAIG)
	{
		PIDDriveStraight.Output = UpdatePIDController(PIDDriveStraight, INtarget - DriveEncoderError);
		MtrDrvFL = PIDDriveStraight.Output;
		MtrDrvBL = PIDDriveStraight.Output;
		MtrDrvFR = PIDDriveStraight.Output;
		MtrDrvBR = PIDDriveStraight.Output;
		if (PIDDriveStraight.Output <= 0) PlayTone(440,10);
	}
	else if (INdurationType == RELTRNGYR)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - (SenGyro - StepStartGyro));
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}
	else if (INdurationType == ABSTRNGYR)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - AbsoluteGyro);
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}
	else if (INdurationType == SQUAREUPG)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, (INtarget - (SenGyro % 3600))*2);
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}

	else if (INdurationType == GYRSTRAFE || INdurationType == LEFTULGYR || INdurationType == RIGTULGYR)
	{
		// We scaled the front motor power down here in order to straighten our strafes.
		MtrDrvFL = (INdl+INstrafe-SenGyro*GYROSTRAFEP)*.9;
		MtrDrvBL =  INdl-INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvFR = (INdr-INstrafe+SenGyro*GYROSTRAFEP)*.9;
		MtrDrvBR =  INdr+INstrafe+SenGyro*GYROSTRAFEP;
	}

	if (abs(INlift) <= 127) MtrLift = INlift;									  //Set custom lift power if value in power range...
	else MtrLift	 = UpdatePIDController(PIDLift,		INlift	   - SenLiftPot); //Otherwise set lift height for PID Controller to handle.
	MtrConveyor = INconveyor;													  //Set conveyor power.
	if(abs(INspatula) <= 127) MtrSpatula = INspatula;
	else MtrSpatula  = UpdatePIDController(PIDSpatula,  INspatula  - SenSpatPot); //Spatula
	if(abs(INdescorer) <= 127) MtrDescorer = INdescorer;

	switch(INdurationType) // This code asks what type of target condition we are looking for. Have we met it? If so, move on.
	{
		case RESETAUTO: AutonomousReset(AutonomousStep);																		   break;
		case TIMELIMIT: if(time1[T1] >= INtarget)																				AutoNextStep();break;
		case LIFTPOTEN: if((PIDLift.Error < INlift-100)!=(PIDLift.LastError < INlift-100))										AutoNextStep();break;
		case RELTRNGYR: if((INtarget > 0) ? ((SenGyro - StepStartGyro) > INtarget) : ((SenGyro - StepStartGyro) < INtarget))	AutoPIDDelay();break;
		case ENCODSTRA: if((INdr > 0) ? (DriveEncoderError > INtarget) : (DriveEncoderError < INtarget))			AutoNextStep();break;
		case ENCODTURN: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoNextStep();break;
		case SPATPOTEN: if(abs(SenSpatPot-INtarget) <= 5)															AutoNextStep();break;
		case WHITELINE: if(HaveFoundLeftEdge && HaveFoundRightEdge)													AutoNextStep();break;
		case SCREENBTN: if(nLCDButtons || (INtarget != 0 && (time1[T1] >= INtarget)))								AutoNextStep();break;
		case PIDSTRAIG: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoPIDDelay();break;
		case CONVSWICH:	if(SenConveyerSwitch || time1[T1] >= INtarget)												AutoNextStep();break;
		case GYRSTRAFE: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoNextStep();break;
		case LEFTULGYR: if((INstrafe > 0) ? (SenLeftUltrasonic  >= INtarget) : (SenLeftUltrasonic  <= INtarget))	AutoNextStep();break;
		case RIGTULGYR: if((INstrafe < 0) ? (SenRightUltrasonic >= INtarget) : (SenRightUltrasonic <= INtarget))	AutoNextStep();break;
		case BACKULSTR: if((INdr     > 0) ? (SenBackUltrasonic  >= INtarget) : (SenBackUltrasonic  <= INtarget))	AutoNextStep();break;
		case ABSTRNGYR: if((INtarget > 0) ? ((SenGyro % 3600) > INtarget) : ((SenGyro % 3600) < INtarget))			AutoNextStep();break;
		case SQUAREUPG: if(time1[T1] >= INstrafe && INstrafe != 0)													AutoNextStep();break;
		case CROSSLINE: if(HaveFoundRightEdge || HaveFoundLeftEdge || time1[T1] >= INtarget)						AutoNextStep();break;
		case FRONTLINE: if(SenRightLine>RightLineFolPosi || time1[T1] >= INtarget)									AutoNextStep();break;
		default://nothing
	}
	if(time1[T1] >= FailsafeMS && INdurationType != RESETAUTO)								AutoNextStep();
	if(time1[T2] >= PIDWaitMS && HitTarget)													AutoNextStep();
	DriveEncoderErrorLast = DriveEncoderError;
}

void AutonomousControl()
{
	#define n 9 //Number of columns in each autonomous array
	int CurrentAutoStep[n];
	if      (DriverMode == DriverSubPyramid && !IsRobotInAutonomousMode)
		for (int j=0; j<n; j++) {CurrentAutoStep[j] = AutoPyramid[AutonomousStep][j];}
	else if (DriverMode == DriverSubDescore && !IsRobotInAutonomousMode)
		for (int j=0; j<n; j++) {CurrentAutoStep[j] = AutoDescore[AutonomousStep][j];}
	else switch (AutonomousRoutine)
	{
		case 01: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto01[AutonomousStep][j];} break;
		case 02: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto02[AutonomousStep][j];} break;
		case 03: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto03[AutonomousStep][j];} break;
		case 04: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto04[AutonomousStep][j];} break;
		case 05: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto05[AutonomousStep][j];} break;
		case 06: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto06[AutonomousStep][j];} break;
		//case 07: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto07[AutonomousStep][j];} break; //there is no routine 7
		case 08: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto08[AutonomousStep][j];} break;
		case 09: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto09[AutonomousStep][j];} break;
		case 10: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto10[AutonomousStep][j];} break;
		case 11: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto11[AutonomousStep][j];} break;
		case 12: for (int j=0; j<n; j++) {CurrentAutoStep[j] = auto12[AutonomousStep][j];} break;
		default: //nothing
	}
	AutonomousStructure(CurrentAutoStep);
}

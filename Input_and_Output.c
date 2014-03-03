void Input()
{
#ifdef UPDATEINPUTVARIABLES //Normal - Overwrite variables
//Joystick readings
	//Joystick 1 Sticks
	StkDrvX =				  vexRT[Ch4];
	StkDrvY =				  vexRT[Ch3];
	StkDrvZ =				  vexRT[Ch1];
	StkMtrTest =			  vexRT[Ch2];

	//Joystick 1 Buttons
	BtnAutonFromDriver =(bool)vexRT[Btn7U];
	BtnSubroutineSelect=(bool)vexRT[Btn7L];
	//BtnDriveStyle =	(bool)vexRT[Btn7R];
	BtnDisablePots =	(bool)vexRT[Btn7D];
	BtnConveyorFwd =	(bool)vexRT[Btn8U];
	BtnConveyorRev =	(bool)vexRT[Btn8D];
	BtnDescorerUp =		(bool)vexRT[Btn8L];
	BtnDescorerDown =	(bool)vexRT[Btn8R];
	BtnLiftUp =			(bool)vexRT[Btn5U];
	BtnLiftDown =		(bool)vexRT[Btn5D];
	BtnSpatulaUp =		(bool)vexRT[Btn6U];
	BtnSpatulaDown =	(bool)vexRT[Btn6D];
	BtnHalfSpeed =		(bool)vexRT[Btn7R];

	//Joystick 2 Buttons
	BtnLiftUp2 =		(bool)vexRT[Btn5UXmtr2];
	BtnLiftDown2 =		(bool)vexRT[Btn5DXmtr2];
	BtnConveyorFwd2 =	(bool)vexRT[Btn8UXmtr2];
	BtnConveyorRev2 =	(bool)vexRT[Btn8DXmtr2];
	BtnSpatulaUp2 =		(bool)vexRT[Btn6UXmtr2];
	BtnSpatulaDown2 =	(bool)vexRT[Btn6DXmtr2];
	BtnDescorerUp2 =	(bool)vexRT[Btn8LXmtr2];
	BtnDescorerDown2 =	(bool)vexRT[Btn8RXmtr2];

//Sensor readings
	//Potetiometers
	SenSpatPot =		   SensorValue[SpatulaPotentiometer];
	SenLiftPot =	4095 - SensorValue[LiftPotentiometer];
	SenAutoPot =		   SensorValue[AutoSelector];

	//Line Followers
	SenLeftLine =	4095 - SensorValue[LeftLineFollower];
	SenRightLine =	4095 - SensorValue[RightLineFollower];
	SenLeftEdge =	4095 - SensorValue[LeftLineEdgeDetector];
	SenRightEdge =	4095 - SensorValue[RightLineEdgeDetector];

	//Gyroscope
	SenGyro = 0 - SensorValue[Gyro];

	//Ultrasonic Sensors
	SenLeftUltrasonic =		SensorValue[LeftSideUltrasonic];
	SenRightUltrasonic =	SensorValue[RightSideUltrasonic];
	SenBackUltrasonic =		SensorValue[BackSideUltrasonic];

	//Limit Switches
	SenConveyerSwitch = 	SensorValue[ConveyerSwitch];

	//Screen buttons
	LastBtnScreenLeft =		BtnScreenLeft;
	LastBtnScreenCenter =	BtnScreenCenter;
	LastBtnScreenRight =	BtnScreenRight;
	BtnScreenLeft =			(nLCDButtons & 1) > 0;
	BtnScreenCenter =		(nLCDButtons & 2) > 0;
	BtnScreenRight =		(nLCDButtons & 4) > 0;

	//Encoders
	SenDrivenMotorEncoderBackLeft =		nMotorEncoder[DriveBL];
	SenDrivenMotorEncoderBackRight =	nMotorEncoder[DriveBR];
	SenDriveEncoderAvg = 				(0-SensorValue[BackRightQuad])*1.86;
	SenDriveEncoderDif = 				(0-SensorValue[BackRightQuad])*1.86;

#else //Simulator - Don't overwrite variables

	LastBtnScreenLeft =		BtnScreenLeft;
	LastBtnScreenCenter =	BtnScreenCenter;
	LastBtnScreenRight =	BtnScreenRight;
	BtnScreenLeft =			(nLCDButtons & 1) > 0;
	BtnScreenCenter =		(nLCDButtons & 2) > 0;
	BtnScreenRight =		(nLCDButtons & 4) > 0;
#endif
}


void Output()
{
	//Motor slope commands
	if(IsRobotInAutonomousMode)
	{
		//Drive
		SlewedMotor[DriveFL] +=		SlopeFilter(MtrDrvFL,		SlewedMotor[DriveFL],	AutonDriveSlewConstant);
		SlewedMotor[DriveBL] +=		SlopeFilter(MtrDrvBL,		SlewedMotor[DriveBL],	AutonDriveSlewConstant);
		SlewedMotor[DriveFR] +=		SlopeFilter(MtrDrvFR,		SlewedMotor[DriveFR],	AutonDriveSlewConstant);
		SlewedMotor[DriveBR] +=		SlopeFilter(MtrDrvBR,		SlewedMotor[DriveBR],	AutonDriveSlewConstant);

		//Lift
		SlewedMotor[LiftL] +=		SlopeFilter(MtrLift,		SlewedMotor[LiftL],		AutonLiftSlewConstant);
		SlewedMotor[LiftR] +=		SlopeFilter(MtrLift,		SlewedMotor[LiftR],		AutonLiftSlewConstant);

		//Spatula
		SlewedMotor[SpatulaR] +=	SlopeFilter(MtrSpatula,		SlewedMotor[SpatulaR],	AutonSpatulaSlewConstant);
		SlewedMotor[SpatulaL] +=	SlopeFilter(MtrSpatula,		SlewedMotor[SpatulaL],	AutonSpatulaSlewConstant);

		//Conveyor
		SlewedMotor[Conveyor] +=	SlopeFilter(MtrConveyor,	SlewedMotor[Conveyor],	AutonConveyorSlewConstant);

		//Descorer
		SlewedMotor[Descorer] +=	SlopeFilter(MtrDescorer,	SlewedMotor[Descorer],	AutonDescorerSlewConstant);
	}
	else //Robot is in Driver Control Mode
	{
		if(BtnHalfSpeed)
		{
			//Drive
			SlewedMotor[DriveFL] +=		SlopeFilter(MtrDrvFL/2,		SlewedMotor[DriveFL],	DriveSlewConstant);
			SlewedMotor[DriveBL] +=		SlopeFilter(MtrDrvBL/2,		SlewedMotor[DriveBL],	DriveSlewConstant);
			SlewedMotor[DriveFR] +=		SlopeFilter(MtrDrvFR/2,		SlewedMotor[DriveFR],	DriveSlewConstant);
			SlewedMotor[DriveBR] +=		SlopeFilter(MtrDrvBR/2,		SlewedMotor[DriveBR],	DriveSlewConstant);

			//Lift
			SlewedMotor[LiftL] +=		SlopeFilter(MtrLift/2,		SlewedMotor[LiftL],		LiftSlewConstant);
			SlewedMotor[LiftR] +=		SlopeFilter(MtrLift/2,		SlewedMotor[LiftR],		LiftSlewConstant);

			//Spatula
			SlewedMotor[SpatulaR] +=	SlopeFilter(MtrSpatula/2,	SlewedMotor[SpatulaR],	SpatulaSlewConstant);
			SlewedMotor[SpatulaL] +=	SlopeFilter(MtrSpatula/2,	SlewedMotor[SpatulaL],	SpatulaSlewConstant);

			//Conveyor
			SlewedMotor[Conveyor] +=	SlopeFilter(MtrConveyor/2,	SlewedMotor[Conveyor],	ConveyorSlewConstant);

			//Descorer
			SlewedMotor[Descorer] +=	SlopeFilter(MtrDescorer/2,	SlewedMotor[Descorer],	DescorerSlewConstant);
		}
		else if (DriverMode == DriverMotorTest)
		{
			for (int j=0; j<10; j++)
				SlewedMotor[j] = (TestMotorEnabled[j]*StkMtrTest);
		}
		else
		{
			//Drive
			SlewedMotor[DriveFL] +=		SlopeFilter(MtrDrvFL,		SlewedMotor[DriveFL],	DriveSlewConstant);
			SlewedMotor[DriveBL] +=		SlopeFilter(MtrDrvBL,		SlewedMotor[DriveBL],	DriveSlewConstant);
			SlewedMotor[DriveFR] +=		SlopeFilter(MtrDrvFR,		SlewedMotor[DriveFR],	DriveSlewConstant);
			SlewedMotor[DriveBR] +=		SlopeFilter(MtrDrvBR,		SlewedMotor[DriveBR],	DriveSlewConstant);

			//Lift
			SlewedMotor[LiftL] +=		SlopeFilter(MtrLift,		SlewedMotor[LiftL],		LiftSlewConstant);
			SlewedMotor[LiftR] +=		SlopeFilter(MtrLift,		SlewedMotor[LiftR],		LiftSlewConstant);

			//Spatula
			SlewedMotor[SpatulaR] +=	SlopeFilter(MtrSpatula,		SlewedMotor[SpatulaR],	SpatulaSlewConstant);
			SlewedMotor[SpatulaL] +=	SlopeFilter(MtrSpatula,		SlewedMotor[SpatulaL],	SpatulaSlewConstant);

			//Conveyor
			SlewedMotor[Conveyor] +=	SlopeFilter(MtrConveyor,	SlewedMotor[Conveyor],	ConveyorSlewConstant);

			//Descorer
			SlewedMotor[Descorer] +=	SlopeFilter(MtrDescorer,	SlewedMotor[Descorer],	DescorerSlewConstant);
		}
	}

	//Range check and cap (Make sure motors are within the -127 to 127 range)
	for (int i=0; i<10; i++) {CapValue(-127, SlewedMotor[i], 127);}

	//Motor assign commands
	if (MotorsAreEnabled)
	{
		if(DriveStyle)
		{
			motor[DriveFL]	=  -SlewedMotor[DriveBR];
			motor[DriveBL]	=  -SlewedMotor[DriveFR];
			motor[DriveFR]	=  -SlewedMotor[DriveBL];
			motor[DriveBR]	=  -SlewedMotor[DriveFL];
		}
		else
		{
			motor[DriveFL]	=	SlewedMotor[DriveFL];
			motor[DriveBL]	=	SlewedMotor[DriveBL];
			motor[DriveFR]	=	SlewedMotor[DriveFR];
			motor[DriveBR]	=	SlewedMotor[DriveBR];
		}
		motor[LiftL]		=	SlewedMotor[LiftL];
		motor[LiftR]		=	SlewedMotor[LiftR];
		motor[SpatulaR] 	=	SlewedMotor[SpatulaR];
		motor[SpatulaL] 	=	SlewedMotor[SpatulaL];
		motor[Conveyor] 	=	SlewedMotor[Conveyor];
		motor[Descorer] 	=	SlewedMotor[Descorer];
	}
	else
	{
		motor[DriveFL]		=	0;
		motor[DriveBL]		=	0;
		motor[DriveFR]		=	0;
		motor[DriveBR]		=	0;
		motor[LiftL]		=	0;
		motor[LiftR]		=	0;
		motor[SpatulaR]		=	0;
		motor[SpatulaL]		=	0;
		motor[Conveyor]		=	0;
		motor[Descorer]		=	0;
	}
}

void SubroutineCheck()
{
	if (BtnSubroutineSelect && BtnConveyorFwd)		DriverMode = DriverSubPyramid;
	if (BtnSubroutineSelect && BtnDescorerUp)		DriverMode = DriverSubDescore;
	if (BtnSubroutineSelect && BtnAutonFromDriver)	IsRobotInVirtualAutonomousMode = true; //Start Autonomous from the Joystick
}

void DriveControl()
{
	StkCos1 =		(float) StkDrvX/127.0;
	StkSin =		(float) StkDrvY/127.0;
	StkCos2	=		(float) StkDrvZ/127.0;
	StkTheta =		radiansToDegrees(atan2(StkSin, StkCos1));												//////////////////////////////////////////////////
	StkEstPower =	137 - (cos(StkTheta * 4) * 10);// <---------------------------------------------------	// This function makes up for the fact that	the	//
	StkPower =		sqrt((StkCos1*StkCos1) + (StkCos2*StkCos2) + (StkSin*StkSin)) * (16129/StkEstPower);	// joystick is not a perfect circle. It			//
	if (StkPower <= JoystickDZ) StkPower = 0;																// approximates the shape of the joystick.	    //
																											//////////////////////////////////////////////////
	if(DriveStyle) //Normal (Robot faces away from driver)
	{																										//////////////////////////////////////////////////
		MtrDrvFL = -((StkSin*abs(StkSin)) - (StkCos2*abs(StkCos2)) + (StkCos1*abs(StkCos1))) * StkPower;	// Using the trigonometric identities of a	    //
		MtrDrvBL = -((StkSin*abs(StkSin)) - (StkCos2*abs(StkCos2)) - (StkCos1*abs(StkCos1))) * StkPower;	// unit circle, we can treat the 'y' value of   //
		MtrDrvFR = -((StkSin*abs(StkSin)) + (StkCos2*abs(StkCos2)) - (StkCos1*abs(StkCos1))) * StkPower;	// the joystick as sine and the 'x' as cosine.  //
		MtrDrvBR = -((StkSin*abs(StkSin)) + (StkCos2*abs(StkCos2)) + (StkCos1*abs(StkCos1))) * StkPower;	//////////////////////////////////////////////////
	}
	else //Inverted (Robot faces driver)																	//////////////////////////////////////////////////
	{																										// A traditional arcade drive function (I.E.	//
		MtrDrvFL =  ((StkSin*abs(StkSin)) + (StkCos2*abs(StkCos2)) + (StkCos1*abs(StkCos1))) * StkPower;	// Left = X+Y, Right = X-Y) would allow	the 	//
		MtrDrvBL =  ((StkSin*abs(StkSin)) + (StkCos2*abs(StkCos2)) - (StkCos1*abs(StkCos1))) * StkPower;	// the value being sent to the motors to exceed //
		MtrDrvFR =  ((StkSin*abs(StkSin)) - (StkCos2*abs(StkCos2)) - (StkCos1*abs(StkCos1))) * StkPower;	// or be capped at the maximum value of 127.	//
		MtrDrvBR =  ((StkSin*abs(StkSin)) - (StkCos2*abs(StkCos2)) + (StkCos1*abs(StkCos1))) * StkPower;	// In our system, we use the the therom			//
	}																										// (sin^2 + cos^2 = 1) to more naturally map	//
	if (BtnDriveStyle && !LastBtnDriveStyle) DriveStyle = !DriveStyle; //Toggle Drive Style					// joystick values to motor levels. In order to //
	LastBtnDriveStyle = BtnDriveStyle;																		// maintain the sign of the original value,		//
}																											// however, we deviated from this function by   //
																											// multiplying each value by its absolute value //
																											// instead of squaring each value.				//
																											//////////////////////////////////////////////////

void LiftControl()
{	//////////////////////////////////////////////////////////////////////////////////
	// There are three lift positions; ground, high, and ultra high.				//
	// Pushing the lift up and down buttons switches between these three modes,		//
	// and a PID controller takes the lift to the correct height. If the spatula	//
	// is in the way of the lift going up or down, the robot will not allow the		//
	// lift to move, and will 'yell,' alerting the driver that the spatula is in	//
	// the way.																		//
	// If the lift is set to and is at the ground position, the PID controller will	//
	// not control the lift motors, and the motors will be set to 0 in order to		//
	// minimize stress on the motors and their thermistors.							//
	//////////////////////////////////////////////////////////////////////////////////
	
	if (BtnDisablePots) //Emergency override button pressed. Lift buttons control Lift power directly.
	{
		LiftTarget = 0; //Will keep lift motors at zero even when BtnDisablePots is released until a new lift target position is set.
		if		(BtnLiftUp   ==  BtnLiftDown  && BtnLiftUp2 == BtnLiftDown2)	MtrLift = 0;
		else if	(BtnLiftUp   || (BtnLiftUp2   && BtnLiftUp  == BtnLiftDown))	MtrLift = Up;
		else if	(BtnLiftDown || (BtnLiftDown2 && BtnLiftUp  == BtnLiftDown))	MtrLift = Down;
	}
	else
	{
		if ((BtnLiftUp  && !LastBtnLiftUp) || // <--Driver1   v--Driver2
			(BtnLiftUp2 && !LastBtnLiftUp2 && BtnLiftUp == BtnLiftDown))			//UP
		{
			if (LiftTarget < DriverTLPos)			//If was at ground position (target might be 0)...
			{
				if (SenSpatPot <= NoLiftSpatPos)	//..If spatula is low enough:
					LiftTarget = DriverTLPos;		//....then go to trough position
				else if (!bSoundActive)				//..If spatula too high and no sound is playing:
					PlaySoundFile("Aah.wav");		//....then yell!
			}
			else 									//If was at high position:
				LiftTarget = DriverULPos;			//..then go to ultra high position.
		}
		else if ((BtnLiftDown  && !LastBtnLiftDown) || // <--Driver1   v--Driver2
				 (BtnLiftDown2 && !LastBtnLiftDown2 && BtnLiftUp == BtnLiftDown))	//DOWN
		{
			if (LiftTarget > DriverTLPos)			//If was at ultra high position:
				LiftTarget = DriverTLPos; 			//..then go to trough position.
			else									//If was NOT at ultra high:
			{
				if (SenSpatPot < HSPos)				//..If was at trough (or ground, or 0) and spatula is not in the way:
					LiftTarget = DriverGLPos;		//....then go to ground position.
				else if (!bSoundActive)				//..If spatula too high and no sound is playing:
					PlaySoundFile("Aah.wav");		//....then yell!
			}
		}
		if ((SenLiftPot < DriverMLPos && LiftTarget == DriverGLPos) || LiftTarget == 0) MtrLift = 0; // If Lift is low enough and target is ground or 0, then stop
		else MtrLift = UpdatePIDController(PIDLift, LiftTarget-SenLiftPot);							 // Otherwise, use the PID controller
	}
	LastBtnLiftUp	 = BtnLiftUp;
	LastBtnLiftDown	 = BtnLiftDown;
	LastBtnLiftUp2	 = BtnLiftUp2;
	LastBtnLiftDown2 = BtnLiftDown2;
}


void IntakeControl()
{
	//Conveyor
	if 	   ((BtnConveyorFwd == BtnConveyorRev) && (BtnConveyorFwd2 == BtnConveyorRev2))  MtrConveyor = 0;    //If no button is pressed
	else if	(BtnConveyorFwd || BtnConveyorFwd2 && (BtnConveyorFwd  == BtnConveyorRev))   MtrConveyor = Fwd; //Defaults to driver 1
	else if	(BtnConveyorRev || BtnConveyorRev2 && (BtnConveyorFwd  == BtnConveyorRev))   MtrConveyor = Rev; //Defaults to driver 1

	//Spatula
	if		(BtnSpatulaUp == BtnSpatulaDown)	MtrSpatula = 0;
	else if	(BtnSpatulaUp)						MtrSpatula = Up;
	else if	(BtnSpatulaDown)					MtrSpatula = Down;

}

void DescorerControl()
{
	if (BtnDescorerUp == BtnDescorerDown && BtnDescorerUp2 == BtnDescorerDown2) //No descorer button pressed
		MtrDescorer = 0;
	else if	(BtnDescorerUp   || (BtnDescorerUp2   && BtnDescorerUp == BtnDescorerDown)) //Up descorer button pressed, defaults to joystick 1
		MtrDescorer = Up;
	else if	(BtnDescorerDown || (BtnDescorerDown2 && BtnDescorerUp == BtnDescorerDown)) //Down descorer button pressed, defaults to joystick 1
		MtrDescorer = -80;
}

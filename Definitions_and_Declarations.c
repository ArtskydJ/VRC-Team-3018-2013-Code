// This portion of the code is intended to contain all of our
// constant, type, and variable declarations and definitions
// for the rest of our code.

//Definitions
	//Flags
	#define BEEP					// Beep before each autonomous step
	#define PLAYSOUNDS				// Play sound effects when robot scoops, outtakes, descores, or is about to injure itself.
	#define UPDATEINPUTVARIABLES	// Allow sensors to update variables. Disable for manual control of sensor values.
	//#define LOGENCODERS			// Write encoder values to the debug stream

	#ifdef COMPETITION
		#define IsRobotInAutonomousMode bIfiAutonomousMode
		#define IsRobotDisabled bIfiRobotDisabled
	#else
		#define IsRobotInAutonomousMode bSimulatedAutonomousMode
		#define IsRobotDisabled bSimulatedRobotDisabled
	#endif

	//Macros
	#define CapValue(Min,Value,Max) Value = (Value<Min)? Min:Value; Value = (Value>Max)? Max:Value

	/* Line Following
	Our goal is to follow the right edge of a white tape line using two line followers and a PID controller.
	We read raw values between 0 and 4095 from each of the two line followers. These absolute values don't
	correspond to anything directly, so we need to have calibration points for each sensor that tell us how low
	a value each line follower should see when it is on a grey foam tile, and how high a value they should see
	when they are on a bright white line.
	
	This calibration data should be set before the line following program runs. We can set the high and low
	calibration values for each sensor below. While following a line, we want to take the predetermined
	calibration data, along with the latest sensors' values, and be able to get a number between -1000 and 1000
	for each line follower that represents the left or right distance, respectively, that each sensor is away
	from our setpoint. Our PID controller then takes the average of these two values to calculate the final error.
	
	Additionally, our setpoint should be offsetable by a percentage. By this we mean that we should be able to
	follow not just the point right between the tile and the tape, but also a certain distance to the left or
	the right of the line's edge. 90% would mean mostly following white (to the left of the edge), but 10% would
	mean mostly following grey (to the right of the edge).

	In order to do this, we use the following calculations for each line follower:
		C * ((L + (H - L) * P) - I) / (H - L)
		
		H = High = The calibrated high value for the line follower--what it should read when on a white line.
		L = Low  = The calibrated low value for the line follower--what it should read when on a grey foam tile.
		I = Input = The current value of the line follower, closer to 0 when dark, and closer to 4095 when light.
		P = Percentage = The ratio between grey and white that we are seeking as our setpoint.
		C = Constant = Constant representing the lowest value we want (in our case, -1000).
					   The absolute value of the constant is the highest value we want. (in our case, 1000)
	Let's break the math down:
		H - L = The difference between the highest and lowest calibrated values. This gives us our working range.
	From now on, we'll say that D = H - L:
		C * ((L + D * P) - I) / D
		D * P = The value inside the range we want to follow, but lower than what the line follower would see.
		L + (D * P) = The value inside the range we want to follow, converted back to a value our line follower
					  might read. This is our raw target value.
	So let's make T = (L + (D * P)) (T for Target position)
		C * (T - I) / D
		(T - I) = Error. Error means the difference or distance between the target value and the input value.
		k = -1000 = constant
			This constant is so that the finished result can be stored in an int.
			Otherwise it would default to -1, 0 or 1.
		T-I = Error
			Target - Input = Error
	Explanation:
		Error/Difference creates a range of -.5 to .5 if the percent is 50/100.
		Multiplying by the constant creates a range of 500 to -500
		A PID controller is easily used to follow the line.
	*/

	#define LineEdge 1800
	#define FloorEdgeLineup 2500 						//For line edge detectors
	#define LineFolPercent (10.0/100.0)					//Percentage between tile and tape: 0/100=tile, 100/100=white

	// Front Center Line Followers' Calibration values
	#define LeftLineFolTileDefault  1200 //1350 //1350 //1147		//Low
	#define LeftLineFolLineDefault  1960 //2750 //1700 //1515		//High
	#define RightLineFolTileDefault 1390 //1660 //1660 //1223		//Low
	#define RightLineFolLineDefault 3100 //3920 //1977 //3600		//High

	#define LeftLineFolDiff   (LeftLineFolLine  - LeftLineFolTile)						// High - Low. Brings the lowest value down to 0.
	#define LeftLineFolPosi   (LeftLineFolTile  + (LeftLineFolDiff  * LineFolPercent))	// Low + (Diff * percent)
	#define RightLineFolDiff  (RightLineFolLine - RightLineFolTile)						// High - Low. Brings the lowest value down to 0.
	#define RightLineFolPosi  (RightLineFolTile + (RightLineFolDiff * LineFolPercent))	// Low + (Diff * percent)

	//This scales our line sensor values from -1000 to 1000
	#define LeftLineFolScaled  ( -1000*(  LeftLineFolPosi - (float) SenLeftLine  ) /  LeftLineFolDiff )
	#define RightLineFolScaled ( -1000*( RightLineFolPosi - (float) SenRightLine ) / RightLineFolDiff )

	//Directional definitions for the motors
	#define Up 127
	#define Down -127
	#define Fwd 127
	#define Rev -127
	#define Right 127
	#define Left -127

	//Autonomous definitions
	#define Start 0
	#define Finish 1

	//Autonomous Step Types
	#define RESETAUTO 0  // Autonomous Done (End of array)
	#define TIMELIMIT 1  // Time limit
	#define LIFTPOTEN 2  // Lift Potentiometer
	#define RELTRNGYR 3  // Turn Relative Gyroscope
	#define ENCODSTRA 4  // Encoder Straight
	#define ENCODTURN 5  // Encoder Turn
	#define SPATPOTEN 6  // Spatula Potentiometer
	#define	WHITELINE 7  // Until white Line
	#define SCREENBTN 8  // Screen Button
	#define PIDSTRAIG 9  // PID Straight
	#define CONVSWICH 10 // Conveyer switch
	#define GYRSTRAFE 11 // Gyro Strafe
	//#define TURNAGYRO 12 // Turn Absolute Gyroscope
	//#define RUSRSTRAF 13 // Right Ultrasonic Relative Strafe
	//#define BCKULTSTR 14 // Drive to PID Back Ultra
	#define LEFTULGYR 15 // Strafe until Ultrasonic Left with Gyro
	#define RIGTULGYR 16 // Strafe until Ultrasonic Right with Gyro
	#define BACKULSTR 17 // Straight until Ultrasonic Back
	#define ABSTRNGYR 18 // Absolute gyro turn
	#define SQUAREUPG 19 // Square up Gyro
	#define CROSSLINE 20 // Hit line with edge sensor
	#define FRONTLINE 21 // Hit line with center sensor
	//#define ENABLSPAT 22 // Enable Spatula Down PID. (Wait for Target)
	//#define DISBLSPAT 23
	#define WALL_L	128
	#define WALL_R	129
	#define LINE	130


	//Preset lift heights
	// As you can see, these have changed over time.
	// Provided in the comments here are old values for historical reference.
	#define GLPos 1100 //600 //270 //330
	#define MLPos 1745 //1539 //1235
	#define TLPos 2690 //2425 //3000 //3200
	#define ULPos 2866 //2600 //3000 //3200

	#define DriverGLPos 1130 //700 //270 //330
	#define DriverMLPos 1150 //820 //1235
	#define DriverTLPos 2689 //2400 //3000 //3200
	#define DriverULPos 2866 //2600 //3000 //3200

	//Preset spatula heights
	#define LSPos 450 //2325 //2265 //720  //1510
	#define MSPos 1025 //2900 //2500 //1500 //2200
	#define NoLiftSpatPos 1400 //1225
	#define HSPos 1895 //3770 //3580 //2480 //3921

	//Misc Constants
	#define GYROSTRAFEP 2
	#define NumOfAutoRoutines 12
	#define NumOfMenuItems 11
	#define NmOfAutNmStrs 3
	#define NumOfTimeRecords 100
	#define JoystickDZ 20

	//Wait Times
	#define MinLoopMS 5
	#define FailsafeMS 4000
	#define NextMessageCharMS 250
	#define PIDWaitMS 200

//Enum Definitions
	typedef enum
	{
		Center,
		Left0,
		Left1
	} TLCDPos;

	typedef enum
	{
		DispDriverMode,
		DispDisabledMode,
		DispAutonomousMode,
	} TDisplayMode;

	typedef enum
	{
		DriverJoystickControl,
		DriverMotorTest,
		DriverSubPyramid,
		DriverSubDescore
	} TDriverMode;

//Struct Definitions
	typedef struct
	{
		float Kp;
		float Ki;
		float Kd;
		int Error;
		int Integral;
		int Derivative;
		int LastError;
		int Output;
	}	TPID;

//Enum Variable Declarations
	TLCDPos DisplayPosition = Left0;
	TDriverMode DriverMode = DriverJoystickControl;

//Struct Variable Declarations
	TPID PIDLineFollower;
	TPID PIDDescorer;
	TPID PIDWallFollower;
	TPID PIDLift;
	TPID PIDSpatula;
	TPID PIDDriveStraight;
	TPID PIDDriveGyro;

//Integer Variable Declarations
	//Main Joystick Sticks
	int StkDrvX;
	int StkDrvY;
	int StkDrvZ;
	int StkMtrTest;

	//Sensors
	int SenLiftPot;
	int SenAutoPot;
	int SenGyro;
	int SenDrivenMotorEncoderBackLeft  = 0;
	int SenDrivenMotorEncoderBackRight = 0;
	int SenDriveEncoderAvg;
	int SenDriveEncoderDif;
	int SenSpatPot;
	int SenLeftLine  = 0;
	int SenRightLine = 0;
	int SenLeftEdge  = 0;
	int SenRightEdge = 0;
	int SenLeftUltrasonic;
	int SenRightUltrasonic;
	int SenBackUltrasonic;
	int SenConveyerSwitch;

	//Motors
	int MtrDrvFL;
	int MtrDrvBL;
	int MtrDrvFR;
	int MtrDrvBR;
	int MtrLift;
	int MtrSpatula;
	int MtrConveyor;
	int MtrDescorer;

	//Computational
	int LeftLineFolTile	 = LeftLineFolTileDefault;
	int LeftLineFolLine  = LeftLineFolLineDefault;
	int RightLineFolTile = RightLineFolTileDefault;
	int RightLineFolLine = RightLineFolLineDefault;
	int LastBtnDriveStyle;
	int AutonomousStep = 0;
	int LastAutonomousRoutine = 0;
	int AutonomousRoutine = 1;
	int LiftTarget = 0;
	int DriveEncoderError;
	int DriveEncoderErrorLast;
	int DriveEncoderStartAvg;
	int DriveEncoderStartDif;
	int StepStartGyro = 0;
	int ScrollStringIndex = 0;
	int ScrollCharIndex = 0;
	int LastMenuItem = 0;
	int MenuItem = 0;
	int MainLoopTime = 0;
	int MainNonDelayedLoopTime = 0;
	int LastGyro = 0;
	int AbsoluteGyro = 0;
	int AddToAbsGyro = 0;

	//Extra Timers (not as precise as built in timers)
	int LastMasterTimer = 0;
	int DiffMasterTimer = 0;
	unsigned long TimerAutonomous = 0;
	unsigned long TimerLCDScroll  = 0;
	unsigned long TimerPIDEnd	  = 0;

//Floating Point Variable Declarations
	//Computational
	float StkPower;
	float StkSin;
	float StkCos1;
	float StkCos2;
	float StkEstPower;
	float StkTheta;
	//Old Slew Constants included for reference
	float DriveSlewConstant			= 3;	//2; // 0.1; //2
	float LiftSlewConstant			= 10;	//1; //0.1; //1
	float SpatulaSlewConstant		= 10;	//3; //0.1; //3
	float ConveyorSlewConstant		= 5;	//3; //0.1; //3
	float DescorerSlewConstant		= 3;	//3; //0.1; //3
	//Slew Constants with 'Auton' in front get applied during Autonomous instead of the default slew constants.
	float AutonDriveSlewConstant    = 3;	//2; // 0.1; //2
	float AutonLiftSlewConstant     = 10;	//1; //0.1; //1
	float AutonSpatulaSlewConstant  = 40;	//3; //0.1; //3
	float AutonConveyorSlewConstant = 5;	//3; //0.1; //3
	float AutonDescorerSlewConstant = 5;	//3; //0.1; //3

//Boolean Variable Declarations
	//Joystick 1 (Main Joystick)
	bool BtnConveyorFwd;
	bool BtnConveyorRev;
	bool BtnDriveStyle = 0;
	bool BtnSubroutineSelect;
	bool BtnLiftUp;
	bool BtnLiftDown;
	bool LastBtnLiftUp;
	bool LastBtnLiftDown;
	bool BtnSpatulaUp;
	bool BtnSpatulaDown;
	bool BtnDescorerUp;
	bool BtnDescorerDown;
	bool BtnDisablePots;
	bool BtnAutonFromDriver;
	bool BtnHalfSpeed;

	//Joystick 2 (Secondary Joystick)
	bool BtnConveyorFwd2;
	bool BtnConveyorRev2;
	bool BtnLiftUp2;
	bool BtnLiftDown2;
	bool LastBtnLiftUp2;
	bool LastBtnLiftDown2;
	bool BtnSpatulaUp2;
	bool BtnSpatulaDown2;
	bool BtnDescorerUp2;
	bool BtnDescorerDown2;

	//Screen buttons
	bool BtnScreenLeft					= false;
	bool LastBtnScreenLeft				= false;
	bool BtnScreenCenter				= false;
	bool LastBtnScreenCenter			= false;
	bool BtnScreenRight					= false;
	bool LastBtnScreenRight				= false;

	//Computational
	bool HitTarget						= false;
	bool bSimulatedAutonomousMode		= false;
	bool bSimulatedRobotDisabled		= false;
	bool DriveStyle;
	bool MotorsAreEnabled				= true;
	bool AutonIsOnTheClock				= false;
	bool HaveFoundLeftEdge				= false;
	bool HaveFoundRightEdge				= false;
	bool bItemActivated					= false;
	bool IsRobotInVirtualAutonomousMode	= false;

//String Variable Declarations
	string TopLCDLine		 = "";
	string LastTopLCDLine	 = "";
	string BottomLCDLine	 = "";
	string LastBottomLCDLine = "";

//Array Declarations
	int AutoTimeRecord[NumOfTimeRecords];
	float SlewedMotor[10];
	int TestMotorEnabled[10] = {0,0,0,0,0,0,0,0,0,0};
	string BatteryLevel[2];
	const string AutoName[NumOfAutoRoutines][NmOfAutNmStrs]={
		//Names of each of our Autonomous routines
		"Left--Under trou","gh in it; go for"," pyramid-25   ",		//1
		"Right-8 Wall, Py","ramid, under tro","ugh in it-40   ",	//2
		"Left--8 Wall & u","nder trough in t","rough-65   ",		//3
		"Right-Pyramid & ","under trough in ","trough-45   ",		//4
		"Left--Pyramid, y","ellow, pyramid, ","score-65   ",		//5
		"Right-Pyramid & ","under trough in ","it, descore-45   ",	//6
		"NONE   NONE   ","NONE   NONE   ","NONE   NONE   ",			//7
		"Right-Under trou","gh, pyramid, ye","llow; score-60   ",	//8
		"Right-Autonomous","/Programming Ski","lls-185   ",			//9
		"Right-Autonomous","/Programming"," Skills-240   ",			//10
		"TESTS   TESTS   ","TESTS   TESTS   ","TESTS   TESTS   ",	//11
		"Test--New Autono","mous Skills","   "};					//12
	const string MenuItemName[NumOfMenuItems]={
		"Autonomous: ",
		"Dis/Enable Mtrs",
		"Battery Levels:",
		"Motor Test:",
		"Motor Test:",
		"Analog Value:",
		"Digital Value:",
		"Left-Line Tile:",
		"Left-Line Line:",
		"Right-Line Tile:",
		"Right-Line Line:"};

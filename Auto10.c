#define RESET_AUTONOMOUS    {0,0,0,0,0,0,0,0,RESETAUTO}
#define SCOOP_UP_SACKS      {GLPos,0,Up,0,0,0,0,700,TIMELIMIT}
#define SCOOP_UP_SACKS_LONG {GLPos,0,Up,0,0,0,0,850,TIMELIMIT}
#define RAISE_LIFT(INTime)  {TLPos,0,MSPos,0,0,0,0,INTime,TIMELIMIT}
#define LOWER_LIFT(INTime)  {GLPos,0,0,0,0,0,0,INTime,TIMELIMIT}
#define OUTTAKE(INTime)     {TLPos,Fwd,0,0,0,0,0,INTime,TIMELIMIT}
#define FWD_OUTTAKE(INTime) {TLPos,Fwd,0,30,30,0,0,INTime,TIMELIMIT}
#define WAIT(INTime)        {0,0,0,0,0,0,0,INTime,TIMELIMIT}


const int auto10[][]={ //New Programming Skills Start with 3 preloads in intake ... WAS 08
RESET_AUTONOMOUS,															//Reset

//Scoop up sacks along right wall and trough
{GLPos,	0,		LSPos,	Up,		100,	100,	0,		750,	TIMELIMIT},	//Drive into wall
SCOOP_UP_SACKS,																//Scoop along wall part 1
{0,		-100,	MSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//Drive backward
{0,		-110,	LSPos,	0,		0,		0,		Left,	300,	RIGTULGYR},	//Strafe left, lower spatula
{0,		0,		LSPos,	0,		100,	100,	0,		0650,	TIMELIMIT},	//Drive forward
SCOOP_UP_SACKS,																//Scoop along wall part 2
{0,		0,		MSPos,	0,		-100,	-100,	0,		-80,	ENCODSTRA},	//Drive backward
{0,		-100,	LSPos,	0,		0,		0,		Left,	600,	RIGTULGYR},	//Strafe left, lower spatula
{0,		-100,	LSPos,	0,		100,	100,	0,		660,	TIMELIMIT},	//Drive forward
SCOOP_UP_SACKS,																//Scoop along wall part 3
WAIT(50),																	//Wait
{0,		0,		MSPos,	0,		-45,	-45,	0,		300,	TIMELIMIT},	//Back away from wall
WAIT(50),																	//Back up
{0,		0,		0,		0,		0,		0,		0,		-910,	RELTRNGYR},	//Gyro spin to trough
{GLPos,	-100,	0,		0,		Fwd,	Fwd,	0,		940,	ENCODSTRA},	//Drive to trough
SCOOP_UP_SACKS,																//Scoop under the trough
{0,		0,		0,		0,		Rev,	Rev,	0,		-150,	ENCODSTRA},	//Back up and raise lift
RAISE_LIFT(2500),															//Raise Lift
{TLPos,	100,	MSPos,	0,		90,		90,		0,		800,	TIMELIMIT},	//Drive forward to trough
{TLPos,	Fwd,	0,		0,		10,		10,		0,		2500,	TIMELIMIT},	//Outtake
{80,	Fwd,	0,		0,		110,	110,	0,		100,	TIMELIMIT},	//Push sacks
{0,		Fwd,	0,		0,		-45,	-45,	0,		3000,	WHITELINE},	//Back into line
{GLPos,	0,		0,		0,		45,		45,		0,		335,	TIMELIMIT},	//Forward
{GLPos,	0,		0,		0,		0,		0,		0,		-900,	RELTRNGYR},	//Turn 90 degrees
LOWER_LIFT(400),															//Finish lowering lift

//Scoop up pyramids and yellow
{GLPos,	0,		LSPos,	0,		80,		80,		0,		150,	TIMELIMIT},	//Drive away from line cross
{GLPos,	0,		LSPos,	0,		80,		80,		LINE,	300,	TIMELIMIT},	//Follow line
SCOOP_UP_SACKS_LONG,														//Scoop up pyramid part 1
{0,		-50,	LSPos,	0,		-60,	-60,	0,		-200,	ENCODSTRA},	//Back up
{0,		0,		LSPos,	0,		75,		75,		LINE,	800,	TIMELIMIT},	//Follow line
SCOOP_UP_SACKS_LONG,														//Scoop up pyramid part 2
{0,		0,		LSPos,	0,		-60,	-60,	0,		-50,	ENCODSTRA},	//Back up
{0,		0,		LSPos,	0,		75,		75,		LINE,	3000,	CROSSLINE},	//Follow line until cross line...
{0,		-110,	LSPos,	0,		75,		75,		LINE,	350,	TIMELIMIT},	//Follow line until time
SCOOP_UP_SACKS_LONG,														//Scoop up yellow and pyramid take 1
{0,		0,		LSPos,	0,		-60,	-60,	0,		550,	TIMELIMIT},	//Back up
{0,		-90,	LSPos,	0,		75,		75,		LINE,	1000,	TIMELIMIT},	//Follow line
SCOOP_UP_SACKS,																//Scoop up pyramid take 2
{0,		0,		LSPos,	0,		-60,	-60,	0,		-180,	ENCODSTRA},	//Back up
{0,		-90,	LSPos,	0,		75,		75,		LINE,	800,	TIMELIMIT},	//Follow line
SCOOP_UP_SACKS_LONG,														//Scoop up pyramid take 3
{0,		0,		LSPos,	0,		-60,	-60,	0,		-200,	ENCODSTRA},	//Back up
{0,		0,		MSPos,	0,		0,		0,		0,		900,	RELTRNGYR},	//Gyro Spin
{GLPos,	-50,	LSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//Back up

//Scoop up sacks under trough, outtake
{0,		-90,	LSPos,	0,		Fwd,	Fwd,	0,		400,	ENCODSTRA},	//Drive to trough
SCOOP_UP_SACKS,																//Scoop bags under trough
{GLPos,	0,		LSPos,	0,		0,		0,		0,		100,	TIMELIMIT},	//Slam spatula down
{TLPos,	0,		LSPos,	0,		-100,	-100,	0,		-200,	ENCODSTRA},	//Back up and raise lift
RAISE_LIFT(2500),															//Raise lift
{TLPos+50,50,	MSPos,	0,		100,	100,	0,		200,	ENCODSTRA},	//Drive forward to trough
FWD_OUTTAKE(2900),															//Outtake
{Up,	Fwd,	LSPos,	0,		100,	100,	0,		350,	TIMELIMIT},	//Drive into trough

//Go to left start tile
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA},	//Back up from trough
{GLPos,	0,		MSPos,	0,		Fwd,	Rev,	0,		-200,	ENCODTURN},	//Turn to get a better angle
{GLPos,	0,		0,		0,		Rev,	Rev,	0,		-1650,	ENCODSTRA},	//Back up from trough toward start tile
{GLPos,	0,		0,		0,		Rev,	Fwd,	0,		1030,	TIMELIMIT},	//Turn toward wall
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		500,	TIMELIMIT}, //Drive forward over start tile
{0,		0,		MSPos,	0,		0,		0,		0,		1000,	SCREENBTN}, //Wait for button or time (to match load sacks and realign if necessary)

//Scoop up sacks along left wall and trough
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		900,	TIMELIMIT}, //Drive into wall
SCOOP_UP_SACKS,																//Scoop along wall part 1
{GLPos,	-100,	MSPos,	0,		-80,	-80,	0,		-150,	ENCODSTRA},	//Drive backward
{GLPos,	-100,	MSPos,	0,		0,		0,		Right,	250,	LEFTULGYR},	//Strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	TIMELIMIT},	//Drive forward
SCOOP_UP_SACKS,																//Scoop along wall part 2
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-150,	ENCODSTRA},	//Drive backward
{GLPos,	-127,	0,		0,		0,		0,		Right,	590,	LEFTULGYR},	//Strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0690,	TIMELIMIT},	//Drive forward
SCOOP_UP_SACKS,																//Scoop along wall part 3
{GLPos,	-127,	MSPos,	0,		-80,	-80,	0,		30,		TIMELIMIT},	//Srive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		930,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	ENCODSTRA},	//Drive to trough
SCOOP_UP_SACKS,																//Scoop bags under trough
{0,		0,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//Back up, lower spatula
RAISE_LIFT(1800),															//Raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		300,	TIMELIMIT},	//Drive forward to trough
FWD_OUTTAKE(2000),															//Outtake

//Back up and park on left tile
{TLPos,	Fwd,	LSPos,	0,		Rev,	0,		0,		500,	TIMELIMIT},	//Turn
{TLPos,	Fwd,	0,		0,		Rev,	Rev,	0,		-400,	ENCODSTRA},	//Back up, keep lift high
{GLPos,	Fwd,	0,		0,		Rev,	Rev,	0,		-1000,	ENCODSTRA},	//Back up, lower lift

RESET_AUTONOMOUS};															//Reset

/*
Starts on Right tile pointed at right wall.

ERRORS:
*/
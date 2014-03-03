const int auto01[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
{GLPos,	0,		HSPos,	Up,		120,	120,	Left,	240,	ENCODSTRA}, //strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1700,	ENCODSTRA}, //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop bags under trough
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA}, //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2200,	TIMELIMIT}, //raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		0100,	ENCODSTRA}, //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1300,	TIMELIMIT}, //dump bags in trough
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-20,	ENCODSTRA}, //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	RELTRNGYR},	//Gyro Spin //maybe lessen this
{GLPos,	0,		LSPos,	0,		0,		0,		0,		700,	TIMELIMIT}, //Wait for lift to go down all the way
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0400,	ENCODSTRA}, //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop up bags in pyramid part 1
{GLPos,	Rev,	LSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA}, //back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0150,	ENCODSTRA}, //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-70,	ENCODSTRA}, //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0150,	ENCODSTRA}, //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop up bags in pyramid part 3
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};//Autonomous is done

/*
Starts on Left tile pointed toward trough

ERRORS:
not too bad...
delay after going up, too long
should back up more

*/

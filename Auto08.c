const int auto08[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
{GLPos,	0,		HSPos,	Up,		110,	120,	Right,	580,	ENCODSTRA}, //strafe right and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		2200,	ENCODSTRA}, //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop bags under trough
{0,		0,		LSPos,	0,		-60,	-60,	0,		3000,	WHITELINE}, //Back into line
{GLPos,	0,		0,		0,		45,		45,		0,		320,	TIMELIMIT},	//forward
{0,		0,		MSPos,	0,		0,		0,		0,		-930,	RELTRNGYR},	//Gyro Spin to pyramid
{0,		0,		LSPos,	0,		-60,	-60,	0,		-80,	ENCODSTRA}, //back
{0,		0,		LSPos,	0,		100,	100,	0,		0400,	ENCODSTRA}, //drive to pyramid
{0,		0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop up bags in pyramid part 1
{0,		0,		LSPos,	0,		-60,	-60,	0,		-150,	ENCODSTRA}, //back up
{0,		0,		LSPos,	0,		115,	Fwd,	0,		1000,	ENCODSTRA}, //drive forward
{0,		0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop up bags in pyramid part 2
{0,		0,		Down,	0,		Rev,	Rev,	0,		0400,	TIMELIMIT}, //slam down spatula
{TLPos,	0,		MSPos,	0,		0,		0,		0,		900,	RELTRNGYR},	//Gyro Spin //maybe lessen this
{TLPos,	0,		0,		0,		0,		0,		0,		1500,	TIMELIMIT}, //raise lift
{TLPos,	50,		0,		0,		Fwd,	Fwd,	0,		0320,	TIMELIMIT}, //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		1600,	TIMELIMIT}, //dump bags in trough
{GLPos,	0,		0,		0,		Rev,	Rev,	0,		-20,	ENCODSTRA}, //drive backward
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};//Autonomous is done

/*
Starts on Right tile pointed forward

ERRORS:
drives at an angle toward the left when going toward the trough...
*/

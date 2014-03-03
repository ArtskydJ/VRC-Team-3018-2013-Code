const int auto05[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Right,	700,	TIMELIMIT},	//strafe right and drive forward
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		630,	ENCODSTRA},	//drive to pyramid
{0,		0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 1
{0,		0,		LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		75,		ENCODSTRA},	//drive forward
{0,		0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	250,	GYRSTRAFE},	//strafe
{GLPos,	0,		LSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//pause for motor slew to rest
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		180,	TIMELIMIT},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		150,	ENCODSTRA},	//drive forward to under trough ... maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		305,	TIMELIMIT},	//back up
{0,		0,		MSPos,	0,		0,		0,		0,		900,	RELTRNGYR},	//Gyro Spin to yellow
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		190,	TIMELIMIT},	//back up
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		580,	ENCODSTRA},	//drive to yellow
{0,		0,		Up,		0,		-10,	0,		0,		800,	TIMELIMIT},	//scoop up yellow
{0,		0,		LSPos,	0,		Rev,	60,		0,		50,		ENCODSTRA},	//back up
{TLPos,	0,		LSPos,	0,		-60,	100,	0,		360,	ENCODSTRA},	//turn
{TLPos,	0,		0,		0,		-30,	-30,	0,		400,	TIMELIMIT},	//Lift, back up
{TLPos,	0,		0,		0,		0,		0,		0,		1000,	TIMELIMIT},	//Lift up
{TLPos,	70,		0,		0,		0,		0,		0,		100,	TIMELIMIT},	//Lift, outtake
{TLPos,	Fwd,	0,		0,		80,		80,		0,		650,	TIMELIMIT},	//Forward, outtake
{TLPos,	Fwd,	0,		0,		0,		0,		0,		1200,	TIMELIMIT},	//outtake
{0,		0,		MSPos,	0,		-40,	-40,	0,		-575,	ENCODSTRA},	//output bags and backing up
{0,		0,		0,		0,	      0,      0,	0,	       0,	RESETAUTO}};//Autonomous is done

/*
Starts on Left tile pointed forward

ERRORS:
*/
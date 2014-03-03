const int auto02[][]={ //New Two (not used, not working after picking up wall)
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
//{-100,0,		Up,		127,	0,		0,		Left,	-001,	ENCODTURN},	//strafe right, lower spatula
{0,		0,		LSPos,	Up,		0,		0,		0,		0320,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks  -1-
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	270,	RIGTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks  -2-
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-80,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	0650,	RIGTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0550,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks  -3-
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-030,	ENCODSTRA},	//drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-1660,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		180,	ENCODSTRA},	//drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop bags of pyramid part 1
/*{GLPos,0,		LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		90,		ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2*/
{50,	0,		Down,	0,		0,		0,		0,		300,	TIMELIMIT},	//Move spatula down
{ULPos,	0,		MSPos,	0,		1000,	-60,	0,		0800,	TIMELIMIT}, //NO ENCODER ON THIS SIDE
{TLPos,	0,		MSPos,	0,		0,		0,		0,		1200,	TIMELIMIT}, //NO ENCODER ON THIS SIDE
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	TIMELIMIT},	//Outtake
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	TIMELIMIT},	//back up
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	TIMELIMIT},	//Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	TIMELIMIT},	//strafe onto tile
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};//Reset

/*
Starts on Right tile pointed toward wall

ERRORS:
not good enough...
does not strafe, have not checked past...
*/

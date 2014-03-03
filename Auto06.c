const int auto06[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Left,	700,	TIMELIMIT},	//strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		600,	ENCODSTRA},	//drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		100,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		MSPos,	0,		0,		0,		0,		150,	TIMELIMIT},	//spatula down (out of the way of the lift)
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2100,	TIMELIMIT},	//start lifting
{TLPos,	50,		0,		0,		100,	100,	0,		800,	TIMELIMIT},	//Drive forward to trough
{TLPos,	Fwd,	0,		0,		20,		20,		0,		1100,	TIMELIMIT},	//Dump sacks in trough
{0,		Fwd,	0,		0,		-40,	-40,	0,		-300,	ENCODSTRA},	//keep dumping and back up

{GLPos,	0,		MSPos,	0,		0,		0,		0,		900,	RELTRNGYR},	//Turn toward right wall
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		900,	ENCODSTRA},	//Drive toward right wall
{GLPos,	0,		LSPos,	0,		0,		0,		0,		150,	TIMELIMIT},	//Wait
{GLPos,	0,		LSPos,	0,		0,		0,		0,		-920,	RELTRNGYR},	//Turn toward opponent's trough

{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		500,	ENCODSTRA},	//Drive toward opponent's trough
{GLPos,	0,		Up,		Down,	0,		0,		0,		700,	TIMELIMIT},	//scoop up sacks, lower descorer
{GLPos,	0,		MSPos,	0,		-90,	-90,	0,		750,	TIMELIMIT},	//back up slowly
{GLPos,	0,		MSPos,	0,		Fwd,	Fwd,	0,		450,	TIMELIMIT},	//forward to good descore position
{GLPos,	0,		Up,		Down,	0,		0,		0,		400,	TIMELIMIT},	//spatula up, lower descorer
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};//Autonomous is done

/*
Starts on Right tile pointed forward

ERRORS:
*/
const int auto04[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Left,	700,	TIMELIMIT},	//strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		600,	ENCODSTRA},	//drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		100,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-250,	GYRSTRAFE},	//strafe
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//pause for motor slew to rest
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		180,	TIMELIMIT},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		150,	ENCODSTRA},	//drive forward to under trough ... maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//back up, start lifting
{TLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-125,	ENCODSTRA},	//back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	TIMELIMIT},	//keep lifting
{TLPos,	0,		MSPos,	0,		100,	100,	0,		600,	TIMELIMIT},	//drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		20,		20,		0,		1800,	TIMELIMIT},	//dump sacks
{0,		Fwd,	MSPos,	0,		-40,	-40,	0,		-575,	ENCODSTRA},	//output bags and backing up
{0,		0,		     0,	0,	      0,      0,	0,	       0,	RESETAUTO}};//Autonomous is done
//Lift,	Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetVal,TargetCondition

/*
Starts on Right tile pointed forward
12.7 elapsed, could do more?

ERRORS:
could be sped up around the trough area
*/

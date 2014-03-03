const int auto09[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset

{GLPos,	0,		HSPos,	Up,		100,	100,	Right,	500,	GYRSTRAFE}, //strafe right and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		2300,	ENCODSTRA}, //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT}, //scoop bags under trough
{TLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA}, //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	TIMELIMIT}, //raise lift
{TLPos,	50,		MSPos,	0,		100,	100,	0,		0120,	ENCODSTRA}, //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1300,	TIMELIMIT}, //dump bags in trough
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-1600,	ENCODSTRA}, //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	TIMELIMIT}, //lower lift
{0,		0,		MSPos,	0,		0,		0,		0,		1000,	SCREENBTN}, //reposition

{GLPos,	0,		MSPos,	0,		110,	110,	Left,	800,	TIMELIMIT},	//strafe left and drive forward
{GLPos,	0,		LSPos,	0,		100,	100,	0,		500,	ENCODSTRA},	//drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-150,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		100,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-150,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-400,	ENCODTURN},	//strafe
{GLPos,	0,		LSPos,	0,		100,	100,	0,		200,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-200,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-500,	ENCODTURN},	//strafe
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		150,	ENCODSTRA},	//drive forward to trough     (make this longer?)
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags
{TLPos,	Fwd,	MSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	TIMELIMIT},	//keep lifting
{TLPos,	0,		MSPos,	0,		Fwd,	Fwd,	0,		80,		ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1800,	TIMELIMIT},	//dump sacks
{TLPos,	Fwd,	MSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//Reverse
{GLPos,	Fwd,	MSPos,	0,		-40,	-40,	0,		-205,	ENCODSTRA},	//dump bags and back up
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-880,	RELTRNGYR},	//Gyro Spin

// Third Part
{GLPos,	0,		LSPos,	0,		0,		0,		0,		300,	TIMELIMIT},	//Wait for lift to go down all the way
{GLPos,	0,		LSPos,	0,		-100,	-100,	0,		150,	TIMELIMIT},	//back up to get yellow //This should be less
{GLPos,	0,		LSPos,	0,		100,	100,	0,		200,	ENCODSTRA},	//drive forward to yellow
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up yellow bag
{GLPos,	Fwd,	LSPos,	0,		0,		0,		0,		400,	TIMELIMIT},	//put spatula down
{GLPos,	0,		LSPos,	0,		100,	100,	0,		250,	ENCODSTRA},	//drive to second pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 1
{GLPos,	-50,	LSPos,	0,		-80,	-80,	0,		-200,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		150,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//scoop up bags
{GLPos,	0,		LSPos,	0,		100,	100,	0,		150,	ENCODSTRA},	//drive forward
{0,		0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 3
{0,		0,		LSPos,	0,		-100,	-100,	0,		-500,	ENCODSTRA},	//back up to line up with trough
{0,		0,		MSPos,	0,		0,		0,		0,		880,	RELTRNGYR},	//Gyro Spin
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		400,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop bags under trough
{TLPos,	0,		LSPos,	0,		-80,	-80,	0,		-180,	ENCODSTRA},	//flag ..... back up and raise lift
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	TIMELIMIT},	//raise lift
{TLPos,	Fwd,	MSPos,	0,		100,	100,	0,		100,	ENCODSTRA},	//flag2 ..... if good bat maybe, change to 500 drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		-30,	1500,	TIMELIMIT},	//dump bags in trough while straifing
{TLPos,	Rev,	LSPos,	0,		100,	100,	0,		150,	TIMELIMIT},	//drive to trough
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		-300,	ENCODSTRA},	//back up from trough
{GLPos,	0,		MSPos,	0,		-20,	-127,	0,		-1700,	ENCODSTRA},	//drive back to blue left start tile
{0,		0,		MSPos,	0,		Rev,	Fwd,	0,		10,		ENCODTURN},	//turn

//Robot is realigned on other starting tile
{Down,	0,		MSPos,	0,		0,		0,		0,		300,	TIMELIMIT},	//Wait for screen button
{0,		0,		MSPos,	0,		0,		0,		0,		2000,	SCREENBTN},	//Wait for screen button

//Fourth Part
{GLPos,	0,		LSPos,	127,	0,		0,		0,		0200,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0800,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-250,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0310,	ENCODTURN},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		100,	100,	0,		0800,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0600,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-200,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0280,	ENCODTURN},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		800,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-40,	ENCODSTRA},	//drive backward
{GLPos,	Rev,	MSPos,	0,		0,		0,		0,		880,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop bags under trough
{TLPos,	50,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	TIMELIMIT},	//raise lift
{TLPos,	50,		LSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		40,		2000,	TIMELIMIT},	//Outtake
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	TIMELIMIT},	//Push in
{TLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1700,	ENCODSTRA},	//back up
{GLPos,	Fwd,	LSPos,	0,		0,		0,		Right,	900,	TIMELIMIT},	//strafe onto tile
{0,		0,		0,		0,		0,      0,		0,		0,		RESETAUTO}};//Autonomous is done

/*
Starts on Right tile pointed forward

ERRORS:
*/
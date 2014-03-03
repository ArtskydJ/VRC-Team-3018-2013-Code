const int auto12[][]={

{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},	//Reset

{-100,	0,		LSPos,	Up,		0,		0,		0,		0100,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{0,		-100,	MSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//drive backward

{0,		0,		MSPos,	0,		0,		0,		0,		-925,	RELTRNGYR},	//Gyro Spin to trough
//{0,	0,		LSPos,	0,		0,		0,		Right,	50,		GYRSTRAFE},	//strafe right, lower spatula
//{0,	Rev,	LSPos,	0,		0,		0,		Left,	300,	RIGTULGYR},	//strafe left, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1940,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop bags under trough
/*
{0,		0,		LSPos,	0,		Rev,	Rev,	0,		-150,	ENCODSTRA},	//back up and raise lift
{Up,	0,		MSPos,	0,		0,		0,		0,		2500,	TIMELIMIT},	//raise lift
{TLPos,	100,	MSPos,	0,		90,		90,		0,		800,	TIMELIMIT},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		10,		10,		0,		2400,	TIMELIMIT},	//Outtake
{90,	Fwd,	0,		0,		80,		80,		0,		400,	TIMELIMIT},	//Outtake
//{0,	Fwd,	0,		0,		80,		80,		0,		80,		TIMELIMIT}, //Push sacks
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		380,	TIMELIMIT},	//back up
//{0,	Fwd,	MSPos,	0,		-50,	-50,	0,		-30,	BACKULSTR},	//back up
//             SCORE                   SCORE                      SCORE               SCORE
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-820,	RELTRNGYR},	//Gyro Spin to next stack
//{GLPos,0,		MSPos,	0,		Rev,	Rev,	0,		-50,	ENCODSTRA},	//back up
//{GLPos,Fwd,	MSPos,	0,		Rev,	Rev,	0,		-800,	TIMELIMIT},	//back up
//{GLPos,Fwd,	0,		0,		Fwd,	Fwd,	0,		200,	ENCODSTRA}, //Push sacks
//{GLPos,0,		0,		0,		0,		0,		0,		700,	TIMELIMIT},	//Wait for lift
{GLPos,	0,		0,		0,		0,		0,		0,		1000,	TIMELIMIT},


{GLPos,	0,		LSPos,	0,		110,	110,	0,		400,	ENCODSTRA},	//drive to first pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 1
{0,		-50,	LSPos,	0,		-100,	-100,	0,		-150,	ENCODSTRA},	//back up

{0,		0,		LSPos,	0,		110,	110,	0,		155,	ENCODSTRA},	//drive forward first pyramid 2
{0,		0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 2
{0,		0,		LSPos,	0,		-100,	-100,	0,		-100,	ENCODSTRA},	//scoop up bags

{0,		0,		LSPos,	0,		110,	110,	0,		740,	ENCODSTRA},	//drive forward yellow sack
{0,		-50,	Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up yellow
{0,		0,		LSPos,	0,		-95,	-100,	0,		550,	TIMELIMIT},	//hmm

{0,		0,		LSPos,	0,		110,	110,	0,		360,	ENCODSTRA},	//drive forward to second stack
{0,		0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyraid take 1
{0,		-50,	LSPos,	0,		-80,	-80,	0,		-200,	ENCODSTRA},	//back up

{0,		0,		LSPos,	0,		110,	110,	0,		180,	ENCODSTRA},	//drive to second pyramid
{0,		0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 2
{0,		-50,	LSPos,	0,		-80,	-80,	0,		-220,	ENCODSTRA},	//back up

{0,		0,		LSPos,	0,		110,	110,	0,		300,	ENCODSTRA},	//drive forward
{0,		0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop up pyramid take 3
{0,		0,		LSPos,	0,		-100,	-100,	0,		-60,	ENCODSTRA},	//back up to trough

{0,		0,		MSPos,	0,		0,		0,		0,		860,	RELTRNGYR},	//Gyro Spin
{GLPos,	-50,	LSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//back up
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		400,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	TIMELIMIT},	//scoop bags under trough
{TLPos,	0,		LSPos,	0,		-100,	-100,	0,		-200,	ENCODSTRA},	//flag ..... back up and raise lift
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2500,	TIMELIMIT},	//raise lift
{TLPos+50,50,	MSPos,	0,		100,	100,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	TIMELIMIT},	//Outtake
{Up,	Rev,	LSPos,	0,		100,	100,	0,		150,	TIMELIMIT},	//drive to trough
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA},	//back up from trough
//             SCORE                   SCORE                      SCORE               SCORE
{GLPos,		0,	MSPos,	0,		Fwd,	Rev,	0,		-200,	ENCODTURN},	//turn
{GLPos,		0,	MSPos,	0,		Rev,	Rev,	0,		-900,	ENCODSTRA},	//back up from trough
//{GLPos,	0,	MSPos,	0,		0,		0,	 	Left,	-1700,	ENCODSTRA},	//drive back to blue left start tile
{GLPos,		0,	MSPos,	0,		Rev,	Fwd,	0,		10,		ENCODTURN},	//turn
{GLPos,	0,		MSPos,	0,		Fwd,	Fwd,	0,		400,	TIMELIMIT},
{0,		0,		MSPos,	0,		70,		70,		0,		2000,	SCREENBTN},

//Robot is realigned on other starting tile

{GLPos,	0,		MSPos,	0,		0,		0,		0,		1300,	TIMELIMIT},	//Wait for Lift
{0,		0,		MSPos,	0,		0,		0,		0,		2700,	SCREENBTN},	//Wait for screen button

//Fourth Step
{-100,	0,		LSPos,	127,	0,		0,		0,		0200,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		0,		0,		80,		127,	0,		0720,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-150,	ENCODSTRA},	//drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		Right,	230,	LEFTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-150,	ENCODSTRA},	//drive backward
{GLPos,	0,		0,		0,		0,		0,		Right,	600,	LEFTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		750,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		100,	TIMELIMIT},	//drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		860,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//back up and raise lift
{ULPos,	0,		MSPos,	0,		0,		0,		0,		2500,	TIMELIMIT},	//raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	TIMELIMIT},	//Outtake
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	TIMELIMIT},	//back up
{TLPos,	-50,	0,		0,		Fwd,	Fwd,	0,		200,	TIMELIMIT},	//Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1400,	ENCODSTRA},	//back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	TIMELIMIT},	//strafe onto tile
*/
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};//Reset

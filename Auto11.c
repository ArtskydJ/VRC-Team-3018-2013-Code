const int auto11[][]={
  {0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},		//Reset
//{0,		Rev,	0,		0,		0,		0,		0,		1000,	TIMELIMIT},	//strafe right, lower spatula
//{0,		Fwd,	0,		0,		0,		0,		0,		1000,	TIMELIMIT},	//strafe right, lower spatula
//{0,		0,		0,		0,		0,		0,		Left,	250,	RIGTULGYR},	//strafe
//{0,		0,		0,		0,		0,		0,		0,		-900,	RELTRNGYR},	//square up gyro
//{0,		0,		0,		0,		50,		50,		0,		900,	WHITELINE},	//SQUARE UP LINE
//{0,		0,		0,		0,		0,		0,		0,		100,	TIMELIMIT}, //WAIT FOR SLEW
//{0,		0,		0,		0,		-32,	-32,	0,		600,	WHITELINE},	//SQUARE UP LINE
//{0,		0,		Down,	0,		0,		0,		0,		100,	TIMELIMIT}, //SPAT DOWN
//{0,		0,		0,		0,		0,		0,		1000,	850,	SQUAREUPG},	//square up gyro
//{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-450,	GYRSTRAFE},	//strafe
//{0,		0,		0,		0,		0,		0,		Left,	100,	RUSRSTRAF},		//drive forward
//{0,		0,		0,		0,		0,      0,		0,		0,		ABSTRNGYR},

//{0,			0,		0,		0,		-75,	75,		0,		2000,	FRONTLINE},	//Find line
//{0,			0,		0,		0,		40,		-40,	0,		200,	FRONTLINE},	//Go a bit farther
//THIS ONE WORKS:
//{0,			0,		0,		0,		75,		75,		LINE,	7000,	TIMELIMIT},	//FOLLOW LINE

//{0,			0,		0,		0,		-75,	75,		0,		2000,	FRONTLINE},	//Find line
//{0,			0,		0,		0,		40,		-40,	0,		200,	FRONTLINE},	//Go a bit farther
//{0,			0,		0,		0,		75,		75,		LINE,	7000,	TIMELIMIT},	//FOLLOW LINE

//{0,		0,		0,		0,		0,		0,		0,		-900,	RELTRNGYR},	//turn 90deg
//{0,		0,		0,		0,		75,		75,		0,		1000,	TIMELIMIT},	//Go straight

//{0,		0,		0,		0,		-45,	-45,	0,		3000,	WHITELINE},	//back into line
//{0,		0,		0,		0,		45,		45,		0,		335,	TIMELIMIT},	//back into line
//{0,		0,		0,		0,		0,		0,		0,		-900,	RELTRNGYR},	//turn 90deg
//{0,		0,		0,		0,		75,		75,		LINE,	7000,	TIMELIMIT},	//FOLLOW LINE

//{0,		0,		LSPos,	0,		75,		75,		LINE,	3000,	CROSSLINE},	//FOLLOW LINE until cross line
  {0,		0,		LSPos,	0,		50,		50,		0,		7000,	TIMELIMIT},
  {0,		0,		0,		0,		0,      0,		0,		0,		RESETAUTO}};	//Reset
//lift,		conv,	spat,	desc,	left,	right,	strafe,	target,	durationType

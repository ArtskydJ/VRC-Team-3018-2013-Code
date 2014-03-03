const int AutoDescore[][]={
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},
	{GLPos,	0,		0,		0,		Rev,	Rev,	0,		-300,	ENCODSTRA},		//Back up
	{GLPos,	0,		0,		Down,	0,		0,		0,		500,	TIMELIMIT},		//Lower descorer
	{GLPos,	0,		0,		-50,	Rev,	Rev,	0,		-400,	ENCODSTRA},		//Pull out bags
	{GLPos,	0,		0,		-50,	-75,	-75,	0,		-300,	ENCODSTRA},		//Pull out bags
	{GLPos,	0,		0,		Up,		Fwd,	Fwd,	0,		550,	ENCODSTRA},		//Drive back into the trough
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	


const int AutoPyramid[][]={
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},		//scoop up bags in pyramid part 1
	{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA},		//back up
	{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	ENCODSTRA},		//drive forward
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},		//scoop up bags in pyramid part 2
	{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},		//back up
	{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	ENCODSTRA},		//drive forward
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},		//scoop up bags in pyramid part 3
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};

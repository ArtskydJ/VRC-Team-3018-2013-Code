void UpdateScrollingText(string *ShowMessage, int INNumOfStrings)
{
	if (LastAutonomousRoutine != AutonomousRoutine) //If we change autonomous routines
	{
		ScrollStringIndex = 0;
		ScrollCharIndex = 0;
	}
	if(TimerLCDScroll >= NextMessageCharMS) //If it is time to scroll message
	{
		UpdateBatteryLevels();
		string TempString = "";
		string TempStringCat = "";
        TempString = (ShowMessage[ScrollStringIndex]);
        if (ScrollCharIndex > strlen(TempString))
        {
            ScrollCharIndex=1;
            ScrollStringIndex = ((ScrollStringIndex+1) % INNumOfStrings);
        }
        TempString = (ShowMessage[ScrollStringIndex]);	//Start the text
        StringDelete(TempString,0,ScrollCharIndex);		//Delete the beginning
		TempStringCat = (ShowMessage[((ScrollStringIndex+1) % INNumOfStrings)]);	//Get a string ready to be appended
        strcat(TempString, TempStringCat);				//Append
		TempStringCat = (ShowMessage[((ScrollStringIndex+2) % INNumOfStrings)]);	//Get a string ready to be appended
        strcat(TempString, TempStringCat);				//Append
        BottomLCDLine = TempString;
		ScrollCharIndex++; 		//Scroll the message
		TimerLCDScroll = 0;		//Reset Timer
	}
}


void ExecuteMenuActivated()
{
	bItemActivated = false;
	switch (MenuItem)
	{
		case 00: {IsRobotInVirtualAutonomousMode = true; bSimulatedRobotDisabled = false; bSimulatedAutonomousMode = false;} break;
		case 01: {MotorsAreEnabled = !MotorsAreEnabled;}	break; //Enable / Disable motors
		case 02: break; //View battery Levels
		case 03: {DriverMode = (DriverMode==DriverMotorTest)? DriverJoystickControl:DriverMotorTest;} break; //Run Motor Test/choose speed
		case 04: {TestMotorEnabled[PotPosition(10)+1] = (( TestMotorEnabled[PotPosition(10)]+2 )%3)-1;} break; //Toggle Motors between -1, 0 and 1
		case 05: break; //View Analog Value
		case 06: break; //View Digital Value
		case 07: {LeftLineFolTile  = SenLeftLine;}  break;
		case 08: {LeftLineFolLine  = SenLeftLine;}  break;
		case 09: {RightLineFolTile = SenRightLine;} break;
		case 10: {RightLineFolLine = SenRightLine;} break;
		default: break; //Execute nothing
	}
}


void ViewName()
{
	string TempString = MenuItemName[MenuItem];
	if (MenuItem==0)
	{
		string temp;
		StringFormat(temp,"%d",AutonomousRoutine);
		strcat(TempString, temp);
	}
	TopLCDLine = TempString;
}


void ViewValue()
{
	string TempString1="",TempString2="";
	bool ScrollingValue=false;
	switch (MenuItem) //BOTTOM LINE
	{
		case 00: {string temp[NmOfAutNmStrs];
					for (int j=0; j<NmOfAutNmStrs; j++) temp[j]=AutoName[AutonomousRoutine-1][j];
					UpdateScrollingText(temp,NmOfAutNmStrs); ScrollingValue=true;} break; //Scrolling Autonomous Name
		case 01: {TempString1 = (MotorsAreEnabled)?"Enabled":"Disabled";} break;
		case 02: {UpdateScrollingText(BatteryLevel,2); ScrollingValue=true;} break; //Scrolling Battery Levels
		case 03: {TempString1 = (DriverMode == DriverJoystickControl) ?"Off":"On";
					StringFormat(TempString2,"-Speed:%003d",StkMtrTest);} break;
		case 04: {int temp1=PotPosition(10)+1; int temp2=TestMotorEnabled[temp1];
					StringFormat(TempString1,"Motor %02d:", temp1);
					TempString2=(temp2==-1)?"Rev": (temp2==1)?"Fwd":"Off"; } break;// -1 Rev    1 Fwd    0 Off
		case 05: StringFormat(TempString1,  "in%1d:%0004d", PotPosition(8)+1, SensorValue[PotPosition(8)   ]); break; //View Analog Value
		case 06: StringFormat(TempString1,"dgt%02d:%00005d",PotPosition(12)+1,SensorValue[PotPosition(12)+8]); break; //View Digital Value
		case 07: StringFormat(TempString1,"%0004d-%0004d",LeftLineFolTile, SenLeftLine);  break;
		case 08: StringFormat(TempString1,"%0004d-%0004d",LeftLineFolLine, SenLeftLine);  break;
		case 09: StringFormat(TempString1,"%0004d-%0004d",RightLineFolTile,SenRightLine); break;
		case 10: StringFormat(TempString1,"%0004d-%0004d",RightLineFolLine,SenRightLine); break;
		default: break;
	}
	if (ScrollingValue==false)
	{
		DisplayPosition=Center;
		strcat(TempString1,TempString2);
		BottomLCDLine = TempString1;
	}
	else
	{
		if (MenuItem==0)	DisplayPosition=Left0; //No   "<" at the beginning
		else				DisplayPosition=Left1; //With "<" at the beginning
	}
}

void RefreshLCD(TDisplayMode DispMode)
{
	if (TopLCDLine != LastTopLCDLine)
	{
		clearLCDLine(0);
		displayLCDCenteredString(0,TopLCDLine);
	}
	if (BottomLCDLine != LastBottomLCDLine)
	{
		clearLCDLine(1);
		if (DispMode==DispAutonomousMode)
			displayLCDCenteredString(1,BottomLCDLine);
		else
		{
			if      (DisplayPosition==Left0)	displayLCDString(1,0,BottomLCDLine);
			else if (DisplayPosition==Left1)	displayLCDString(1,1,BottomLCDLine);
			else if (DisplayPosition==Center)	displayLCDCenteredString(1,BottomLCDLine);
			if (MenuItem>0)					displayLCDString(1,0, "<");
			if (MenuItem<NumOfMenuItems-1)	displayLCDString(1,15,">");
		}
	}
	LastTopLCDLine = TopLCDLine;
	LastBottomLCDLine = BottomLCDLine;
}


void UpdateScreen(TDisplayMode DispMode)
{
	if(DispMode == DispDisabledMode || DispMode == DispDriverMode) //Show current routine and its name OR the menu
	{
		if (LastBtnScreenLeft  == 0 && BtnScreenLeft)  MenuItem--;
		if (LastBtnScreenRight == 0 && BtnScreenRight) MenuItem++;
		CapValue(0, MenuItem, NumOfMenuItems-1);
		if (LastBtnScreenCenter == 0 && BtnScreenCenter) bItemActivated = !bItemActivated; //Press
		if (bItemActivated)
			ExecuteMenuActivated();
		ViewName();  //TOP LINE
		ViewValue(); //BOTTOM LINE
		if (LastMenuItem != MenuItem)
		{
			ScrollStringIndex = 0;
			ScrollCharIndex = 0;
		}
		LastMenuItem = MenuItem;
	}
	else if(DispMode == DispAutonomousMode)
	{
		StringFormat(TopLCDLine, "Time:%.1f Rout:%d", ((float)TimerAutonomous/1000), AutonomousRoutine);
		StringFormat(BottomLCDLine, "Step: %d", AutonomousStep);	//Show step
	}
	RefreshLCD(DispMode);
	LastAutonomousRoutine = AutonomousRoutine;
}

#include "globals.h"
#include "menu.h"
#include "square.h"

#define LI 15 //left Indent
#define SBL 10 //space between lines
#define MENU_MAX 4

byte menu(){
  
  static byte menuCursor=1;
  Square curSquare(2,SBL*menuCursor+1,TYPE_SIMPLE);
  
  ab.setCursor(LI,SBL*1);
  ab.print("Play");
  ab.setCursor(LI,SBL*2);
  ab.println("Settings");
  ab.setCursor(LI,SBL*3);
  ab.println("Info");
  ab.setCursor(LI,SBL*4);
  ab.println("Credit"); 

  curSquare.draw();

  if (ab.justPressed(UP_BUTTON)){
    if (menuCursor>1)
      menuCursor--;
    else menuCursor=MENU_MAX;
  }
  if (ab.justPressed(DOWN_BUTTON)){
    if (menuCursor<MENU_MAX)
      menuCursor++;
    else menuCursor=1;
  }  

  if (ab.justPressed(A_BUTTON)){
    //if (1==cursor)
    return menuCursor;  
  }
  
  return 0;
}

byte settings(){
  
  static byte settingsCursor=1;
  Square curSquare(2,SBL*settingsCursor+1,TYPE_SLASH);

  ab.setCursor(LI,SBL*1);
  ab.print("'Gift'    ");
  if (globalSettings&1)
    ab.print("Enabled");
  else
    ab.print("Disabled");
      
  ab.setCursor(LI,SBL*2);
  ab.print("Grid for P1   ");
  if (globalSettings&4)
    ab.print("On");
  else
    ab.print("Off");
    
  ab.setCursor(LI,SBL*3);
  ab.print("Grid for P2   ");
  if (globalSettings&2)
    ab.print("On");
  else
    ab.print("Off");
  
  ab.setCursor(LI,SBL*4);
  ab.print("P1 Speed      ");
  ab.print(21-fallingTimerInitP1);

  ab.setCursor(LI,SBL*5);
  ab.print("P2 Speed      ");
  ab.print(21-fallingTimerInitP2);  

  curSquare.draw();

  if (ab.justPressed(UP_BUTTON)){
    if (settingsCursor>1)
      settingsCursor--;
    else settingsCursor=MENU_MAX+1;
  }
  if (ab.justPressed(DOWN_BUTTON)){
    if (settingsCursor<MENU_MAX+1)
      settingsCursor++;
    else settingsCursor=1;
  }

  if (ab.justPressed(LEFT_BUTTON)){   
    if (4==settingsCursor){
        if (fallingTimerInitP1<20)
          fallingTimerInitP1++;
        else
          fallingTimerInitP1=5; //max speed
    }
    else if (5==settingsCursor){
        if (fallingTimerInitP2<20)
          fallingTimerInitP2++;
        else
          fallingTimerInitP2=5; //max speed
    }
  }
  if (ab.justPressed(A_BUTTON)||ab.justPressed(RIGHT_BUTTON)){
    switch (settingsCursor){
      case 1:
        if (globalSettings&1)
          globalSettings--;
        else
          globalSettings++;
      break;     
      case 3:
        if (globalSettings&2)
          globalSettings&=253;
        else
          globalSettings|=2;
      break;
      case 2:
        if (globalSettings&4)
          globalSettings&=251;
        else
          globalSettings|=4;
      break; 
      case 4:
        if (fallingTimerInitP1>5)
          fallingTimerInitP1--;
        else
          fallingTimerInitP1=fallingTimerP1; //default=20
      break;
      case 5:
        if (fallingTimerInitP2>5)
          fallingTimerInitP2--;
        else
          fallingTimerInitP2=fallingTimerP1; //default=20
      break;      
      default:
      break;
    }
  }  

  if (ab.justPressed(B_BUTTON)){
    return MENU_BACK;     
  }  
  return 0;
}

byte info(){
  ab.println("Move until you reach");
  ab.println("a border to change");
  ab.println("moving direction");
  //ab.println("It turn clockwise only");
  ab.println("Hold 'turn' to drop");
  ab.println("");
  ab.println("P1 Turn:Up P1 Move:Down");
  ab.println("P2 Turn:A  P2 Move:B");
  ab.print("Pause: Left");
  //ab.drawChar(30,40,23,1,1,0);
  //ab.drawChar(60,40,24,1,1,0);
  
  if (ab.justPressed(B_BUTTON)){
    return MENU_BACK;     
  }
  return 0;
}

byte credit(){
  ab.println("       TWOTRIS");
  ab.println("");
  ab.println("written by");
  ab.println("    Cedric Martin");
  ab.println("");
  ab.println("March 2020");
  
  if (ab.justPressed(B_BUTTON)){
    return MENU_BACK;     
  }
  return 0; 
}

/*
  ab.println("'Gift' enabled");
  ab.println("speed  ");*/


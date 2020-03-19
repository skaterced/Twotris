#include "globals.h"
//#include "square.h"

Arduboy2 ab;
int timer=0;

int fallingTimerP1=20;
int fallingTimerP2=20;
int fallingTimerInitP1=20;
int fallingTimerInitP2=20;

int buttonTimerTurnP1=0;
int buttonTimerTurnP2=0;
int buttonTimerMoveP1=0;
int buttonTimerMoveP2=0;

bool p1GoesToTheRight=true;
bool p2GoesToTheRight=false;

int blinkingLinesP1=0;
int blinkingLinesP2=0;
int BlinkingP1=0;
int BlinkingP2=0;
int scoreP1=0;
int scoreP2=0;
//bool occupiedGridP1[160];
//bool occupiedGridP2[160];
int NbStillSquaresP1=0;
int NbStillSquaresP2=0;

// Settings TODO when several, put them on a byte and mask the one you want
bool GIFT=true;

//Initialised in order to make a nice Title
class Square stillSquaresP1 [MAXS]={Square(TR1+4*SW,TL1,TYPE_EMPTY),Square(TR1+5*SW,TL1,TYPE_EMPTY),Square(TR1+9*SW,TL1,TYPE_4),Square(TR1+10*SW,TL1,TYPE_4),Square(TR1+15*SW,TL1,TYPE_DOTS),Square(TR1+16*SW,TL1,TYPE_DOTS),Square(TR1+14*SW,TL1,TYPE_DOTS),
                                    Square(TR1+22*SW,TL1,TYPE_SLASH),Square(TR1+26*SW,TL1,TYPE_SLASH),Square(TR1+28*SW,TL1,TYPE_STONE),Square(TR1+29*SW,TL1,TYPE_STONE),Square(TR1+30*SW,TL1,TYPE_STONE),
                                    
                                    Square(TR1+4*SW,TL2,TYPE_EMPTY),Square(TR1+5*SW,TL2,TYPE_EMPTY),Square(TR1+8*SW,TL2,TYPE_4),Square(TR1+9*SW,TL2,TYPE_4),Square(TR1+10*SW,TL2,TYPE_4),Square(TR1+11*SW,TL2,TYPE_4),Square(TR1+13*SW,TL2,TYPE_DOTS),
                                    Square(TR1+17*SW,TL2,TYPE_DOTS),Square(TR1+22*SW,TL2,TYPE_SLASH),Square(TR1+26*SW,TL2,TYPE_SLASH),Square(TR1+31*SW,TL2,TYPE_STONE),

                                    Square(TR1+4*SW,TL3,TYPE_EMPTY),Square(TR1+5*SW,TL3,TYPE_EMPTY),Square(TR1+7*SW,TL3,TYPE_4),Square(TR1+9*SW,TL3,TYPE_4),Square(TR1+11*SW,TL3,TYPE_4),Square(TR1+13*SW,TL3,TYPE_DOTS),
                                    Square(TR1+17*SW,TL3,TYPE_DOTS),Square(TR1+20*SW,TL3,TYPE_EMPTY),Square(TR1+22*SW,TL3,TYPE_SLASH),Square(TR1+26*SW,TL3,TYPE_SLASH),Square(TR1+29*SW,TL3,TYPE_STONE),Square(TR1+30*SW,TL3,TYPE_STONE),

                                    Square(TR1+4*SW,TL4,TYPE_EMPTY),Square(TR1+5*SW,TL4,TYPE_EMPTY),Square(TR1+7*SW,TL4,TYPE_4),Square(TR1+9*SW,TL4,TYPE_4),Square(TR1+11*SW,TL4,TYPE_4),Square(TR1+13*SW,TL4,TYPE_DOTS),
                                    Square(TR1+17*SW,TL4,TYPE_DOTS),Square(TR1+20*SW,TL4,TYPE_EMPTY),Square(TR1+22*SW,TL4,TYPE_SLASH),Square(TR1+23*SW,TL4,TYPE_SLASH),Square(TR1+26*SW,TL4,TYPE_SLASH),Square(TR1+28*SW,TL4,TYPE_STONE),
                                    
                                    Square(TR1+4*SW,TL5,TYPE_EMPTY),Square(TR1+5*SW,TL5,TYPE_EMPTY),Square(TR1+7*SW,TL5,TYPE_4),Square(TR1+11*SW,TL5,TYPE_4),Square(TR1+13*SW,TL5,TYPE_DOTS),
                                    Square(TR1+17*SW,TL5,TYPE_DOTS),Square(TR1+20*SW,TL5,TYPE_EMPTY),Square(TR1+22*SW,TL5,TYPE_SLASH),Square(TR1+24*SW,TL5,TYPE_SLASH),Square(TR1+26*SW,TL5,TYPE_SLASH),Square(TR1+29*SW,TL5,TYPE_STONE),Square(TR1+30*SW,TL5,TYPE_STONE),
                                    Square(TR1+31*SW,TL5,TYPE_STONE),/*Square(TR1+32*SW,TL5,TYPE_STONE), /* ?? why is 31 not displayed?? */
                                    
                                    Square(TR1+4*SW,TL6,TYPE_EMPTY),Square(TR1+5*SW,TL6,TYPE_EMPTY),Square(TR1+15*SW,TL6,TYPE_DOTS),Square(TR1+16*SW,TL6,TYPE_DOTS),Square(TR1+14*SW,TL6,TYPE_DOTS),
                                    Square(TR1+20*SW,TL6,TYPE_EMPTY),

                                    Square(TR1+1*SW,TL7,TYPE_EMPTY),Square(TR1+2*SW,TL7,TYPE_EMPTY),Square(TR1+3*SW,TL7,TYPE_EMPTY),Square(TR1+4*SW,TL7,TYPE_EMPTY),Square(TR1+5*SW,TL7,TYPE_EMPTY),Square(TR1+6*SW,TL7,TYPE_EMPTY),Square(TR1+7*SW,TL7,TYPE_EMPTY),Square(TR1+8*SW,TL7,TYPE_EMPTY),
                                    Square(TR1+20*SW,TL7,TYPE_EMPTY),Square(TR1+26*SW,TL7,TYPE_SLASH),
                                    Square(TR1+18*SW,TL7,TYPE_EMPTY),Square(TR1+19*SW,TL7,TYPE_EMPTY),Square(TR1+20*SW,TL7,TYPE_EMPTY),Square(TR1+21*SW,TL7,TYPE_EMPTY),Square(TR1+22*SW,TL7,TYPE_EMPTY),

                                    Square(TR1+1*SW,TL8,TYPE_EMPTY),Square(TR1+2*SW,TL8,TYPE_EMPTY),Square(TR1+3*SW,TL8,TYPE_EMPTY),Square(TR1+4*SW,TL8,TYPE_EMPTY),Square(TR1+5*SW,TL8,TYPE_EMPTY),Square(TR1+6*SW,TL8,TYPE_EMPTY),Square(TR1+7*SW,TL8,TYPE_EMPTY),Square(TR1+8*SW,TL8,TYPE_EMPTY)
                                    

                                    };
class Square stillSquaresP2 [MAXS];
//class Square toto;

//#define 


#include "globals.h"
#include "square.h"
#include "title.h"

void affTitle(byte lines){

class Square titleSquares [90]={Square(TR1+4*SW,TL1,TYPE_SIMPLE),Square(TR1+5*SW,TL1,TYPE_SIMPLE),Square(TR1+9*SW,TL1,TYPE_4),Square(TR1+10*SW,TL1,TYPE_4),Square(TR1+15*SW,TL1,TYPE_DOTS),Square(TR1+16*SW,TL1,TYPE_DOTS),Square(TR1+14*SW,TL1,TYPE_DOTS),
                                    Square(TR1+22*SW,TL1,TYPE_SLASH),Square(TR1+26*SW,TL1,TYPE_SLASH),Square(TR1+28*SW,TL1,TYPE_STONE),Square(TR1+29*SW,TL1,TYPE_STONE),Square(TR1+30*SW,TL1,TYPE_STONE),
                                    
                                    Square(TR1+4*SW,TL2,TYPE_SIMPLE),Square(TR1+5*SW,TL2,TYPE_SIMPLE),Square(TR1+8*SW,TL2,TYPE_4),Square(TR1+9*SW,TL2,TYPE_4),Square(TR1+10*SW,TL2,TYPE_4),Square(TR1+11*SW,TL2,TYPE_4),Square(TR1+13*SW,TL2,TYPE_DOTS),
                                    Square(TR1+17*SW,TL2,TYPE_DOTS),Square(TR1+22*SW,TL2,TYPE_SLASH),Square(TR1+26*SW,TL2,TYPE_SLASH),Square(TR1+31*SW,TL2,TYPE_STONE),

                                    Square(TR1+4*SW,TL3,TYPE_SIMPLE),Square(TR1+5*SW,TL3,TYPE_SIMPLE),Square(TR1+7*SW,TL3,TYPE_4),Square(TR1+9*SW,TL3,TYPE_4),Square(TR1+11*SW,TL3,TYPE_4),Square(TR1+13*SW,TL3,TYPE_DOTS),
                                    Square(TR1+17*SW,TL3,TYPE_DOTS),Square(TR1+20*SW,TL3,TYPE_SIMPLE),Square(TR1+22*SW,TL3,TYPE_SLASH),Square(TR1+26*SW,TL3,TYPE_SLASH),Square(TR1+29*SW,TL3,TYPE_STONE),Square(TR1+30*SW,TL3,TYPE_STONE),

                                    Square(TR1+4*SW,TL4,TYPE_SIMPLE),Square(TR1+5*SW,TL4,TYPE_SIMPLE),Square(TR1+7*SW,TL4,TYPE_4),Square(TR1+9*SW,TL4,TYPE_4),Square(TR1+11*SW,TL4,TYPE_4),Square(TR1+13*SW,TL4,TYPE_DOTS),
                                    Square(TR1+17*SW,TL4,TYPE_DOTS),Square(TR1+20*SW,TL4,TYPE_SIMPLE),Square(TR1+22*SW,TL4,TYPE_SLASH),Square(TR1+23*SW,TL4,TYPE_SLASH),Square(TR1+26*SW,TL4,TYPE_SLASH),Square(TR1+28*SW,TL4,TYPE_STONE),
                                    
                                    Square(TR1+4*SW,TL5,TYPE_SIMPLE),Square(TR1+5*SW,TL5,TYPE_SIMPLE),Square(TR1+7*SW,TL5,TYPE_4),Square(TR1+11*SW,TL5,TYPE_4),Square(TR1+13*SW,TL5,TYPE_DOTS),
                                    Square(TR1+17*SW,TL5,TYPE_DOTS),Square(TR1+20*SW,TL5,TYPE_SIMPLE),Square(TR1+22*SW,TL5,TYPE_SLASH),Square(TR1+24*SW,TL5,TYPE_SLASH),Square(TR1+26*SW,TL5,TYPE_SLASH),Square(TR1+29*SW,TL5,TYPE_STONE),Square(TR1+30*SW,TL5,TYPE_STONE),
                                    Square(TR1+31*SW,TL5,TYPE_STONE),//Square(TR1+32*SW,TL5,TYPE_STONE), 
                                    
                                    Square(TR1+4*SW,TL6,TYPE_SIMPLE),Square(TR1+5*SW,TL6,TYPE_SIMPLE),Square(TR1+15*SW,TL6,TYPE_DOTS),Square(TR1+16*SW,TL6,TYPE_DOTS),Square(TR1+14*SW,TL6,TYPE_DOTS),
                                    Square(TR1+20*SW,TL6,TYPE_SIMPLE),

                                    Square(TR1+1*SW,TL7,TYPE_SIMPLE),Square(TR1+2*SW,TL7,TYPE_SIMPLE),Square(TR1+3*SW,TL7,TYPE_SIMPLE),Square(TR1+4*SW,TL7,TYPE_SIMPLE),Square(TR1+5*SW,TL7,TYPE_SIMPLE),Square(TR1+6*SW,TL7,TYPE_SIMPLE),Square(TR1+7*SW,TL7,TYPE_SIMPLE),Square(TR1+8*SW,TL7,TYPE_SIMPLE),
                                    Square(TR1+20*SW,TL7,TYPE_SIMPLE),Square(TR1+26*SW,TL7,TYPE_SLASH),
                                    Square(TR1+18*SW,TL7,TYPE_SIMPLE),Square(TR1+19*SW,TL7,TYPE_SIMPLE),Square(TR1+20*SW,TL7,TYPE_SIMPLE),Square(TR1+21*SW,TL7,TYPE_SIMPLE),Square(TR1+22*SW,TL7,TYPE_SIMPLE),

                                    Square(TR1+1*SW,TL8,TYPE_SIMPLE),Square(TR1+2*SW,TL8,TYPE_SIMPLE),Square(TR1+3*SW,TL8,TYPE_SIMPLE),Square(TR1+4*SW,TL8,TYPE_SIMPLE),Square(TR1+5*SW,TL8,TYPE_SIMPLE),Square(TR1+6*SW,TL8,TYPE_SIMPLE),Square(TR1+7*SW,TL8,TYPE_SIMPLE),Square(TR1+8*SW,TL8,TYPE_SIMPLE)
};

  
  int titleIterator=89;
  switch (lines){
    case 0: 
      titleIterator=0; //nb of squares in the bottom line
    break;    

    case 1:
      titleIterator=12; //nb of squares in the bottom line
    break;    

    case 2:
      titleIterator=23; //nb of squares in the second line
    break;    
    
    case 3:
      titleIterator=35; //etc...
    break;    

    case 4:
      titleIterator=47; //etc...
    break;    

    case 5:
      titleIterator=60; //etc...
    break;    

    case 6:
      titleIterator=66;
    break;    

    case 7:
      titleIterator=81;
    break;    

    case 8:
      titleIterator=89;
    break;
    
    case 9: case 10: case 11:
      ab.setCursor(30,TL1+8);
      ab.print(F("two Buttons"));
    break;
    case  12: case 13: case 14:
      ab.setCursor(30,TL1+8);
      ab.print(F("two Buttons"));
      ab.setCursor(30,TL1+17);
      ab.print(F("two Players"));
    break;
    case  15: case 16: case 17: case 18: case 19: case 20:
      ab.setCursor(30,TL1+8);
      ab.print(F("two Buttons"));
      ab.setCursor(30,TL1+17);
      ab.print(F("two Players"));
      ab.setCursor(25,TL1+26);
      ab.print(F("too much fun !"));
    break;
    case  22: case 23: case 24: case  25: case 26: case 27: case 28: 
      ab.setCursor(30,TL1+11);
      ab.print(F("written by"));
      ab.setCursor(19,TL1+23);
      ab.print(F("Cedric Martin"));
      ab.drawLine(28,TL1+23,29,TL1+22,1); //"é"
    break;
    case  30: case 31: case 32: case  33: case 34: case 35: case 36: 
      ab.setCursor(39,TL1+11);
      ab.print(F("Music by"));
      ab.setCursor(32,TL1+23);
      ab.print(F("Silent Bob"));      
    break;    
    case  38: case 39: case 40: case  41: case 42: case 43: case 44: 
      ab.setCursor(5,TL1+11);
      ab.print(F("Original Tetris by"));
      ab.setCursor(12,TL1+23);
      ab.print(F("Aleksei Pajitnov"));
      ab.drawPixel(48,TL1+23); //"ï"
    break;
    case 47:
      timer=0;
    break;
    default:
    break;
  }
  
  for (int i=0; i<titleIterator; i++){
    titleSquares[i].draw();
  }
}


#include "globals.h"
#include "title.h"

void affTitle(byte lines){
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
      ab.print("two Buttons");
    break;
    case  12: case 13: case 14:
      ab.setCursor(30,TL1+8);
      ab.print("two Buttons");
      ab.setCursor(30,TL1+17);
      ab.print("two Players");
    break;
    case  15: case 16: case 17: case 18: case 19: case 20:
      ab.setCursor(30,TL1+8);
      ab.print("two Buttons");
      ab.setCursor(30,TL1+17);
      ab.print("two Players");
      ab.setCursor(25,TL1+26);
      ab.print("too much fun !");
    break;
    case  22: case 23: case 24: case  25: case 26: case 27: case 28: 
      ab.setCursor(30,TL1+11);
      ab.print("written by");
      ab.setCursor(19,TL1+23);
      ab.print("Cedric Martin");
      ab.drawLine(28,TL1+23,29,TL1+22,1); //"é"
    break;
    case  30: case 31: case 32: case  33: case 34: case 35: case 36: 
      ab.setCursor(39,TL1+11);
      ab.print("Music by");
      ab.setCursor(32,TL1+23);
      ab.print("Silent Bob");      
    break;    
    case  38: case 39: case 40: case  41: case 42: case 43: case 44: 
      ab.setCursor(5,TL1+11);
      ab.print("Original Tetris by");
      ab.setCursor(12,TL1+23);
      ab.print("Aleksei Pajitnov");
      ab.drawPixel(48,TL1+23); //"ï"
    break;
    case 47:
      timer=0;
    break;
    default:
    break;
  }
  
  for (int i=0; i<titleIterator; i++){
    stillSquaresP1[i].draw();
  }
}

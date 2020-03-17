
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
    case  15: default: 
      ab.setCursor(30,TL1+8);
      ab.print("two Buttons");
      ab.setCursor(30,TL1+17);
      ab.print("two Players");
      ab.setCursor(25,TL1+26);
      ab.print("too much fun !");
    break;

  }
  
  
  
  for (int i=0; i<titleIterator; i++){
    stillSquaresP1[i].draw();
  }
}

// the part of the pieces

#include "globals.h"
#include "square.h"
#include "background.h"
#include "game.h"
//#include "Tinyfont.h"
//Tinyfont tinyfont = Tinyfont(ab.sBuffer, Arduboy2::width(), Arduboy2::height());

void drawBackground(){
  ab.fillRect(0,0,128,66,1);
  ab.fillRect(LB,0,10*SW,63,0);
  ab.fillRect(LB+6+9*SW,0,10*SW,63,0);
  
  //score
  affScore(true);
  affScore(false);
  
  //tinyfont.print("bonjour102");
  //arrows
  ab.drawChar(4,30,p1GoesToTheRight? 26:27,1,0,1);
  ab.drawChar(118,30,p2GoesToTheRight? 26:27,1,0,1);
  
  //next
  ab.fillRect(3,4,4*SW,5*SW,0);
  ab.fillRect(109,4,4*SW,5*SW,0);

  /*
  //debug
  int temp=0;
  for (int i=0; i<160;i++){
    if (occupiedGridP1[i])
      temp++;
  }
    ab.setCursor(75,30);
    ab.print(temp);
*/
  //
  drawStillSquares();
}

void affScore(bool P1){
  if (P1){    
    if (scoreP1>=1000){
      ab.setCursor(3,44);
      ab.print(scoreP1/1000);      
      ab.setCursor(9,44);
      ab.print("K+");

      ab.setCursor(3,52);
      zeroPrint(scoreP1-1000);
    }
    else {
      ab.setCursor(3,52);
      zeroPrint(scoreP1);
    }    
  }
  else {
    if (scoreP2>=1000){
      ab.setCursor(107,44);
      ab.print(scoreP2/1000);      
      ab.setCursor(113,44);
      ab.print("K+");

      ab.setCursor(107,52);
      zeroPrint(scoreP2-1000);
    }    
    else {
      ab.setCursor(107,52);
      zeroPrint(scoreP2);
    }
  }
}

void zeroPrint(int score){
  if (score<10){
    ab.print("00");    
  }
  else if (score <100){
    ab.print("0");  
  }
  ab.print (score);
}

void drawStillSquares(){
  for(int i=0;i<NbStillSquaresP1;i++){
    stillSquaresP1[i].draw();
  }
  for(int i=0;i<NbStillSquaresP2;i++){
    stillSquaresP2[i].draw();
  }  
}

void checkFullLines(byte minY, byte maxY, bool p1){ //let's start again
  int nbSameY[4]={0,0,0,0};
  if (p1&&blinkingLinesP1!=0){ //this should not happend
    ab.clear();
    ab.print("Error Blinking=");
    ab.print(blinkingLinesP1);
    ab.display();
    delay(3000);
  }
  for(int j=0; j<(maxY-minY)/SW+1; j++){
    for(int i=0;i<NbStillSquaresP1;i++){
      if (stillSquaresP1[i].y==minY+j*SW) {
        nbSameY[j]++;
      }
    }
    if (10==nbSameY[j]){
      blinkingLinesP1+=1<<(14-((minY-3)/SW+j));  // less significant bit is bottom line
      BlinkingP1=10;
    }
  }
  
  if (0==blinkingLinesP1)
    blinkingLinesP1=-1;
  // Add test for P2
}
/*
void checkFullLines(byte minY, byte maxY, bool p1){ // BUG ! Full Lines are not necessary adjacent

  int nbSameY[4]={0,0,0,0};
  int minYtoRemove=66;
  byte widthOfRemoval=0;
  
  if (p1){
    for(int j=0; j<(maxY-minY)/SW+1; j++){
      for(int i=0;i<NbStillSquaresP1;i++){
    //stillSquaresP1[i].draw();
        if (stillSquaresP1[i].y==minY+j*SW) {
          nbSameY[j]++;
        }
      }
      if (10==nbSameY[j]){
        if (minYtoRemove>minY+j*SW){
          minYtoRemove=minY+j*SW;
        }
        widthOfRemoval++;
      }
    }
    
    if (66!=minYtoRemove){
      blinkingLinesP1=(minYtoRemove<<3)+widthOfRemoval;
      BlinkingP1=10;
      scoreP1+=widthOfRemoval*3;
    }
    else
      blinkingLinesP1=-1;
  }
  else { //same for p2
    for(int j=0; j<(maxY-minY)/SW+1; j++){
      for(int i=0;i<NbStillSquaresP2;i++){
    //stillSquaresP1[i].draw();
        if (stillSquaresP2[i].y==minY+j*SW) {
          nbSameY[j]++;
        }
      }
      if (10==nbSameY[j]){
        if (minYtoRemove>minY+j*SW){
          minYtoRemove=minY+j*SW;
        }
        widthOfRemoval++;
      }
    }
    
    if (66!=minYtoRemove){
      blinkingLinesP2=(minYtoRemove<<3)+widthOfRemoval;
      BlinkingP2=10;
      scoreP2+=widthOfRemoval*3;
    }
    else
      blinkingLinesP2=-1;    
  }
}
*/
void removeBlinkingLines(bool p1){

  if (p1){
    int temp=blinkingLinesP1&511;
    //ab.fillRect(LB,3+i*SW,10*SW,SW,1);
    for (int k=0; k<15; k++){
      if (1==temp&1){
        for(int i=0; i<NbStillSquaresP1; i++){
          while((59-k*SW)==stillSquaresP1[i].y){
            if (i==NbStillSquaresP1-1){
              stillSquaresP1[i].y=0;
              stillSquaresP1[i].type=0;
            }
            for (int j=i;j<NbStillSquaresP1-1;j++){
              stillSquaresP1[j]=stillSquaresP1[j+1];
            }
            NbStillSquaresP1--;
          }
        if (stillSquaresP2[i].y<59-k*SW){
          stillSquaresP2[i].y+=SW;
      }
        }
        temp=temp>>1;
      }
    }
  } 
  else {/*same for p2**/
    int width=blinkingLinesP2&7;
    int minY=blinkingLinesP2>>3;
    /*
    int temp=getIndice(LB+6+9*SW,minY,false);
    for (int i=temp+width*10;i>=0;i--){      
      if ((i-width*10)>=0){
        occupiedGridP2[i]=occupiedGridP2[i-width*10];  
      }
      else
        occupiedGridP1[i]=false;  
    }*/
      for(int i=0; i<NbStillSquaresP2; i++){
      while((minY<=stillSquaresP2[i].y)&&(stillSquaresP2[i].y<=(minY+(width-1)*SW))){
        for (int j=i;j<NbStillSquaresP2;j++){
          stillSquaresP2[j]=stillSquaresP2[j+1];
        }
      }
      //warning, could be moved twice ?
      if (stillSquaresP2[i].y<minY){
        stillSquaresP2[i].y+=width*SW;
      }
    }
    NbStillSquaresP2-=width*10;
  }
}

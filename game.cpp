
#include "globals.h"
#include "background.h"
#include "square.h"
#include "game.h"

#define MOVE_BUTTON_TRIGGER 3
#define TURN_BUTTON_TRIGGER 5
//p1GoesToTheRight=true;
//p2GoesToTheRight=false;
//prout=true;

void control(Piece* P){
  if (ab.justPressed(LEFT_BUTTON)){
    ab.setCursor(40,30);
    ab.print("* pause *");
    ab.display();
    delay(100);
    while(!ab.pressed(LEFT_BUTTON));
  }
  if (P->p1){
    if (ab.pressed(P1_TURN)){
      if (++buttonTimerTurnP1>TURN_BUTTON_TRIGGER){
        buttonTimerTurnP1=-3;
        while (P->move(MOVE_DOWN));
        P->stick();
        return;
      }
    }
    if (ab.pressed(P1_MOVE)){
      //if (buttonTimerMoveP1>=MOVE_BUTTON_TRIGGER){
      if ((0==buttonTimerMoveP1)||(buttonTimerMoveP1>=MOVE_BUTTON_TRIGGER)){
        if (p1GoesToTheRight){
          if (!P->move(MOVE_RIGHT)){
            p1GoesToTheRight=false;
          }
        }
        else{
          if (!P->move(MOVE_LEFT)){
            p1GoesToTheRight=true;
          }      
        }
      }
      buttonTimerMoveP1++;
    }
    if (ab.justReleased(P1_MOVE)){
      buttonTimerMoveP1=0;
    }
    if (ab.justReleased(P1_TURN)){
      buttonTimerTurnP1=0;
      P->turn();
    }
  } 
  else {// do the same for p2...
    if (ab.pressed(P2_TURN)){
      if (++buttonTimerTurnP2>TURN_BUTTON_TRIGGER){
        buttonTimerTurnP2=-3;
        while (P->move(MOVE_DOWN));
        P->stick();
        return;
      }
    }
    if (ab.pressed(P2_MOVE)){
      //if (buttonTimerMoveP1>=MOVE_BUTTON_TRIGGER){
      if ((0==buttonTimerMoveP2)||(buttonTimerMoveP2>=MOVE_BUTTON_TRIGGER)){
        if (p2GoesToTheRight){
          if (!P->move(MOVE_RIGHT)){
            p2GoesToTheRight=false;
          }
        }
        else{
          if (!P->move(MOVE_LEFT)){
            p2GoesToTheRight=true;
          }      
        }
      }
      buttonTimerMoveP2++;
    }
    if (ab.justReleased(P2_MOVE)){
      buttonTimerMoveP2=0;
    }
    if (ab.justReleased(P2_TURN)){
      buttonTimerTurnP2=0;
      P->turn();
    }  
  }
}

void playing(Piece* p1, Piece* p2, Piece* nextP1, Piece* nextP2){

  drawBackground();
  
  if (0!=blinkingLinesP1){
    
    if (-1==blinkingLinesP1){ // new Piece
      blinkingLinesP1=0;
      p1->reInit(nextP1->shape);
      p1->orientation=0;
      p1->update();
      if (p1->checkCollision()){ //game over
        //ab.display();
        blinkingLinesP1=-2;
        for (int i=0; i<4;i++){
          ab.clear();
          ab.print("x:");
          ab.print(p1->body[i].x);
          ab.print(" y:");
          ab.println(p1->body[i].y);          
        }
        ab.display();
        delay(500);
      }
      //p1.shape=nextP1.shape;
      for (int i=0; i<4; i++){
        p1->body[i].type=nextP1->body[i].type;
      }
      nextP1->shapeShift();
      nextP1->update();
    }
    else if (blinkingLinesP1>0){

      if (0==BlinkingTimerP1--){
        removeBlinkingLines(true);
        blinkingLinesP1=-1;
      }
    }
  }
  else {
      //if (ab.everyXFrames(fallingTimeP1)){
    if (0==fallingTimerP1--){
      fallingTimerP1=fallingTimerInitP1;
      if (!p1->move(MOVE_DOWN)){
        p1->stick();
        randomSeed(timer*321);
      }
    }
  }
  
  if (0!=blinkingLinesP2){
    
    if (-1==blinkingLinesP2){ // new Piece
      blinkingLinesP2=0;
      p2->reInit(nextP2->shape);
      p2->orientation=0;
      p2->update();
      if (p2->checkCollision()){ //game over
        //ab.display();
        blinkingLinesP2=-2;
        for (int i=0; i<4;i++){
          ab.clear();
          ab.print("x:");
          ab.print(p2->body[i].x);
          ab.print(" y:");
          ab.println(p2->body[i].y);          
        }
        ab.display();
        delay(500);
      }
      //p1.shape=nextP1.shape;
      for (int i=0; i<4; i++){
        p2->body[i].type=nextP2->body[i].type;
      }
      nextP2->shapeShift();
      nextP2->update();
    }
    else if (blinkingLinesP2>0){

      if (0==BlinkingTimerP2--){
        removeBlinkingLines(false);
        blinkingLinesP2=-1;
      }
    }
  }
  else {
      //if (ab.everyXFrames(fallingTimeP1)){
    if (0==fallingTimerP2--){
      fallingTimerP2=fallingTimerInitP2;
      if (!p2->move(MOVE_DOWN)){
        p2->stick();
        randomSeed(timer*321);
      }
    }
  }  
}
    /*
    else if (blinkingLinesP1>0){
      byte width=blinkingLinesP1&7;
      if (0==BlinkingP1%2)
        ab.fillRect(LB1,blinkingLinesP1>>3,10*SW,width*SW,1);
      else 
        ab.fillRect(LB1,blinkingLinesP1>>3,10*SW,width*SW,0);
      if (0==BlinkingP1--){
        removeBlinkingLines(true);
        blinkingLinesP1=-1;
      }
    }
    else { //BlinkingP1== -2 or less
        ab.setCursor(LB1-7,30);
        ab.println("Busted !");
    }
  }
  else {
      //if (ab.everyXFrames(fallingTimeP1)){
    if (0==fallingTimerP1--){
      fallingTimerP1=fallingTimerInitP1;
      if (!p1->move(MOVE_DOWN)){
        p1->stick();
        randomSeed(timer*321);
      }
    }
  }
  if (0!=blinkingLinesP2){ //same for P2
    
    if (-1==blinkingLinesP2){ 
      blinkingLinesP2=0;
      p2->reInit(nextP2->shape);
      p2->update();
      if (p2->checkCollision()){ //game over
        ab.setCursor(74,30);
        ab.println(" Busted !");
        ab.display();
        blinkingLinesP2=-2;
      }
      //p1.shape=nextP2.shape;
      for (int i=0; i<4; i++){
        p2->body[i].type=nextP2->body[i].type;
      }
      nextP2->shapeShift();
      nextP2->update();
    }
    else if (blinkingLinesP2>0){
      byte width=blinkingLinesP2&7;
      if (0==BlinkingP2%2)
        ab.fillRect(LB2,blinkingLinesP2>>3,10*SW,width*SW,1);
      else 
        ab.fillRect(LB2,blinkingLinesP2>>3,10*SW,width*SW,0);
      if (0==BlinkingP2--){
        removeBlinkingLines(false);
        blinkingLinesP2=-1;
      }
    }
    else {
      ab.setCursor(65,30);
      if (blinkingLinesP2==-2)
        ab.println("Busted!");
      else 
        ab.println("Array filled!");
    }
  }
  else {
      //if (ab.everyXFrames(fallingTimeP1)){
    if (0==fallingTimerP2--){
      fallingTimerP2=fallingTimerInitP2;
      if (!p2->move(MOVE_DOWN)){
        p2->stick();
      }
    }
  }
}
*/

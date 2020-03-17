
#include "globals.h"
#include "square.h"
#include "background.h"
/*
Piece(bool p1):Piece(0,0,0,p1){//:Piece(p1? 23:23+6+9*SW, 3,random(6)+1,p1){
  this->reInit();
}*/


void Square::draw(){
  switch(this->type){
    case TYPE_EMPTY :
      ab.drawRect(this->x,this->y,SW,SW,1);
      break;
    case TYPE_SLASH :
      ab.fillRect(this->x,this->y,SW,SW,1);
      ab.drawLine(this->x+SW-1,this->y,this->x,this->y+SW-1,0);
      break;
    case TYPE_DOTS :
      ab.drawLine(this->x,this->y,this->x+SW-1,this->y+SW-1,1);
      ab.drawLine(this->x+2,this->y,this->x+3,this->y+1,1);
      ab.drawLine(this->x,this->y+2,this->x+1,this->y+3,1);
      break;      
    case TYPE_4 :
        ab.drawPixel(this->x+SW-1,this->y+SW-1);
        ab.fillRect(this->x,this->y,SW-1,SW-1,1);
      break;
    case TYPE_STONE :
        ab.drawPixel(this->x,this->y+SW-1);
        ab.drawLine(this->x,this->y,this->x+2,this->y,1);
        ab.drawLine(this->x+1,this->y+1,this->x+3,this->y+1,1);
      break;      
    default:
      ab.fillRect(this->x,this->y,SW-1,SW-1,1);
      break;
  }
}

void Piece::reInit(byte shape){
  this->shape=shape;
  this->x= p1? 23:23+6+9*SW;
  this->y= 3;
  this->orientation=0; //depends... todo check
  if (p1)
    p1GoesToTheRight=true;
  else
    p2GoesToTheRight=false;
  //this->shapeShift();
}

void Piece::shapeShift(){
  int temp=random(7)+1;  //tODO: CHECK THIS RANDOM... I don't think it works as you want
  int temp2;
  this->shape=temp;
  switch (temp){
    case SHAPE_Z : case SHAPE_L :
      temp2=TYPE_SLASH;
    break;
    case SHAPE_O:
      temp2=TYPE_DOTS;
    break;
    case SHAPE_I :
      temp2=TYPE_4;
    break;
    default :
      temp2=TYPE_EMPTY;
    break;
  }
  for (int i=0; i<4; i++){
    this->body[i].type=temp2;
  }
}
  
void Piece::stick(){
  int minY=64;
  int maxY=0;
  if (this->p1){
    for (int i=0; i<4; i++){
      stillSquaresP1[NbStillSquaresP1+i]=this->body[i];
      if (this->body[i].y>maxY)
        maxY=this->body[i].y;
      if (this->body[i].y<minY)
        minY=this->body[i].y;     
    }
    if (NbStillSquaresP1+4<=MAXS){
      NbStillSquaresP1+=4;
      checkFullLines(minY, maxY,true);
    }
    else blinkingLinesP1=-2;
  }
  else { //p2
    for (int i=0; i<4; i++){
      stillSquaresP2[NbStillSquaresP2+i]=this->body[i];
      if (this->body[i].y>maxY)
        maxY=this->body[i].y;
      if (this->body[i].y<minY)
        minY=this->body[i].y;     
    }
    if (NbStillSquaresP2+4<=MAXS){
      NbStillSquaresP2+=4;
      checkFullLines(minY, maxY,false);
    }
    else blinkingLinesP1=-2;
  }  
}
void Piece::update(){
  body[0].x=this->x;
  body[0].y=this->y;
  //body[0].type=0;
  switch (this->shape){
    case SHAPE_I:
      switch (this->orientation){
        case 1 : case 3:
          body[1].x=this->x-SW;
          body[1].y=this->y;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x+2*SW;
          body[3].y=this->y;
        break;
        case 0 : case 2:
          body[1].x=this->x;
          body[1].y=this->y-1*SW;
          body[2].x=this->x;
          body[2].y=this->y+1*SW;
          body[3].x=this->x;
          body[3].y=this->y-2*SW;
        break;
      }
    break;
    case SHAPE_T:
      switch (this->orientation){
        case 0 :
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x;
          body[3].y=this->y+SW;
        break;
        case 3 :
          body[1].x=this->x;
          body[1].y=this->y-1*SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x-SW;
          body[3].y=this->y;
        break;
        case 2 :
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x-SW;
          body[2].y=this->y;
          body[3].x=this->x;
          body[3].y=this->y+SW;
        break;
        case 1 :
          body[1].x=this->x;
          body[1].y=this->y+1*SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x-SW;
          body[3].y=this->y;
        break;        
      }
    break;
    case SHAPE_S:
      switch (this->orientation){
        case 0 : case 2:
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x+SW;
          body[3].y=this->y+SW;
        break;
        case 1 : case 3:
          body[1].x=this->x;
          body[1].y=this->y-1*SW;
          body[2].x=this->x-SW;
          body[2].y=this->y;
          body[3].x=this->x+SW;
          body[3].y=this->y-SW;
        break;
      }
    break;
    case SHAPE_Z:
      switch (this->orientation){
        case 1 : case 3:
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x-SW;
          body[3].y=this->y-SW;
        break;
        case 0 : case 2:
          body[1].x=this->x;
          body[1].y=this->y+SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x+SW;
          body[3].y=this->y-SW;
        break;
      }
    break;    
    case SHAPE_L:
      switch (this->orientation){
        case 0 :
          body[1].x=this->x;
          body[1].y=this->y+SW;
          body[2].x=this->x+SW;
          body[2].y=this->y+SW;
          body[3].x=this->x;
          body[3].y=this->y-SW;
        break;
        case 1 :
          body[1].x=this->x-SW;
          body[1].y=this->y;
          body[2].x=this->x-SW;
          body[2].y=this->y+SW;
          body[3].x=this->x+SW;
          body[3].y=this->y;
        break;
        case 2 :
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x-SW;
          body[2].y=this->y-SW;
          body[3].x=this->x;
          body[3].y=this->y+SW;
        break;
        case 3 :
          body[1].x=this->x+SW;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x-SW;
          body[3].y=this->y;
        break;        
      }
    break; 
    case SHAPE_P:
      switch (this->orientation){
        case 0 :
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y-SW;
          body[3].x=this->x;
          body[3].y=this->y+SW;
        break;
        case 1 :
          body[1].x=this->x-SW;
          body[1].y=this->y;
          body[2].x=this->x+SW;
          body[2].y=this->y+SW;
          body[3].x=this->x+SW;
          body[3].y=this->y;
        break;
        case 2 :
          body[1].x=this->x;
          body[1].y=this->y-SW;
          body[2].x=this->x-SW;
          body[2].y=this->y+SW;
          body[3].x=this->x;
          body[3].y=this->y+SW;
        break;
        case 3 :
          body[1].x=this->x-SW;
          body[1].y=this->y-SW;
          body[2].x=this->x+SW;
          body[2].y=this->y;
          body[3].x=this->x-SW;
          body[3].y=this->y;
        break;        
      }
    break;     
    case SHAPE_O: default :
      body[1].x=this->x;
      body[1].y=this->y+1*SW;
      body[2].x=this->x+SW;
      body[2].y=this->y+SW;
      body[3].x=this->x+SW;
      body[3].y=this->y;    
    break;
  }
}
bool Piece::move(byte dir){
  bool temp;
  switch(dir){
    case MOVE_RIGHT:
      this->x+=SW;
      this->update();
      temp=this->checkCollision();
      if (temp) { // collision -> back to the previous spot
        this->x-=SW;
        this->update();
        return false;
      }
    break;
    case MOVE_LEFT:
      this->x-=SW;
      this->update();
      temp=this->checkCollision();
      if (temp) { // collision -> back to the previous spot
        this->x+=SW;
        this->update();
        return false;
      }
    break;
    case MOVE_DOWN:
      this->y+=SW;
      this->update();
      temp=this->checkCollision();
      if (temp) { // collision -> back to the previous spot
        this->y-=SW;
        this->update();
        return false;
      }
    break;    
  }
  return true;
}

bool Piece::checkCollision(){ //return true if Piece collides with something
  int temp = this->p1 ? 0:6+9*SW;
  for (int i=0;i<4;i++){
    if ((this->body[i].x>LB+temp+9*SW)||(this->body[i].x<LB+temp)||((this->body[i].y>63-SW)&&(this->body[i].y<200)) )
      return true;
    if (this->p1){
      for (int j=0;j<NbStillSquaresP1;j++){
        if ((this->body[i].x==stillSquaresP1[j].x)&&(this->body[i].y==stillSquaresP1[j].y))
          return true;
      }
    }
    else {
      for (int j=0;j<NbStillSquaresP2;j++){
        if ((this->body[i].x==stillSquaresP2[j].x)&&(this->body[i].y==stillSquaresP2[j].y))
          return true;
      }
    }
  }
  return false;
}

void Piece::turn(){
  byte backUp=this->orientation;
  if (++this->orientation >=4)
    this->orientation=0;
  this->update();
  if (this->checkCollision()){
    this->orientation=backUp;
    this->update();
  }
}

void Piece::draw(){
  for (int i=0;i<4;i++){
    body[i].draw();
  }
}

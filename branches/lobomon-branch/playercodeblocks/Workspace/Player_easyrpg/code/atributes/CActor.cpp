
//extern CWorld  * World; //cuando exista
#include <SDL/SDL.h>
#include "../tools/math-sll.h"
#include "../sprites/Chara.h"
#include "CActor.h"
#include "../tools/CDeltaTime.h"


extern CDeltaTime System;
/*
metodos faltantes

World->CollisionAt(GridX, GridY+1, WORLD_COLLISION_FROM_UP)



*/
#define ACTOR_STATE_IDLE        0x00
#define ACTOR_STATE_MOVING      0x01

#define ACTOR_DIRECTION_UP      0x00
#define ACTOR_DIRECTION_DOWN    0x01
#define ACTOR_DIRECTION_LEFT    0x02
#define ACTOR_DIRECTION_RIGHT   0x03

#define ACTOR_FLAGS_FREEZE      0x01

#define ACTOR_SPEED_SLOW        2.0f

int CActor::Clamp(int value, int min, int max) {
if(value<min)//mark when is out of range under development
{
outofarea=false;
return (min);}
else
if(value>max)
{outofarea=false;
return (max);
}
else
 {
 outofarea=true;
return (value);
 }

    return ((value<min)? min:(value>max)? max:value);
}
int CActor::Min(int value, int max) {
    return ((value>max)? max:value);
}


sll CActor::Minf(float value, float max) {
    return ((value>=max)? max:value);
}
sll CActor::Clampf(float value, float min, float max) {
    return ((value<min)? min:(value>=max)? max:value);
}
void CActor::setposXY(int x,int y)
{
 realX=(sll)x;
 realY=(sll)y;
}
void CActor::MoveOnInput() {
    // In case the method was called and the actor is put on freeze
    // (for example, on message display or game pause)
    if (flags & ACTOR_FLAGS_FREEZE) return;


    // Depending on current actor state, select between accepting input
    // and Cmotion
    switch(state) {
        case ACTOR_STATE_IDLE:
          unsigned char * keyData;
     		  keyData = SDL_GetKeyState(NULL);
	  if ( keyData[SDLK_UP]  ){// && World->CollisionAt(GridX, GridY-1, WORLD_COLLISION_FROM_DOWN)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_UP;
                dir=0;
                Cmotion.distance  = 0;
            } else if (keyData[SDLK_DOWN]  ){// && World->CollisionAt(GridX, GridY+1, WORLD_COLLISION_FROM_UP)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_DOWN;
                dir=2;
                Cmotion.distance  = 0;
            } else if ( keyData[SDLK_LEFT] ){// && World->CollisionAt(GridX-1, GridY, WORLD_COLLISION_FROM_RIGHT)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_LEFT;
                dir=3;
                Cmotion.distance  = 0;
            } else if ( keyData[SDLK_RIGHT] ){ //&& World->CollisionAt(GridX+1, GridY, WORLD_COLLISION_FROM_LEFT)==false) {
                state            = ACTOR_STATE_MOVING;
                Cmotion.direction = ACTOR_DIRECTION_RIGHT;
                dir=1;
                Cmotion.distance  = 0;
            }else{frame=0;}
// 	    GridX = (x)>>4; GridY = (y)>>4;// Calculate Grid X and Grid Y
            break;
        case ACTOR_STATE_MOVING:
            // Calculate how many pixels has the actor travelled  and how many's left
            Cmotion.delta    =Clampf(ACTOR_SPEED_SLOW*System.deltaTime, 0, 16-Cmotion.distance); // Clampf(value, min, max)
            Cmotion.distance = Minf(Cmotion.distance+ACTOR_SPEED_SLOW*System.deltaTime, 16.0f);//Minf(distancia + movimiento, maximo )
            frameupdate();
            // Change position of character by adding the delta
            switch(Cmotion.direction) {
                case ACTOR_DIRECTION_UP:    realY=sllsub(realY, Cmotion.delta);  break;
                case ACTOR_DIRECTION_DOWN:  realY=slladd(realY, Cmotion.delta);  break;
                case ACTOR_DIRECTION_LEFT:  realX=sllsub(realX, Cmotion.delta);  break;
                case ACTOR_DIRECTION_RIGHT:  realX=slladd(realX, Cmotion.delta); break;
            }

               if (Cmotion.distance == 16.0f) state = ACTOR_STATE_IDLE;
             break;
    }
}
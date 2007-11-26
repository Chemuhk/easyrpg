#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "sprite.h"
#include "key.h"
#include "font.h"
#include "audio.h"
#include "map.h"
#include <vector>
#include <string>
#include "skill.h"
#include "item.h"
#include "Enemy.h"



void Enemy::set_HP(int The_HP)
{
   HP=The_HP;
}
void Enemy::set_MaxHP(int The_MaxHP)
{
   MaxHP=The_MaxHP;
}
void Enemy::set_MP(int The_MP)
{
   MP=The_MP;
}
void Enemy::set_MaxMP(int The_MaxMP)
{
   MaxMP=The_MaxMP;
}

int * Enemy::get_HP()
{
  return (&HP);
}
int * Enemy::get_MaxHP()
{
  return (&MaxHP);
}
int* Enemy::get_MP()
{
   return (&MP);
}
int* Enemy::get_MaxMP()
{
   return (&MaxMP);
}

void Enemy::set_Heal(int The_Heal)
{
   Heal=The_Heal;
}
void Enemy::set_Attack(int The_Attack)
{
   Attack=The_Attack;
}
void Enemy::set_Defense(int The_Defense)
{
   Defense=The_Defense;
}
void Enemy::set_Speed(int The_Speed)
{
   Speed=The_Speed;
}
void Enemy::set_Spirit(int The_Spirit)
{
   Spirit=The_Spirit;
}
void Enemy::set_Level(int The_Level)
{
   Level=The_Level;
}
void Enemy::set_Exp(int The_Exp)
{
   Exp=The_Exp;
}

int * Enemy::get_Heal()
{
  return (&Heal);
}
int * Enemy::get_Attack()
{
  return (&Attack);
}
int* Enemy::get_Defense()
{
   return (&Defense);
}
int* Enemy::get_Speed()
{
   return (&Speed);
}

int * Enemy::get_Spirit()
{
  return (&Spirit);
}
int * Enemy::get_Level()
{
  return (&Level);
}
int* Enemy::get_Exp()
{
   return (&Exp);
}

void Enemy::set_name(const char * name)
{
   nombre=name;
}
const char * Enemy::get_name()
{
   return(nombre);
}


void Enemy::add_skill(Skill Myskill)
{
      Skills.push_back(Myskill);
}

const char * Enemy::get_skill_name(int num)
{
   return (((Skills.at(num))).get_name()); 
}

int * Enemy::get_skill_mp_price(int num)
{
   return (((Skills.at(num))).get_mp_price()); 
}
int * Enemy::get_skill_damange(int num)
{
   return (((Skills.at(num))).get_damange()); 
}
int * Enemy::get_skill_level_req(int num)
{
   return (((Skills.at(num))).get_level_req()); 
}

Animacion * Enemy::get_skill_get_anim(int num)
{
   return (((Skills.at(num))).get_anim()); 
}
int Enemy::get_skill_size()
{
     return (Skills.size());
}

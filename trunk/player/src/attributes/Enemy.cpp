/*Enemy.cpp, Enemy routines.
    Copyright (C) 2007 EasyRPG Project <http://easyrpg.sourceforge.net/>.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "../sprites/sprite.h"
#include "../tools/key.h"
#include "../tools/font.h"
#include "../tools/audio.h"
#include <vector>
#include <string>
#include "skill.h"
#include "item.h"
#include "Enemy.h"



void Enemy::set_HP(int The_HP)
{

}
void Enemy::set_MaxHP(int The_MaxHP)
{

}
void Enemy::set_MP(int The_MP)
{

}
void Enemy::set_MaxMP(int The_MaxMP)
{

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

}
int* Enemy::get_MaxMP()
{

}

void Enemy::set_Heal(int The_Heal)
{

}
void Enemy::set_Attack(int The_Attack)
{

}
void Enemy::set_Defense(int The_Defense)
{

}
void Enemy::set_Speed(int The_Speed)
{

}
void Enemy::set_Spirit(int The_Spirit)
{

}
void Enemy::set_Level(int The_Level)
{

}
void Enemy::set_Exp(int The_Exp)
{

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

}
int* Enemy::get_Speed()
{

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

}

void Enemy::set_name(const char * name)
{

}
const char * Enemy::get_name()
{

}


void Enemy::add_skill(Skill Myskill)
{

}

const char * Enemy::get_skill_name(int num)
{

}

int * Enemy::get_skill_mp_price(int num)
{

}
int * Enemy::get_skill_damange(int num)
{

}
int * Enemy::get_skill_level_req(int num)
{

}

Animacion * Enemy::get_skill_get_anim(int num)
{

}
int Enemy::get_skill_size()
{
	return (Skills.size());
}
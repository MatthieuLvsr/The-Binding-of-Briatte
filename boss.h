#ifndef BOSS_H
#define BOSS_H

#include "floor.h"
#include "map.h"
#include "player.h"
#include "boss.h"
#include "shooter.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define DELAY_BOSS 10.0 //frames entre chaque action du boss

struct BOSS_MONSTER{
    int x;
    int y;
    int fly;
    int ss;
    int damage;
    double tirRate;
    double lastShot;
    int reloading;
    char facing;
    int health;
    int type;
    int active;
    int alive;
    double delay;
};
typedef struct BOSS_MONSTER BOSS_MONSTER;

typedef struct Floor Floor;
typedef struct PLAYER PLAYER;
typedef struct RoomItem RoomItem;
typedef struct SHOOT SHOOT;


BOSS_MONSTER* newBoss(int floor);
void bossAI(Floor* floor, BOSS_MONSTER *boss, PLAYER *player, SHOOT** projectiles);
int checkCollisionBoss(char** room,PLAYER *player, BOSS_MONSTER* boss, char dir);
int looseHealthBoss(int hp, BOSS_MONSTER *boss);
int checkHealthBoss(BOSS_MONSTER *boss);




#endif
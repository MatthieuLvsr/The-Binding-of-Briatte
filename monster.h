#ifndef MONSTER_H
#define MONSTER_H

#include "shooter.h"
#include "player.h"
struct MONSTER{
    int x;
    int y;
    int fly;
    int ss;
    int damage;
    int health;
    int type;
    int ind;
    int alive;
    double delay;
};
typedef struct MONSTER MONSTER;

struct MONSTER_LIST{
    int roomX;
    int roomY;
    int size;
    MONSTER* monster;
    struct MONSTER_LIST* last;
};
typedef struct MONSTER_LIST MONSTER_LIST;

typedef struct MAP MAP;
typedef struct PLAYER PLAYER;
typedef struct SHOOT SHOOT;

MONSTER_LIST* spawn(int size, int roomX, int roomY, MAP *map);

MONSTER* newMonster(MAP* map);

MONSTER* getMonster(int id, MAP* map, int ind);

void printMonsters(MONSTER_LIST* monster_list);
void printMonster(MONSTER_LIST* monster_list);
int getNbMonster(void);
int getMonsterByCoord(MONSTER_LIST* monster_list, int x, int y);
int looseHealthMonster(int hp, MONSTER *monster);
int checkHealthMonster(MONSTER *monster);
void hitMonsterByCoord(int damage, MONSTER_LIST* monster_list, int x, int y);
int monsterLength(MONSTER_LIST* monster_list);
int checkKills(MONSTER_LIST* monster_list);
void monsterAI(Floor* floor, MONSTER_LIST *monster_list, PLAYER *player, SHOOT** projectiles);
int checkCollisionMonster(char** room,PLAYER *player, MONSTER* monster, char dir);


#endif
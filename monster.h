#ifndef MONSTER_H
#define MONSTER_H

struct MONSTER{
    int x;
    int y;
    int fly;
    int ss;
    int damage;
    int health;
    int type;
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

MONSTER_LIST* spawn(int size, int roomX, int roomY, MAP *map);

MONSTER* newMonster(MAP* map);

MONSTER* getMonster(int id, MAP* map);

void printMonsters(MONSTER_LIST* monster_list);
void printMonster(MONSTER_LIST* monster_list);
int getNbMonster(void);


#endif
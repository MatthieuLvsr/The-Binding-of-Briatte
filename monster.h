#ifndef MONSTER_H
#define MONSTER_H

struct MONSTER{
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
typedef struct MONSTER MONSTER;

#endif
/** Génération du joueur
 * Date 26/10/2022
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "floor.h"
#include "map.h"
#include "player.h"

struct PLAYER{
    int x;
    int y;
    int fly;
    int ss;
    double tirRate;
    int damage;
    double lastShot;
    int reloading;
    int roomX;
    int roomY;
    char facing;
    int health;
    int shield;
    int nextLevel;
};
typedef struct PLAYER PLAYER;

typedef struct Floor Floor;

/** Déplacement du joueur
 * @param floor étage
 * @param player joueur
 * @param dir direction
*/
void movePlayer(Floor* floor, PLAYER* player, char dir);

/** Vérification des collisions
 * @param room pièce
 * @param player joueur
 * @param dir direction
 * @return booleen de possibilité de déplacement
*/
int checkCollision(char** room, PLAYER* player, char dir, char status);

int looseHealth(int hp, PLAYER *player);
int checkHealth(PLAYER player);

#endif
/** Génération des tirs
 * Date : 26/10/2022
*/

#ifndef SHOOTER_H
#define SHOOTER_H

struct SHOOT{
    int startX;
    int startY;
    char dir;
    char type;
    int ind;
    struct SHOOT* last;
};

typedef struct SHOOT SHOOT;
typedef struct MAP MAP;
typedef struct PLAYER PLAYER;
typedef struct BOSS_MONSTER BOSS_MONSTER;

/** Nouveau tir
 * @param projectiles liste des tirs
 * @param startX position x du projectile
 * @param startY position y du projectile
 * @param dir direction
 * @param type affichage du projectile
*/
void newShoot(SHOOT** projectiles, int startX, int startY, char dir, char type);

/** Supression d'un tir
 * @param projectiles liste des tirs
 * @param ind index à supprimer
*/
void deleteShoot(SHOOT** projectiles,int ind);

/** Affichage de la liste des tirs
 * @param projectiles liste des tirs
*/
void printShoots(SHOOT* projectiles);

/** Affichage d'un tir
 * @param projectiles liste des tirs
*/
void printShoot(SHOOT* projectiles);

/** Mise à jour des tirs
 * @param projectiles liste des projectiles
 * @param map pièce
 * @param player joueur
*/
void updateShoots(SHOOT** shoots, MAP* map, PLAYER* player, BOSS_MONSTER *boss);

/** Récupération de la longueur de la liste
 * @param shoots liste des tirs
 * @return taille de la liste
*/
int shootsLength(SHOOT* shoots);

/** Tir
 * @param shoots liste des tirs
 * @param player joueur
*/
void shoot(SHOOT** shoots, int startX, int startY, char dir, char type);

#endif
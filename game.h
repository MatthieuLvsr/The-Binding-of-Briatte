#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "map.h"
#include "floor.h"
#include "player.h"
#include "shooter.h"

#define SPEED 1500

/** Lancement du jeu
 * @return erreur
*/
int play(void);

#endif
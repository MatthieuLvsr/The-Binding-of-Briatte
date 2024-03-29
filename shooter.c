#include <stdio.h>
#include <stdlib.h>
#include "shooter.h"
#include "map.h"
#include "player.h"

void newShoot(SHOOT** projectiles, int startX, int startY, char dir, char type){
    SHOOT* newShoot = malloc(sizeof(SHOOT));
    newShoot->startX = startX;
    newShoot->startY = startY;
    newShoot->dir = dir;
    newShoot->type = type;
    newShoot->ind = shootsLength(*projectiles) + 1;
    newShoot->last = *projectiles;
    *projectiles = newShoot;
}

void shoot(SHOOT** shoots, PLAYER player){
    newShoot(shoots,player.x,player.y,player.facing,'o');
}

SHOOT* getShoot(SHOOT* shooters, int ind){
    while(shooters != NULL && shooters->ind != ind){
        shooters = shooters->last;
    }
    return shooters;
}

void deleteShoot(SHOOT** projectiles,int ind){
    while((*projectiles)->ind != ind && (*projectiles)){     
        *projectiles = (*projectiles)->last;   
    }
    if(ind == shootsLength(*projectiles)){
        SHOOT* tmp = (*projectiles)->last;
        free(*projectiles);
        *projectiles = tmp;
    }else{
        getShoot(*projectiles,ind+1)->last = (*projectiles)->last;
        free(*projectiles);
    }
}

void printShoots(SHOOT* projectiles){
    while(projectiles){
        printShoot(projectiles);
        projectiles = projectiles->last;
    }
}

void printShoot(SHOOT* projectile){
    printf("%d : start(%d,%d) - dir: %c - type: \"%c\"\n",projectile->ind,projectile->startX,projectile->startY,projectile->dir,projectile->type);
}

void updateShoots(SHOOT** shoots, MAP* map, PLAYER player){
    SHOOT* projectiles = *shoots;
    while(projectiles){
        int x = projectiles->startX;
        int y = projectiles->startY;
        switch (projectiles->dir)
        {
        case 'q':
            if(x-1 <= 0)deleteShoot(shoots,projectiles->ind);
            else if(map->room[y][x-1]!='R'){
                projectiles->startX -= 1;
            }else if(player.ss){
                projectiles->startX -= 1;
            }else{
                deleteShoot(shoots,projectiles->ind);
            }
            break;
        case 'z':
            if(y-1 <= 0)deleteShoot(shoots,projectiles->ind);
            else if(map->room[y-1][x]!='R'){
                projectiles->startY -= 1;
            }else if(player.ss){
                projectiles->startY -= 1;
            }else{
                deleteShoot(shoots,projectiles->ind);
            }
            break;
        case 'd':
            if(x+1 >= map->width - 1)deleteShoot(shoots,projectiles->ind);
            else if(map->room[y][x+1]!='R'){
                projectiles->startX += 1;
            }else if(player.ss){
                projectiles->startX += 1;
            }else{
                deleteShoot(shoots,projectiles->ind);
            }
            break;
        case 's':
            if(y+1 >= map->height - 1)deleteShoot(shoots,projectiles->ind);
            else if(map->room[y+1][x]!='R'){
                projectiles->startY += 1;
            }else if(player.ss){
                projectiles->startY += 1;
            }else{
                deleteShoot(shoots,projectiles->ind);
            }
            break;
        
        default:
            break;
        }
        projectiles = projectiles->last;
    }
}

int shootsLength(SHOOT* shoots){
    int i = 0;
    while(shoots){
        i += 1;
        shoots = shoots->last;
    }
    return i;
}
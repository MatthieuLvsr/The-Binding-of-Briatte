#include <stdio.h>
#include <stdlib.h>
#include "floor.h"
#include "map.h"
#include "player.h"

void movePlayer(Floor* floor, PLAYER* player, char dir){
    RoomItem* room = getRoomByCoord(floor->list,player->roomX, player->roomY);
    if(!checkCollision(room->map->room,player,dir))return;    
    if(player->x < 1){
        player->roomX -= 1;
        player->x = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->width) - 2;
        player->y = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->height - 1) / 2;
        // nextStep(floor,*player);
    }else if(player->x > room->map->width - 2){
        player->roomX += 1;
        player->x = 1;
        player->y = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->height - 1) / 2;
        // nextStep(floor,*player);
    }else if(player->y > room->map->height - 2){
        player->roomY += 1;
        player->y = 1;
        player->x = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->width - 1) / 2;
        // nextStep(floor,*player);
    }else if(player->y < 1){
        player->roomY -= 1;
        player->y = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->height) - 2;
        player->x = (getRoomByCoord(floor->list,player->roomX,player->roomY)->map->width - 1) / 2;
        // nextStep(floor,*player);
    }else{
        // displayRoom(room->map->room,room->map->height,room->map->width,*player);
    }
}

int checkCollision(char** room, PLAYER* player, char dir){
switch (dir)
    {
    case 'q':
        player->facing = 'q';
        if(room[player->y][player->x - 1] == 'W') return 0;
        if(room[player->y][player->x - 1] == 'G' && !player->fly) return 0;
        if(room[player->y][player->x - 1] == 'R' && !player->fly) return 0;
        player->x -= 1;
        return 1;
        break;
    case 'z':
        player->facing = 'z';
        if(room[player->y - 1][player->x] == 'W') return 0;
        if(room[player->y - 1][player->x] == 'G' && !player->fly) return 0;
        if(room[player->y - 1][player->x] == 'R' && !player->fly) return 0;
        player->y -= 1;
        return 1;
        break;
    case 'd':
        player->facing = 'd';
        if(room[player->y][player->x + 1] == 'W') return 0;
        if(room[player->y][player->x + 1] == 'G' && !player->fly) return 0;
        if(room[player->y][player->x + 1] == 'R' && !player->fly) return 0;
        player->x += 1;
        return 1;
        break;
    case 's':
        player->facing = 's';
        if(room[player->y + 1][player->x] == 'W') return 0;
        if(room[player->y + 1][player->x] == 'G' && !player->fly) return 0;
        if(room[player->y + 1][player->x] == 'R' && !player->fly) return 0;
        player->y += 1;
        return 1;
        break;
    }
}
#include "game.h"

int play(void){

    SHOOT* projectiles = NULL;

    // newShoot(&projectiles,2,2,'s','o');  
    
    Floor* floor = newFloor(3);
    PLAYER player;
    player.fly = 0;
    player.ss = 0;
    player.tirRate = 15000;
    player.lastShot = 0.0;
    player.roomX = (floor->size-1)/2;
    player.roomY = (floor->size-1)/2;
    player.facing = 'z';
    player.x = (getRoomByCoord(
                floor->list,
                (floor->size-1)/2,
                (floor->size-1)/2
                )->map->width - 1) / 2;
    player.y = (getRoomByCoord(
                floor->list,
                (floor->size-1)/2,
                (floor->size-1)/2
                )->map->height - 1) / 2;
    printFloor(*floor);
    checkDoors(floor);
    nextStep(floor,player, projectiles);
    char dir;
    double frame = 1.0;
    getch();
    while (dir != 'p'){
        RoomItem* room = getRoomByCoord(floor->list,player.roomX,player.roomY);
        if((int)frame%SPEED==0){
            updateShoots(&projectiles,room->map, player);
            system("@cls||clear");
            displayRoom(room->map->room,room->map->height,room->map->width,player,projectiles);
            // printf("%lf",frame);
            if(player.tirRate - (frame - player.lastShot) <= 0) player.reloading = 1;
            if ( _kbhit() ){
                dir = _getch();
                movePlayer(floor,&player,dir);
                if(dir == 32){
                    if(player.reloading){
                        shoot(&projectiles,player);
                        player.reloading = 0;
                        player.lastShot = frame;
                    }
                }
            }
            frame += 1.0;
        }
        frame += 1.0/SPEED;
    }
    // printShoots(projectiles);
    // printf("%d",shootsLength(projectiles));
    freeFloor(floor);


    return 0;
}
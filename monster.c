#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "monster.h"

MONSTER_LIST* spawn(int size, int roomX, int roomY, MAP *map){
    MONSTER_LIST* monster_list = NULL;
    for(int i = 0; i < size; i += 1){
        MONSTER_LIST* newMonster = malloc(sizeof(MONSTER_LIST));
        newMonster->roomX = roomX;
        newMonster->roomY = roomY;
        newMonster->size = size;

        int x,y;
        do{
            x = rand()%map->width;
            y = rand()%map->height;
        }while(map->room[y][x] != EMPTY);
        int index = rand()%getNbMonster();
        newMonster->monster = getMonster(index, map);
        newMonster->last = monster_list;
        monster_list = newMonster;
    }
    return monster_list;
}

// MONSTER* newMonster(MAP* map){
//     int x,y;
//     do{
//         x = rand()%map->width;
//         y = rand()%map->height;
//     }while(map->room[y][x] != EMPTY);
    
//     return monster;
// }

MONSTER* getMonster(int id, MAP* map){
    FILE * fp = fopen("./monster.tbob","r");
    if(fp == NULL){
        printf("ERROR");
    }else{
        int x,y;
        do{
            x = rand()%map->width;
            y = rand()%map->height;
        }while(map->room[y][x] != EMPTY);
        MONSTER* monster = malloc(sizeof(MONSTER));
        monster->alive = 1;
        monster->damage = 1;
        monster->delay = 20.0;
        monster->type = 1;
        monster->x = x;
        monster->y = y;
        monster->fly = 0;
        monster->ss = 0;
        int curId, curW, curH, ind = 0, next = 1;
        char str[100];
        char attribut[20];
        char c = ' ';
        fseek(fp,0,SEEK_END);
        int max = ftell(fp);
        fseek(fp,5,SEEK_SET);
        fseek(fp,5,SEEK_CUR);
        // fscanf(fp,"%s",str);
        // printf("%s\n",str);
        // printf("RESULT: %d\n",strcmp(str,"---"));
        while(ind <= id){
            while(next){
                fscanf(fp,"%s",str);
                if(strcmp(str,"---") && ind <= id){
                    if(ind == id){
                        strcpy(attribut,"");
                        int i = 0;
                        c = ' ';
                        while(c != '='){
                            c = str[i];
                            if(c != '='){
                                strncat(attribut,&c,1);
                            }
                            i += 1;
                        }
                        // printf("attribut : %s",attribut);
                        if(!strcmp(attribut,"hpMax")){
                            monster->health = (int)str[i] - 48;
                            // printf(" = %d\n", (int)str[i] - 48);
                        }else if(!strcmp(attribut,"flight")){
                            if(str[i] == 't'){
                                monster->fly = 1;
                                // printf(" = %s\n","True");
                            }
                        }else if(!strcmp(attribut,"shoot")){
                            if(str[i] == 't'){
                                monster->ss = 1;
                                // printf(" = %s\n","True");
                            }
                        }else printf("\n");
                    }
                    if(ftell(fp) == max){
                        ind += 1;
                    }
                }else{
                    next = 0;
                }
            }
            next = 1;
            ind += 1;
        }
        // MAP* map = malloc(sizeof(MAP));
        // map->room = initRoom(curH,curW);
        // map->height = curH;
        // map->width = curW;
        // map->status = 0;
        // for(int i = 0; i < curH; i += 1){
        //     for(int j = 0; j < curW; j += 1){
        //         map->room[i][j] = fgetc(fp);
        //         fseek(fp,1,SEEK_CUR);
        //         if(j == curW - 1)fseek(fp,1,SEEK_CUR);
        //     }
        // }
        // displayRoom(room,curH,curW);
        fclose(fp);
        return monster;
    }
}

void printMonsters(MONSTER_LIST* monster_list){
    while(monster_list){
        printMonster(monster_list);
        monster_list = monster_list->last;
    }
}

void printMonster(MONSTER_LIST* monster_list){
    printf("[%d,%d] - hpMax: %d - fly: %d - shoot: %d\n",monster_list->monster->x,monster_list->monster->y,monster_list->monster->health,monster_list->monster->fly,monster_list->monster->ss);
}

int getNbMonster(void){
    FILE * fp = fopen("./monster.tbob","r");
    if(fp == NULL){
        printf("ERROR");
    }else{
        fseek(fp,1,SEEK_SET);
        int nb = 0;
        fscanf(fp,"%d",&nb);
        return nb;
    }
}
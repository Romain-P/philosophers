//
// Created by romain on 06/03/2018.
//

#ifndef PSU_PHILOSOPHER_2017_MAIN_H
# define PSU_PHILOSOPHER_2017_MAIN_H

#include <sys/types.h>
#include "option.h"

typedef enum    exit_status_e
{
    SUCCESS = 0,
    FAILURE = 84
}               exit_status_t;

typedef enum    state_e
{
    EATING,
    SLEEPING,
    THINKING
}               state_t;

typedef struct game_handler_s game_handler_t;

typedef struct      player_s {
    state_t         state;
    pthread_mutex_t mutex;
    size_t          eats;
    struct player_s *on_right;
    game_handler_t  *handler;
}                   player_t;

typedef struct      game_handler_s
{
    size_t          reached_eats;
    options_t       *options;
    player_t        *philosophers;
}                   game_handler_t;

void    handler_init(game_handler_t *handler, options_t *options, player_t players[]);
void    eat(player_t *player);
void    think(player_t *player);
void    sleep(player_t *player);
void    *start(void *arg);

#endif //PSU_PHILOSOPHER_2017_MAIN_H

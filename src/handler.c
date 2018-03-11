//
// Created by romain on 11/03/2018.
//

#include <pthread.h>
#include <extern.h>
#include "philosopher.h"

void handler_init(game_handler_t *handler, options_t *options, player_t players[])
{
    handler->philosophers = players;
    handler->options = options;
    for (size_t i = 0; i < options->philosophers; ++i) {
        player_t *right = i == options->philosophers - 1 ? players : players + i;
        players[i].on_right = right;
        players[i].state = THINKING;
        players[i].mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
        players[i].eats = 0;
        players[i].handler = handler;
    }
}

void    eat(player_t *player)
{
    lphilo_take_chopstick(&player->on_right->mutex);
    lphilo_take_chopstick(&player->mutex);
    lphilo_eat();
    lphilo_release_chopstick(&player->on_right->mutex);
    lphilo_release_chopstick(&player->mutex);
    player->eats += 1;
    if (player->eats > player->handler->reached_eats)
        player->handler->reached_eats = player->eats;
    player->state = EATING;
}

void    think(player_t *player)
{
    lphilo_take_chopstick(&player->mutex);
    lphilo_think();
    lphilo_release_chopstick(&player->mutex);
    player->state = THINKING;
}

void    sleep(player_t *player)
{
    player->state = SLEEPING;
    lphilo_sleep();
}

void            *start(void *arg)
{
    player_t    *player = (player_t *) arg;

    while (player->handler->reached_eats < player->handler->options->max_eats) {
        if (pthread_mutex_trylock(&(player->mutex)) == 0) {
            if (player->state != THINKING)
                think(player);
            if (pthread_mutex_trylock(&(player->on_right->mutex)) == 0) {
                if (player->state != EATING)
                    eat(player);
                pthread_mutex_unlock(&player->on_right->mutex);
            }
            pthread_mutex_unlock(&player->mutex);
        }
        if (player->state == EATING)
            sleep(player);
    }
    return NULL;
}
//
// Created by romain on 06/03/2018.
//

#include <stdlib.h>
#include <philosopher.h>
#include "thread.h"

bool thread_init(pthread_t threads[], player_t players[], size_t size, void *(*callback)(void *))
{
    for (size_t i=0; i < size; ++i)
        if (pthread_create(&threads[i], NULL, callback, players + i))
            return false;
    return true;
}

bool thread_await(pthread_t threads[], size_t size)
{
    for (size_t i=0; i < size; ++i)
        if (pthread_join(threads[i], NULL))
            return false;
    return true;
}
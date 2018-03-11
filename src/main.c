//
// Created by romain on 06/03/2018.
//

#include "philosopher.h"
#include <stdio.h>
#include "thread.h"

static exit_status_t error(char *error)
{
    printf("%s\n", error);
    return FAILURE;
}

int             main(int ac, char **args)
{
    options_t       options;

    if (!parse_options(&options, (size_t) ac, args))
        return FAILURE;
    pthread_t threads[options.philosophers];
    player_t players[options.philosophers];
    game_handler_t handler;
    handler_init(&handler, &options, players);
    if (!thread_init(threads, players, options.philosophers, &player_start))
        return error("Several threads were impossible to init");
    if (!thread_await(threads, options.philosophers))
        return error("Several threads can't be awaited");
    return (SUCCESS);
}
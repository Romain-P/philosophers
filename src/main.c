//
// Created by romain on 06/03/2018.
//

#include "philosopher.h"
#include <stdlib.h>
#include <stdio.h>
#include "thread.h"
#include "option.h"

static void *af(void *arg) {
    while(arg);
    return NULL;
}

static exit_status_t error(char *error)
{
    printf("%s\n", error);
    return FAILURE;
}

int             main(int ac, char **args)
{
    options_t   options;

    if (!parse_options(&options, ac, args))
        return FAILURE;
    pthread_t threads[10];
    if (!thread_init(threads, 10, &af, (void *)1))
        return error("Several threads were impossible to init");
    if (!thread_await(threads, 10))
        return error("Several threads can't be awaited");
    return (SUCCESS);
}
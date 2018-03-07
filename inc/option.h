//
// Created by romain on 06/03/2018.
//

#ifndef PROJECT_OPTION_H
# define PROJECT_OPTION_H

# include <stdint.h>
# include <stdbool.h>

typedef struct      options_s
{
    size_t          philosophers;
    size_t          max_eats;
}                   options_t;

typedef struct      args_s
{
    size_t          ac;
    char  * const   *args;
}                   args_t;

bool                parse_options(options_t *opts, size_t ac, char * const *args);

#endif //PROJECT_OPTION_H

//
// Created by romain on 06/03/2018.
//

#include <stdio.h>
#include <string.h>
#include "option.h"
#include "util.h"

static char const *get_next_arg(char const *label, args_t *pos) {
    if (!pos->args[pos->ac++]) {
        print_err(*pos->args, "no argument found for the given option %s", label);
        return NULL;
    }
    return pos->args[pos->ac];
}

static bool set_option_size(char const *label, size_t *field, args_t *pos, bool strict)
{
    if (strcmp(label, pos->args[pos->ac]))
        return true;
    else if (*field != 0)
        return print_err(*pos->args, "%s already set", label);
    int64_t parsed;
    char const *arg = get_next_arg(label, pos);
    if (!arg)
        return print_err(*pos->args, "option %s requires an argument", label);
     else if (!parse_int(arg, &parsed))
        return print_err(*pos->args, "%s is not a number (required by option %s)", arg, label);
     else if (parsed == 0 && strict)
        return print_err(*pos->args, "option %s: arg must be > 0 (parsed %d)", label, parsed);
     else if (parsed < 0)
        return print_err(*pos->args, "option %s: arg must be positive (parsed %d)", label, parsed);
    *field = (size_t) parsed;
    return true;
}

bool            parse_options(options_t *opts, size_t ac, char * const *args)
{
    if (ac < 2)
        goto error;
    *opts = (options_t){0, 0};
    for (args_t pos = {1, args}; pos.ac < ac; ++pos.ac) {
        if (!set_option_size("-p", &opts->philosophers, &pos, true))
            break;
        else if (!set_option_size("-e", &opts->max_eats, &pos, true))
            break;
    }
    if (!opts->max_eats || !opts->philosophers) {
        error:
        return print_err(*args, "you must specify valid -p and -e options");
    }
    return true;
}
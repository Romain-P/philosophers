//
// Created by romain on 06/03/2018.
//

#include <stdlib.h>
#include <memory.h>
#include <stdarg.h>
#include "util.h"

bool        parse_int(char const *str, int64_t *ptr)
{
    char    *end;

    *ptr = (int64_t) strtol(str, &end, 0);
    return end == str + strlen(str);
}

bool        print_err(char *bin, char const *format, ...)
{
    size_t      bin_len;
    size_t      err_len;
    size_t      base_len;

    bin_len = strlen(bin);
    err_len = strlen(format);
    char        base[bin_len + 3];
    char        err[bin_len + err_len + 2];
    strcpy(base, bin);
    strcpy(base + bin_len, ": ");
    base_len = bin_len + 2;
    strcpy(err, base);
    strcpy(err + base_len, format);
    strcpy(err + base_len + strlen(format), "\n");
    va_list list;
    va_start(list, format);
    vfprintf(stderr, err, list);
    va_end(list);
    return false;
}
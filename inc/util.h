//
// Created by romain on 06/03/2018.
//

#ifndef PROJECT_UTIL_H
# define PROJECT_UTIL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

/**
 * @param str   given string to convert
 * @param ptr   a pointer that points to a int
 *
 * @return      false if the string is not a number, true otherwise
 */
bool parse_int(char const *str, int64_t *ptr);

/**
 * Prints on error output a formatted message with process name as base.
 * Also creates a new line.
 *
 * @param bin       process name
 * @param format    message format
 * @param ...       args
 * @return          false for any case
 */
bool        print_err(char *bin, char const *format, ...);

#endif //PROJECT_UTIL_H

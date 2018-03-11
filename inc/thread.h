//
// Created by romain on 06/03/2018.
//

#ifndef PROJECT_THREAD_H
# define PROJECT_THREAD_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>

/**
 * Initialize given threads with no attributes
 *
 * @param threads   threads array
 * @param players   philosophers array
 * @param size      the number of threads in this array
 * @param callback  called as main entry when the thread starts
 * @return          false if an error occurred, true otherwise
 */
bool thread_init(pthread_t threads[], player_t players[], size_t size, void *(*callback)(void *));


/**
 * Join several threads to the thread this function is called from.
 *
 * @param threads   threads array
 * @param size      size of this array
 * @return          false if an error occurred, true otherwise
 */
bool thread_await(pthread_t threads[], size_t size);

#endif //PROJECT_THREAD_H

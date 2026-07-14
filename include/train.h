#ifndef TRAIN_H
#define TRAIN_H

#include <stdbool.h>
#include "types.h"

/*----------------------------------------------------
 * Train Management
 *---------------------------------------------------*/

/* Add a new train */
bool train_add(const Train *train);

/* Update an existing train */
bool train_update(const char *train_no, const Train *train);

/* Delete a train */
bool train_delete(const char *train_no);

/* Search for a train */
Train *train_search(const char *train_no);

/* Display all trains */
void train_list_all(void);

#endif
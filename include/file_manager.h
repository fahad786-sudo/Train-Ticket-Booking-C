#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdbool.h>

/*----------------------------------------------------
 * Entity Types
 *---------------------------------------------------*/
typedef enum
{
    ENTITY_TRAIN,
    ENTITY_USER,
    ENTITY_PASSENGER,
    ENTITY_BOOKING
} EntityType;

/*----------------------------------------------------
 * Generic CRUD Operations
 *---------------------------------------------------*/

/*
 * Create a new record
 */
bool dal_create(EntityType entity, const void *record);

/*
 * Read a record using its primary key
 */
void *dal_read(EntityType entity, const char *key);

/*
 * Update an existing record
 */
bool dal_update(EntityType entity, const char *key, const void *record);

/*
 * Delete a record
 */
bool dal_delete(EntityType entity, const char *key);

/*
 * Read all records
 */
void *dal_read_all(EntityType entity, int *count);

#endif
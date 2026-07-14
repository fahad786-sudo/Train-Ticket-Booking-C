#include <stdio.h>
#include <stdbool.h>

#include "file_manager.h"

/*----------------------------------------------------
 * Get File Name
 *---------------------------------------------------*/
static const char *get_file_name(EntityType entity)
{
    switch (entity)
    {
        case ENTITY_TRAIN:
            return "data/trains.dat";

        case ENTITY_USER:
            return "data/users.dat";

        case ENTITY_PASSENGER:
            return "data/passengers.dat";

        case ENTITY_BOOKING:
            return "data/bookings.dat";

        default:
            return NULL;
    }
}

/*----------------------------------------------------
 * Create Record
 *---------------------------------------------------*/
bool dal_create(EntityType entity, const void *record)
{
    const char *file_name = get_file_name(entity);
    (void)file_name;
    (void)record;

    return false;
}

/*----------------------------------------------------
 * Read Record
 *---------------------------------------------------*/
void *dal_read(EntityType entity, const char *key)
{
    (void)entity;
    (void)key;

    return NULL;
}

/*----------------------------------------------------
 * Update Record
 *---------------------------------------------------*/
bool dal_update(EntityType entity, const char *key, const void *record)
{
    (void)entity;
    (void)key;
    (void)record;

    return false;
}

/*----------------------------------------------------
 * Delete Record
 *---------------------------------------------------*/
bool dal_delete(EntityType entity, const char *key)
{
    (void)entity;
    (void)key;

    return false;
}

/*----------------------------------------------------
 * Read All Records
 *---------------------------------------------------*/
void *dal_read_all(EntityType entity, int *count)
{
    (void)entity;
    (void)count;

    return NULL;
}
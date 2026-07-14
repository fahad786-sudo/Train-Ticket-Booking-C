#include <stdio.h>
#include <string.h>

#include "file_manager.h"
#include "types.h"

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

    if (file_name == NULL)
        return false;

    FILE *fp = fopen(file_name, "ab");

    if (fp == NULL)
        return false;

    switch (entity)
    {
        case ENTITY_TRAIN:
            fwrite(record, sizeof(Train), 1, fp);
            break;

        default:
            fclose(fp);
            return false;
    }

    fclose(fp);
    return true;
}

/*----------------------------------------------------
 * Read Record (Not implemented yet)
 *---------------------------------------------------*/
void *dal_read(EntityType entity, const char *key)
{
    (void)entity;
    (void)key;
    return NULL;
}

/*----------------------------------------------------
 * Update Record (Not implemented yet)
 *---------------------------------------------------*/
bool dal_update(EntityType entity, const char *key, const void *record)
{
    (void)entity;
    (void)key;
    (void)record;
    return false;
}

/*----------------------------------------------------
 * Delete Record (Not implemented yet)
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
    static Train trains[100];

    *count = 0;

    const char *file_name = get_file_name(entity);

    if (file_name == NULL)
        return NULL;

    FILE *fp = fopen(file_name, "rb");

    if (fp == NULL)
        return NULL;

    if (entity == ENTITY_TRAIN)
    {
        while (*count < 100 &&
               fread(&trains[*count], sizeof(Train), 1, fp) == 1)
        {
            (*count)++;
        }

        fclose(fp);

        return trains;
    }

    fclose(fp);
    return NULL;
}
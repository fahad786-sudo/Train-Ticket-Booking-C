#include <stdio.h>
#include <string.h>

#include "train.h"
#include "file_manager.h"

/*----------------------------------------------------
 * Add Train
 *---------------------------------------------------*/
bool train_add(const Train *train)
{
    if (train == NULL)
    {
        return false;
    }

    if (strlen(train->train_no) == 0 ||
        strlen(train->train_name) == 0)
    {
        return false;
    }

    if (dal_create(ENTITY_TRAIN, train))
    {
        printf("\nTrain added successfully!\n");
        return true;
    }

    printf("\nFailed to add train!\n");
    return false;
}

/*----------------------------------------------------
 * Update Train
 *---------------------------------------------------*/
bool train_update(const char *train_no, const Train *train)
{
    (void)train_no;
    (void)train;
    return false;
}

/*----------------------------------------------------
 * Delete Train
 *---------------------------------------------------*/
bool train_delete(const char *train_no)
{
    (void)train_no;
    return false;
}

/*----------------------------------------------------
 * Search Train
 *---------------------------------------------------*/
Train *train_search(const char *train_no)
{
    (void)train_no;
    return NULL;
}

/*----------------------------------------------------
 * List All Trains
 *---------------------------------------------------*/
void train_list_all(void)
{
    int count = 0;

    Train *trains = (Train *)dal_read_all(ENTITY_TRAIN, &count);

    if (trains == NULL || count == 0)
    {
        printf("\nNo trains found.\n");
        return;
    }

    printf("\n========== TRAIN LIST ==========\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nTrain %d\n", i + 1);
        printf("------------------------------\n");
        printf("Train No   : %s\n", trains[i].train_no);
        printf("Name       : %s\n", trains[i].train_name);
        printf("Source     : %s\n", trains[i].source);
        printf("Destination: %s\n", trains[i].destination);
        printf("Departure  : %s\n", trains[i].departure_time);
        printf("Arrival    : %s\n", trains[i].arrival_time);
        printf("Seats      : %d\n", trains[i].available_seats);
        printf("Fare       : %.2f\n", trains[i].fare);
    }
}
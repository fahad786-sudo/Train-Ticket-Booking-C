#include <stdio.h>

#include "train.h"

int main(void)
{
    Train train =
    {
        "12658",
        "Chennai Express",
        "Bengaluru",
        "Chennai",
        "08:30",
        "14:15",
        120,
        120,
        850.00
    };

    train_add(&train);

    printf("\n");

    train_list_all();

    return 0;
}
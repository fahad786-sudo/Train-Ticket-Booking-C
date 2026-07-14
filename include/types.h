#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

/*----------------------------------------------------
 * User Roles
 *---------------------------------------------------*/
typedef enum
{
    ROLE_ADMIN,
    ROLE_PASSENGER
} Role;

/*----------------------------------------------------
 * Booking Status
 *---------------------------------------------------*/
typedef enum
{
    BOOKING_CONFIRMED,
    BOOKING_CANCELLED
} BookingStatus;

/*----------------------------------------------------
 * Train Structure
 *---------------------------------------------------*/
typedef struct
{
    char train_no[7];
    char train_name[50];

    char source[30];
    char destination[30];

    char departure_time[6];
    char arrival_time[6];

    int total_seats;
    int available_seats;

    float fare;

} Train;

/*----------------------------------------------------
 * User Structure
 *---------------------------------------------------*/
typedef struct
{
    char user_id[10];

    char username[30];
    char password_hash[65];

    Role role;

} User;

/*----------------------------------------------------
 * Passenger Structure
 *---------------------------------------------------*/
typedef struct
{
    char user_id[10];

    char full_name[50];

    char contact_no[15];

    char email[50];

    int age;

    char gender[10];

} Passenger;

/*----------------------------------------------------
 * Booking Structure
 *---------------------------------------------------*/
typedef struct
{
    char pnr[20];

    char user_id[10];

    char train_no[7];

    int num_seats;

    char passenger_names[200];

    float total_fare;

    char booking_date[20];

    BookingStatus status;

} Booking;

/*----------------------------------------------------
 * Session Structure
 *---------------------------------------------------*/
typedef struct
{
    bool logged_in;

    Role role;

    char user_id[10];

    char username[30];

} Session;

#endif
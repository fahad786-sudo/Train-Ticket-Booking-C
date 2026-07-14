#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utilities.h"

/*----------------------------------------------------
 * Clear Screen
 *---------------------------------------------------*/
void util_clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*----------------------------------------------------
 * Pause
 *---------------------------------------------------*/
void util_pause(void)
{
    printf("\nPress ENTER to continue...");
    getchar();
}

/*----------------------------------------------------
 * Read Line
 *---------------------------------------------------*/
bool util_read_line(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL)
    {
        return false;
    }

    util_trim_newline(buffer);

    return true;
}

/*----------------------------------------------------
 * Remove Newline
 *---------------------------------------------------*/
void util_trim_newline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

/*----------------------------------------------------
 * Check Numeric
 *---------------------------------------------------*/
bool util_is_numeric(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return false;
        }

        str++;
    }

    return true;
}

/*----------------------------------------------------
 * Empty String
 *---------------------------------------------------*/
bool util_is_empty(const char *str)
{
    return strlen(str) == 0;
}

/*----------------------------------------------------
 * Print Header
 *---------------------------------------------------*/
void util_print_header(const char *title)
{
    printf("\n========================================\n");
    printf(" %s\n", title);
    printf("========================================\n");
}

/*----------------------------------------------------
 * Print Line
 *---------------------------------------------------*/
void util_print_line(void)
{
    printf("----------------------------------------\n");
}
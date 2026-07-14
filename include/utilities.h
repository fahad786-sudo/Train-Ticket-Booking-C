#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdbool.h>

/*----------------------------------------------------
 * Console Functions
 *---------------------------------------------------*/
void util_clear_screen(void);
void util_pause(void);

/*----------------------------------------------------
 * Input Functions
 *---------------------------------------------------*/
bool util_read_line(char *buffer, int size);
void util_trim_newline(char *str);

/*----------------------------------------------------
 * Validation Functions
 *---------------------------------------------------*/
bool util_is_numeric(const char *str);
bool util_is_empty(const char *str);

/*----------------------------------------------------
 * Display Functions
 *---------------------------------------------------*/
void util_print_header(const char *title);
void util_print_line(void);

#endif
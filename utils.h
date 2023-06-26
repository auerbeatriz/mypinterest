#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

/**
 * Save the index file
*/
void saveDataToFile(char* image_path, char* hist_path, char* locality_name, char* filepath);

void showMenu();
/**
 * Verify if a file alread has a certain data line
*/
bool isDataPresent(char* image_path, char* hist_path, char* locality_name, char* filepath);

#endif
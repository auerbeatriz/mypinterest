#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"

void saveDataToFile(char* image_path, char* hist_path, char* locality_name, char* filepath) {
    if (isDataPresent(image_path, hist_path, locality_name, filepath)) {
        return;
    }

    FILE* file = fopen(filepath, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filepath);
        return;
    }

    fprintf(file, "%s %s %s\n", image_path, hist_path, locality_name);
    fclose(file);
}

bool isDataPresent(char* image_path, char* hist_path, char* locality_name, char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filepath);
        return false;
    }

    char target[256];
    sprintf(target, "%s %s %s\n", image_path, hist_path, locality_name);

    char line[256];
    while(fgets(line, 256, file) != NULL) {
        if (strcmp(line, target) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;  // Dados não encontrados
}

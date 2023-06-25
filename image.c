#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "image.h"

struct image
{
    char path;
    int width, height, max_gray_level;
    unsigned char** content;
};

Image* readImage(char* fpath) {
    // verify if it is a PGM file
    char* file_extension = fpath + strlen(fpath) - 3; // points to the 3 last characters's position (file extension)
    if(strcmp(file_extension, "pgm") == 0) { 

        // if so, try to read the file
        FILE* pgm = fopen(fpath, "r"); 
        if(pgm) {

            // read and discart the unused line: "P2"
            char discard;
            fscanf(pgm, " %s", &discard);

            // load the image
            Image* image = _initializeImage(pgm);
            _readImageContent(image, pgm);
            
            fclose(pgm);
            return image;
        }
        else {
            printf("Não foi possível realizar a leitura do arquivo informado.\n");
        }

        fclose(pgm);
    }
    else {
        printf("Tipo de arquivo não suportado.\n");
    }

    return EMPTY_FLAG;
}

Image* _initializeImage(FILE* pgm) {
    Image* image = (Image*) malloc(sizeof(Image));
    fscanf(pgm, " %d %d\n %d\n", &image->width, &image->height, &image->max_gray_level);

    image->content = malloc(image->height * sizeof(unsigned char*));
    for (int i = 0; i < image->height; i++) {
        image->content[i] = (unsigned char*)malloc(image->width * sizeof(unsigned char));
    }

    return image;
}

void _readImageContent(Image* image, FILE* pgm) {
    for(int i = 0; i < image->height; i++) {
        for(int j=0; j < image->width; j++) {
            int valor;
            fscanf(pgm, "%hhu", &image->content[i][j]);
        }
    }
}

void saveHistogramToFile(int* histogram, const char* filepath) {
    FILE* file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filepath);
        return;
    }

    for (int i = 0; i <= 255; i++) {
        fprintf(file, "%d ", histogram[i]);
    }

    fclose(file);
}

void extractImageDescritor(Image* image) {
    // initialize a histogram vector of 255 positions
    int* histogram = malloc(256 * sizeof(int));
    for (int i = 0; i < 256; i++) {
        histogram[i] = 0;
    }
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int v = (int)image->content[i][j];
            histogram[v] = histogram[v] + 1;
        }
    }
    
    saveHistogramToFile(histogram, "histogram.txt");
}

void printhistogram(int* histogram){
    for(int i = 0; i <= 255; i++){
        printf("%d ", histogram[i]);
    }
}

void printImageContent(Image* img) {
    for(int i = 0; i < img->height; i ++) {
        for(int j = 0; j < img->width; j ++) {
            printf("%u ", img->content[i][j]);
        }
        printf("\n");
    }
}

void printImageDimenstions(Image* img) {
    printf("Dimensoes: %d %d\n", img->width, img->height);
}
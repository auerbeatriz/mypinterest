#include <stdlib.h>
#include <stdio.h>
#include "image.h"

struct image
{
    char path;
    int width, height, max_gray_level;
    unsigned char** content;
};

Image* readImage(char *fpath) {
    // verify if it is a PGM file
    char *file_extension = fpath + strlen(fpath) - 3; // points to the 3 last characters's position (file extension)
    if(strcmp(file_extension, "pgm") == 0) { 

        // if so, try to read the file
        FILE *pgm = fopen(fpath, "r"); 
        if(pgm) {

            // read and discart the unused line: "P2"
            fgets(file_extension, 3, pgm);  

            Image* image = (Image*)malloc(sizeof(Image));

            // read image dimensions
            fscanf(pgm, " %d %d\n %d\n", &image->width, &image->height, &image->max_gray_level);
            
            // read image content
            image->content = malloc(image->height * sizeof(unsigned char*));
            for (int i = 0; i < image->height; i++) {
                image->content[i] = malloc(image->width * sizeof(unsigned char));

                for(int j = 0; j < image->width; j++) {
                    fscanf(pgm, " %c", &image->content[i][j]);
                }
            }

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

void printImageContent(Image *img) {

    for(int i = 0; i < img->height; i ++) {
        for(int j = 0; j < img->width; j ++) {
            printf("%c ", img->content[i][j]);
        }
        printf("\n");
    }

}
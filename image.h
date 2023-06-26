#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#ifndef IMAGE_H
#define IMAGE_H

/**
 * PGM Image Structure:
 * int wight, height, max_gray_level
 * uc content (pixel matrix)
*/
typedef struct image Image;

/*
 * Read the content of a PGM file and return it as an Image
*/
Image* readImage(char* fpath);

void indexImageFromLocation(List* images, List* descriptors, char* location);

int getImageWidth(Image* image);
int getImageHeight(Image* image);
unsigned char** getImageContent(Image* image);

/*
 * Print the content of the image
*/
void printImageContent(Image* img);

void printImageDimenstions(Image* img);


/**PRIVATE FUNCTION */
void _readImageContent(Image* image, FILE* pgm);

/**PRIVATE FUNCTION */
Image* _initializeImage(FILE* pgm);

#endif
#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGE_H
#define IMAGE_H

#define EMPTY_FLAG -10000000

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

/*
 * Print the content of the image
*/
void printImageContent(Image* img);

/*
 * Print the dimensions of the image
*/
void printImageDimenstions(Image* img);

/**PRIVATE FUNCTIONS */
void _readImageContent(Image* image, FILE* pgm);
Image* _initializeImage(FILE* pgm);

#endif
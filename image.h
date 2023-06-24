#ifndef IMAGE_H
#define IMAGE_H

#define EMPTY_FLAG -10000000

/**
 * PGM Image Structure
*/
typedef struct image Image;

/*
 * It get the content of an image and save it returns in an Image type
*/
Image* readImage(char *fpath);


/*
 * Print the content of the image
*/
void printImageContent(Image *img);

#endif
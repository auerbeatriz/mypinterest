#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "image.h"

#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#define EMPTY_FLAG -10000000

/**
 * It has a histogram and a locality
*/
typedef struct descriptor Descriptor;

Descriptor* createDescriptor(char* location, char* image_path);
void extractImageDescritor(Image* image, Descriptor* descriptor);
void getDescriptorFromFile(Descriptor* descriptor, char* hist_path);
bool imageDescriptorExists(char* hist_path);
void saveHistogramToFile(Descriptor* descriptor, char* hist_path);
void printhistogram(Descriptor* descriptor);
void updateDescriptor(Descriptor* descriptor, int v);

#endif
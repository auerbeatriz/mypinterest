#ifndef LOCALITY_H
#define LOCALITY_H

typedef struct locality Locality;

/**
 * Creates and return a new empty Locality
 * A locality has a name and a list of images
*/
Locality* createLocality(char* name);

/**
 * Reads the PGM files of a given locality and loads them as Images on the images list
*/
void loadImages(Locality* locality);

/**
 * It can be used to get the name of a certain locality
 * Most used to debug the code
*/
char* getLocalityName(Locality* locality);

#endif
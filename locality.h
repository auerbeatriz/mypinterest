#ifndef LOCALITY_H
#define LOCALITY_H

typedef struct locality Locality;

Locality* createLocality(char* name);
void loadImages(Locality* locality);
char* getLocalityName(Locality* locality);

#endif
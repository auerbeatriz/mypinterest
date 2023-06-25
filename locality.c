#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "locality.h"

struct locality {
    char* name;
    List* images;
};

Locality* createLocality(char* name) {
    Locality* locality = (Locality*) malloc(sizeof(Locality));
    locality->name = name;
    locality->images = createList();

    return locality;
}

void loadImages(Locality* locality){
    // char sla[60] = "base/pgm/localityName/localityName (index).pgm";
    char image_path[60];

    int i = 1;
    while(i <= 10) {
        sprintf(image_path, "base/pgm/%s/%s (%d).pgm", locality->name, locality->name, i);

        Image* image = readImage(image_path);
        appendList(locality->images, image, IMAGE);

        i++;
    }
}


char* getLocalityName(Locality* locality) {
    return locality->name;
}

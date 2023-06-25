#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "locality.h"
#include "utils.h"

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
    char image_path[60];
    char hist_path[80];

    int i = 1;
    while(i <= 10) {
        sprintf(image_path, "base/pgm/%s/%s (%d).pgm", locality->name, locality->name, i); //joins strings to create the image path. source: chatgpt
        sprintf(hist_path, "base/histogram_extractor/%s/%s (%d).txt", locality->name, locality->name, i);

        Image* image = readImage(image_path);
        appendList(locality->images, image, IMAGE);

        extractImageDescritor(image);
        saveDataToFile(image_path, hist_path, locality->name, "base/histogram_extractor/index.txt");

        i++;
    }  

    printf("\n");
}


char* getLocalityName(Locality* locality) {
    return locality->name;
}

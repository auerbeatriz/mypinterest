#include <stdlib.h>
#include <stdio.h>

#include "image.h"
#include "list.h"

int main(void) {

    // ! Remove after testing
    char* path = "base/pgm/biblioteca/biblioteca (1).pgm";
    Image* image = readImage(path);
    printImageContent(image);

    printf("hello world");

    return 0;
}
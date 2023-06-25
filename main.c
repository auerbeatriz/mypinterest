#include <stdlib.h>
#include <stdio.h>
#include "image.c"


#include "list.h"

int main(void) {

    // ! Remove after testing
    char* path = "test.pgm";
    Image* image = readImage(path);
    printImageContent(image);

    return 0;
}
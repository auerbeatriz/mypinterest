#include "descriptor.h"

struct descriptor
{
    int* histogram;
    char* location;
    char* original_image_path;
};

Descriptor* createDescriptor(char* location, char* image_path) {
    Descriptor* descriptor = (Descriptor*) malloc(sizeof(Descriptor));

    descriptor->histogram = malloc(256 * sizeof(int));
    for (int i = 0; i < 256; i++) {
        descriptor->histogram[i] = 0;
    }

    descriptor->location = location;
    descriptor->original_image_path = image_path;

    return descriptor;
}

void extractImageDescritor(Image* image, Descriptor* descriptor) {

    int width = getImageWidth(image);
    int height = getImageHeight(image);
    unsigned char** content = getImageContent(image);

    int v;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            v = (int)content[i][j];
            updateDescriptor(descriptor, v);
        }
    }
}

void getDescriptorFromFile(Descriptor* descriptor, char* hist_path) {
    FILE* file = fopen(hist_path, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", hist_path);
        return;
    }

    int i = 0;
    unsigned char pixel;
    while(!feof(file)) {
        fscanf(file, "%hhu", &pixel);
        descriptor->histogram[i] = (int)pixel;
        i++;
    }
}

bool imageDescriptorExists(char* hist_path) {
    FILE* file = fopen(hist_path, "r");
    if (file == NULL)
        return false;

    // the descriptor image has already been processed
    fseek(file, 0, SEEK_END);
    return (ftell(file) != 0);
}

void updateDescriptor(Descriptor* descriptor, int v) {
    descriptor->histogram[v] = descriptor->histogram[v] + 1;
}

void saveHistogramToFile(Descriptor* descriptor, char* hist_path) {
    FILE* file = fopen(hist_path, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", hist_path);
        return;
    }

    for (int i = 0; i <= 255; i++) {
        fprintf(file, "%d ", descriptor->histogram[i]);
    }

    fclose(file);
}

void printhistogram(Descriptor* descriptor) {
    printf("%s\n", descriptor->location);
    for(int i = 0; i <= 255; i++){
        printf("%d ", descriptor->histogram[i]);
    }
    printf("\n");
}
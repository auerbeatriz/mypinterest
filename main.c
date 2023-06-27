#include <stdlib.h>
#include <stdio.h>  
#include <string.h>
#include <math.h>

#include "list.h"
#include "image.h"
#include "descriptor.h"
#include "utils.h"

void indexImageFromLocation(List* images, List* descriptors, char* location) {
    char image_path[60];
    char hist_path[80];

    int i = 1;
    while(i <= 10) {
        sprintf(image_path, "base/pgm/%s/%s (%d).pgm", location, location, i); //joins strings to create the image path. source: chatgpt
        sprintf(hist_path, "base/histogram_extractor/%s/%s (%d).txt", location, location, i);

        Image* image = readImage(image_path);
        appendList(images, image, IMAGE);

        Descriptor* descriptor = createDescriptor(location, image_path);
        if(imageDescriptorExists(hist_path)) {
            getDescriptorFromFile(descriptor, hist_path);
        }
        else {
            extractImageDescritor(image, descriptor);
            saveHistogramToFile(descriptor, hist_path);
            saveDataToFile(image_path, hist_path, location, "base/histogram_extractor/index.txt");
        }
        appendList(descriptors, descriptor, DESCRIPTOR);

        i++;
    }  
}

void indexImages(List* images, List* descriptors) {
    FILE* f = fopen("localities.txt", "r");
    if(f == NULL) {
        printf("Erro na leitura das localidades.\n");
        return;
    }

    char line[25];
    while(!feof(f)) {
        fgets(line, 25, f);
        char* location = strdup(line);
        location[strcspn(location, "\n")] = '\0'; // remove '\n' source: chatGPT

        indexImageFromLocation(images, descriptors, location);
    }
}

double euclidean_distance(int* hist1, int* hist2) {
    double distance = 0.0;
    for (int i = 0; i < 256; i++) {
        double diff = hist1[i] - hist2[i];
        distance += diff * diff;
    }
    return sqrt(distance);
}


void querysearch(Descriptor* queryDescriptor, List* otherDesc) {
    double distances[5];
    Descriptor** closest = malloc(5 * sizeof(Descriptor*));
    memset(closest, 0, 5 * sizeof(Descriptor*));
    // Initialize distances array with a large value
    for (int i = 0; i < 5; i++) {
        distances[i] = INFINITY;
    }

    int* histogramBase = getDescriptorHistogram(queryDescriptor);

    for(ListNode* p = getFirstElement(otherDesc); p != NULL; p = getNextListNode(p)) {
        Descriptor* descriptor = getDescriptorFromList(p);
        int* histogramComp = getDescriptorHistogram(descriptor);
        
        double distance = euclidean_distance(histogramBase, histogramComp);
        
        // TODO: COLOCAR EM UMA FUNÇÃO
        int i = 0;
        while (i < 5 && distance > distances[i]) {
            i++;
        }
        if( i < 5){
            distances[i] = distance;
            closest[i] = descriptor;

            int j = 4;
            while (j > i){
                distances[j] = distances[j-1];
                closest[j] = closest[j-1];
                j--;
            }
        }
    }

    printf("As top-5 localidades são:\n");
    for(int i=0; i < 5; i++) {
        Descriptor* descriptor = closest[i];
        char* location = getDescriptorLocation(descriptor);
        printf("%s\n", location);
    }
}

int main(void) {
    showMenu();

    List* descriptors = createList();
    List* images = createList();

    char input[100], inputCopy[100];
    scanf(" %99[^\n]", &input);

    while(strcmp(input, "quit") != 0) {
        strcpy(inputCopy, input);
        char* command = strtok(inputCopy, " ");

        if(strcmp(command, "query") == 0) {
            if(!isEmptyList(images) && !isEmptyList(descriptors)){
                char* location = strtok(NULL, " ");
                char* image_query_name = strtok(NULL, "");

                char image_query_path[100];
                sprintf(image_query_path, "query/pgm/%s", image_query_name);

                Image* image = readImage(image_query_path);
                Descriptor* descriptor = createDescriptor(location, image_query_path);
                extractImageDescritor(image, descriptor);

                querysearch(descriptor, descriptors);
            }
            else
                printf("Nenhuma imagem indexada.\n");
        }
        if(strcmp(command, "index") == 0) {
            printf("Indexando imagens, aguarde...\n");
            indexImages(images, descriptors);
            printf("Imagens indexadas com sucesso.\n");
        }

        printf("\n");
        scanf("  %99[^\n]", &input);         
    }

    freeList(images);
    freeList(descriptors);
    
    return 0;
}
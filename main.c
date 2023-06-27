#include <stdlib.h>
#include <stdio.h>  
#include <string.h>

#include "list.h"
#include "image.h"
#include "descriptor.h"
#include "utils.h"

void showMenu() {
    printf("╰☆╮✵٭ ✶ Ｍｙ Ｐｉｎｔｅｒｅｓｔ ✶ ٭✵╭★╯\n");
    printf("Para rodar o programa, liste um dos comandos abaixo:\n");
    printf("index [all | path]\n");
    printf("query [location] [image_name]\n");
    printf("quit\n\n");
    printf("Se estiver em dúvida do que cada comando executa, consulte a documentação.\n\n");
}

void indexImageFromLocation(List* images, List* descriptors, char* location) {
    char image_path[60];
    char hist_path[80];

    int i = 1;
    while(i <= 1) {
        sprintf(image_path, "base/pgm/%s/%s (%d).pgm", location, location, i); //joins strings to create the image path. source: chatgpt
        sprintf(hist_path, "base/histogram_extractor/%s/%s (%d).txt", location, location, i);

        Image* image = readImage(image_path);
        appendList(images, image, IMAGE);

        Descriptor* descriptor = createDescriptor(location, image_path);

        if(imageDescriptorExists(hist_path)) {
            getDescriptorFromFile(descriptor, hist_path);
        }
        else {
            printf("%s\n", location);
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

int main(void) {
    // to be called when command=index
    List* images = createList();
    List* descriptors = createList();
    indexImages(images, descriptors);

    // the program starts hehe!!!
    showMenu();

    char* input, command;
    printf("> ");
    scanf(" %s", &input);
    while(strcmp(input, "quit") == 0) {
        command = strtok(input, " ");

        if(strcmp(command, "query") == 0) {
            char* location = strtok(NULL, " ");
            char* image_query_name = strtok(NULL, "");

            printf("%s %s %s\n", command, location, image_query_name);

            // char* image_query_path[100];
            // sprintf(image_query_path, "query/%s", image_query_name);

            // Image* image = readImage(image_query_name);
            // Descriptor* descriptor = extractImageDescritor(image, location, image_query_path, )
        }

        printf("> ");
        scanf(" %s", &input);
    }

    // printf("Comando: ");
    // char query_path[100];
    // scanf(" %c", query_path);
    // query_path = "query "

    // List* images = loadImages();
    // List* descriptors = loadDescriptors();

    // TODO: free memory!
    // TODO: menu
    
    printf("End of program.");

    return 0;
}
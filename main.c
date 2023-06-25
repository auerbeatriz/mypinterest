#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "image.h"
#include "list.h"
#include "locality.h"

List* loadLocalities() {
    FILE* f = fopen("localities.txt", "r");

    if(f == NULL) {
        printf("Erro na leitura das localidades.\n");
        return NULL;
    }

    List* localities = createList();
    char line[25];
    while(!feof(f)) {
        fgets(line, 25, f);
        char* localityName = strdup(line);
        localityName[strcspn(localityName, "\n")] = '\0'; // remove '\n' source: chatGPT

        Locality* locality = createLocality(localityName);
        appendList(localities, locality, LOCALITY);
    }

    return localities;
}

int main(void) {
    List* localities = loadLocalities();
    execute(localities, loadImages);
    // TODO: free memory!

    printf("End of program.");

    return 0;
}
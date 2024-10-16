#include <stdio.h>
#include <stdlib.h>

/* Print an error and then exit. */
void fatal_error(char *error) {
    fprintf(stderr, "usage: dec <hex>\n");
    if (error == NULL) fprintf(stderr, "       Converts hex into decimal.\n");
    else fprintf(stderr, "%s\n", error);
    
    exit(1);
}

int main(int argc, char **argv) {
    unsigned long num;
    int i;
    char hex_str[20];

    /* Command line args. */
    
    if (argc == 1) fatal_error(NULL);
    
    /* Combined parsing and printing, depending on how many numbers we got. */
    
    if (argc == 2) {
        if (sscanf(argv[1], "%lx", &num) != 1) fatal_error("Bad hex.");
        
        printf("%lu\n", num);
    }
    else {
        for (i = 1; i < argc; i++) {
            if (sscanf(argv[i], "%lx", &num) != 1) fprintf(stderr, "Can't parse: %s\n", argv[i]);
            
            else {
                sprintf(hex_str, "0x%lx", num);
                printf("%10s = %lu\n", hex_str, num);
            }
        }
    }
    
    return 0;
}

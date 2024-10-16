#include <stdio.h>
#include <stdlib.h>

/* Print an error and then exit. */
void fatal_error(char *error) {
    fprintf(stderr, "usage: hex <dec>\n");
    if (error == NULL) fprintf(stderr, "       Converts decimal into hex.\n");
    else fprintf(stderr, "%s\n", error);
    
    exit(1);
}

int main(int argc, char **argv) {
    unsigned long num;
    int i;

    /* Command line args. */
    
    if (argc == 1) fatal_error(NULL);
    
    /* Combined parsing and printing, depending on how many numbers we got. */
    
    if (argc == 2) {
        if (sscanf(argv[1], "%ld", &num) != 1) fatal_error("Bad dec.");
        
        printf("0x%lx\n", num);
    }
    else {
        for (i = 1; i < argc; i++) {
            if (sscanf(argv[i], "%ld", &num) != 1) fprintf(stderr, "Can't parse: %s\n", argv[i]);
            else printf("%8ld = 0x%lx\n", num, num);
        }
    }
    
    return 0;
}

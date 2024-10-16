#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print an error and kill the program. */
void fatal_error(char *error) {
    fprintf(stderr, "usage: zeroseq <start> <end>\n");
    if (error == NULL) fprintf(stderr, "       Prints a sequence of numbers, padded with zeros.\n");
    else fprintf(stderr, "%s\n", error);
    
    exit(1);
}

int main(int argc, char **argv) {
    int start, end, size;
    int i;
    
    if (argc != 3) fatal_error(NULL);
    
    if (sscanf(argv[1], "%d", &start) != 1) fatal_error("Bad start.\n");
    if (sscanf(argv[2], "%d", &end) != 1) fatal_error("Bad end.\n");
    size = strlen(argv[2]);
    
    for (i = start; i <= end; i++) {
        printf("%0*d\n", size, i);
    }
    
    return 0;
}

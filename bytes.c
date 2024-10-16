#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *err) {
    fprintf(stderr, "usage: bytes <no. bytes> [string seq.] [-n (print newline at the end)]\n");
    if (err == NULL) fprintf(stderr, "       Prints bytes.\n");
    else fprintf(stderr, "%s\n", err);
    
    return;
}

int main(int argc, char **argv) {
    int i;
    int no_bytes, seq, str_len, nl, print_null;
    char *str;
    
    /* Command line parsing. */
    if (argc == 1 || argc > 4) { usage(NULL); exit(1); }
    if (argc >= 2) {
        if (argv[1][0] == '?') { usage(NULL); exit(1); }
        if (sscanf(argv[1], "%d", &no_bytes) != 1) { usage("Can't parse no. bytes"); exit(1); }
    }
    seq = (argc >= 3);
    nl = (argc == 4 && strcmp(argv[3], "-n") == 0) ? 1 : 0;
    
    /* Doin' it. */
    print_null = (strcmp(argv[2], "-0") == 0);
    str = (seq && !print_null) ? argv[2] : "\0";
    str_len = (seq && !print_null) ? strlen(str) : 1;
    
    for (i = 0; i < no_bytes; i++) {
        putchar(str[i % str_len]);
    }
    
    if (nl) printf("\n");
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
    fprintf(stderr, "usage: 2char <hex ...>\n");
    fprintf(stderr, "       Converts a number to its ASCII equivalent.\n");
    
    return;
}

int main(int argc, char **argv) {
    int n, i;
    char hex_str[20];
    
    if (argc == 1 || argv[1][0] == '?') { usage(); exit(1); }
    
    for (i = 1; i < argc; i++) {
        if (sscanf(argv[i], "%x", &n) != 1) {
            fprintf(stderr, "Couldn't parse %s.\n", argv[i]);
            continue;
        }
        
        snprintf(hex_str, 20, "0x%x", n);
        
        if (n < 0x20 || n > 0x7e) printf("%8s: not a printable char.\n", hex_str);
        else printf("%8s = \'%c\'\n", hex_str, (unsigned char) n);
    }
    
    return 0;
}

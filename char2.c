#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
    fprintf(stderr, "usage: char2 <chars ...>\n");
    fprintf(stderr, "       Converts ASCII chars to hex numbers.\n");
    
    return;
}

int main(int argc, char **argv) {
    int i, j, size;
    char char_str[20];
    
    if (argc == 1 || argv[1][0] == '?') { usage(); exit(1); }
    
    for (i = 1; i < argc; i++) {
        size = strlen(argv[i]);
        
        if (i != 1) printf("\n");
        
        for (j = 0; j < size; j++) {
            snprintf(char_str, 20, "\'%c\'", argv[i][j]);
            printf("%8s = 0x%x\n", char_str, argv[i][j]);
        }
    }
    
    return 0;
}

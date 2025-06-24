#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool print_file_contents(const string &filename) {
    FILE *f;
    string err_msg;
    int cur;

    f = fopen(filename.c_str(), "r");
    if (f == NULL) {
        err_msg = "Couldn't open ";
        err_msg += filename;
        perror(err_msg.c_str());

        return false;
    }

    while (1) {
        cur = fgetc(f);
        if (cur == EOF) {
            fclose(f);
            return true;
        }
        putchar(cur);
    }
}

void print_usage() {
    fprintf(stderr, "usage: lcat <file names ...>\n");
    fprintf(stderr, 
            "       Prints the contents of one or more files with a label for each file.\n");
}

int main(int argc, char **argv) {
    int i, ret_val, response;

    if (argc == 1 || strcmp(argv[1], "?") == 0) {
        print_usage();
        exit(1);
    }

    ret_val = 0;

    for (i = 1; i < argc; i++) {
        printf("\n\t~[ %s ]~\n\n", argv[i]); 
        response = print_file_contents(argv[i]);

        if (!response) ret_val = 1;
    }

    return ret_val;
}

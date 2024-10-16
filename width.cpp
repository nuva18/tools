#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
snprintf(buf, 200, "[%d] = %c\n", chars, current_char);
write(9, buf, strlen(buf));
*/

void usage(const string &s) {
    fprintf(stderr, "usage: width [width] -- text on stdin\n");
    if (s == "") fprintf(stderr, "       Constrains text to a width limit.\n");
    else fprintf(stderr, "%s\n", s.c_str());
}

int main(int argc, char **argv) {
    string word, tmp;
    char current_char;
    int chars, max_chars;
    bool all_one_word;
    
    /* Command line parsing. */
    
    if (argc > 2 || (argc == 2 && argv[1][0] == '?')) { usage(""); exit(1); }
    else if (argc == 2) {
        if (sscanf(argv[1], "%d", &max_chars) != 1) { usage("Bad width."); exit(1); }
        if (max_chars < 3) { usage("Width too small, should be >= 3."); exit(1); }
    }
    else max_chars = 80;
    
    /* Initialize & loop. */
    
    chars = 0;
    word = "";
    all_one_word = true;
    
    while (1) {
        current_char = getchar();
        chars++;
        
        if (current_char == EOF) exit(0);
        else if (current_char == '\n' || current_char == ' ') {
        
            /* If a single word is >= 80 characters, break it into 80 character chunklets. */
        
            if (all_one_word && (int) word.size() >= max_chars) {
                while ((int) word.size() >= max_chars) {
                    tmp = word.substr( 0, (max_chars - 1) );
                    cout << tmp << "-\n";
                    
                    tmp = '-' + word.substr( (max_chars - 1) );
                    word = tmp;
                }
            }
            
            /* Print out our word, and do some resetting. */
        
            cout << word;
            putchar(current_char);
            word = "";
            
            if (current_char == '\n') {
                chars = 0;
                all_one_word = true;
            }
            else all_one_word = false;
        }
        else {
        
            /* Otherwise, just add the character to the word, and print a newline when the line hits 80 characters. */
        
            word += current_char;
            
            if (chars >= max_chars && !all_one_word) {
                putchar('\n');
                chars = word.size();
                all_one_word = true;
            }
        }
    }
    
    return 0;
}

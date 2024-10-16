#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

/* Return a random integer using lrand48(), [1, max] */
int rand_int(int max) {    
    return (lrand48() % max) + 1;
}

/* Print an error, and then exit. */
void fatal_error(const string &error) {
    fprintf(stderr, "usage: roll [no-dice]d[no-sides] [print-total(y|n)]\n");
    if (error != "") fprintf(stderr, "%s\n", error.c_str());
    else fprintf(stderr, "       Simulates rolling dice.\n");
    
    exit(1);
}

int main(int argc, char **argv) {
    int no_dice, no_sides, total, current;
    int i;
    bool print_total;
    char *dice_ptr, *sides_ptr;
    string tmp;
    istringstream sin;
    
    /* Command line args. */
    
    /* no-dice and no-sides. */
    
    if (argc >= 2) {
        if (argv[1][0] == '?') fatal_error("");
        
        /* This is incredibly messy, but I'm tired and I can't think of a way to do this that 
           doesn't totally suck. */
        
        /* Find where the 'd' is, if it exists, and seperate the string into two. */
        
        dice_ptr = argv[1];
        for (i = 0; dice_ptr[i] != '\0' && dice_ptr[i] != 'd'; i++) ;
        
        if (dice_ptr[i] == 'd') {
            dice_ptr[i] = '\0';
            i++;
            sides_ptr = dice_ptr + i;
            
            /* Then we can just sscanf the two strings. */
            
            if (sscanf(sides_ptr, "%d", &no_sides) != 1) fatal_error("Bad no-sides.");
        }
        else no_sides = 6;
        
        if (sscanf(dice_ptr, "%d", &no_dice) != 1) no_dice = 1; /* Kind of a bandaid fix, cuz otherwise it'll error out on input like "d100", which is bad. */
    }
    else {
        no_dice = 1;
        no_sides = 6;
    }
    
    /* print-total. */
    
    if (argc == 3) {
        if (argv[2][0] != 'y' && argv[2][0] != 'Y' && argv[2][0] != 'n' && argv[2][0] != 'N') {
            fatal_error("Bad print-total; should be y or n.");
        }
    
        print_total = (argv[2][0] == 'y' || argv[2][0] == 'Y');
    }
    else print_total = true;
    
    
    /* Roll the dice. */
    
    srand48(time(NULL));
    total = 0;
    
    for (i = 0; i < no_dice; i++) {
        current = rand_int(no_sides);
        cout << current << endl;
        total += current;
    }
    
    if (print_total && no_dice > 1) cout << "Total: " << total << endl;
    
    return 0;
}

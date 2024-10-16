#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "haiku_bits.hpp"
using namespace std;

int main() {
    int first_index, third_index;
    
    srand48(time(NULL));
    
    /* Don't repeat lines. */
    
    first_index = lrand48() % five_syllables.size();
    do {
        third_index = lrand48() % five_syllables.size();
    }
    while (first_index == third_index);
    
    /* Print haiku. */
    
    cout << five_syllables[first_index] << endl;
    cout << seven_syllables[ lrand48() % seven_syllables.size() ] << endl;
    cout << five_syllables[third_index] << endl;
    
    return 0;
}

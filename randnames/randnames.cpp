#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include "names.hpp"
using namespace std;

/* Return a random element from a vector. */
string get_random_from_vector(const vector <string> &vec) {
    return vec[lrand48() % vec.size()];
}

/* Generate a name. */
string gen_name(char preferred_gender) {
    char actual_gender;
    string name;

    name = "";

    /* Set the actual gender. */

    if (preferred_gender == 'm' || preferred_gender == 'f') actual_gender = preferred_gender;
    else actual_gender = (lrand48() % 2 == 0) ? 'm' : 'f';

    /* First name. */

    if (actual_gender == 'm') name += get_random_from_vector(male_names);
    else name += get_random_from_vector(female_names);

    /* Middle name. */

    if (lrand48() % 5 == 0) {
        name += " ";
        if (actual_gender == 'm') name += get_random_from_vector(male_names);
        else name += get_random_from_vector(female_names);
    }

    /* Last name. */

    if (lrand48() % 99 != 0) {
        name += " ";

        if (lrand48() % 10 == 0) name += get_random_from_vector(last_prefixes);

        name += get_random_from_vector(last_names);
        if (lrand48() % 15 == 0) {
            name += "-";
            name += get_random_from_vector(last_names);
        }
        
        if (lrand48() % 10 == 0) {
			name += " ";
			if (actual_gender == 'm') name += get_random_from_vector(male_suffixes);
			else name += get_random_from_vector(female_suffixes);
		}
    }

    return name;
}

/* Print and error and kill the program. */
void fatal_error(const string &error) {
    fprintf(stderr, "usage: randnames [no-names] [gender (m|f|x)]\n");
    if (error == "") fprintf(stderr, "       Generates random names.\n");
    else fprintf(stderr, "%s\n", error.c_str());
    
    exit(1);
}

int main(int argc, char **argv) {
    unordered_set <string> used;
    string current_name;
    int i, no_names;
    char preferred_gender;

    srand48(time(NULL));

    no_names = 1;
    preferred_gender = 'x';

    /* Command line variables. 
       randnames no-names gender */
    
    if (argc >= 2) {
		if (argv[1][0] == '?') fatal_error("");
		if (sscanf(argv[1], "%d", &no_names) != 1) fatal_error("Bad no-names.");
	}
	else no_names = 1;
	
	if (argc == 3) preferred_gender = argv[2][0];
	else preferred_gender = 'x';
    
	/* Generate and print the names. */

    for (i = 0; i < no_names; i++) {
        do {
            current_name = gen_name(preferred_gender);
        }
        while (used.find(current_name) != used.end());

        cout << current_name << endl;
        used.insert(current_name);
    }

    return 0;
}

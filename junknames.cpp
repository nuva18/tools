#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/* Generate a name. */
string gen_name(int len) {
    string rv;
    string c, v, n;
    int i, no_c, no_n;
    
    c = "bcdfghjklmnpqrstvwxyz";
    v = "aeiou";
    n = "0123456789";
    rv = "";
    
    no_c = (lrand48() % len) + 1;
    if (no_c < (len * 0.75)) no_c = len * 0.75;
    no_n = len - no_c;
    
    for (i = 0; i < no_c; i++) {
        if (i % 2 == 0) rv += c[lrand48() % c.size()];
        else rv += v[lrand48() % v.size()];
    }
    
    for (i = 0; i < no_n; i++) rv += n[lrand48() % n.size()];
    
    return rv;
}

/* Print usage. */
void usage(const string &err) {
    fprintf(stderr, "usage: junknames [no] [len]\n");
    if (err == "") fprintf(stderr, "       Generates junk usernames.\n");
    else fprintf(stderr, "%s\n", err.c_str());
    
    return;
}

int main(int argc, char **argv) {
    int len, no, i;
    string name;
    unordered_set <string> used;
    
    len = 6;
    no = 1;
    
    if (argc != 1) {
        if (argc == 2 && argv[1][0] == '?') { usage(""); exit(1); }
        if (argc >= 2) if (sscanf(argv[1], "%d", &no) != 1) { usage("Bad number."); exit(1); }
        if (argc == 3) if (sscanf(argv[2], "%d", &len) != 1) { usage("Bad length."); exit(1); }
        if (argc > 3) { usage(""); exit(1); }
    }
    
    srand48(time(NULL));
    
    for (i = 0; i < no; i++) {
        do {
            name = gen_name(len);
        }
        while (used.find(name) != used.end());
        
        cout << name << endl;
        used.insert(name);
    }
    
    return 0;
}

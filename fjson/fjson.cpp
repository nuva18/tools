#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "json.hpp"
using namespace std;
using nlohmann::json;

int string_to_int(const string &s) {
    int response, n;

    response = sscanf(s.c_str(), "%d", &n);
    if (response != 1) return -1;
    return n;
}

void usage(const string &err) {
    fprintf(stderr, "usage: fjson [tab-width]\n");
    if (err == "") {
        fprintf(stderr, "       Format json files.\n");
        fprintf(stderr, "       0 for tab-width means don't serialize\n");
        
    }
    else fprintf(stderr, "%s\n", err.c_str());
} 

int main(int argc, char **argv) {
    json j;
    int tab_width;
    
    if (argc == 1) tab_width = 2;
    else if (argv[1][0] == '?' || argc > 2) {
        usage("");
        exit(1);
    } 
    else tab_width = string_to_int(argv[1]);

    if (tab_width < 0) {
        usage("Bad tab-width.");
        exit(1);
    }

    try {
        cin >> j;
    }
    catch (json::parse_error& e) {
        cerr << "Failed to parse input. " << endl;
        cerr << e.what() << endl;
        exit(1);
    }

    if (tab_width == 0) cout << j << endl;
    else cout << j.dump(tab_width) << endl; 
}


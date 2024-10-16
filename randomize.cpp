#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main() {
    map <double, string> lines;
    map <double, string>::const_iterator lit;
    string line;
    
    srand48(time(NULL));
    
    while (getline(cin, line)) lines.insert(make_pair(drand48(), line));
    
    for (lit = lines.begin(); lit != lines.end(); lit++) {
        cout << lit->second << endl;
    }
    
    return 0;
}

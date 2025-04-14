#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    string label, sides;
    int side_size;

    label = "80  characters";
    side_size = (80 - label.size() - 2) / 2;
    sides.resize(side_size, '=');

    printf("%s %s %s\n", sides.c_str(), label.c_str(), sides.c_str());
}

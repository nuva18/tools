#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "json.hpp"
using namespace std;
using nlohmann::json;

int main() {
    json j;
    cin >> j;
    cout << j.dump(2) << endl; 
}


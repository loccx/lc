#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printMap(const map<int, int>& map) {
    for (auto &m : map) {
        cout << m.first << " " << m.second << '\n';
    }
    cout << '\n';
}

void printMap2(map<int, int>& map) {
    for (auto &m : map) {
        map[m.first] = 0; // becuase we are doing pass by referrence and not copy, modifying the map in this function will modify the original map. when the function pops off, there was no copy of a stack to be popped off, because we are modifying the original map.
        cout << m.first << " " << m.second << '\n';
    }
    cout << '\n';
}

int main() {
    map<int, int> t1;
    printMap(t1);

    t1[4] = 3;
    printMap(t1);
    if (t1[5]) printMap(t1); // if key does not exist when you try to access it, then it actually instantiates the pair: key : value with value defaulted to 0 or 0 equivalent
    cout << t1.at(5) << '\n'; // now if i access 5, it will return 0
    //cout << t1.at(2) << '\n'; // returns key error if key not found, unlike regular bracket access.
    printMap(t1);
    
    printMap2(t1);
    printMap(t1);
}


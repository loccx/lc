#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> poop;
    poop[5] = 3;
    poop[2] = 7;
    poop[1] = 9;

    cout << poop.at(0) << '\n';
}

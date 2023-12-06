#include <iostream>

using namespace std;

int main() {
    for (long long x = 2222222222222222222; x >= 2; x /= 10) {
        cout << x << ":\n";
        cout << x % 5 << '\n';
    }
}

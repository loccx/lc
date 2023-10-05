#include <iostream>

using namespace std;

void sieve(int n) {
    if (n == 0 || n == 1 || n == 2) {
        cout << "There are no primes strictly less than the inputted number.\n";
        return;
    }

    vector<bool> p(n - 2);

    int iter = 0;
    int primeiter = iter;
    int pSize = int(p.size());

    /*
     *
     * [T, F, F, F, F, F, F, F]
     * #2, 3, 4, 5, 6, 7, 8, 9
     * i0, 1, 2, 3, 4, 5, 6, 7
     *
     */

    while (iter < pSize) {
        if (!p[iter]) {
            cout << iter + 2 << " ";
            primeiter = iter;
            while (primeiter < pSize) {
                if (!p[primeiter]) p[primeiter] = true;
                primeiter += (iter + 2);
            }
        }
        iter++;
    }
    cout << '\n';
    return;
}

int main() {
    int n;
    cout << "Enter N:\n";
    cin >> n;

    sieve(n);

    return 0;
}

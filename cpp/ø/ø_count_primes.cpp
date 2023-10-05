#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2) return 0;
        vector<bool> p(n - 2);

        int iter = 0;
        int pSize = int(p.size());
        int pIter;
        int primeCount = 0;
        while (iter < pSize) {
            if (!p[iter]) {
                primeCount++;
                pIter = iter;
                while (pIter < pSize) {
                    if (!p[pIter]) p[pIter] = true;
                    pIter += (iter + 2);
                }
            }
            iter++;
        }

        return primeCount;
    }
};

int main() {
    int k;
    cout << "enter number to count:\n";
    cin >> k;

    Solution test;
    int res = test.countPrimes(k);
    cout << "# of primes: " << res << '\n';
    return 0;
}

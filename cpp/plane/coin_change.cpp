#include <iostream>
#include <limits.h>

using namespace std;

/*
int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int k = 1; k < amount + 1; k++) {
        dp[k] = INT_MAX;
        for (auto coin : coins) {
            if (k - coin < 0) continue;
            if (dp[k - coin] != INT_MAX) dp[k] = min(dp[k], dp[k - coin] + 1);
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}
*/

void print_vec(const vector<int>& vec) {
    for (auto v : vec) cout << v << " ";
    cout << '\n';
}

int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int k = 1; k < amount + 1; k++) {
        dp[k] = INT_MAX;
        for (auto c : coins) {
            if (k == c) dp[k] = 1;
            if (k - c > 0 && dp[k-c] != INT_MAX) {
                dp[k] = min(dp[k-c] + 1, dp[k]);
            }
        }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 113;
    // 22 5's, 1 2, 1 1, total 24 coins

    int minCoins = coinChange(coins, amount);
    cout << minCoins << '\n';
}

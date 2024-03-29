#include <iostream>
#include <limits.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int dp[amount+1];
    dp[0] = 0;

    for(int k=1;k<amount+1;k++){
        dp[k] = INT_MAX;
        for(auto c : coins){
            if (k-c>=0 && dp[k-c] != INT_MAX){
                dp[k] = min(dp[k], dp[k-c]+1);
            }
        }
    }

    return dp[amount]==INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 12;

    int minCoins = coinChange(coins, amount);
    cout << minCoins << '\n';
}

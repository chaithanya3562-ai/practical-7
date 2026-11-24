
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;
    int coins[100];
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter amount: ";
    cin >> amount;
    int dp[10000];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {

            if (coins[j] <= i &&
                dp[i - coins[j]] != INT_MAX) {

                int cost = dp[i - coins[j]] + 1;

                if (cost < dp[i]) {
                    dp[i] = cost;
                }
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        cout << "Change cannot be made";
    } else {
        cout << "Minimum coins required: "
             << dp[amount];
    }

    return 0;
}

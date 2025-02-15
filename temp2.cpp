#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
const int MOD = 998244353; // Modular arithmetic base
const int MAX = 1 << 20;   // Maximum size for arrays (2^20)

int64 n;                   // Number of elements in the array
int64 a[MAX];              // Input array
int64 primeIndicator[MAX]; // Array to indicate mobius function (-1, 0, 1)
int64 dp[MAX];             // Array to store dynamic programming results
int64 divisorSum[MAX];     // Array to store divisor-related sums
vector<int64> divisors[MAX]; // Precomputed divisors for each number

int main() {
    // Initialize arrays
    fill(primeIndicator, primeIndicator + MAX, 1); // Start with all values as "prime-like"
    dp[0] = 1; // Base case: the first element has one way

    // Read input size
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the input array
    }

    // Precompute divisors and mobius-like function values
    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divisors[j].push_back(i); // Store divisor `i` for number `j`
            if (j == i) {
                primeIndicator[j] = -primeIndicator[j]; // Toggle mobius value for prime
            } else {
                primeIndicator[j] -= primeIndicator[i]; // Adjust composite values
            }
        }
    }

    // Dynamic programming calculation
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            // Update dp[i] using contributions from previous states
            for (int64 div : divisors[a[i]]) {
                dp[i] = (dp[i] + primeIndicator[div] * divisorSum[div]) % MOD;
            }
        }
        // Update the divisor sums with the current dp value
        for (int64 div : divisors[a[i]]) {
            divisorSum[div] = (divisorSum[div] + dp[i]) % MOD;
        }
    }

    // Output the result for the last element
    cout << (dp[n - 1] + MOD) % MOD; // Ensure non-negative result
    return 0;
}

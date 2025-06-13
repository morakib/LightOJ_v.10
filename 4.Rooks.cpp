#include<bits/stdc++.h>
using namespace std;

// Memoization table for nCr calculations
long long dp[35][35];

// Function to calculate nCr (n choose r) using dynamic programming
long long nCr(int n, int r) {
    // Base cases
    if (n == r || r == 0) return 1;
    if (r == 1) return n;
    
    // If already calculated, return stored value
    if (dp[n][r] != -1) return dp[n][r];
    
    // Recursive formula: nCr = (n-1)Cr + (n-1)C(r-1)
    dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
    return dp[n][r];
}

int main() {
    // Initialize memoization table
    memset(dp, -1, sizeof(dp));
    
    // Precompute factorials up to 20
    long long fact[21];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 20; i++) {
        fact[i] = i * fact[i-1];
    }
    
    int test_cases;
    cin >> test_cases;
    
    for (int case_num = 1; case_num <= test_cases; case_num++) {
        int n, k;
        cin >> n >> k;
        
        long long result = 0;
        
        // If we have more rooks than board size, impossible
        if (k <= n) {
            // Formula: (nCk)^2 * k!
            long long combination = nCr(n, k);
            result = combination * combination * fact[k];
        }
        
        cout << "Case " << case_num << ": " << result << endl;
    }
    
    return 0;
}

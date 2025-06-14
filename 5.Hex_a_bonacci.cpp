#include <iostream>
using namespace std;
// Step 1: Understanding what we need
// - 6 starting numbers: a, b, c, d, e, f
// - Position n that we want to find
// - Each new number = sum of previous 6 numbers
// - Answer should be % 10000007 to avoid big numbers

const int MOD = 10000007; // This keeps our numbers small

// Step 2: Simple function to calculate hex-a-bonacci
long long hexabonacci(int a, int b, int c, int d, int e, int f, int n) {
    
    // Step 3: Handle easy cases first (positions 0-5)
    if (n == 0) return a % MOD;  // Position 0 is just 'a'
    if (n == 1) return b % MOD;  // Position 1 is just 'b'
    if (n == 2) return c % MOD;  // Position 2 is just 'c'
    if (n == 3) return d % MOD;  // Position 3 is just 'd'
    if (n == 4) return e % MOD;  // Position 4 is just 'e'
    if (n == 5) return f % MOD;  // Position 5 is just 'f'
    
    // Step 4: For position 6 and beyond, we need to calculate
    // We use "rolling array" - keep only last 6 numbers in memory
    
    long long last6[6];  // Array to store last 6 numbers
    last6[0] = a % MOD;  // Store a
    last6[1] = b % MOD;  // Store b  
    last6[2] = c % MOD;  // Store c
    last6[3] = d % MOD;  // Store d
    last6[4] = e % MOD;  // Store e
    last6[5] = f % MOD;  // Store f
    
    // Step 5: Calculate from position 6 to position n
    for (int i = 6; i <= n; i++) {
        
        // Add all 6 previous numbers
        long long sum = 0;
        for (int j = 0; j < 6; j++) {
            sum = (sum + last6[j]) % MOD;  // Add each number, keep small with %
        }
        
        // Step 6: Slide the window (move all numbers left, put new sum at end)
        // Before: [a][b][c][d][e][f]
        // After:  [b][c][d][e][f][sum]
        
        for (int j = 0; j < 5; j++) {
            last6[j] = last6[j + 1];  // Move each number one position left
        }
        last6[5] = sum;  // Put new sum at the end
    }
    
    // Step 7: Return the answer (it's in last position of our array)
    return last6[5];
}

// Step 8: Main function to handle input/output
int main() {
    int t;  // Number of test cases
    cin >> t;
    
    // Process each test case
    for (int caseno = 1; caseno <= t; caseno++) {
        int a, b, c, d, e, f, n;
        cin >> a >> b >> c >> d >> e >> f >> n;  // Read the 6 starting numbers and position
        
        long long result = hexabonacci(a, b, c, d, e, f, n);  // Calculate answer
        cout << "Case " << caseno << ": " << result << endl;   // Print result
    }
    
    return 0;
}

/*
Let's trace through an example:
Input: a=0, b=1, c=2, d=3, e=4, f=5, n=7

Step-by-step execution:
1. n=7, so we need to calculate (not a base case)
2. last6 = [0, 1, 2, 3, 4, 5]

3. i=6: sum = 0+1+2+3+4+5 = 15
   last6 becomes [1, 2, 3, 4, 5, 15]

4. i=7: sum = 1+2+3+4+5+15 = 30
   last6 becomes [2, 3, 4, 5, 15, 30]

5. Return last6[5] = 30

That's our answer for position 7!
*/

// Even simpler version for understanding:
/*
int hexabonacci_simple(int a, int b, int c, int d, int e, int f, int n) {
    // If asking for one of the first 6 positions, just return it
    if (n <= 5) {
        int start[6] = {a, b, c, d, e, f};
        return start[n] % MOD;
    }
    
    // Otherwise, calculate step by step
    int window[6] = {a%MOD, b%MOD, c%MOD, d%MOD, e%MOD, f%MOD};
    
    for (int pos = 6; pos <= n; pos++) {
        // Add all 6 numbers
        int newNum = 0;
        for (int i = 0; i < 6; i++) {
            newNum = (newNum + window[i]) % MOD;
        }
        
        // Slide window: remove first, add new at end
        for (int i = 0; i < 5; i++) {
            window[i] = window[i+1];
        }
        window[5] = newNum;
    }
    
    return window[5];
}
*/

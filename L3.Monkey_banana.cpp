#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int case_num = 1; case_num <= t; case_num++) {
        int n;
        cin >> n;
        
        // Read the diamond-shaped pyramid
        vector<vector<int>> diamond(2 * n - 1);
        
        // Read top half (expanding part) - rows 0 to n-1
        for (int i = 0; i < n; i++) {
            diamond[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                cin >> diamond[i][j];
            }
        }
        
        // Read bottom half (shrinking part) - rows n to 2n-2
        for (int i = n; i < 2 * n - 1; i++) {
            diamond[i].resize(2 * n - 1 - i);
            for (int j = 0; j < 2 * n - 1 - i; j++) {
                cin >> diamond[i][j];
            }
        }
        
        // DP array - same structure as diamond
        vector<vector<int>> dp(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            dp[i].resize(diamond[i].size());
        }
        
        // Initialize first row (top of diamond)
        dp[0][0] = diamond[0][0];
        
        // Fill the expanding part (top half)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = diamond[i][j];
                int max_from_above = 0;
                
                // Can come from (i-1, j-1) if j > 0
                if (j > 0 && j - 1 < dp[i-1].size()) {
                    max_from_above = max(max_from_above, dp[i-1][j-1]);
                }
                
                // Can come from (i-1, j) if j < dp[i-1].size()
                if (j < dp[i-1].size()) {
                    max_from_above = max(max_from_above, dp[i-1][j]);
                }
                
                dp[i][j] += max_from_above;
            }
        }
        
        // Fill the shrinking part (bottom half)
        for (int i = n; i < 2 * n - 1; i++) {
            for (int j = 0; j < diamond[i].size(); j++) {
                dp[i][j] = diamond[i][j];
                int max_from_above = 0;
                
                // Can come from (i-1, j)
                if (j < dp[i-1].size()) {
                    max_from_above = max(max_from_above, dp[i-1][j]);
                }
                
                // Can come from (i-1, j+1)
                if (j + 1 < dp[i-1].size()) {
                    max_from_above = max(max_from_above, dp[i-1][j+1]);
                }
                
                dp[i][j] += max_from_above;
            }
        }
        
        // Answer is at the bottom point of diamond
        cout << "Case " << case_num << ": " << dp[2*n-2][0] << endl;
    }
    
    return 0;
}

/*
DIAMOND SHAPE EXPLANATION:

For n=4, the shape looks like:
Row 0:     [X]           (1 element)
Row 1:    [X][X]         (2 elements)  
Row 2:   [X][X][X]       (3 elements)
Row 3:  [X][X][X][X]     (4 elements) <- WIDEST
Row 4:   [X][X][X]       (3 elements)
Row 5:    [X][X]         (2 elements)
Row 6:     [X]           (1 element)

MOVEMENT RULES:
- Top half: go diagonally down-left or down-right
- Bottom half: go diagonally down-left or down-right (but array shrinks)

KEY INSIGHT: 
- Path must go from top point to bottom point
- Always moving downward
- Collect maximum bananas along the way
*/

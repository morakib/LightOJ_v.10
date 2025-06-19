#include<bits/stdc++.h>
using namespace std;

int cost[16][16];
int dp[16][(1<<16)];

int solve(int i, int mask, int& n)
{
    if(i == n)
        return 0;

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int answer = INT_MIN;
    for(int j = 0; j < n; j++)
    {
        if(mask&(1<<j))
            answer = max(answer, cost[j][i] + solve(i+1, (mask^(1<<j)), n));
    }

    return dp[i][mask] = answer;
}

int main() {
    int t,n,m,x,i,j,k,q;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        cin >> n;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> cost[i][j];
        }
        cout<< "Case " << tc << ": ";
        cout << solve(0, (1<<n) - 1, n) << '\n';
   }

   return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000;
unsigned int phi[MAXN + 1];             //✅ unsigned int (4 bytes) is safe and efficient for storing φ(i) for all i ≤ 5,000,000.
unsigned long long score_sum[MAXN + 1]; //✅ So unsigned long long (8 bytes) is necessary here to avoid overflow and store large sums.

///This is an efficient algorithm to compute Euler's Totient Function φ(n) for all integers n from 1 to MAXN, using a modified Sieve of Eratosthenes.
// Euler’s Totient Function φ(n) counts how many integers from 1 to n are coprime with n.
void compute_phi_and_scores() {
    for (int i = 0; i <= MAXN; i++) phi[i] = i;

    for (int i = 2; i <= MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAXN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    for (int i = 2; i <= MAXN; i++) {
        unsigned long long score = 1ULL * phi[i] * phi[i];
        score_sum[i] = score_sum[i - 1] + score;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    compute_phi_and_scores();

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << case_num << ": " << score_sum[b] - score_sum[a - 1] << '\n';
    }

    return 0;
}

// Array	      Type	             Size (elements)	  Size (bytes)
// phi[]	    unsigned int	          5,000,001	       ≈ 20 MB
// score_sum[]	unsigned long long	   5,000,001	       ≈ 40 MB
// Total		                                          	≈ 60 MB

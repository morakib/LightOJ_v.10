#include <iostream>
using namespace std;

long long maxKnights(long long n, long long m) {
    if (n == 1 || m == 1) {
        return n * m;
    }
    else if (n == 2 || m == 2) {
        long long side = max(n, m);
        long long result = (side / 4) * 4;
        long long rem = side % 4;
        if (rem == 1) result += 2;
        else if (rem > 1) result += 4;
        return result;
    }
    else {
        return (n * m + 1) / 2;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long n, m;
        cin >> n >> m;
        cout << "Case " << i << ": " << maxKnights(n, m) << endl;
    }
}

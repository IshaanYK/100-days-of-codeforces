#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int min_val = 1e9, max_val = -1e9;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        min_val = min(min_val, val);
        max_val = max(max_val, val);
    }
    cout << (max_val - min_val + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (w == 0) c0++;
        else if (w == 1) c1++;
        else if (w == 2) c2++;
    }
    int pairs = min(c1, c2);
    int ans = c0 + pairs + (c1 - pairs) / 3 + (c2 - pairs) / 3;
    cout << ans << "\n";
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

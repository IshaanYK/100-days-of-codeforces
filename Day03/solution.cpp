#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        long long ans = 0;
        int mn = INT_MAX;
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
 
            mn = min(mn, x); // smallest tower seen so far
            ans += mn;       // add that minimum
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}

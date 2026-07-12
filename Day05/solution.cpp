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
 
        int mx = 0, mn = 100;
 
        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            mx = max(mx, h);
            mn = min(mn, h);
        }
 
        cout << mx - mn + 1 << '\n';
    }
 
    return 0;
}

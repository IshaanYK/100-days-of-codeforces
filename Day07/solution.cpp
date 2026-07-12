#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
 
        sort(a.begin(), a.end(), greater<ll>());
 
        bool ok = true;
 
        for (int i = 0; i + 2 < n; i++) {
            if (a[i + 1] == 0 || a[i] % a[i + 1] != a[i + 2]) {
                ok = false;
                break;
            }
        }
 
        if (ok)
            cout << a[0] << " " << a[1] << '\n';
        else
            cout << -1 << '\n';
    }
 
    return 0;
}

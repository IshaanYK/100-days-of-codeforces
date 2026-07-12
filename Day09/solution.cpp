#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        int n;
        cin >> n;
 
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
 
        sort(a.begin(), a.end());
 
        int ans = n;
 
        // Check every existing value
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
 
            int left = i;
            int right = n - j;
            ans = min(ans, max(left, right));
 
            i = j;
        }
 
        // Check every gap between consecutive distinct values
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) continue;
 
            int left = i;
            int right = n - i;
            ans = min(ans, max(left, right));
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        for (int i = 0; i < n; i++) 
            cin >> b[i];

        long long sum = 0;
        long long best = 0;

        for (int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
            best = max(best, min(a[i], b[i]));
        }
        cout << sum + best << '\n';
    }
    return 0;
}

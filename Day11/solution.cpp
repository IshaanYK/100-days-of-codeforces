#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
 
        // If buying 3 individual keys is cheaper or equal,
        // never buy a group key.
        if (3 * a <= b) {
            cout << n * a << "\n";
            continue;
        }
 
        long long groups = n / 3;
        long long rem = n % 3;
 
        long long ans = groups * b;
 
        if (rem == 1)
            ans += min(a, b);
        else if (rem == 2)
            ans += min(2 * a, b);
 
        cout << ans << "\n";
    }
 
    return 0;
}

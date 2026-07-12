#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;
 
        // Option 1: No AI
        long long noAI = (n + (x + y) - 1) / (x + y);
 
        // Option 2: Use AI
        long long withAI;
 
        if (x * z >= n) {
            withAI = (n + x - 1) / x;
        } else {
            long long remaining = n - x * z;
            long long extra = (remaining + (x + 10 * y) - 1) / (x + 10 * y);
            withAI = z + extra;
        }
 
        cout << min(noAI, withAI) << '\n';
    }
 
    return 0;
}

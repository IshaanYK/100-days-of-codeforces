#include <algorithm>
#include <iostream>
 
using namespace std;
using int64 = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int64 n, k;
        cin >> n >> k;
        int64 active = min(n, k);
        int64 answer = active;
        n -= active;
 
        int64 cost = 2;
        while (active > 0 && n / cost > 0) {
            int64 take = min(active, n / cost);
            answer += take;
            n -= take * cost;
            active = take;
            cost *= 2;
        }
        cout << answer << '\n';
    }
    return 0;
}

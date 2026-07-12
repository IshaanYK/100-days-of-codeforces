# Day 01: Another Popcount Problem\n\n- **Rating**: 800\n- **Time Complexity**: $O(log N) per test case$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nGiven N and K, we want to perform operations where the first min(N, K) operations cost 1 each, and subsequent operations double in cost. We want to maximize the number of operations we can perform.\n\n## ⚙️ Approach\nWe greedily take the maximum operations of cost 1, then double the cost and take as many as possible (limited by the number of operations in the previous step) with the remaining N, and repeat.\n\n## 💻 C++ Solution\n```cpp\n#include <algorithm>
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
}\n```\n
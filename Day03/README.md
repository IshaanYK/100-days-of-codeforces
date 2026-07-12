# Day 03: Destroying Towers\n\n- **Rating**: 800\n- **Time Complexity**: $O(N) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nWe want to find the sum of the minimum tower heights seen so far as we iterate through the prefix of tower heights.\n\n## ⚙️ Approach\nIterate through the tower heights, maintain a running minimum of the tower height, and add this minimum to the total answer at each step.\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
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
}\n```\n
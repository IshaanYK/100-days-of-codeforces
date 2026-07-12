# Day 05: Games on the Train\n\n- **Rating**: 800\n- **Time Complexity**: $O(N) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nFind the difference between the maximum and minimum heights of the stations plus 1, representing the span of heights visited.\n\n## ⚙️ Approach\nIterate through the heights, keeping track of the maximum and minimum height values. Output (max - min + 1).\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
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
}\n```\n
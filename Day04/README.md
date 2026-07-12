# Day 04: Tatar TV Show\n\n- **Rating**: 800\n- **Time Complexity**: $O(N) per testcase$\n- **Space Complexity**: $O(N) to store the binary string$\n\n## 💡 Explanation\nWe are given a binary string of length N and an integer K. We need to check if the parity of '1's at every index modulo K is even.\n\n## ⚙️ Approach\nGroup the indices of the string by their remainder modulo K. For each group (0 to K-1), count the number of '1's. If any remainder group has an odd number of '1's, return NO. Otherwise, return YES.\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, k;
        cin >> n >> k;
 
        string s;
        cin >> s;
 
        bool ok = true;
 
        for (int r = 0; r < k && ok; r++) {
            int cnt = 0;
            for (int i = r; i < n; i += k) {
                if (s[i] == '1') cnt++;
            }
            if (cnt % 2) ok = false;
        }
 
        cout << (ok ? "YES" : "NO") << '\n';
    }
 
    return 0;
}\n```\n
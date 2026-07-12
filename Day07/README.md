# Day 07: Euclid, Sequence and Two Numbers\n\n- **Rating**: 800\n- **Time Complexity**: $O(N log N) per testcase due to sorting$\n- **Space Complexity**: $O(N) to store the sequence$\n\n## 💡 Explanation\nCheck if the descending sorted array satisfies a sequence where a[i] % a[i+1] == a[i+2] for all i. If so, return a[0] and a[1].\n\n## ⚙️ Approach\nSort the array in descending order, check if each element is the remainder of the division of the two preceding elements. If the property holds, output a[0] and a[1], otherwise output -1.\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
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
}\n```\n
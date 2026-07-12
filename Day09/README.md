# Day 09: Convergence\n\n- **Rating**: 800\n- **Time Complexity**: $O(N log N) per testcase due to sorting$\n- **Space Complexity**: $O(N) to store the array$\n\n## 💡 Explanation\nFind a value V to minimize max(count of elements < V, count of elements > V).\n\n## ⚙️ Approach\nSort the array. Iterate through unique elements and calculate the maximum of the elements to its left and right. Also check values between adjacent distinct elements.\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
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
}\n```\n
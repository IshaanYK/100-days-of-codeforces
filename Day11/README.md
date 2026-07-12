# Day 11: Optimal Purchase\n\n- **Rating**: 800\n- **Time Complexity**: $O(1) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nFind the minimum cost to buy N keys, either individually for cost a, or in groups of 3 for cost b.\n\n## ⚙️ Approach\nIf 3*a <= b, buy all individually. Otherwise, buy as many groups of 3 as possible, and handle the remainder (1 or 2 keys) using the cheaper combination.\n\n## 💻 C++ Solution\n```cpp\n#include <iostream>
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
}\n```\n
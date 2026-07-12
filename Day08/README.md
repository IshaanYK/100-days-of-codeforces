# Day 08: AI Project Development\n\n- **Rating**: 800\n- **Time Complexity**: $O(1) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nCompare the cost of completing N tasks using Option 1 (No AI, (x+y) tasks/step) vs Option 2 (Use AI, x tasks/step for Z steps, then x+10y tasks/step).\n\n## ⚙️ Approach\nCalculate noAI = ceil(N / (x+y)). Calculate withAI: if x * Z >= N, ceil(N / x); else, Z + ceil((N - x*Z) / (x + 10y)). Print min(noAI, withAI).\n\n## 💻 C++ Solution\n```cpp\n#include <iostream>
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
}\n```\n
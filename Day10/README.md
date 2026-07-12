# Day 10: Construct an Array\n\n- **Rating**: 800\n- **Time Complexity**: $O(N) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nPrint N odd numbers starting from 1.\n\n## ⚙️ Approach\nOutput 2*i - 1 for i from 1 to N.\n\n## 💻 C++ Solution\n```cpp\n#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        for (int i = 1; i <= 2 * n; i += 2)
            cout << i << " ";
 
        cout << '\n';
    }
 
    return 0;
}\n```\n
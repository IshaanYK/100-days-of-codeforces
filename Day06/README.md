# Day 06: Palindrome, Twelve and Two Terms\n\n- **Rating**: 800\n- **Time Complexity**: $O(1) per testcase$\n- **Space Complexity**: $O(1) auxiliary space$\n\n## 💡 Explanation\nGiven N, split it into two non-negative terms that sum to N and satisfy certain modulo 12 properties.\n\n## ⚙️ Approach\nIf N is 10, it's impossible (output -1). If N % 12 == 10, output 22 and N-22. Otherwise, output N % 12 and N - (N % 12).\n\n## 💻 C++ Solution\n```cpp\n#include <iostream>
using namespace std;
 
using int64 = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int64 n;
        cin >> n;
 
        if (n == 10) {
            cout << -1 << '\n';
        } else if (n % 12 == 10) {
            cout << 22 << " " << n - 22 << '\n';
        } else {
            cout << n % 12 << " " << n - (n % 12) << '\n';
        }
    }
 
    return 0;
}\n```\n
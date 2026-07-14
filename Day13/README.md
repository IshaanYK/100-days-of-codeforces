# Day 13: Slimes on a Line

- **Rating**: 800
- **Time Complexity**: $O(N)$ per testcase
- **Space Complexity**: $O(1)$ auxiliary space

## 💡 Explanation
We are given the initial positions of $N$ slimes on a line. In each operation, we can choose an integer $x$. Slimes to the left of $x$ move 1 unit right, slimes to the right of $x$ move 1 unit left, and slimes at $x$ do not move. We want to find the minimum number of operations to make all slimes occupy the same position.

## ⚙️ Approach
1. **Range Reduction**:
   Let the minimum coordinate of any slime be $L$ and the maximum coordinate be $R$. The current range span of all slimes is $R - L$.
   - If we choose $x$ strictly between $L$ and $R$ (i.e., $L < x < R$), then $L$ increases by 1 (to $L+1$) and $R$ decreases by 1 (to $R-1$).
   - This reduces the range of positions by 2 units in a single operation.
   - If no integer $x$ exists strictly between $L$ and $R$, it means $R - L \le 1$. If $R - L = 1$, we can choose $x = L$ (or $x = R$) to bring the remaining slimes to the same position in 1 operation. If $R - L = 0$, all slimes are already at the same position, requiring 0 operations.

2. **Formula**:
   Since each operation can reduce the range span by at most 2, the minimum number of operations required is:
   $$\lceil \frac{R - L}{2} \rceil = \lfloor \frac{R - L + 1}{2} \rfloor$$
   which translates to `(max_val - min_val + 1) / 2` using integer division in C++.

## 💻 C++ Solution
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int min_val = 1e9, max_val = -1e9;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        min_val = min(min_val, val);
        max_val = max(max_val, val);
    }
    cout << (max_val - min_val + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

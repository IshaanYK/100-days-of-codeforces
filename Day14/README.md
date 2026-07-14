# Day 14: Marisa Steals Reimu's Takeout

- **Rating**: 800
- **Time Complexity**: $O(N)$ per testcase
- **Space Complexity**: $O(1)$ auxiliary space

## 💡 Explanation
We are given an array of takeout values $w_i \in \{0, 1, 2\}$. We want to find the maximum number of disjoint subsequences we can form such that each subsequence has a sum divisible by 3.

Since $w_i \in \{0, 1, 2\}$, any subsequence with a sum divisible by 3 can be decomposed into smaller base subsequences that are also divisible by 3:
1. A single `0` (sum 0)
2. One `1` and one `2` (sum 3)
3. Three `1`s (sum 3)
4. Three `2`s (sum 6)

Since any larger valid subsequence can be partitioned into these base cases, to maximize the number of operations, we should always decompose them into these base cases.

---

## ⚙️ Approach

### 1. Dynamic Programming (DP) Approach
Let $c_0$, $c_1$, and $c_2$ be the counts of 0s, 1s, and 2s in the input respectively.
- Since each `0` can form its own subsequence, we immediately get $c_0$ operations.
- For 1s and 2s, we can compute the maximum operations using a DP table `dp[i][j]` representing the max operations using $i$ ones and $j$ twos:
  - Transition 1 (use one 1 and one 2): `dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)`
  - Transition 2 (use three 1s): `dp[i][j] = max(dp[i][j], dp[i-3][j] + 1)`
  - Transition 3 (use three 2s): `dp[i][j] = max(dp[i][j], dp[i][j-3] + 1)`

### 2. Optimized Greedy Approach (Implemented)
Since a `(1, 2)` pair uses only 2 elements to get 1 operation, while `(1, 1, 1)` and `(2, 2, 2)` use 3 elements, it is always optimal to pair as many `1`s and `2`s as possible first.
1. Let $M = \min(c_1, c_2)$ be the number of `(1, 2)` pairs.
2. The remaining `1`s (if any) are grouped in triplets: $\lfloor (c_1 - M) / 3 \rfloor$.
3. The remaining `2`s (if any) are grouped in triplets: $\lfloor (c_2 - M) / 3 \rfloor$.
4. Total operations = $c_0 + M + \lfloor \frac{c_1 - M}{3} \rfloor + \lfloor \frac{c_2 - M}{3} \rfloor$.

This greedy approach runs in $O(N)$ time and $O(1)$ space.

---

## 💻 C++ Solution
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (w == 0) c0++;
        else if (w == 1) c1++;
        else if (w == 2) c2++;
    }
    int pairs = min(c1, c2);
    int ans = c0 + pairs + (c1 - pairs) / 3 + (c2 - pairs) / 3;
    cout << ans << "\n";
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

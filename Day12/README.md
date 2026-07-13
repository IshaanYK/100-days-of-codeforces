# Day 12: Absolute Cinema

- **Rating**: 1000
- **Time Complexity**: $O(N)$ per testcase
- **Space Complexity**: $O(N)$ auxiliary space

## 💡 Explanation
Given two arrays $a$ and $b$ of size $N$. For each pair $(a_i, b_i)$, we can swap them or keep them as they are. The goal is to maximize the sum of one array plus the maximum element of the other array after optimal swaps.

## ⚙️ Approach
1. **Upper Bound Analysis**:
   Suppose in the final arrangement, the maximum of array $a$ is at index $k$ (i.e. $\max(a) = a_k$).
   Since $a_k$ and $b_k$ are the original numbers from the $k$-th pair, we have $a_k \le \min(a_k, b_k)$ if we arrange them such that $a_k$ is the smaller one.
   The total value we get is:
   $$\max(a) + \sum_{i=1}^{N} b_i = a_k + b_k + \sum_{i \neq k} b_i$$
   For any other pair $i \neq k$, $b_i \le \max(a_i, b_i)$.
   For the $k$-th pair, $a_k + b_k = \max(a_k, b_k) + \min(a_k, b_k)$.
   Therefore, the sum is bounded by:
   $$\sum_{i=1}^{N} \max(a_i, b_i) + \min(a_k, b_k) \le \sum_{i=1}^{N} \max(a_i, b_i) + \max_{1 \le i \le N} (\min(a_i, b_i))$$

2. **Constructive Sufficiency**:
   We can always achieve this upper bound:
   - For every pair $(a_i, b_i)$, assign the larger value to array $b$ and the smaller value to array $a$.
   - Now, $\sum b = \sum \max(a_i, b_i)$.
   - The maximum element of array $a$ is exactly $\max(\min(a_i, b_i))$.
   - Adding these two gives the exact upper bound.

## 💻 C++ Solution
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        for (int i = 0; i < n; i++) 
            cin >> b[i];

        long long sum = 0;
        long long best = 0;

        for (int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
            best = max(best, min(a[i], b[i]));
        }
        cout << sum + best << '\n';
    }
    return 0;
}
```

# Day 02: Another Puzzle from Papyrus\n\n- **Rating**: 800\n- **Time Complexity**: $O(N log N) per testcase due to sorting$\n- **Space Complexity**: $O(N) to store the arrays$\n\n## 💡 Explanation\nWe need to make array a greater than or equal to array b element-wise. We can either do this without rearranging elements (paying sum(a[i] - b[i])) or by rearranging array a and/or b (paying an extra cost C plus sum(a[i] - b[i]) of the sorted arrays).\n\n## ⚙️ Approach\nCheck Case 1: if a[i] >= b[i] for all i, calculate cost1 = sum(a[i] - b[i]). Check Case 2: sort both arrays, if sorted a[i] >= sorted b[i] for all i, calculate cost2 = C + sum(a[i] - b[i]). Return the minimum of valid costs, or -1 if impossible.\n\n## 💻 C++ Solution\n```cpp\n#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr);
 
    int t;
    cin >> t ;
 
    while (t--) {
        int n , c;
        cin>> n >> c ;
 
        vector <int> a(n) , b(n) ;
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
 
        // case1 without rearrangemnt 
        int cost1 = 0;
        bool ok1 = true ;
 
        for(int i = 0 ; i < n ; i++) {
            if (a[i] < b[i]) {
                ok1 = false;
                break;
            }
            cost1 += a[i] - b[i];
        }
 
        // case2 rearrangement 
 
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
 
        int cost2 = c;
        bool ok2 = true;
 
        for(int i = 0 ; i < n ; i++){
            if (a[i] < b[i]){
                ok2 = false;
                break;
 
            }
            cost2 += a[i] - b[i];
        }
 
        if (!ok1 && !ok2)
        cout << -1 << '\n';
 
        else if ( ok1 && ok2)
        cout << min(cost1, cost2) <<'\n';
 
        else if (ok1) 
        cout << cost1 << '\n';
 
        else 
        cout << cost2 << '\n';
 
    }
    return 0;
 
}\n```\n
#include <iostream>
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
}

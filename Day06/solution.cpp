#include <iostream>
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
}

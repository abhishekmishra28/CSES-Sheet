#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    fastio();

    ll t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x; 
        
        if (y >= x) {
            if (y % 2 == 0) {
                cout << (y * y) - x + 1 << "\n";
            } else {
                cout << (y - 1) * (y - 1) + x << "\n";
            }
        } else {
            if (x % 2 != 0) {
                cout << (x * x) - y + 1 << "\n";
            } else {
                cout << (x - 1) * (x - 1) + y << "\n";
            }
        }
    }
    return 0;
}
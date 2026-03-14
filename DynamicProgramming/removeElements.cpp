#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;

vll dp;

vll getDigits(ll n){
    vll ans;
    while(n>0){
        if(n%10 != 0){
            int digit = n%10;
            ans.push_back(digit);
        }
        n/=10;
    }
    return ans;
}

ll removeElements(ll n){
    if(n<=0) return 0;
    if(n<=9) return 1;
    vll digits = getDigits(n);
    ll results = LLONG_MAX;
    if(dp[n] != -1) return dp[n];
    for(int i=0;i<digits.size();i++){
        results = min(results,removeElements(n-digits[i]));
    }
    return dp[n] = 1 + results;
}

int main() {
    fastio();
    ll n;
    cin>>n;
    dp.resize(n+1,-1);
    ll res = removeElements(n);
    cout<<res;
    return 0;
}
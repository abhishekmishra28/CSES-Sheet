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
using vvl = vector<vector<ll>>;

ll CoinChange(vll &coins, int amt){
    int n = coins.size();
    vvl dp(n+1,vll(amt+1,LLONG_MAX));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amt;j++){
            ll take = LLONG_MAX;
            if(coins[i-1]<=j){
                take = 1 + dp[i][j-coins[i-1]];
            }
            ll notTake = dp[i-1][j]; 
            dp[i][j] = min(take,notTake);
        }
    }
    return (dp[n][amt] == LLONG_MAX) ? -1 : dp[n][amt];
}

int main() {
    fastio();
    int n,Amount;
    cin>>n>>Amount;
    vll coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    ll ans = CoinChange(coins,Amount);
    cout<<ans;
    return 0;
}
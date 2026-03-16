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

int tabulation(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int take = 1e9;
                if(coins[i-1] <= j){
                    take = 1+dp[i][j-coins[i-1]];
                }
                int notTake = dp[i-1][j];
                dp[i][j] = min(take,notTake);
            }
        }
        return (dp[n][amount] == 1e9) ? -1 : dp[n][amount];
}

int main() {
    fastio();
    int n,Amount;
    cin>>n>>Amount;
    vi coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int ans = tabulation(coins,Amount);
    cout<<ans;
    return 0;
}
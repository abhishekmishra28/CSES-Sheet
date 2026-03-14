#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using vvc = vector<vector<char>>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

int solve(int r, int c, vvc &grid,vvi &dp) {
    if(r>=grid.size() || c>=grid.size()) return 0;
    if(grid[r][c] == '*') return 0;
    if(r==grid.size()-1 && c==grid.size()-1) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    int down = solve(r+1,c,grid,dp);
    int right = solve(r,c+1,grid,dp);
    return dp[r][c] = (down + right) % MOD;
}

int gridPath(vvc &grid){
    int n = grid.size();
    vvi dp(n,vector<int>(n,-1));
    return solve(0,0,grid,dp);
}

int main() {
    fastio();

    int n;
    cin>>n;
    vvc grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int paths = gridPath(grid);
    cout<<paths;
    return 0;
}
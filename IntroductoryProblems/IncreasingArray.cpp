#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    ll moves = 0;
    for(int i=1;i<n;i++){
        if(nums[i]>=nums[i-1]) continue;
        int diff = abs(nums[i]-nums[i-1]);
        moves+=diff;
        nums[i]+=diff;
    }
    cout<<moves;
    return 0;
}
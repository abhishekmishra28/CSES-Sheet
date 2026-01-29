#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)


void Permutation(int n){
    for(int i = 2; i <= n; i += 2)
        cout << i << " ";
    for(int i = 1; i <= n; i += 2)
        cout << i << " ";
}

int main() {
    fastio();
    int n;
    cin>>n;
    if(n==1) cout<<1;
    else if(n==2 || n==3) cout<<"NO SOLUTION";
    else Permutation(n);
    return 0;
}
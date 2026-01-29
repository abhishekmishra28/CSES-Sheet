#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> arr;
    for(int i=0;i<n-1;i++){
        int key;
        cin>>key;
        arr.push_back(key);
    }
    int total = n*(n+1)/2;
    int acc = accumulate(arr.begin(),arr.end(),0);
    cout<<total-acc;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    int rep = 1;
    for(int i=0;i<n-1;){
        int cnt = 1;
        int j = i+1;
        while(j>i && s[i]==s[j]) {
            cnt++;
            j++;
        }
        rep = max(rep,cnt);
        i = j;
    }
    cout<<rep;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& coins, int n, int x){

    vector<int> prev(x+1, 0);
    vector<int> cur(x+1, 0);

    for(int i=0; i<=x; i++){
        if(i%coins[0]==0) prev[i] = i/coins[0];
        else prev[i] = 1e9;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            int nottake = prev[j];
            int take = 1e9;
            if(j>=coins[i]) take = 1+cur[j-coins[i]];
            cur[j] = min(nottake, take);
        }
        prev=cur;
    }

    int ans = prev[x];
    if(ans>=1e9) return -1;
    return ans;
}

int main(){
    int n;
    int x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int res = f(coins, n, x);
    
    cout<<res<<endl;
    return 0;


}
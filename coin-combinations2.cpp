#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }

    int mod = 1e9+7;

    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=x; j++){
            int nottake = dp[i+1][j];
            int take = 0;
            if(coins[i]<=j) take = dp[i][j-coins[i]];

            dp[i][j] = (take+nottake)%mod;
        }
    }

    cout<<dp[0][x]<<endl;
    return 0;


}
#include<bits/stdc++.h>
using namespace std;

// int f(int x, vector<int>coins, vector<int>& dp){
//     if(x==0) return 1;
//     if(x<0) return 0;

//     if(dp[x]!=-1) return dp[x];
    
//     int ans = 0;

//     for(int i=0; i<coins.size(); i++){
//         ans+=f(x-coins[i], coins, dp);
//     }

//     return dp[x] = ans;
// }

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

   vector<int>dp(x+1, 0); //dp[k] denotes number of ways to form 'k'
   int mod = 1e9+7;

   dp[0] = 1;

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(coins[j]<=i){
                dp[i] = (dp[i]+dp[i-coins[j]])%mod;
            }
        }
    }

    cout<<dp[x];

    
    return 0;

}
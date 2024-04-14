#include<bits/stdc++.h>
using namespace std;

int f(int n){
    vector<int> dp(n+1, 0);
    int mod = 1e9+7;
        dp[0]=1;

        for(int i=1; i<=n; i++){ //sum to be achieved
            for(int j=1; j<=6 && i-j>=0; j++){ //no. shown on the dice
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }

        return dp[n];
}

int main(){
    int n;
    cin>>n;

    
    cout<<f(n);
    return 0;

}
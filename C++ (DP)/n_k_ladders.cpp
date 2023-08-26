#include<iostream>
#include<vector>
using namespace std;

int helper(int n , int k , int *dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=helper(n-i,k , dp);
    }
    return dp[n] = ans;
    
    
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int dp [1000]= {0};
    cout<<helper(n , k , dp);
}
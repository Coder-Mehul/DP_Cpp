#include<bits/stdc++.h>

using namespace std;



int helper(int w_a[], int v_a[], int n, int i, int w ,int dp[][100001]) {
    if(i == n || w == 0) {
        return 0;
    }
    if(dp[i][w] != -1) {
        return dp[i][w];
    }
    if(w_a[i] > w) {
        dp[i][w] = helper(w_a, v_a, n, i+1, w ,dp);
        return dp[i][w];
    }
    dp[i][w] = max(helper(w_a, v_a, n, i+1, w - w_a[i],dp) + v_a[i], helper(w_a, v_a, n, i+1, w,dp));
    return dp[i][w];
}

int main() {
    int n;
    cin >> n;
    int w;
    cin >> w;
    int w_a[n];
    int v_a[n];

    for(int i = 0; i < n; i++) {
        cin >> w_a[i];
        cin >> v_a[i];
    }
    int dp[n][100001];

    memset(dp, -1, sizeof(dp));

    cout << helper(w_a, v_a, n, 0, w ,dp);
}


// int main() {
//     int n;
//     cin >> n;
//     int w;
//     cin >> w;
//     int w_a[n];
//     int v_a[n];

//     for(int i = 0; i < n; i++) {
//         cin >> w_a[i];
//         cin >> v_a[i];
//     }
//     int dp[n][w];

   

//     for(int i=0;i<n;i++){
//         for(int j=0;j<w;j++){
             
            
            
            
            
            
            
//             }
//         }
    
// }
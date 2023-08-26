#include <bits/stdc++.h>
using namespace std;
                                                        // Memoization
// vector<int> memo;

// int helper(int arr[], int n, int i) {
//     if (i >= n - 2) {
//         return 0;
//     }
//     if (memo[i] != -1) {
//         return memo[i];
//     }
//     int costMoveOneStep = helper(arr, n, i + 1) + abs(arr[i] - arr[i + 1]);
//     int costMoveTwoSteps = helper(arr, n, i + 2) + abs(arr[i] - arr[i + 2]);
//     memo[i] = min(costMoveOneStep, costMoveTwoSteps);
//     return memo[i];
// }

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    dp[0]=0;
    dp[1] =dp[0] + abs(arr[0] - arr[1]);
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+ abs(arr[i-1]-arr[i]) , dp [i-2]+abs(arr[i-2]-arr[i]));
    }
    cout << dp[n-1];
}

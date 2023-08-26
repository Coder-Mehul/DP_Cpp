#include <bits/stdc++.h>
using namespace std;


int main() {
    int n ;
    int k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;  

    for (int i = 1; i < n; i++) {
        for (int jump = 1; jump <= k; jump++) {
            if (i - jump >= 0) {
                dp[i] = min(dp[i], dp[i - jump] + abs(arr[i] - arr[i - jump]));
            }
        }
    }

    cout << dp[n - 1];  
}


// vector<vector<int>> memo;

// int helper(int arr[], int n, int i ,int k) {
//     if (i >= n - k) {
//         return 0;
//     }
//     if (memo[i][k] != -1) {
//         return memo[i][k];
//     }
//     int costMove=0;
//     int ans=INT_MAX;
//     for(int jump=1;jump<=k;jump++){
//         costMove += helper(arr , n , i+jump , k)+abs(arr[i]-arr[i+jump]);
//         ans=min(ans , costMove);
//     }
//     memo[i][k] = ans; 
//     return ans;
// }

// int main() {
//     int n;
//     int k;
//     cin>>n;
//     cin>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
    
//     memo.assign(n + 1, vector<int>(k + 1, -1));
    
//     cout<<helper(arr ,n ,0,k);
// }



// #include <bits/stdc++.h>
// using namespace std;

// int helper(int arr[], int n, int i ,int k) {
//     if (i >= n - k) {
//         return 0;
//     }
//     int costMove=0;
//     int ans=INT_MAX;
//     for(int jump=1;jump<=k;jump++){
//         costMove += helper(arr , n , i+jump , k) + abs(arr[i] - arr[i+jump]);
//         ans = min(ans, costMove);
//     }
//     return ans;
// }

// int main() {
//     int n=5;
//     int k=3;
//     int arr[] = {10 , 30 ,40 ,50 ,20};
    
//     cout << helper(arr, n, 0, k);
// }


// #include <bits/stdc++.h>
// using namespace std;
//                                                         // Memoization
// vector<vector<int>> memo;

// int helper(int arr[], int n, int i ,int k) {
//     if (i >= n - k) {
//         return 0;
//     }
//     // if (memo[i][k] != -1) {
//     //     return memo[i][k];
//     // }
//     int costMove=0;
//     int ans=INT_MAX;
//     for(int jump=1;jump<=k;jump++){
//         costMove += helper(arr , n , i+jump , k)+abs(arr[i]-arr[i+jump]);
//         ans=min(ans , costMove);
//     }
//     return ans;
// }

// int main() {
//     int n=5;
//     // cin>>n;
//     int k=3;
//     // cin>>k;
//     int arr[] = {10 , 30 ,40 ,50 ,20};
//     // for(int i=0;i<n;i++){
//     //     cin>>arr[i];
//     // }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=k;j++){
//             memo[i][j]=-1;
//         }
//     }
//     cout<<helper(arr ,n ,0,k);
// }


// // #include <bits/stdc++.h>

// // using namespace std;


// // int helper(int a[] , int b[] , int c[] ,int days , int i, char prev){
// //     if(i==days){
// //         return 0;
// //     }int a1=0;
// //     int b1=0;
// //     int c1=0;
// //     if(prev=='a'){
// //     int a1=max(helper(a , b, c , days , i+1 , 'b')+b[i] ,helper(a , b, c , days , i+1 , 'c')+c[i]);
// //     }
// //     if(prev=='b'){
// //     int b1=max(helper(a , b , c, days , i+1 , 'a')+a[i],helper(a , b , c, days , i+1 , 'c')+c[i]);
// //     }
// //     if(prev=='c'){
// //     int c1=max(helper(a , b ,c , days , i+1 , 'a' )+a[i], helper(a , b , c, days , i+1 , 'b')+b[i]);
// //     }

// //     return max(max(a1 ,b1),c1);
// // }

// // int main(){
// //     int days;
// //     cin>>days;

// //     int a[days];
// //     int b[days];
// //     int c[days];

// //     for(int i=0;i<days;i++){
// //         cin>>a[i];
// //         cin>>b[i];
// //         cin>>c[i];
// //     }

// //     cout<<helper(a , b, c , days ,0 ,'z');
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int memo[101][4];

// int helper(int a[], int b[], int c[], int days, int i, int prev) {
//     if (i == days) {
//         return 0;
//     }

//     if (memo[i][prev] != -1) {
//         return memo[i][prev];
//     }

//     int maxScore = 0;

//     if (prev == 0) {
//         maxScore = max(maxScore, max(helper(a, b, c, days, i + 1, 1) + b[i], helper(a, b, c, days, i + 1, 2) + c[i]));
//     } else if (prev == 1) {
//         maxScore = max(maxScore, max(helper(a, b, c, days, i + 1, 0) + a[i], helper(a, b, c, days, i + 1, 2) + c[i]));
//     } else if (prev == 2) {
//         maxScore = max(maxScore, max(helper(a, b, c, days, i + 1, 0) + a[i], helper(a, b, c, days, i + 1, 1) + b[i]));
//     }

//     memo[i][prev] = maxScore;
//     return maxScore;
// }

// int main() {
//     int days;
//     cin >> days;

//     int a[days];
//     int b[days];
//     int c[days];

//     for (int i = 0; i < days; i++) {
//         cin >> a[i] >> b[i] >> c[i];
//     }

//     memset(memo, -1, sizeof(memo));  

//     cout << max(helper(a, b, c, days, 0, 0), max(helper(a, b, c, days, 0, 1), helper(a, b, c, days, 0, 2))) << endl;
// }

// //     int dp[days+1][2];
// //     dp[0][0]=max(max(a[0],b[0]),c[0]);
// //     if(dp[0][0]==a[0]){
// //         dp[0][1]=0;
// //     }
// //     if(dp[0][0]==b[0]){
// //         dp[0][1]=1;
// //     }
// //     if(dp[0][0]==c[0]){
// //         dp[0][1]=2;
// //     }
// //     for(int i=1;i<days;i++){
// //         if(dp[i-1][1]==0){
// //             if(b[i]>=c[i]){
// //                 dp[i][0]=b[i];
// //                 dp[i][1]=1;
// //             }
// //             else{
// //                 dp[i][0]=c[i];
// /        /                 dp[i][1]=2;
// //             }
// //         }
// //         if(dp[i-1][1]==1){
// //             if(a[i]>=c[i]){
// //                 dp[i][0]=a[i];
// //                 dp[i][1]=0;
// //             }
// //             else{
// //                 dp[i][0]=c[i];
// //                 dp[i][1]=2;
// //             }
// //         }
// //         if(dp[i-1][1]==2){
// //             if(b[i]>=a[i]){
// //                 dp[i][0]=b[i];
// //                 dp[i][1]=1;
// //             }
// //             else{
// //                 dp[i][0]=a[i];
// //                 dp[i][1]=0;
// //             }
// //         }
// //     }
// //     int ans=0;
// //     for(int i=0;i<days;i++){
// //         cout<<dp[i][0]<<endl;
// //         ans+=dp[i][0];
// //     }
// //     // cout<<ans;
// // }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int days;
    cin >> days;

    int a[days];
    int b[days];
    int c[days];

    for (int i = 0; i < days; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[days][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for (int i = 1; i < days; i++) {
        dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    int maxScore = max(max(dp[days - 1][0], dp[days - 1][1]), dp[days - 1][2]);
    cout << maxScore << endl;

    return 0;
}

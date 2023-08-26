// #include <bits/stdc++.h>
// using namespace std;

// string maxByLength(string a, string b) {
//     return a.length() > b.length() ? a : b;
// }

// string lcs(string a, string b, int n, int m, string dp[][1001]) {
//     if (m == 0 || n == 0) {
//         return "";
//     }
//     if (dp[n][m] != "") {
//         return dp[n][m];
//     }
//     if (a[n - 1] == b[m - 1]) {
//         dp[n][m] = lcs(a, b, n - 1, m - 1, dp) + a[n - 1];
//         return dp[n][m];
//     }
//     dp[n][m] = maxByLength(lcs(a, b, n - 1, m, dp), lcs(a, b, n, m - 1, dp));
//     return dp[n][m];
// }

// int main() {
//     string a;
//     cin >> a;
//     string b;
//     cin >> b;

//     int n = a.length();
//     int m = b.length();
//     string dp[n + 1][1001];
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             dp[i][j] = "";
//         }
//     }
//     cout << lcs(a, b, n, m, dp);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

string maxByLength(string a, string b) {
    return a.length() > b.length() ? a : b;
}

string lcs(string a, string b) {
    int n = a.length();
    int m = b.length();
    string dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = "";
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
            } else {
                dp[i][j] = maxByLength(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;

    cout << lcs(a, b);

    return 0;
}

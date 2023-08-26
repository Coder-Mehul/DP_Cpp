#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int helper(vector<int> &arr, int n, int i, int prev) {
    if (i == n) {
        return 0;
    }

    if (memo[i][prev + 1] != -1) {
        return memo[i][prev + 1];
    }

    int inc = 0;
    if (arr[i] > prev) {
        inc = 1 + helper(arr, n, i + 1, arr[i]);
    }

    int exc = helper(arr, n, i + 1, prev);

    memo[i][prev + 1] = max(inc, exc);

    return memo[i][prev + 1];
}

int main() {
    vector<int> arr = {50, 4, 10, 8, 30, 100};
    int n = arr.size();

    memo.assign(n + 1, vector<int>(101, -1));

    cout << helper(arr, n, 0, INT_MIN);
}

#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int solveByMemo(vector<int>& dp, int n) {
    if(n==0) {
        dp[n] = n;
        return dp[n];
    }

    if(n==1) {
        dp[n] = n;
        return dp[n];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = solveByMemo(dp, n-1) + solveByMemo(dp, n-2);
    return dp[n];
}

int solveByTop()

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    int result = solveByMemo(dp, n);
    cout << result << endl;
    return 0;
}

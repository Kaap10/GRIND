//recursive approach
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) // Base case
        return 1;
    return n * factorial(n - 1); // Recursive call
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}


//iterative approach
#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}


//using memoization (top-down approach)
#include <iostream>
#include <vector>
using namespace std;

int factorialMemo(int n, vector<int>& memo) {
    if (n == 0 || n == 1)
        return 1;
    if (memo[n] != -1) // Check if already computed
        return memo[n];
    memo[n] = n * factorialMemo(n - 1, memo); // Store result
    return memo[n];
}

int main() {
    int n = 5;
    vector<int> memo(n + 1, -1);
    cout << "Factorial of " << n << " is " << factorialMemo(n, memo) << endl;
    return 0;
}

//using tabulation (bottom up approach)
#include <iostream>
#include <vector>
using namespace std;

int factorialTabulation(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n];
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is " << factorialTabulation(n) << endl;
    return 0;
}

//using stl
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); // Fill vector with 1 to n
    return accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}


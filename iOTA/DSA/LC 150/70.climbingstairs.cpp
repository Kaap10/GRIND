// TLE through recursion
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};


// Space optimization rocks 
class Solution {
public:
    int climbStairs(int n) {
    if (n <= 2) return n;

    int oneStepBefore = 2;
    int twoStepsBefore = 1;
    int allWays = 0;

    for (int i = 3; i <= n; i++) {
        allWays = oneStepBefore + twoStepsBefore;
        twoStepsBefore = oneStepBefore;
        oneStepBefore = allWays;
    }

    return allWays;
}
};
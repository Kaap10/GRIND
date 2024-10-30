// approach1 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;

        int start = 0;
        for(int index = 0; index < gas.size(); index++) {
            balance = balance + gas[index] - cost[index];

            if(balance<0) {
                deficit = deficit + abs(balance);
                start = index + 1;
                balance = 0;
            }
        }

        if(balance - deficit >= 0) {
            return start;
        }

        else {
            return -1;
        }
    }
};



// approach2 : O(n^2) time complexity
// brute force approach -> 34/39 test cases passed and TLE 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            int tank = 0;
            bool canComplete = true;
            
            for (int j = 0; j < n; j++) {
                int k = (i + j) % n; // circular ind
                tank += gas[k] - cost[k];
                if (tank < 0) {
                    canComplete = false;
                    break;
                }
            }
            if (canComplete) {
                return i;
            }
        }
        return -1;
    }
};

// approach3 : O(n) time complexity
// optimized approach
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int total_gas = 0, total_cost = 0, start = 0, tank = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total_gas < total_cost ? -1 : start;
    }
};




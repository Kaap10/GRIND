class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(1001, true);
        vector<int> primes;

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= 1000; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }


        for (int i = n - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) {
                bool found = false;
                for (int p : primes) {
                    if (p < nums[i - 1] && nums[i - 1] - p < nums[i]) {
                        nums[i - 1] -= p;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        }


        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};


// class Solution {
// public:

//     int give_prime

//     bool check_array(int x) {

//     }

//     bool primeSubOperation(vector<int>& nums) {
//         int n = nums.size();

//         for(int i=0; i<n; i++) {
//             int x = nums[i];

//             //yahan se current nume se chota prime milega
//             int prime = give_prime(x);
//             int update = x - prime;
//             //difference ko current numm ki jagah update krdenge
//             x = update;

//             //yahan check krenge ki array humar inc sorted mai hai ya nhi
//             if(check_array) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };


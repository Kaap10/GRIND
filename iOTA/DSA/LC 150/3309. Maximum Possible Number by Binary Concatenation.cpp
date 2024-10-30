class Solution {
public:
    string toBinary(int num) {
        string binary;
        while (num > 0) {
            binary = (num % 2 == 0 ? '0' : '1') + binary;
            num /= 2;
        }
        return binary;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaries;

        for (int num : nums) {
            binaries.push_back(toBinary(num));
        }

        int maxDecimal = 0;
        sort(binaries.begin(), binaries.end());
        do {
            string concatenatedBinary = binaries[0] + binaries[1] + binaries[2];
            int decimalValue = stoi(concatenatedBinary, 0, 2);
            maxDecimal = max(maxDecimal, decimalValue);
        } while (next_permutation(binaries.begin(), binaries.end()));

        return maxDecimal;
    }
};
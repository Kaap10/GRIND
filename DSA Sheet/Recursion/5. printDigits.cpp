//iterative aproach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printDigitsIterative(int N) {
    vector<int> digits;
    while (N > 0) {
        digits.push_back(N % 10); // Extract the last digit
        N /= 10; // Remove the last digit
    }
    reverse(digits.begin(), digits.end()); // Reverse to get the correct order
    for (int digit : digits) {
        cout << digit << " ";
    }
}

int main() {
    int N = 1234;
    cout << "Digits of " << N << ": ";
    printDigitsIterative(N);
    return 0;
}


//recursive approach
#include <iostream>
using namespace std;

void printDigitsRecursive(int N) {
    if (N == 0) return; // Base case
    printDigitsRecursive(N / 10); // Process the rest of the digits
    cout << N % 10 << " "; // Print the last digit
}

int main() {
    int N = 1234;
    cout << "Digits of " << N << ": ";
    printDigitsRecursive(N);
    return 0;
}


//string conversion
#include <iostream>
#include <string>
using namespace std;

void printDigitsString(int N) {
    string num = to_string(N); // Convert number to string
    for (char ch : num) {
        cout << ch << " "; // Print each character
    }
}

int main() {
    int N = 1234;
    cout << "Digits of " << N << ": ";
    printDigitsString(N);
    return 0;
}



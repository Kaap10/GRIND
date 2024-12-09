//iterative
#include <iostream>
using namespace std;

int countDigitsIterative(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10; // Reduce the number by one digit
    }
    return count;
}

int main() {
    int n = 12345;
    cout << "Number of digits: " << countDigitsIterative(n) << endl;
    return 0;
}


//strign conversion
#include <iostream>
#include <string>
using namespace std;

int countDigitsString(int n) {
    string numStr = to_string(n);
    return numStr.length();
}

int main() {
    int n = 12345;
    cout << "Number of digits: " << countDigitsString(n) << endl;
    return 0;
}

//recursive 
#include <iostream>
using namespace std;

int countDigitsRecursive(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigitsRecursive(n / 10);
}

int main() {
    int n = 12345;
    cout << "Number of digits: " << countDigitsRecursive(n) << endl;
    return 0;
}

//logarithmic approach
#include <iostream>
#include <cmath>
using namespace std;

int countDigitsLog(int n) {
    return floor(log10(n)) + 1;
}

int main() {
    int n = 12345;
    cout << "Number of digits: " << countDigitsLog(n) << endl;
    return 0;
}


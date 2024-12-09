//recursive approach
#include <iostream>
using namespace std;

void reverseCount(int n) {
    if (n == 0) return;  // Base case
    cout << n << " ";
    reverseCount(n - 1); // Recursive call
}

int main() {
    int n = 5;
    reverseCount(n);
    return 0;
}


//iterative appraoch
#include <iostream>
using namespace std;

void reverseCount(int n) {
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
}

int main() {
    int n = 5;
    reverseCount(n);
    return 0;
}


//lambda function
#include <iostream>
#include <functional>
using namespace std;

void reverseCount(int n) {
    auto print = [](int i) { while (i >= 1) cout << i-- << " "; };
    print(n);
}

int main() {
    int n = 5;
    reverseCount(n);
    return 0;
}

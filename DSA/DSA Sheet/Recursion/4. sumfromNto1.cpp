//using formula
#include <iostream>
using namespace std;

int sumFormula(int N) {
    return (N * (N + 1)) / 2;
}

int main() {
    int N = 5;
    cout << "Sum from " << N << " to 1 is: " << sumFormula(N) << endl;
    return 0;
}


//iterative approach
#include <iostream>
using namespace std;

int sumIterative(int N) {
    int sum = 0;
    for (int i = N; i >= 1; --i) {
        sum += i;
    }
    return sum;
}

int main() {
    int N = 5;
    cout << "Sum from " << N << " to 1 is: " << sumIterative(N) << endl;
    return 0;
}


//recursion
#include <iostream>
using namespace std;

int sumRecursive(int N) {
    if (N == 0) return 0; // Base case
    return N + sumRecursive(N - 1);
}

int main() {
    int N = 5;
    cout << "Sum from " << N << " to 1 is: " << sumRecursive(N) << endl;
    return 0;
}
    
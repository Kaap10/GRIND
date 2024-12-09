//iterative method
#include <iostream>
using namespace std;

int powerIterative(int N) {
    int result = 1;
    for (int i = 0; i < N; ++i) {
        result *= 2;
    }
    return result;
}

int main() {
    int N = 5;
    cout << "2^" << N << " = " << powerIterative(N) << endl;
    return 0;
}


//recursive method
#include <iostream>
using namespace std;

int powerRecursive(int N) {
    if (N == 0) return 1; // Base case
    return 2 * powerRecursive(N - 1);
}

int main() {
    int N = 5;
    cout << "2^" << N << " = " << powerRecursive(N) << endl;
    return 0;
}


//fast exponentation
#include <iostream>
using namespace std;

int powerFast(int N) {
    if (N == 0) return 1; // Base case
    int halfPower = powerFast(N / 2);
    if (N % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return 2 * halfPower * halfPower;
    }
}

int main() {
    int N = 5;
    cout << "2^" << N << " = " << powerFast(N) << endl;
    return 0;
}

//bit manipulation
#include <iostream>
using namespace std;

int powerBitManipulation(int N) {
    return 1 << N; // Left shift by N
}

int main() {
    int N = 5;
    cout << "2^" << N << " = " << powerBitManipulation(N) << endl;
    return 0;
}

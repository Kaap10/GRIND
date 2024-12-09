//iterative approach
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    return 0;
}


//recursion
#include <iostream>
using namespace std;

void printArrayRecursive(int arr[], int n, int index = 0) {
    if (index == n) return;  // Base case: end of array
    cout << arr[index] << " "; // Print current element
    printArrayRecursive(arr, n, index + 1);  // Recursive call to next element
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArrayRecursive(arr, n);
    cout << endl;
    return 0;
}


//stl for each
#include <iostream>
#include <algorithm>
using namespace std;

void printArraySTL(int arr[], int n) {
    for_each(arr, arr + n, [](int x) 
        { 
            cout << x << " "; 
        });
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArraySTL(arr, n);
    return 0;
}

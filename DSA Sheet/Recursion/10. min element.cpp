//iterative approach
#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    int min_val = arr[0]; // Start with the first element as minimum
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i]; // Update minimum if a smaller value is found
        }
    }
    return min_val;
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum value in the array is: " << findMin(arr, n) << endl;
    return 0;
}


//using min_element
#include <iostream>
#include <algorithm>  // for std::min_element
using namespace std;

int findMin(int arr[], int n) {
    return *min_element(arr, arr + n);  // Returns the pointer to the min element, dereference it
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum value in the array is: " << findMin(arr, n) << endl;
    return 0;
}


//recursion
#include <iostream>
using namespace std;

int findMinRecursive(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];  // Base case: only one element
    }
    int mid = left + (right - left) / 2;
    int leftMin = findMinRecursive(arr, left, mid);  // Find min in left half
    int rightMin = findMinRecursive(arr, mid + 1, right);  // Find min in right half
    return (leftMin < rightMin) ? leftMin : rightMin;  // Return the smaller value
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum value in the array is: " << findMinRecursive(arr, 0, n - 1) << endl;
    return 0;
}

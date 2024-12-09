//iterative
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}


//recursion
int linearSearchRecursive(int arr[], int n, int target, int index = 0) {
    if (index == n) return -1;  // Base case: end of array
    if (arr[index] == target) return index;  // Target found
    return linearSearchRecursive(arr, n, target, index + 1);  // Recursive call for next index
}


//stl find function
#include <algorithm> // for find
int linearSearchSTL(int arr[], int n, int target) {
    auto it = std::find(arr, arr + n, target);
    if (it != arr + n) {
        return it - arr;  // Return index of the element
    }
    return -1;  // Element not found
}


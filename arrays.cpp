#include <bits/stdc++.h>
using namespace std;

// print largest element in an array
int print_largest(vector<int> &arr, int n) {
        int largest = arr[0];
        for (int i=1; i<n;i++){
            if (arr[i] > largest)
            {largest = arr[i];}
        }  return largest;
    }


// print second largest element in an array without using sorting
int print_second_largest(vector<int> &arr, int n) {
    int largest = arr[0];
    int second_largest = INT_MIN; // Initialize to a very small value
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}



// check if an array is sorted
bool is_sorted(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            continue; // If current element is greater than or equal to the previous one, continue
        } else {
            return false; // If any element is smaller than the previous one, it's not sorted
        }
    }
    return true; // If we reach here, the array is sorted
}








int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Largest element: " << print_largest(arr, n) << endl;
    cout << "Second largest element: " << print_second_largest(arr, n) << endl;
    cout << "Is the array sorted? " << (is_sorted(arr, n) ? "Yes" : "No") << endl;
    return 0;
}
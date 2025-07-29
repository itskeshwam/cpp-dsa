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
        if (arr[i] >= arr[i - 1]) 
        {} 
        else {
            return false; // If any element is smaller than the previous one, it's not sorted
        }
    }
    return true; // If we reach here, the array is sorted
}




// remove duplicates from an array using set (brute force)
void remove_duplicates(vector<int> &arr, int n) {
    set<int> unique_elements;
    for (int i = 0; i < n; i++) {
        unique_elements.insert(arr[i]);
    }
    arr.assign(unique_elements.begin(), unique_elements.end());
}

// remove duplicates from an array using two pointers (optimized)
int remove_duplicates_two_pointers(vector<int> &arr, int n) {
    if (n == 0) return 0;
    int i = 0; // Pointer for the next unique element
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return (i + 1);
}

// rotate array by k places
int rotate(vector<int> &arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "rotated array: ";
    rotate(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // cout << "Largest element: " << print_largest(arr, n) << endl;
//     // cout << "Second largest element: " << print_second_largest(arr, n) << endl;
//     // cout << "Is the array sorted? " << (is_sorted(arr, n) ? "Yes" : "No") << endl;
//     remove_duplicates(arr, n);
//     return 0;
// }
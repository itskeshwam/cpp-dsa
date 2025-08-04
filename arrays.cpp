#include <bits/stdc++.h>
using namespace std;

// print largest element in an array
int print_largest(vector<int> &arr, int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// print second largest element in an array without using sorting
int print_second_largest(vector<int> &arr, int n) {
    int largest = arr[0];
    int second_largest = INT_MIN;
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
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// remove duplicates from an array using set (brute force)
void remove_duplicates(vector<int> &arr, int n) {
    set<int> unique_elements;
    for (int i = 0; i < n; i++) {
        unique_elements.insert(arr[i]);
    }
    arr.assign(unique_elements.begin(), unique_elements.end());
}

// remove duplicates using two pointers (optimized)
int remove_duplicates_two_pointers(vector<int> &arr, int n) {
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return (i + 1);
}

// rotate array by 1 place
int rotate(vector<int> &arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return 0;
}

// rotate array by k places
int rotate_k_places(vector<int> &arr, int n, int k) {
    k = k % n;
    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
    return 0;
}


// optimized rotate function using reverse
void rotate_optimized(vector<int> &arr, int n, int k) {
    k = k % n; // handle cases where k >= n
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
} 


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Optional input if using rotate_k_places
    int k;
    // cin >> k;

    // ==== Uncomment this block to print the largest element ====
    // cout << "Largest element: " << print_largest(arr, n) << endl;

    // ==== Uncomment this block to print the second largest element ====
    // cout << "Second largest element: " << print_second_largest(arr, n) << endl;

    // ==== Uncomment this block to check if array is sorted ====
    // cout << "Is the array sorted? " << (is_sorted(arr, n) ? "Yes" : "No") << endl;

    // ==== Uncomment this block to remove duplicates using set ====
    // remove_duplicates(arr, n);
    // cout << "Array after removing duplicates (set): ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Uncomment this block to remove duplicates using two pointers ====
    // int new_size = remove_duplicates_two_pointers(arr, n);
    // cout << "Array after removing duplicates (2 pointers): ";
    // for (int i = 0; i < new_size; i++) cout << arr[i] << " ";
    // cout << endl;

    // ==== Uncomment this block to rotate array by 1 place ====
    // rotate(arr, n);
    // cout << "Array after 1-place rotation: ";
    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;

    // ==== Uncomment this block to rotate array by k places ====
    // cin >> k;
    // rotate_k_places(arr, n, k);
    // cout << "Array after rotating by k places: ";
    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;


    // ==== Uncomment this block to use optimized rotate function ====
    cin >> k;
    rotate_optimized(arr, n, k);
    cout << "Array after optimized rotation: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;


    // 




    return 0;
}

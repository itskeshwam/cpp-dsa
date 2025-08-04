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


// right rotate an array by k places
int rotate_right_k_places(vector<int> &arr, int n, int k) {
    if (n == 0) return 0;
    k = k % n; 
    for (int i = 0; i < k; i++) {
        int temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    return 0;
}


// right rotate an array by k places optimized
int rotate_right_k_places_optimized(vector<int> &arr, int n, int k)
{
    if (n == 0) return 0;
    k = k % n; // handle cases where k >= n
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    return 0;
}



// move all zeros to the end of the array (brute force)
void moveZeros(vector<int> &arr, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        arr[i] = temp[i];
    }
    for (int i = nz; i < n; i++) {
        arr[i] = 0;
    }
}


// move all zeros to the end of the array (optimized) 2 pointers
vector<int> moveZerosOptimized(vector<int> &arr, int n) {
    int j = -1; // pointer for non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return arr; // no zeros found

    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    } return arr;
}



// linear search 
int linear_search(vector<int> &arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index of the key
        }
    }
    return -1; // key not found
}



// union and intersection of two SORTED arrays brute force
vector<int> union_sorted_arrays(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for (int i = 0; i < n1; i++) {
        st.insert(a[i]);
    }
    for (int i = 0; i < n2; i++) {
        st.insert(b[i]);
    }
    vector<int> temp;
    for (auto it : st) {
        temp.push_back(it);
    }
    return temp;
}



// union optimized 2 pointers
vector<int> union_sorted_arrays_optimized(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> union_result;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (union_result.size() == 0 || union_result.back() != a[i]) {
                union_result.push_back(a[i]);
            }
            i++;
        } else {
            if (union_result.size() == 0 || union_result.back() != b[j]) {
                union_result.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1) {
        if (union_result.size() == 0 || union_result.back() != a[i]) {
            union_result.push_back(a[i]);
        }
        i++;
    }
    while (j < n2) {
        if (union_result.size() == 0 || union_result.back() != b[j]) {
            union_result.push_back(b[j]);
        }
        j++;
    }
    return union_result;   
}



// intersection of two SORTED arrays brute force
vector<int> intersection_sorted_arrays(vector<int> &a, vector<int> &b, int n2) {
    vector<int> ans;
    vector<int> visited(n2, 0); // to keep track of visited elements in b
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j] && visited[j] == 0) {
                ans.push_back(a[i]);
                visited[j] = 1; // mark as visited
                break;
            }
            if (b[j] > a[i]) {
                break; // since both arrays are sorted, we can break early
            }
        }
    }
    return ans;
}



// intersection optimized 2 pointers
vector<int> intersection_sorted_arrays_optimized(vector<int> &a, vector<int> &b, int n2) {
    int n1 = a.size();
    int i = 0, j = 0;
    vector<int> intersection_result;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            i++;
        } 
        else if (a[i] > b[j]) {
            j++;
        } 
        else { // a[i] == b[j]
            intersection_result.push_back(a[i]);
            i++;
            j++;
        }
    }
    return intersection_result;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Optional input (needed only for rotations or search)
    int k; // for rotations
    int key; // for linear search

    // =================== FUNCTION TEST CASES ===================

    // ==== Largest Element ====
    // cout << "Largest element: " << print_largest(arr, n) << endl;

    // ==== Second Largest Element ====
    // cout << "Second largest element: " << print_second_largest(arr, n) << endl;

    // ==== Check if Sorted ====
    // cout << "Is array sorted? " << (is_sorted(arr, n) ? "Yes" : "No") << endl;

    // ==== Remove Duplicates using Set ====
    // remove_duplicates(arr, n);
    // cout << "Array after removing duplicates (set): ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Remove Duplicates using Two Pointers ====
    // int new_size = remove_duplicates_two_pointers(arr, n);
    // cout << "Array after removing duplicates (two pointers): ";
    // for (int i = 0; i < new_size; i++) cout << arr[i] << " ";
    // cout << endl;

    // ==== Rotate Array Left by 1 ====
    // rotate(arr, n);
    // cout << "Array after rotating left by 1: ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Rotate Array Left by k ====
    // cin >> k;
    // rotate_k_places(arr, n, k);
    // cout << "Array after rotating left by " << k << " places: ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Optimized Rotate Left by k ====
    // cin >> k;
    // rotate_optimized(arr, n, k);
    // cout << "Optimized left rotation by " << k << ": ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Rotate Array Right by k ====
    // cin >> k;
    // rotate_right_k_places(arr, n, k);
    // cout << "Right rotation by " << k << " places: ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Optimized Rotate Right by k ====
    // cin >> k;
    // rotate_right_k_places_optimized(arr, n, k);
    // cout << "Optimized right rotation by " << k << ": ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Move Zeros to End (Brute) ====
    // moveZeros(arr, n);
    // cout << "Zeros moved to end (brute): ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Move Zeros to End (Optimized) ====
    // moveZerosOptimized(arr, n);
    // cout << "Zeros moved to end (optimized): ";
    // for (int x : arr) cout << x << " ";
    // cout << endl;

    // ==== Linear Search ====
    // cin >> key;
    // int index = linear_search(arr, n, key);
    // if (index != -1)
    //     cout << "Element found at index: " << index << endl;
    // else
    //     cout << "Element not found." << endl;

    // ==== Union of Two Sorted Arrays (Brute) ====
    // int m, n2;
    // cin >> m >> n2;
    // vector<int> a(m), b(n2);
    // for (int i = 0; i < m; i++) cin >> a[i];
    // for (int i = 0; i < n2; i++) cin >> b[i];
    // vector<int> union_result = union_sorted_arrays(a, b);
    // cout << "Union (brute): ";
    // for (int x : union_result) cout << x << " ";
    // cout << endl;

    // ==== Union of Two Sorted Arrays (Optimized) ====
    // int m, n2;
    // cin >> m >> n2;
    // vector<int> a(m), b(n2);
    // for (int i = 0; i < m; i++) cin >> a[i];
    // for (int i = 0; i < n2; i++) cin >> b[i];
    // vector<int> union_result = union_sorted_arrays_optimized(a, b);
    // cout << "Union (optimized): ";
    // for (int x : union_result) cout << x << " ";
    // cout << endl;

    // ==== Intersection of Two Sorted Arrays (Brute) ====
    // int m, n2;
    // cin >> m >> n2;
    // vector<int> a(m), b(n2);
    // for (int i = 0; i < m; i++) cin >> a[i];
    // for (int i = 0; i < n2; i++) cin >> b[i];
    // vector<int> intersection_result = intersection_sorted_arrays(a, b, n2);
    // cout << "Intersection (brute): ";
    // for (int x : intersection_result) cout << x << " ";
    // cout << endl;

    // ==== Intersection of Two Sorted Arrays (Optimized) ====
    int m, n2;
    cin >> m >> n2;
    vector<int> a(m), b(n2);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n2; i++) cin >> b[i];
    vector<int> intersection_result = intersection_sorted_arrays_optimized(a, b, n2);
    cout << "Intersection (optimized): ";
    for (int x : intersection_result) cout << x << " ";
    cout << endl;

    return 0;
}
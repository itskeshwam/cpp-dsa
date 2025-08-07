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



// find the missing number in an array of size n containing numbers from 1 to n brute force 
// liner search
int find_missing_number_brute(vector<int> &arr, int n) {
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i; // missing number found
        }
    }
    return -1; // if no missing number found
}

// better approach using hashing
int find_missing_number_hashing(vector<int> &arr, int n) {
    vector<int> hash(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        hash[arr[i]] = 1; // mark the number as present
    }
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i; // missing number found
        }
    }
    return -1; // if no missing number found
}

// optimal approach using sum formula
int find_missing_number_optimal(vector<int> &arr, int n) {
    int total_sum = (n * (n + 1)) / 2; 
    int s2 = 0; // sum of elements in the array
    for (int i = 0; i < n; i++) {
        s2 += arr[i];
    }
    return total_sum - s2; // missing number is the difference
}

int find_missing_number_xor(vector<int> &arr, int n) {
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++) {
        xor1 ^= i;
        xor2 ^= arr[i];
    }
    xor1 ^= n; // include n in the XOR (since range is 0 to n)
    return xor1 ^ xor2;
}



// maximum consecutive 1's 
int max_consecutive_ones(vector<int> &arr, int n) {
    int max_count = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            max_count = max(max_count, count);
        } else {
            count = 0; // reset count when a 0 is encountered
        }
    }
    return max_count;
}



// find the number that appears only once in an array where every other number appears twice
// brute force (for every element linear search)
int find_unique_number_brute(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num) {
                cnt++;
            }
        }
        if (cnt == 1) {
            return num; // unique number found
        }
    }
    return -1; // if no unique number found
}

// better using hashing
int find_unique_number_hashing(vector<int> &arr, int n) {
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);  
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i <= maxi; i++) {
        if (hash[i] == 1) {
            return i; // unique number found
        }
    }
    return -1; // if no unique number found
}


// better with map 
int find_unique_number_map(vector<int> &arr, int n) {
    unordered_map<int, int> mpp; 
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    for (auto it : mpp) {
        if (it.second == 1) {
            return it.first; // unique number found
        }
    }
    return -1; // if no unique number found
}


// optimal approach using XOR
int find_unique_number_xor(vector<int> &arr, int n) {
    int xoor = 0;
    for (int i = 0; i < n; i++) {
        xoor ^= arr[i]; // XOR all elements
    }
    return xoor; // the result will be the unique number
}



// longest subarray with sum k (positive integers)
// brute force (generate all subarrays and check their sums)
int longest_subarray_with_sum_k_brute(vector<int> &arr, int n, int k) {
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == k) {
                max_length = max(max_length, j - i + 1);
            }
        }
    }
    return max_length;
}



// better using hashing
    // wont work for negative numbers   
int longest_subarray_with_sum_k_hashing(vector<int> &a, int n, int k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1); // subarray from start to i
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // for zeroes put this 
        // preSumMap[sum] = i; // store the first occurrence of this sum
    
        // for negative numbers, we need to store the first occurrence of each sum
        if (preSumMap.find(sum) == preSumMap.end()) {   
            preSumMap[sum] = i; // store the first occurrence of this sum
        }    
    }
    return maxLen;
}


// optimal using 2 pointers
// This approach works only for positive integers
int longest_subarray_with_sum_k_2_pointers(vector<int> &a, int n, int k) {
    int left = 0, right = 0;
    long long sum = 0; 
    int max_length = 0;
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
            max_length = max(max_length, right - left + 1);
        }
        right++;
        if (right < n) // check to avoid out of bounds
            sum += a[right];
    }
    return max_length;
}



// 2 sum problem
// brute force
vector<int> two_sum_brute(vector<int> &arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {};  // empty vector
}

// better using hashing
vector<int> two_sum_hashing(vector<int> &nums, int target) {
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i}; // return indices of the two numbers
        }
        mpp[num] = i; // store the index of the current number
    }
    return {-1, -1}; // empty vector if no pair found
}



// optimal using two pointers
string two_sum_two_pointers(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "Yes";
        } else if (sum < target) { left++;
        } else right--;
    }
    return "No"; // if no pair found
}



// sort an array of 0's, 1's, and 2's
// brute (just sort the array)
// better using counting sort
void sort_012(vector<int> &arr, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for (int i = 0; i < cnt0 ; i++) {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++) {
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < n; i++) {
        arr[i] = 2;
    }
}


// optimal using Dutch National Flag Algorithm
    void sort_012_dutch_flag(vector<int> &arr, int n) {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }    




















int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Optional input (needed only for rotations or search)
    int k; // for rotations, longest subarray, 
    int key; // for linear search
    int target; // for 2 sum problem
    
// =================== FUNCTION TEST CASES ===================
// Uncomment the following lines to test each function individually


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
    // int m, n2;
    // cin >> m >> n2;
    // vector<int> a(m), b(n2);
    // for (int i = 0; i < m; i++) cin >> a[i];
    // for (int i = 0; i < n2; i++) cin >> b[i];
    // vector<int> intersection_result = intersection_sorted_arrays_optimized(a, b, n2);
    // cout << "Intersection (optimized): ";
    // for (int x : intersection_result) cout << x << " ";
    // cout << endl;


// ==== Find Missing Number (Brute Force) ====
    // int missing_number = find_missing_number_brute(arr, n);
    // cout << "Missing number (brute): " << missing_number << endl;


// ==== Find Missing Number (Hashing) ====
    // int missing_number_hashing = find_missing_number_hashing(arr, n);
    // cout << "Missing number (hashing): " << missing_number_hashing << endl;


// ==== Find Missing Number (Optimal) ====
    // int missing_number_optimal = find_missing_number_optimal(arr, n);
    // cout << "Missing number (optimal): " << missing_number_optimal << endl;


// ==== Find Missing Number (XOR) for 0 to n ====
    // int missing_number_xor = find_missing_number_xor(arr, n);
    // cout << "Missing number (XOR): " << missing_number_xor << endl;


// ==== Maximum Consecutive 1's ====
    // cout << "Maximum consecutive 1's: " << max_consecutive_ones(arr, n) << endl;


// ==== Find the number that appears only once in an array where every other number appears twice ====
    // brute 
    // int unique_number_brute = find_unique_number_brute(arr, n);
    // cout << "Unique number (brute): " << unique_number_brute << endl;
    
    // better using hashing
    // int unique_number_hashing = find_unique_number_hashing(arr, n);
    // cout << "Unique number (hashing): " << unique_number_hashing << endl;
    
    // better with map
    // int unique_number_map = find_unique_number_map(arr, n);
    // cout << "Unique number (map): " << unique_number_map << endl;

    // optimal using XOR
    // int unique_number_xor = find_unique_number_xor(arr, n);
    // cout << "Missing number (XOR): " << unique_number_xor << endl;

    
// ==== Longest Subarray with Sum k (Brute Force) ====
    // brute force won't work for negative numbers and zeros
        // cin >> k;
        // int longest_length = longest_subarray_with_sum_k_brute(arr, n, k);
        // cout << "Longest subarray with sum " << k << ": " << longest_length << endl;

    // better using hash map for positive integers and zeros and optimal for negative numbers
        // cin >> k;
        // int longest_length_hashing = longest_subarray_with_sum_k_hashing(arr, n, k);
        // cout << "Longest subarray with sum " << k << " (hashing): " << longest_length_hashing << endl;   

    // optimal using 2 pointers for positive integers and zeros
        // cin >> k;
        // int longest_length_2_pointers = longest_subarray_with_sum_k_2_pointers(arr, n, k);
        // cout << "Longest subarray with sum " << k << " (2 pointers): " << longest_length_2_pointers << endl;


// ==== 2 Sum Problem ====
    // brute force
        // cin >> target;
        // vector<int> result = two_sum_brute(arr, n, target);
        // if (!result.empty()) {
        //     cout << "Indices: " << result[0] << ", " << result[1] << endl;
        // } else {
        //     cout << "No such pair found." << endl;
        // }
    
    
    // better using hashing
        // cin >> target; 
        // vector<int> result_hashing = two_sum_hashing(arr, target);
        // if (result_hashing[0] != -1) {
        //     cout << "Indices: " << result_hashing[0] << ", " << result_hashing[1] << endl;
        // } else {
        //     cout << "No such pair found." << endl;
        // }

    // optimal using two pointers 
        // cin >> target;
        // string result_two_pointers = two_sum_two_pointers(arr, target);
        // cout << result_two_pointers << endl;



// sort an array of 0's, 1's, and 2's
    // better using counting sort
        // sort_012(arr, n);
        // cout << "Sorted array of 0's, 1's, and 2's: ";
        // for (int x : arr) cout << x << " ";
        // cout << endl;


    // optimal using Dutch National Flag Algorithm
        sort_012(arr, n);
        cout << "Sorted array of 0's, 1's, and 2's (Dutch National Flag): ";
        for (int x : arr) cout << x << " ";
        cout << endl;


    



































    return 0;
}
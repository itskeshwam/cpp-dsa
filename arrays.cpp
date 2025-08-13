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



// majority element in an array 
// brute force
int majority_element_brute(vector<int> &arr, int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return arr[i]; // majority element found
        }
    }
    return -1; // if no majority element found
}



// better approach using hashing
int majority_element_hashing(vector<int> &v){
    map<int, int> mpp;
    for (int i = 0; i < v.size(); i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > v.size() / 2) {
            return it.first; // majority element found
        }
    }
    return -1; // if no majority element found
}


// optimal approach using Boyer-Moore Voting Algorithm
int majority_element_boyer_moore(vector<int> &v) {
    int count = 0;
    int element;
    for (int i = 0; i < v.size(); i++) {
        if (count == 0) {
            element = v[i];
            count = 1;
        } else if (v[i] == element) {
            count++;
        } else {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == element) {
            count1++;
        }
    } if (count1 > v.size() / 2) {
        return element; // majority element found
        }
    return -1; // if no majority element found
}



// maximum subarray sum (kadane's algorithm)
// Brute Force O(n^3)
int max_subarray_sum_brute(vector<int> &arr, int n) {
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

// Better O(n^2)
int max_subarray_sum_better(vector<int> &arr, int n) {
    int max_sum = INT_MIN; 
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

// Optimal O(n) using Kadane's Algorithm
int max_subarray_sum_kadane(vector<int> &arr) {
    int n = arr.size();
    int ansStart = -1, ansEnd = -1;
    int start = 0;

    int sum = 0; 
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i;
        sum += arr[i];

        if (sum > max_sum) {
            max_sum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}



// Best time to buy and sell stock
// Brute Force O(n^2)
int max_profit_brute(vector<int> &a) {
    int n = a.size();
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            maxProfit = max(maxProfit, a[j] - a[i]);
        }
    }
    return maxProfit;
}

// Optimal O(n) using a single pass
int max_profit(vector<int> &a) {
    int mini = a[0];
    int maxProfit = 0;
    for (int i = 1; i < a.size(); i++) {
        int cost = a[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, a[i]);
    }
    return maxProfit;
}



// rearrange array elements by sign 

// works for equal number of positive and negative elements

// Brute Force O(2n)
void rearrange_array_sign_brute(vector<int> &arr) {
    int n = arr.size();
    vector<int> positive, negative;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        arr[2 * i] = positive[i];
        arr[2 * i + 1] = negative[i];
    }
}

// Better O(n) using two pointers
vector<int> rearrange_array_sign(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            ans[posIndex] = arr[i];
            posIndex += 2;
        } else {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return ans;
}

// For unequal number of positive and negative elements
vector<int> rearrange_array_sign_unequal(vector<int> &arr) {
    vector<int> pos, neg;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    if (pos.size() >= neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[index++] = pos[i];
        }
    } else {
        for (int i = 0; i < pos.size(); i++) {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[index++] = neg[i];
        }
    }
    return arr;
}



// next permutation in an array 
// skip brute and just say 1) find all permutations and sort them, 2) linear search for the current permutation and return the next one.... we skip it cuz time comeplexity is O(n! x n) which is not feasible for large n

// better using cpp stl
void next_permutation(vector<int> &arr) {
    next_permutation(arr.begin(), arr.end());
}

// optimal approach using next permutation algorithm
vector<int> next_permutation_optimized(vector<int> &nums) {
    int ind = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            ind = i;
            break;
        }  
    }
    if (ind == -1) {
        reverse(nums.begin(), nums.end());
        return nums; // return the smallest permutation
    }
    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
    return nums; // return the next permutation
}
    
    

// leaders in an array
// brute - linear search for every element
vector<int> leaders_brute(vector<int> &arr) {
    vector<int> leaders;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] >= arr[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            leaders.push_back(arr[i]);
        }
    }
    return leaders;
}


// optimal using reverse traversal
vector<int> leaders_optimized(vector<int> &arr) {
    vector<int> leaders;
    int n = arr.size();
    int maxi = INT_MIN; // Initialize to minimum integer value
    for (int i = n - 1; i >= 0; i--){
        if (arr[i] > maxi) {
            leaders.push_back(arr[i]);
        }
        maxi = arr[i];
    } 
    // sort (leaders.begin(), leaders.end()); // if needed in ascending order
    reverse(leaders.begin(), leaders.end()); // to maintain the order of leaders as they appear 
    return leaders;
}


// longest consecutive sequence in an array
// brute 
int longest_consecutive_sequence_brute(vector<int> &arr) {
    int longest = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int count = 1;
        while (find(arr.begin(), arr.end(), x + 1) != arr.end()) {
            count = count + 1;
            x= x + 1;
        }
        longest = max(longest, count);
    }
    return longest;
}


// better by sorting the array
int longest_consecutive_sequence_sorted(vector<int> &arr) {
    if (arr.empty()) return 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] - 1 == lastSmaller) {
            cnt = cnt + 1; 
            lastSmaller = arr[i];
        } else if (lastSmaller != arr[i]) { 
            cnt = 1; // reset count for a new sequence
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// optimal using set 
int longest_consecutive_sequence_set(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;{
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]); // insert all elements into the set
    }
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) { // check if it is the start of a sequence
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) { // check for consecutive elements
                cnt++;
                x++;
            }
            longest = max(longest, cnt); // update longest sequence
        }
        }
    }
    return longest;
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
        // sort_012(arr, n);
        // cout << "Sorted array of 0's, 1's, and 2's (Dutch National Flag): ";
        // for (int x : arr) cout << x << " ";
        // cout << endl;


// majority element in an array
    // brute force
        // int majority_element = majority_element_brute(arr, n);
        // if (majority_element != -1) {
        //     cout << "Majority element: " << majority_element << endl;
        // } else {
        //     cout << "No majority element found." << endl;
        // }


    // better
        // int majority = majority_element_hashing(arr);
        // if (majority != -1) {
        //     cout << "Majority element (hashing): " << majority << endl;
        // } else {
        //     cout << "No majority element found." << endl;
        // }


    // optimal using Boyer-Moore Voting Algorithm
        // int majority_boyer_moore = majority_element_boyer_moore(arr);
        // if (majority_boyer_moore != -1) {
        //     cout << "Majority element (Boyer-Moore): " << majority_boyer_moore << endl;
        // } else {
        //     cout << "No majority element found." << endl;
        // }



// maximum subarray sum 
// Brute
    // int max_sum_brute = max_subarray_sum_brute(arr, n);
    // cout << "Maximum subarray sum (brute): " << max_sum_brute << endl;

    // Better
    // int max_sum_better = max_subarray_sum_better(arr, n);
    // cout << "Maximum subarray sum (better): " << max_sum_better << endl;

    // Optimal
    // int max_sum_kadane = max_subarray_sum_kadane(arr);
    // cout << "Maximum subarray sum (Kadane's): " << max_sum_kadane << endl;


// Best time to buy and sell stock
    // int max_profit_value = max_profit(arr);
    // cout << "Maximum profit from stock: " << max_profit_value << endl;


// rearrange array elements by sign
    // Brute Force (works for equal number of pos & neg)
    // rearrange_array_sign_brute(arr);
    // for (int num : arr) cout << num << " ";
    // cout << endl;

    // Better Approach (works for equal number of pos & neg)
    // vector<int> ans = rearrange_array_sign(arr);
    // for (int num : ans) cout << num << " ";
    // cout << endl;

    // Unequal case handling
    // vector<int> ans2 = rearrange_array_sign_unequal(arr);
    // for (int num : ans2) cout << num << " ";
    // cout << endl;


// next permutation in an array
    // stl     
        // next_permutation(arr);
        // cout << "Next permutation: ";
        // for (int num : arr) cout << num << " ";
        // cout << endl;

    // optimal approach using next permutation algorithm
        // vector<int> next_perm = next_permutation_optimized(arr);
        // cout << "Next permutation (optimized): ";
        // for (int num : next_perm) cout << num << " ";
        // cout << endl;


// leaders in an array 
    // brute 
        // vector<int> leaders = leaders_brute(arr);
        // cout << "Leaders in the array (brute): ";
        // for (int leader : leaders) 
        // {cout << leader << " " << endl;}
    
    // optimal approach
        // cout << "Leaders in the array (optimized): ";
        // for (int leader : leaders_optimized(arr)) 
        // {cout << leader << " ";}


// longest consecutive sequence
    // brute 
        // int longest_sequence = longest_consecutive_sequence_brute(arr);
        // cout << "Longest consecutive sequence (brute): " << longest_sequence << endl;

    // better
        // int longest_sequence_sorted = longest_consecutive_sequence_sorted(arr);
        // cout << "Longest consecutive sequence (sorted): " << longest_sequence_sorted << endl;

    // optimal using set
        int longest_sequence_set = longest_consecutive_sequence_set(arr);
        cout << "Longest consecutive sequence (optimal): " << longest_sequence_set << endl;





























    return 0;
}
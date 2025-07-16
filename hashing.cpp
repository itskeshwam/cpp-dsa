#include <bits/stdc++.h>
using namespace std;

// number of occurrences of each number in an array
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) { 
//         cin >> arr[i];
//         }

//     // precompute 
//         int hash[13] = {0};
//         for (int i = 0; i < n; i++) {
//             hash[arr[i]] += 1;
//         }

//     int q;
//     cin >> q;
//     while (q--) {
//         int number;
//         cin >> number;
//         // fetch 
//         cout << hash[number] << endl;
//     }
//     return 0;
// }


// number of occurrences of each character in a string
// int main() {
//     string s;
//     cin >> s;

//     //precompute
//     // using ASCII values, 256 is enough for all characters
//     int hash[256] = {0};
//     for (int i = 0; i < s.size(); i++) {
//         hash[s[i]]++;
//     }
//     int q;
//     cin >> q;
//     while (q--) {
//         char c;
//         cin >> c;
//         //fetch
//         cout << hash[c] << endl;
//     }
//     return 0;
// }

// using unordered_map for character frequency
// unordered map is nothing but key-value pair type and also is hash table
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // precompute
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }

//     // iterate through the map
//     for (auto it : mpp) {
//         cout << it.first << "->" << it.second << endl; // key and value
//     }


//     int q;
//     cin >> q;
//     while (q--) {
//         int number;
//         cin >> number;
//         //fetch
//         cout << mpp[number] << endl;   
//     }
//     return 0; 
// }


// same for characters
// int main() {
//     string s;
//     cin >> s;

//     // precompute
//     map<char, int> mpp;
//     for (int i = 0; i < s.size(); i++) {
//         mpp[s[i]]++;
//     }

//     // iterate through the map
//     for (auto it : mpp) {
//         cout << it.first << "->" << it.second << endl; // key and value
//     }

//     int q;
//     cin >> q;
//     while (q--) {
//         char c;
//         cin >> c;
//         // fetch
//         cout << mpp[c] << endl;   
//     }
//     return 0;
// }



// ALWAYS PREFER USING UNORDERED MAP FOR HASHING before using map... and if and when it shows time limit exceeded, then use map as unordered map is not ordered and it uses hashing which is faster than map 

// and for unordered the O(N) would happen because of collisions in the hash table, which can lead to a worst-case time complexity of O(N) for certain operations. However, in practice, unordered_map is often faster than map due to its average-case time complexity of O(1) for lookups, insertions, and deletions.
// In contrast, map has a time complexity of O(log N) for these operations because it is implemented as a balanced binary search tree. This means that while unordered_map can be faster on average, it can also have worse performance in cases of high collision rates, leading to longer chains of elements in the hash table.

// code for maximum frequency of a character in a string
int main() {
    string s;
    cin >> s;
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
    }

    char maxChar = s[0];
    int maxFreq = mpp[maxChar];
    for (auto it : mpp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxChar = it.first;
        }
    }
    cout << maxChar << "->" << maxFreq << endl;
    return 0;
}

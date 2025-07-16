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
int main() {
    string s;
    cin >> s;

    // precompute
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
    }

    // iterate through the map
    for (auto it : mpp) {
        cout << it.first << "->" << it.second << endl; // key and value
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch
        cout << mpp[c] << endl;   
    }
    return 0;
}
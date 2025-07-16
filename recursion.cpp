#include <bits/stdc++.h>
using namespace std;

// print name 5 times 
// void printName(int i, int n)
// {
//     if (i > n) 
//         return;
//     cout << "Keshwam" << endl;
//     printName(i + 1, n);
// }
// int main(){
//     int n;
//     cin >> n;
//     printName(1, n);
// }



//print linearly from 1 to n
// void printNum(int i, int n){
//     if (i > n) 
//         return;
//     cout << i << " ";
//     printNum(i + 1, n);
// }
// int main(){
//     int n;
//     cin >> n;
//     printNum(1, n);
// }



// print n to 1
// void printRev(int i, int n){
//     if (i < 1) 
//         return;
//     cout << i << " ";
//     printRev(i - 1, n);
// }
// int main(){
//     int n;
//     cin >> n;
//     printRev(n, n);
// }




// print linearly from 1 to n using backtracking
// void printNum(int i, int n){
//     if (i<1) 
//         return;
//     printNum(i-1,n);
//     cout << i << endl;
//     // cout << i << " "; if wanted in same line
// }
// int main(){
//     int n;
//     cin >> n;
//     printNum(n,n);
// }




// print linearly from n to 1 using backtracking (without using i-1)
// void RevNum(int i, int n){
//     if (i > n) 
//         return;
//     RevNum(i + 1, n);
//     cout << i << " ";
// }
// int main(){
//     int n;
//     cin >> n;
//     RevNum(1, n);
// }



// sum of n numbers 
// functional 
// int sum(int n){
//     if (n==0) return 0;
//     return n + sum (n-1);
// }
// int main(){
//     int n; 
//     cin >> n;
//     cout << sum(n);
// }

// factorial of n 
// int fact(int n){
//     if (n == 1) return 1;
//     return n * fact(n-1);
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << fact(n);
// }



// reverse an array using 2 pointers or 2 variables
// void reverse(int arr[], int i, int n){
//     if (i >= n / 2) return;
//     swap(arr[i], arr[n - i - 1]);
//     reverse(arr, i + 1, n);
// }
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++) cin >> arr[i];
//     reverse(arr, 0, n);
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }


// check palindrome using recursion
// bool palindrome(string s, int i, int n){
//     if (i >= n / 2) return true;
//     if (s[i] == s[n - i - 1])
//         return palindrome(s, i + 1, n);
//     return false;
// }
// int main(){
//     string s;
//     cin >> s;
//     int n = s.length();
//     if (palindrome(s, 0, n)) 
//         cout << "is palindrome";
//     else 
//         cout << "is not palindrome";
// }

// time complexity of palindrome is O(n) and space complexity is O(n) due to recursion stack
// to reduce time complexity of palindrome to O(n) and space complexity to O(1)

// bool palindrome(string s){
//     int n = s.length();
//     for (int i = 0; i < n / 2; i++) {
//         if (s[i] != s[n - i - 1]) 
//             return false;
//     }
//     return true;
// }
// int main(){
//     string s;
//     cin >> s;
//     if (palindrome(s)) 
//         cout << "is palindrome";
//     else 
//         cout << "is not palindrome";
// }


// fibonacci series using recursion
// int fib(int n){
//     if (n <= 1) return n;
//     return fib(n - 1) + fib(n - 2);
// }
// int main(){
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cout << fib(i) << " ";
//     }
//     return 0;
// }


// print all subsequences of a string
void printF(int ind, vector<int> &ds, int arr[], int n){
    if (ind == n) {
        for (auto it : ds) {
            cout << it << " ";
        }
        if (ds.size() == 0) {
            cout << "{}"; // null subsequence
        }cout << endl;
        return; 
    }
    // not take an element in subsequence
    printF(ind + 1, ds, arr, n); 
    
    // take an element in subsequence
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();

}

int main(){
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printF(0, ds, arr, n);
}
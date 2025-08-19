#include <bits/stdc++.h>
using namespace std;

// --- All your original functions are here ---

// print name 5 times 
void printName(int i, int n)
{
    if (i > n) 
        return;
    cout << "Keshwam" << endl;
    printName(i + 1, n);
}

//print linearly from 1 to n
// NOTE: Renamed from printNum to printNum_1_to_N to avoid conflicts.
void printNum_1_to_N(int i, int n){
    if (i > n) 
        return;
    cout << i << " ";
    printNum_1_to_N(i + 1, n);
}

// print n to 1
void printRev(int i, int n){
    if (i < 1) 
        return;
    cout << i << " ";
    printRev(i - 1, n);
}

// print linearly from 1 to n using backtracking
// NOTE: Renamed from printNum to printNum_1_to_N_backtracking to avoid conflicts.
void printNum_1_to_N_backtracking(int i, int n){
    if (i<1) 
        return;
    printNum_1_to_N_backtracking(i-1,n);
    cout << i << endl;
    // cout << i << " "; if wanted in same line
}

// print linearly from n to 1 using backtracking (without using i-1)
void RevNum(int i, int n){
    if (i > n) 
        return;
    RevNum(i + 1, n);
    cout << i << " ";
}

// sum of n numbers 
// functional 
int sum(int n){
    if (n==0) return 0;
    return n + sum (n-1);
}

// factorial of n 
int fact(int n){
    if (n == 1) return 1;
    return n * fact(n-1);
}

// reverse an array using 2 pointers or 2 variables
void reverse(int arr[], int i, int n){
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverse(arr, i + 1, n);
}

// check palindrome using recursion
// NOTE: Renamed from palindrome to palindrome_recursive to avoid conflicts.
bool palindrome_recursive(string s, int i, int n){
    if (i >= n / 2) return true;
    if (s[i] == s[n - i - 1])
        return palindrome_recursive(s, i + 1, n);
    return false;
}

// time complexity of palindrome is O(n) and space complexity is O(n) due to recursion stack
// to reduce time complexity of palindrome to O(n) and space complexity to O(1)
// NOTE: Renamed from palindrome to palindrome_iterative to avoid conflicts.
bool palindrome_iterative(string s){
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) 
            return false;
    }
    return true;
}

// fibonacci series using recursion
int fib(int n){
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

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


// --- Wrapper functions to run your original main() logic ---
void run_printName() {
    int n;
    cin >> n;
    printName(1, n);
}

void run_printNum_1_to_N() {
    int n;
    cin >> n;
    printNum_1_to_N(1, n);
}

void run_printRev() {
    int n;
    cin >> n;
    printRev(n, n);
}

void run_printNum_1_to_N_backtracking() {
    int n;
    cin >> n;
    printNum_1_to_N_backtracking(n,n);
}

void run_RevNum() {
    int n;
    cin >> n;
    RevNum(1, n);
}

void run_sum() {
    int n; 
    cin >> n;
    cout << sum(n);
}

void run_fact() {
    int n;
    cin >> n;
    cout << fact(n);
}

void run_reverse() {
    int n;
    cin >> n;
    // Using a vector instead of a VLA for better compatibility
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    reverse(arr.data(), 0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void run_palindrome_recursive() {
    string s;
    cin >> s;
    int n = s.length();
    if (palindrome_recursive(s, 0, n)) 
        cout << "is palindrome";
    else 
        cout << "is not palindrome";
}

void run_palindrome_iterative() {
    string s;
    cin >> s;
    if (palindrome_iterative(s)) 
        cout << "is palindrome";
    else 
        cout << "is not palindrome";
}

void run_fib() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
}

void run_printF_subsequences() {
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printF(0, ds, arr, n);
}


// --- The single, common main function ---
int main(){
    // Uncomment the function you want to run

    // run_printName();
    // run_printNum_1_to_N();
    // run_printRev();
    // run_printNum_1_to_N_backtracking();
    // run_RevNum();
    // run_sum();
    // run_fact();
    // run_reverse();
    // run_palindrome_recursive();
    // run_palindrome_iterative();
    // run_fib();
    run_printF_subsequences(); // The last one from your file is uncommented by default.
    
    return 0;
}
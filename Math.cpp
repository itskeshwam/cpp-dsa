#include <bits/stdc++.h>
using namespace std;

// Digit Extraction 
// int main(){
//     int n;
//     cin >> n;
    
//     while (n>0){
//         int lastdigit = n % 10;
//         n=n/10;
//         cout << lastdigit;
//         cout << endl;
//     }
// }



// Count the Number of digits
// int main(){
//     int n;
//     cin >> n;
//     int cnt = 0;
//     while (n>0){
//         n=n/10;
//         cnt += 1;
//     }cout << "Number of digits is: " << cnt;
// }

// also if we notice the count of digit is usually the log of number + 1 so we can also do that "cnt = (int)(log10(n) + 1)"

// Reverse a number
// int main() {
//     int n;
//     cin >> n;
//     int reverse = 0;

//     while (n > 0) {
//         int lastdigit = n % 10;
//         reverse = reverse * 10 + lastdigit;
//         n = n / 10;
//     }
    
//     cout << reverse;
// }



// palindrome number
// int main() {

//     int n;
//     cin >> n;
//     int original = n;
//     int reverse = 0;

//     while (n > 0) {
//         int lastdigit = n % 10;
//         reverse = reverse * 10 + lastdigit;
//         n = n / 10;
//     }

//     if (original == reverse) {
//         cout << original << " Is Palindrome";
//     } else {
//         cout << original << " Is Not a Palindrome";
//     }
// }



// armstrong number
// int main(){
//     int n;
//     cin >> n;
//     int original = n;
//     int sum = 0;

//     while (n > 0) {
//         int lastdigit = n % 10;
//         sum += lastdigit * lastdigit * lastdigit; // For 3-digit numbers
//         n = n / 10;
//     }

//     if (original == sum) {
//         cout << original << " Is an Armstrong Number";
//     } else {
//         cout << original << " Is Not an Armstrong Number";
//     }
    
//     return 0;
// }



// print all divisors 
// 2 methods 

// int main(){
//     int n;
//     cin >> n;
//     for (int i = 1; i<=n; i++){
//         if (n%i == 0){                  // Time complexity O(n)
//             cout << i << " ";
//         }
//     }
// }

// method 2 using list 

// int main(){
//     int n; 
//     cin >> n;
//     vector <int> ls;
//     for (int i = 0; i*i<=n; i++){
//         if (n%i==0){
//             ls.push_back(i);
//             if((n/i) != i){
//                 ls.push_back(n/i);
//             }
//         }
//     }
//     sort(ls.begin(), ls.end());
//     for (auto it : ls) cout << it << " ";
// }


// prime number
// int main(){
//     int n;
//     cin >> n;
//     int cnt = 0;
//     for (int i = 1; i <= sqrt(n); i++) {
//         if (n % i == 0) {
//             cnt++;
//             if (i != n / i) { // Check to avoid counting the square root twice
//                 cnt++;
//             }
//         }
//     }if (cnt == 2) {
//         cout << n << " is a prime number";
//     } else {
//         cout << n << " is not a prime number";
//     }
// }



// GCD and HCF
int main(){
    int a, b;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) {
        cout << b << endl;
    } else {
        cout << a << endl;
    }
    return 0;
}
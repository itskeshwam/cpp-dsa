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
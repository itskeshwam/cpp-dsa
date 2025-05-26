#include <bits/stdc++.h>
using namespace std;
// nxn star pattern

// int main(){
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             cout << '*';
//         }
//         cout << endl;
//     }
// }

// left triangle star pattern

// int main(){
//     int n;
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout << '*';
//         } cout << endl;
//     } 
// } 

// 1/12/123/1234/12345 pattern in left triangle 
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout << j;
        } cout << endl;
    }

}
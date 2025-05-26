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
// int main(){
//     int n;
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=i; j++){
//             cout << j;
//         } cout << endl;
//     }
// }


// inverted left triangle 
// int main(){
//     int n;
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         for (int j=i; j<=n; j++){
//             cout << "*";
//         } cout << endl;
//     }
// }


// inverted left triangle with numbers 
// int main(){
//     int n;
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         for (int j=1; j<=n-i+1; j++){
//             cout << j;
//         } cout << endl;
//     }
// }

// star pyramid 
// int main(){
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         // space 
//         for (int j=0; j<n-i-1; j++){
//             cout << " ";
//         }
        
//         // star 
//         for (int j=0; j<2*i+1; j++){
//             cout << "*";
//         }

//         // space 
//         for (int j=0; j<n-i-1; j++){
//             cout << " ";
//         } cout << endl;
//     }
// }

// inverted star pyramid
// int main(){
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++){
        
//         //space 
//         for (int j =0; j<i; j++){
//             cout <<" ";
//         }

//         //stars 
//         for(int j=0;j< 2*n -(2*i +1);j++){    
//             cout<<"*";
//         }
        
//         // spaces
//         for (int j =0; j<i; j++){
//             cout <<" ";}
//         cout << endl;
//     }
// }

// diamond pattern
// combine both pyramid?

void erect_pyramid(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
        for(int j=0;j< 2*i+1;j++){
            
            cout<<"*";
        }
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
}

void inverted_pyramid(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
        for(int j=0;j< 2*N -(2*i +1);j++){
            
            cout<<"*";
        }
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }cout << endl;
    }
}

int main()
{   
    int N = 5;
    erect_pyramid(N);
    inverted_pyramid(N);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// // selection sort 
// void selection_sort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int mini = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[mini]) {
//                 mini = j;
//             }
//         }
//         swap(arr[i], arr[mini]);
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {cin >> arr[i];}
//     selection_sort(arr, n);
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


// bubble sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


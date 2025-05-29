#include <bits/stdc++.h> //includes all libraries 
// <math.h> for math
// <string.h> for string 
// <iostream.h> for input output 
using namespace std; // if not you have to write std::cin or std::cout >

// functions 
void print(){ // void function - dosn't return anything
    cout << "raj";
}
int sum(int a, int b){
    return a+b;
}

int main(){ // main function - entry point of the program
    print();
    int s = sum(1, 5);
    // prints 6
    cout << s;
    return 0;
}


// stls
// 4 types: 
// 1) algorithms


// 2) containers
void explainPairs(){
    pair<int , int> a = {1, 3}; // pair is a container that holds two values
    
    cout << a.first << " " << a.second << endl; // prints 1 3
    
    pair<int, pair<int, int>> p = {1, {2, 3}}; // nested pair
    
    cout << p.first << " " << p.second.first << " " << p.second.second << endl; // prints 1 2 3

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} }; // array of pairs

    cout << arr[1].second << endl; // prints 5
}

// 3) function objects


// 4) iterators




// pairs 




// vectors 




// 
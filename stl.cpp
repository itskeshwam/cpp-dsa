#include <bits/stdc++.h> //includes all libraries 
// <math.h> for math
// <string.h> for string 
// <iostream.h> for input output 
using namespace std; // if not you have to write std::cin or std::cout >

// functions 
void print(){ // void function - dosn't return anything
    cout << "Keshwam";
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
    
    cout << p.first << " " << p.second.first << " " << p.second.second // prints 1 2 3

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} }; // array of pairs

    cout << arr[1].second << endl; // prints 5
}

// 3) function objects


// 4) iterators




// pairs 




// vectors 
void explainVector() {

    v.push_back(1); // adds 1 to the end of the vector
    v.emplace_back(2); // adds 2 to the end of the vector

    vector<pair<int, int>> vec; // vector of pairs

    vec.push_back({1, 2}); // adds a pair to the end of the vector
    vec.emplace_back(3, 4); // adds a pair to the end of the vector
    
    vecor<int> v(5, 10); // creates a vector of size 5 with all elements initialized to 10

    vector<int v(5); // creates a vector of size 5 with all elements initialized to 0

    vector<int> v1(5, 20); // creates a vector of size 5 with all elements initialized to 20
    vector<int> v2(v1); // creates a vector v2 that is a copy of v1

    vector<int>::iterator it v.begin(); // creates an iterator for the vector

    it++;
    cout << *(it) << " "; // prints the element at the iterator's position
}




// 
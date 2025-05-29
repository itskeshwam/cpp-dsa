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





// 4 types: Algorithms, containers, iterators, and function objects

// containers
// pairs 
void explainPairs(){

    pair<int , int> a = {1, 3}; // pair is a container that holds two values
    
    cout << a.first << " " << a.second << endl; // prints 1 3
    
    pair<int, pair<int, int>> p = {1, {2, 3}}; // nested pair
    
    cout << p.first << " " << p.second.first << " " << p.second.second // prints 1 2 3

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} }; // array of pairs

    cout << arr[1].second << endl; // prints 5
}















// vectors 
void explainVector() {
vector<int> v; 
    v.push_back(1); // adds 1 to the end of the vector
    v.emplace_back(2); // adds 2 to the end of the vector
// diffenece between them in simple words is pushback copies while emplaceback constructs in place, so it is more efficient for complex objects. 
    vector<pair<int, int>> vec; // vector of pairs

    vec.push_back({1, 2}); 
    vec.emplace_back(3, 4); 
    // difference here is curly braces {} are used in push_back to create a pair, while emplace_back directly constructs the pair in place.

    vecor<int> v(5, 10); // creates a vector of size 5 with all elements initialized to 10

    vector<int v(5); // creates a vector of size 5 with all elements initialized to 0 or garbage values

    vector<int> v1(5, 20); // creates a vector of size 5 with all elements initialized to 20
    vector<int> v2(v1); // creates a vector v2 that is a copy of v1

    vector<int>::iterator it v.begin(); // creates an iterator for the vector and points it to the memory location of the first element

    it++; 
    cout << *(it) << " "; // * prints the element at the iterator's position 

    it = it + 2; // moves the iterator two positions forward
    cout << *(it) << " "; // prints the element at the new iterator's position

    vector<int>::iterator it = v.end(); // points to the memory location just after the last element of the vector and not the last element itself 
    
    // THESE ARE NEVER USED IN PRACTICE, THEY ARE JUST FOR DEMONSTRATION
    // reverse end
    vector<int>::iterator it = v.rend(); // points to the memory location just before the first element of the vector in reverse order 
    
    // reverse begin
    vector<int>::iterator it = v.rbegin(); // points to the memory location of the last element of the vector in reverse order 


    cout << v[0] << " " << v.at(0); 
    cout << v.back() << " "; // prints the last element of the vector

    // auto keyword is used to automatically assign the datatype of the variable
    for (auto it = v.begin(); it != v.end(); it++) { // iterates through the vector using an iterator
        cout << *it << " "; // prints the element at the iterator's position
    }

    // auto it : v is similar to the above for loop, but it is a range-based for loop where it automatically iterates through the vector without needing an iterator
    for (auto it : v) {
        cout << it << " "; // prints the element at the iterator's position
    }

    // deleting elements from vector
    v.erase(v.begin() + 2); // deletes the element at index 2, 
    // for example if v = {1, 2, 3, 4, 5}, then after this operation v = {1, 2, 4, 5}
    v.erase(v.begin() + 2, v.begin() + 5); // deletes the elements from index 2 to index 5 (exclusive)
    // for example if v = {1, 2, 3, 4, 5}, then after this operation v = {1, 2} because it deletes the elements 3, 4, and 5 as v.begin() + 5 points to the memory location just after the last element of the vector and not the last element itself therefore deleting the element at index 5
    v.clear(); // clears the vector, removing all elements


    // inserting elements into vector
    vector<int> v(2, 100); //{ 100 , 100 }
    v.insert(v.begin(), 300); // { 300 , 100 , 100 } (adds at the beginning)
    v.insert(v.begin() + 1, 2, 10); // { 300 , 10 , 10 , 100 , 100 } (adds two 10 at second position)

    vector<int> copy(2, 50); // { 50 , 50 }
    v.insert(v.begin(), copy.begin(), copy.end()); // // { 50 , 50 , 300 , 10 , 10 , 100 , 100 } (inserts the elements of copy vector at the beginning of v vector)

    // {10 , 20}
    cout << v.size(); // 2

    v.pop_back(); // {10} // removes the last element of the vector

    // v1 -> {10 , 20}
    // v2 -> {30 , 40}
    v1.swap(v2); // v1 -> {30 , 40} and v2 -> {10 , 20} // swaps 

    cout << v.empty(); // returns true if the vector is empty, false otherwise

}










// Lists

void explainList() {
    list<int> l; // creates an empty list of integers

    l.push_back(2); // {2}
    l.emplace_back(4); // {2, 4} 
    l.push_front(5); // {5, 2, 4} 
    l.emplace_front(); {2 , 4} 

    // rest functions are similar to vector
    // begin, end, rbegin, rend, clear, insert, size, swap

} 











// Deque
void explainDeque() {
    deque<int> d; // creates an empty deque of integers

    d.push_back(1); // {1}
    d.emplace_back(2); // {1, 2}
    d.push_front(4); // {4, 1, 2}
    d.emplace_front(3); // {3, 4, 1, 2}

    d.pop_back(); // {4, 3, 1} // removes the last element of the deque
    d.pop_front(); // {3, 1} // removes the first element of the deque

    dq.back(); // returns the last element of the deque
    dq.front(); // returns the first element of the deque

    // rest functions are similar to vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}










// stacks
void explainStack() {
    stack<int> s; // creates an empty stack of integers

    s.push(1); // {1}
    s.push(2); // {1, 2}
    s.push(3); // {1, 2, 3}
    s.push(3); // {1, 2, 3, 3} // stack allows duplicate elements
    s.emplace(5); // {1, 2, 3, 3, 5} // emplace adds an element to the top of the stack

    cout << s.top(); // returns the top element of the stack (5 in this case)

    
    s.pop(); // removes the top element of the stack, now {1, 2, 3, 3}

    cout << s.top(); // 3
    cout << s.size(); // 2
    cout << s.empty(); // returns true if the stack is empty, false otherwise

    stack<int> s1 , s2; 
    s1.swap(s2); // swaps the contents 

}






// queues
void explainQueue() {
    queue<int> q; // creates an empty queue of integers

    q.push(1); // {1}
    q.emplace(2); // {1, 2}
    q.push(3); // {1, 2, 3}

    q.back() += 5; // adds 5 to the last element of the queue, now {1, 2, 8}  

    cout << q.back(); // returns the last element of the queue (8 in this case)
    cout << q.front(); // returns the first element of the queue (1 in this case)

    q.pop(); // removes the first element of the queue, now {2, 8}

    cout << q.front(); // 2 


    cout << q.size(); // returns the size of the queue
    cout << q.empty(); // returns true if the queue is empty, false otherwise

    // size swap emplace are similar to stack and deque
}








// priority queues
void explainPriorityQueue() {
    priority_queue<int> pq; // creates an empty priority queue of integers

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2} // elements are sorted in descending order by default
    pq.emplace(10); // {10, 8, 5, 2} // emplace adds an element to the top of the priority queue

    cout << pq.top(); // returns the top element of the priority queue (3 in this case)

    pq.pop(); // removes the top element of the priority queue, now {3, 2, 1}

// size swap empty are similar to stack and deque


// minimum heap
    priority_queue<int, vector<int>, greater<int>> pq; // creates an empty minimum heap of integers

   pq.push(5); // {5}
   pq.push(2); // {2, 5}
   pq.push(8); // {2, 5, 8} // elements are sorted in ascending order
   pq.emplace(10); // {2, 5, 8, 10} // emplace adds an element to the top of the minimum heap

    cout << pq.top(); // returns the top element of the minimum heap (2 in this case)

    pq.pop(); // removes the top element of the minimum heap, now {2, 5, 8}

}








// sets (sorted and unique elements)
void explainSet() {
    set<int> s; // creates an empty set of integers

    s.insert(1); // {1}
    s.emplace(2); // {1, 2}
    s.insert(2); // {1, 2} // set does not allow duplicate elements
    s.insert(4); // {1, 2, 4}
    s.emplace(3); // {1, 2, 3, 4} // emplace adds an element to the set

    // functionality of insert in vector can be also used here
    // increases efficiency 
    
    //begin(), end(), rbegin(), rend(), clear(), size(), swap() are  similar to vector

    //{1, 2, 3, 4, 5}
    auto it = s.find(3); // finds the element 3 in the set, (iterator)
    auto it = s.find(6); // if not found, it points to the end of the set (s.end())

    st.erase(5); // removes the element 5 from the set, takes logrithmic time

    int cnt = s.count(1); // returns the number of occurrences of 1 in the set (0 or 1)
    
    auto it = s.find(3);
    st.erase(it); // removes the element at the iterator's position, takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = s.find(2); 
    auto it2 = s.find(4);
    s.erase(it1, it2); // after erase {1, 4, 5} [first , last) 
    
    // lower_bound and upper_bound functions works in the same way as in vector
    auto it = s.lower_bound(2); // 
    auto it = s.upper_bound(3); // 
}








// Multisets (sorted and duplicate elements)
void explainMultiset() {
    multiset<int> ms; 

    ms.insert(1); // {1}
    ms.emplace(1); // {1, 1} // allows duplicate elements
    ms.insert(1); // {1, 1, 1} 

    ms.erase(1); // all 1s are removed, now {}

    int cnt = ms.count(1); 

    ms.erase(ms.find(1)); // erase one occurrence of 1, now {1, 1}, pointing address

    ms.erase(ms.find(1), ms.find(1)+2); // find 1 and go till 2

    // rest all func remains same as sets
}


// unordered sets (hashing)
void explainUnorderedSet() {
    unordered_set<int> us; 

    // lower_bound and upper_bound functions are not available in unordered sets
    // unordered sets do not maintain any order of elements, they are based on hashing
    // better complexity than sets except some when collisions occur
}

// maps (key-value pairs)  unique keys and sorted
void explainMap() {
    map<int, int> mpp;

    map<pair<int, int>, int> mpp; // map of pairs


    mpp[1] = 2; // {1: 2}
    mpp.emplace({3, 1}); // {1: 2, 3: 1} 

    mpp.insert({2, 4}); // {1: 2, 2: 4, 3: 1} 

    mpp[{2, 3}] = 10; // {1: 2, 2: 4, 3: 1, (2, 3): 10} // using pair as key

{
    {1, 2}
    {2, 4}
    {3, 1} 
}

for (auto it : mpp) {
    cout << it.first << " " << it.second << endl; // prints the key-value pairs
}

cout << mpp[1];
cout << mpp[5]; 




// Algorithms
sort
sort(v.begin(), v.end()); // sorts the vector v in ascending order
sort(v.begin(), v.end(), greater<int>()); // sorts the vector v in descending order

// reverse
reverse(v.begin(), v.end()); // reverses the vector v

// find
auto it = find(v.begin(), v.end(), 5); // finds the element 5 in the vector v, returns an iterator to the element if found, otherwise returns v.end()

sort(a, a+n, comp);

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) return true; 
    if (a.second > b.second) return false;
    
    if (a.first > b.first) return true;




// builtin_popcount






// COMPLETE THE VIDEO OF STL
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// --- VECTOR ---
void demo_vector()
{
    vector<int> v = {4, 2, 5, 1};
    v.push_back(10);             // insert at end
    sort(v.begin(), v.end());    // sort ascending
    reverse(v.begin(), v.end()); // reverse
    v.pop_back();                // remove last

    cout << "vector: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

/*
vector:
- Dynamic array supporting random access.
- Operations:
  - push_back(): Adds element at the end.
  - pop_back(): Removes last element.
  - sort(): Sorts elements in ascending order.
  - reverse(): Reverses the order of elements.
- Exceptions:
  - Accessing out-of-bound indices leads to undefined behavior.
*/

// --- SET ---
void demo_set()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(2); // ignored

    cout << "set: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // find, erase
    if (s.find(2) != s.end())
        s.erase(2);

    cout << "after erase(2): ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // lower_bound, upper_bound
    cout << "lower_bound(2): " << *s.lower_bound(2) << endl;
    cout << "upper_bound(2): " << *s.upper_bound(2) << endl;
}

/*
set:
- Ordered collection of unique elements.
- Operations:
  - insert(): Adds element; duplicates are ignored.
  - erase(): Removes specified element.
  - find(): Searches for an element.
  - lower_bound(): Returns iterator to first element >= value.
  - upper_bound(): Returns iterator to first element > value.
- Exceptions:
  - Dereferencing end() iterator is undefined.
*/

// --- UNORDERED_SET ---
void demo_unordered_set()
{
    unordered_set<int> us = {1, 3, 2, 4, 1};
    cout << "unordered_set: ";
    for (int x : us)
        cout << x << " ";
    cout << endl;
}

/*
unordered_set:
- Unordered collection of unique elements.
- Operations:
  - insert(), erase(), find() similar to set.
- Notes:
  - Average time complexity for operations is O(1).
  - No ordering; elements are stored based on hash.
*/

// --- MULTISET ---
void demo_multiset()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    cout << "multiset: ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    ms.erase(ms.find(2)); // only one 2 erased

    cout << "after one erase(2): ";
    for (int x : ms)
        cout << x << " ";
    cout << endl;
}

/*
multiset:
- Ordered collection allowing duplicate elements.
- Operations:
  - insert(): Adds element; duplicates allowed.
  - erase(): Removes one instance of the element.
  - find(): Finds an element.
- Notes:
  - Useful when frequency of elements matters.
*/

// --- UNORDERED_MULTISET ---
void demo_unordered_multiset()
{
    unordered_multiset<int> ums = {1, 2, 2, 3};
    cout << "unordered_multiset: ";
    for (int x : ums)
        cout << x << " ";
    cout << endl;
}

/*
unordered_multiset:
- Unordered collection allowing duplicate elements.
- Operations similar to multiset.
- Notes:
  - Average time complexity for operations is O(1).
  - No ordering; elements are stored based on hash.
*/

// --- MAP ---
void demo_map()
{
    map<string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;

    cout << "map: ";
    for (auto p : m)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;

    // find, erase
    if (m.find("b") != m.end())
        m.erase("b");
    cout << "after erase(b): ";
    for (auto p : m)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

/*
map:
- Ordered collection of key-value pairs with unique keys.
- Operations:
  - insert(), erase(), find(), operator[].
- Notes:
  - Keys are ordered.
  - operator[] inserts key if not present.
*/

// --- UNORDERED_MAP ---
void demo_unordered_map()
{
    unordered_map<string, int> um = {{"a", 1}, {"b", 2}, {"c", 3}};
    cout << "unordered_map: ";
    for (auto p : um)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

/*
unordered_map:
- Unordered collection of key-value pairs with unique keys.
- Operations similar to map.
- Notes:
  - Average time complexity for operations is O(1).
  - No ordering; elements are stored based on hash.
*/

// --- MULTIMAP ---
void demo_multimap()
{
    multimap<string, int> mm;
    mm.insert({"a", 1});
    mm.insert({"a", 2});

    cout << "multimap: ";
    for (auto p : mm)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

/*
multimap:
- Ordered collection of key-value pairs allowing duplicate keys.
- Operations:
  - insert(), erase(), find().
- Notes:
  - Useful when multiple values for a key are needed.
*/

// --- UNORDERED_MULTIMAP ---
void demo_unordered_multimap()
{
    unordered_multimap<string, int> umm;
    umm.insert({"x", 1});
    umm.insert({"x", 2});

    cout << "unordered_multimap: ";
    for (auto p : umm)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

/*
unordered_multimap:
- Unordered collection of key-value pairs allowing duplicate keys.
- Operations similar to multimap.
- Notes:
  - Average time complexity for operations is O(1).
  - No ordering; elements are stored based on hash.
*/

// --- QUEUE ---
void demo_queue()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "queue front: " << q.front() << endl;
    q.pop();
    cout << "after pop, front: " << q.front() << endl;
}

/*
queue:
- FIFO (First-In-First-Out) data structure.
- Operations:
  - push(): Adds element at the end.
  - pop(): Removes element from the front.
  - front(): Accesses the front element.
- Notes:
  - No iterators; cannot traverse.
*/

// --- STACK ---
void demo_stack()
{
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);

    cout << "stack top: " << s.top() << endl;
    s.pop();
    cout << "after pop, top: " << s.top() << endl;
}

/*
stack:
- LIFO (Last-In-First-Out) data structure.
- Operations:
  - push(): Adds element at the top.
  - pop(): Removes element from the top.
  - top(): Accesses the top element.
- Notes:
  - No iterators; cannot traverse.
*/

// --- DEQUE ---
void demo_deque()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);

    cout << "deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_back();
    dq.pop_front();
}

/*
deque:
- Double-ended queue supporting fast insertions/removals at both ends.
- Operations:
  - push_back(), push_front(), pop_back(), pop_front().
- Notes:
  - Supports random access.
*/

// --- PRIORITY_QUEUE ---
void demo_priority_queue()
{
    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);

    cout << "priority_queue top: " << pq.top() << endl;

    pq.pop();
    cout << "after pop, top: " << pq.top() << endl;

    // Min heap using greater
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(2);
    cout << "min-heap top: " << min_pq.top() << endl;
}

/*
priority_queue:
- Container adaptor that provides constant time lookup of the largest (by default) element.
- Operations:
  - push(), pop(), top().
- Notes:
  - By default, it's a max-heap.
  - To create a min-heap, use greater<int> as comparator.
*/

// --- LIST ---
void demo_list()
{
    list<int> l = {1, 2, 3};
    l.push_front(0);
    l.push_back(4);
    l.reverse();

    cout << "list: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;
}

/*
list:
- Doubly linked list.
- Operations:
  - push_front(), push_back(), pop_front(), pop_back(), reverse().
- Notes:
  - Efficient insertions/deletions from both ends.
  - No random access; use iterators.
*/

// --- SORT + PAIR + CUSTOM COMPARATOR ---
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // sort by second
}

void demo_sort_pair_custom_cmp()
{
    vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 1}};
    sort(v.begin(), v.end(), cmp);

    cout << "sorted pairs: ";
    for (auto p : v)
        cout << "{" << p.first << ", " << p.second << "} ";
    cout << endl;
}

/*
sort with custom comparator:
- Sorts a vector of pairs based on the second element.
- 'cmp' function defines the sorting criteria.
- Useful when default sorting (by first element) isn't desired.
*/

// --- NEXT_PERMUTATION ---
void demo_next_permutation()
{
    vector<int> v = {1, 2, 3};
    cout << "permutations: ";
    do
    {
        for (int x : v)
            cout << x << " ";
        cout << "| ";
    } while (next_permutation(v.begin(), v.end()));
    cout << endl;
}

/*
next_permutation:
- Generates the next lexicographically greater permutation.
- Useful for generating all permutations of a sequence.
- Returns false when the sequence is in descending order.
*/

// --- __builtin_popcount ---
void demo_builtin_popcount()
{
    int x = 7; // binary: 111
    cout << "__builtin_popcount(7): " << __builtin_popcount(x) << endl;
}

/*
__builtin_popcount:
- Counts the number of set bits (1s) in an integer.
- Useful for bit manipulation problems.
- GCC specific; not standard C++.
*/

// --- MIN_ELEMENT / MAX_ELEMENT ---
void demo_min_max_element()
{
    vector<int> v = {4, 2, 8, 1, 6};
    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());
    cout << "min: " << *min_it << ", max: " << *max_it << endl;
}

/*
min_element / max_element:
- Finds the smallest/largest element in a range.
- Returns an iterator to the element.
- Useful for quick retrieval without sorting.
*/

// --- MAIN ---
int main()
{
    demo_vector();
    demo_set();
    demo_unordered_set();
    demo_multiset();
    demo_unordered_multiset();
    demo_map();
    demo_unordered_map();
    demo_multimap();
    demo_unordered_multimap();
    demo_queue();
    demo_stack();
    demo_deque();
    demo_priority_queue();
    demo_list();
    demo_sort_pair_custom_cmp();
    demo_next_permutation();
    demo_builtin_popcount();
    demo_min_max_element();
    return 0;
}

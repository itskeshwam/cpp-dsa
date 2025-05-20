#include <bits/stdc++.h>
using namespace std; // for not using std:: prefix
// Input and Output

// int main() {
//     int x, y;
//     cin >> x >> y;
//     cout << "value of x: " << x << " and y: " << y; 
//     return 0;
// }


// Data Types 
// int main() {
//     // int (integer)
//     int x = 10; 

//     // long (for long integers)
//     long y = 1000000000;
    
//     //long long (for very long integers)
//     long long z = 1000000000000000;
    
//     // float (for floating point numbers)
//     float z = 10.5;
    
//     // double (for double precision floating point numbers)
//     double a = 10.5;
    
//     // string
//     string s1, s2;
//     cin >> s1 >> s2; // reads a word
//     cout << s1 << " " << s2 << endl; // used 2 variable s1 and s2 cuz space is not allowed in string so "hey brother" needs 2 variables s1 and s2 respectively

//     // getline (takes entire line and not just a wo   rd)
//     string s3;
//     getline(cin, s3); 
//     cout << s3;

//     //char (used for single character)
//     char c = 'a';
//     cout << c << endl;

//     return 0;
// }

// If else statement
// int main(){
//     // PROBLEM 1: write a program if you are an adult or not 
//     int age;
//     cin >> age;
//     if(age >= 18){
//         cout << "You are an Adult!";
//     }
//     else if(age < 18){
//         cout << "You are NOT an Adult!";
//     }
//     return 0;
// }

    // PROBLEM 2: Grading system 
    // below 25 - F
    // 25-44 - E
    // 45-49 - D
    // 50-59 - C
    // 60-79 - B
    // 80-100 - A
    // Ask user to enter marks and print the grade

// int main() {
//     int marks;
//     cin >> marks;
//     if(marks<=25){
//         cout << "Grade F";
//     }
//     else if(marks >= 25 && marks <= 44){ // && or "and" for multiple conditions
//         cout << "Grade E"; 
//     }
//     else if(marks <= 49){
//         cout << "Grade D";
//     }
//     else if(marks <= 59){
//         cout << "Grade C";
//     }
//     else if(marks <= 79){
//         cout << "Grade B";
//     }
//     else if(marks <= 100){
//         cout << "Grade A";
//     }
//     else{
//         cout << "Invalid Marks!";
//     }
//     return 0;
// }

// nested if else statement
int main() {
    // PROBLEM 3: age for job and retirement 
    // if age is less than 18, print "You are not eligible for job"
    // if age is between 18 and 60, print "You are eligible for job"
    // if age is <55 and >60, print "You are not eligible for job , but retirement soon"
    // if age is greater than 60, print "retirement time"
    int age;
    cin >> age;
    if(age < 18){
        cout << "You are not eligible for job";
    }
    else if(age <= 57){
        cout << "You are eligible for job";
        if(age >= 55){
            cout << ", but retirement soon";
        }
    }
    else {
        cout << "retirement time";
    }
    
    return 0;
}
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

// int loops() {
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
// int nested_loops() {
//     // PROBLEM 3: age for job and retirement 
//     // if age is less than 18, print "You are not eligible for job"
//     // if age is between 18 and 60, print "You are eligible for job"
//     // if age is <55 and >60, print "You are not eligible for job , but retirement soon"
//     // if age is greater than 60, print "retirement time"
//     int age;
//     cin >> age;
//     if(age < 18){
//         cout << "You are not eligible for job";
//     }
//     else if(age <= 57){
//         cout << "You are eligible for job";
//         if(age >= 55){
//             cout << ", but retirement soon";
//         }
//     }
//     else {
//         cout << "retirement time";
//     }
    
//     return 0;
// }

// Switch case statement
// PROBLEM : Day of the week
// 1 - Monday
// 2 - Tuesday
// 3 - Wednesday
// 4 - Thursday
// 5 - Friday
// 6 - Saturday
// 7 - Sunday

// int swtich(){
//     int day;
//     cin >> day;
//     switch(day){
//         case 1:
//             cout << "Monday";
//             break; //VERY IMPORTANT
//         case 2:
//             cout << "Tuesday";
//             break; 
//         case 3:
//             cout << "Wednesday";
//             break;
//         case 4:
//             cout << "Thursday";
//             break;
//         case 5:
//             cout << "Friday";
//             break;
//         case 6:
//             cout << "Saturday";
//             break;
//         case 7:
//             cout << "Sunday";
//             break;
//         default:
//             cout << "Invalid day";
//             break;
//     }
//     return 0;
// }


// Arrays and Strings
// int array(){
//     // 1D array example
//     int arr[4];
//     cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]; 
//     cout << arr[3] << endl;
//     arr[2] += 10;
//     cout << arr[2] << endl;
//     arr[1] = 16;
//     cout << arr[1] << endl;

//     // 2D array example
//     int arr2[3][4]; // 3 rows (left to right) and 4 columns (up to down)
//     arr2 [0][0] = 1;
//     arr2 [0][1] = 2;
//     arr2 [0][2] = 3;
//     arr2 [0][3] = 4;
//     arr2 [1][0] = 5;
//     arr2 [1][1] = 6;
//     arr2 [1][2] = 7;
//     arr2 [1][3] = 8;
//     arr2 [2][0] = 9;
//     arr2 [2][1] = 10;
//     arr2 [2][2] = 11;
//     arr2 [2][3] = 12;
//     cout << arr2[2][3] << endl;

//     return 0;
// }

// int main(){
//     string s = "Hello My Brother";
//     int len = s.size(); // or s.length()
//     cout << s[len - 1]; // prints 'r' last element of string
// }



// for loop
// int main(){
//     for(int i = 1; i <=100; i=i+1){
//         cout << "brother" << endl;
//     }
// }


//nested for loop
int main(){
    for(int i=1; i<=25 ;i++)
    {
        for (j=1; j<=25;j++)
        {
            cout<< i << " " << j << endl;
        }
    }
    return 0;
    }
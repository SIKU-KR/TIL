# Basic Syntax for C++

### - Program
1. Comment
2. Header
3. Namespace
4. Functions
### - Variables
### - Input & Output
### - Conditional Statements
1. if ~ else
2. switch case
### - Loops
1. for loop
2. while loop
### - array
### - pointer
---
## Program

**1. Comment**
- Explains about the program
```cpp
// for a 1 comment line
/*
    for many comment lines
*/
```

**2. Header**
- <b><u>#include</u></b> makes specific files to be contained in the current source file. 
- Header File is a file that has informations compiler requires.
- <b><u>iostream</b></u> is standard input & output stream.
```cpp
#include <iostream>
```

**3. Namespace**
- Various NAMES are used in programs, and we *namespace* for efficiency.
```cpp
using namespace std;
```

**4. functions**
- Independent code to perform specific task
```cpp
int main(void){
    cout << "Hello World!" << endl;
    return 0; 
}
```
---
## Variables
```cpp
bool boolvar = true;
int intvar = 1;
double doublevar = 0.4;
char charvar = 'a';
string strvar = "apple";
```
---
## Input & Output
```cpp
#include<iostream>
int main(void) {
    int a;
    cin >> a; // input
    cout << a << endl; // output
}
```
---
## Conditional Statements
**1. if else**
```cpp
if (statement1)
    cout << "statement 1 is TRUE" << endl;
else if (statement2)
    cout << "statement 2 is TRUE" << endl;
else
    cout << "statement 1 & 2 are FALSE" << endl;
```
**2. switch case**
```cpp
switch(variable){
    case 0:
        cout << "variable == 0";
        break;
    case 1:
        cout << "variable == 1";
        break;
    default:
        cout << "Not includes in cases";
        break;
}
```
---
## Loops
**1. for loop**
```cpp
for(int i = 0; i < 10; i++){
    cout << i ;
}
```
**2. while loop**
```cpp
while(statement){
    // loop when statement is true
    cout << "Print in loop";
}
```
```cpp
do {
    cout << "Print in loop";
    // After 1 time of run, check if statement is true.
} while (statement)
```

-  **break;** function makes the program exit the loop.
- **continue;** function makes the program stop current loop and go for next loop.
---
## Functions
- C++ can make **overloading functions**
```cpp
int sub(int, int);
int sub(int, double);
double sub(double);
```
- C++'s function can have **default parameter**
```cpp
// Using default parameter when declaring function
void sub(double value = 1.0);
```
---
## Array
```cpp
int a[10]; //1st dimension array
int b[10][20]; //2nd dimension array
int c[5][10][20]; //3rd dimension array
```
---
## Pointer
*Pointer* : variable that has address of other variable
```cpp
int i = 10;
int *p = &i; //p has address of i

cout << *p; //printed : 10

*p = 20;
cout << *p; //printed : 20
```
*Array's name*  is a pointer

### **Dynamic Allocation** 
```cpp
// Declare a pointer
int *pi;
// Use "new" to allocate the memory
pi = new int[100];
// Use "delete" to return the memory
delete[] pi;
```
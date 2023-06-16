# Basic Syntax for C++

### - Program
1. Comment
2. Header
3. Namespace
4. Functions
### - Variables
### - Input & Output
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
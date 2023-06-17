## Friend
### What is Friend Function?
- Special function which can access class' private members
- Function Prototype place in class, but it's not a member
- Body of function should be declared outside of class
```cpp
class MyClass{
    friend void sub();
    ...
};
```
- **Class** can be declared as a friend
```cpp
class Employee {
    int salary
    friend class Manager;
    // Manager can access all members of Employee
};
```
- Friend member is useful when comparing multiple classes
```cpp
if(equals(obj1, obj2)){
    ...
}
```

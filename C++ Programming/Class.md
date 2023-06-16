### **What is Object Oriented Programming?**
- Way to think data and functions in a chunk
- This is called <u>*encapsulation*</u>
- We can code fast and easily using Object Oriented Programming

### **4 main concepts of Object Oriented Programming**
- Encapsulation
- Information Hiding
- Inheritance
- Polymorphism
---
### **What is Class?**
- A tool to make object
- *Instance* is a object made from Class
- Member Variable is Class' attribute
- Member Function is Class' behavior

```cpp
class Car{
private:
    // member variable
    int speed;
    int gear;
    string color;

public:
// member function
    void speedUp(){
        speed += 10;
    }
    void speedDown(){
        speed -= 10;
    }    
};
```
- We can think *Class* as a *Type*
```cpp
// Declare an instance
Car myCar; 
```
- To access members of class, we use .(dot)
```cpp
myCar.speed = 100;
myCar.speedUp();
myCar.speedDown();
```
- We use *accessor* and *mutator* to access private members
- Use *Accessor* to make READ-ONLY variables
- Use *Mutator* to reject wrong value for variables
```cpp
// example of accessor
getSpeed(){
    return speed;
}
// example of mutator
setBalance(int a){
    speed = a;
}
```
- Class' member function also can be **overloaded**
---
### **Constructor**
- Must have same name of Class
- No return
- Must be public member
- Can be overloaded
- If constructor is not declared, system automatically make *default-constructor*

### **Destructor**
- Name has '~' in front of name of Class
- No return
- Must be public member
- No parameter
- No overloading
- If destructor is not declared, system automatically make *default-constructor*

```cpp
class Car {
private:
    int speed;
    int gear;
    string color;
public:
    // Constructor
    Car();
    Car(int s, int g, string c);
    // Destructor
    ~Car();
}
```

### **Member Initialization List**
```cpp
Car(int s, int g, string c) : speed(s), gear(g), color(c){
    ... //other initialization can be here
}
```
- This also allows program to initial *Const Variables*

### **Copy Constructor** 
- If copy constructor is not declared, system automatically make *default-copy constructor*
- Takes same type of object as a parameter
- We can use Member Initialization List
```cpp
Car(const Car &obj); 
```
---
### - **Dynamically Allocating** of Class (Object)
```cpp
Car myCar; // Static Memory
Car *pCar = new Car(); // Dynamic Memory

// use -> to access member
pCar->speed = 100;
pCar->speedUp();
```
### - **this**
- **'this'** point an object running a fuction
```cpp
void Car::setSpeed(int s){
    this->speed = s;
}
```
### - **const**
- function declared **'const'** cannot change member variables
```cpp
void Car::displayInfo() const {
    cout << "speed: " << speed << endl;
    speed = 20; // Error!
}
```
### - Object can be return value of function
```cpp
Car createCar(){
    Car tmp(0, 1, "metal");
    return tmp;
}
```
### - Object can be a parameter
```cpp
void swapObjects(Car c1, Car c2){
    Car tmp;
    tmp = c1;
    c1 = c2;
    c2 = tmp;
}
```
### - Object's pointer can be a parameter
```cpp
void swapObjects(Car *c1, Car *c2){
    Car tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}
```
### - **Static Member Variable**
- Only one variable is declared in all instances
```cpp
class Car{
    ...
public:
    static int count;
    Car() {
        ...
        count++;
    }
    ~Car() {
        ...
        count--;
    }
};
```
## Polymorphism

### What is "Polymorphyism"?
- Working differently if objects' types are different, eventhough given same message
- Important skill to manage various types of objects

```cpp
class Shape {
protected:
    int x, y;
public:
    void draw() {
        cout << "Shape Draw";
    }
};
```
```cpp
class Rectangle : public Shape {
private:
    int width, height;
public :
    void draw() {
        cout << "Rectangle Draw";
    }
};
```
---
### Object Pointer's Type Casting
- **Upcasting** : Child class type casts to parent class type
```cpp
Shape *ps = new Rectangle();
ps->draw(); //result : "Shape Draw"
```
Pointing Rectangle Object to Shape Object limit ps to use member of Shape


- **Downcasting** : Parent class type casts to child class type
```cpp
Shape *pr = (Rectangle *)ps;
pr->draw(); //result : "Rectangle Draw"
```
---
### *TIP*
When declaring *Parameter of Function*, using parent class is better than using child class

---
### Virtual Function
- If we use *Shape* pointer to call member function, it must be useful if matched *draw() function* is called
```cpp
class Shape {
protected:
    int x, y;
public:
    // Virtual Function Declaring
    virtual void draw(){
        cout << "Shape Draw";
    }
};
```
```cpp
class Rectangle : public Shape {
private:
    int width, height;
public :
    // overloading
    void draw() {
        cout << "Rectangle Draw";
    }
};
```
and then,
```cpp
int main(){
    Shape *ps = new Rectangle();
    ps->draw();
    delete ps;
}
/* result
Rectangle Draw
*/
```
- Destructor should be virtual, when using polymorphism
---
### Dynamic Binding
- **Dynamic Binding** is delaying binding until program runs, and decide which function to be binded in runtime
- **Static Binding** is completing bindings during compile
- **Dynamic Binding** is operated on *Virtual Functions*, and slow
- **Static Binding** is operated on normal functions, and fast
---
### Pure Virtual Function
- **Pure Virtual Function** has function header only, no body
```cpp
virtual (return type)(parameters) = 0;
```
- **Abstract Class** is class which only have *Pure Virtual Function*, and suitable to express abstract concepts
```cpp
class Animal{
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual void speak() = 0;
};
``` 
it is useful when declaring interface

---
### dynamic_cast
- Basically, upcast is allowed, but downcast is not allowed
- In runtime, program judge a type of object which pointer is pointing
- If type is appropriate, return type
- If type is inappropriate, return NULL
- Parent class must use *Virtual Function* to use dynamic_cast
```cpp
class Car {...};
class Bus : public Car {...};

int main(){
    Bus *pBus = new Bus;
    Car *pCar1 = dynamic_cast<Car *>(pBus1); //OK!

    Car *pCar2 = new Car;
    Bus *pBus2 = dynabic_cast<Bus *>(pCar2); //error : downcast
}
```

### const_cast
- add or remove const property to type

### reinterpret_cast
- Cast to specific type from any type pointer

### typeid
- *typeid* operator returns object's type
```cpp
SportsCar* pb = new SportsCar;
cout << typeid(pb).name() << endl;
```
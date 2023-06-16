## **Inheritance**
- Inherit from existing class and add function we need
- Use exist class' field & method
- Can change part of existing class
- Quickly make GUI program 
- Use verified SW(codes)
- Reduce code's repetition
- Inheriting from child class also possible

```cpp
class Car{
    int speed;
}
class SportsCar : public Car{
    bool turbo;
}
```
---
### - Access Specifier
|Access Specifier|Current Class|Child Class|Others|
|---|---|---|---|
|private|O|X|X|
|protected|O|O|X|
|public|O|O|O|
---

### - Overriding
- Child class can override parent class' member function if needed
```cpp
class Car{
public:
    int getHP(){
        return 100;
    }
}
class SportsCar : public Car{
public:
    int getHP(){
        return 300;
    }
}
```
- Overrided function must have same *signature* of parent class
- signature : name, return, parameters
---
### - 3 types of Inheritance
||Inherit by Public|Inherit by protected|Inherit by private|
|---|---|---|---|
|Parent's public Member|->public|->protected|->protected|
|Parents' protected Member|->protected|->protected|->private|
|Parents' public Member|Not Accessible|Not Accessible|Not Accessible|
---
### - Multiple Inheritance
```cpp
class Sub : public Sup1, public Sup2{
    ...
}
```
- Error causes if members of parents 1 and 2 have the same name 
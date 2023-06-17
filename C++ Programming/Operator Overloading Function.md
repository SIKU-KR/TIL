## Operator Overloading Function
### Why do we use *Operating Overloading Functions*?
- Because it is easier to read with Operating Overloading function
---
### Examples
- operator +
```cpp
Vector operator+(Vector& v2){
    Vector v(0.0, 0.0);
    v.x = this->x + v2.x;
    v.y = this ->y + v2.y;
    return v;
}
...
Vector v3 = v1 + v2;
// : v1.operator+(v2)
```

- operator * : must follow commutative law
```cpp
Vector operator+(Vector& v, double alpha){
    return(alpha*v.x, alpha*v.y);
}
Vector operator+(double alpha, Vector& v){
    return(alpha*v.x, alpha*v.y);
}
// : v1.operator+(v2)
```

- operator ==, !=: check if vectors have same data
```cpp
Vector operator==(Vector& v1, Vector& v2){
    return(v1.x ==v2.x && v1.y == v2.y);
}
Vector operator!=(Vector& v1, Vector& v2){
    return(!(v1 == v2));
}
```

- operator << : must return stream object
```cpp
Vector operator<<(ostream& os, const Vector& v){
    os << "(" << v.x << "," << v.y << ")" << endl;
    return os;
}
```

- operator =
```cpp
Vector operator=(const Vector& v2){
    this->x = v2.x;
    this->y = v2.y;
    return this;
}
```
---
### Important Things
- It is not allowed to make new operator
- '::' , '.*', '.', '?:' is not allowed to overload
- Cannot change definition of operator on (int) and (double)
- if you overload +, it's good to overload += and -=
## Template

### Generic Programming
- Code in generic style and Reuse on various types of object

### Template Function
- following example is available for integer and decimal
```cpp
template<typename T>
T get_max(T x. T y){
    if(x > y) return x;
    else return y;
}
```
### Template Function (Explicit Specialization)
```cpp
template<typename T>
void print_array(T[] a, int n){
    for (int i = 0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
}
template <>
//if parameter's type is char, this function is called
void print_array<char>(char []a, int n){
    cout << a << endl;
}
```

### Multiple Type Parameters
- Use of Multiple Type Template is possible
```cpp
template<typename T1, typename T2>
void copy(T1 a1[]. T2 a2[], int n){
    for (int i = 0; i<n; i++){
        a1[i] = a2[i];
    }
}
```

### Class Template
```cpp
template <typename T>
class Box {
private:
    T data;
public:
    void set(T value){ data = value; }
    T get(){ return data; }
}
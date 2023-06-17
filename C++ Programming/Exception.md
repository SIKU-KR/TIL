## Exceptions

- What is Exception?

Error caused by wrong code, incorrect data, exceptional situation

- Basically, this handles only on matching type.
```cpp
try {
    ...
    throw var;
    ...
}
catch(type var){
    ...
}
```
- Can take all exceptions with **...**
```cpp
catch(...){

}
```
- Can return after handling exceptions
```cpp
try {
    ...
    throw var;
    ...
}
catch(type var){
    ...
    throw;
}
```
- Multiple Catch : Handle detailed exceptions first
```cpp
try {
    ...
    throw var;
    ...
}
catch(SmallException e){
    ...
}
catch(...){
    //Exceptions except SmallException will be caught here
    ...
}
```
- Exception Class : Throw can throw type of class
```cpp
class NoPersonException{...};

int main(){
    try {
        ...
        // throw class type
        throw NoPersonException(persons);
    }
    catch(NoPersonException e){
        ...
        // Can access members
        e.get_persons();
    }
}
```


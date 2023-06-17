## Stream
### What is Stream?
- Flow of ordinal data

### File stream
- Must be kept : File open -> Read & Write -> File close
- input
```cpp
ifstream is;
is.open("text.txt");
int number;
is >> number;
is.close();
```
- output
```cpp
ofstream os;
os.open("result.txt");
os << number;
os.close();
```
----
## File
### Text File
- contains readable text in file
- saved with ASCII code
- consisted with continuous lines
### Binary File
- Computer can read, but person cannot
- Saved binary data directly
- not seperated by lines
- every data is not changed to input & output
- Only specific program can read binary files

### Sequential Access File
- Read or Write sequentially from first data

### Random Access File
- Able to Read or Write from any place
- Uses **File Placeholder**, shows where read & write is currently working
- Moving file placeholder by force make possible to random access
```cpp
seekg(long offset, seekdir way);
```
|way|describtion|
|---|---|
|ios::beg|offset from beginning|
|ios::cur|offset from current place|
|ios::end|offset from the end|
```cpp
is.seekg(ios::beg, 100);
is.seekg(ios::end, o);
is.seekg(ios::cur, -100);
```
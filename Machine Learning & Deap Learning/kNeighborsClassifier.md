# kNeighbors Classifier 
This is **my very first machine learning stuff** I've ever studied

---

### Supervised Learning
- **"kNeighbors Classifer"** is a method of *Supervised Learning*
- "Data" and "Answer" are needed, called **"Input"** and **"Target"** (Training Data)
- **Feature** is a input data used to classify data
- Supervised Learning learns to get the right answer, since it gets "target"

---

### kNeighbors Classifier

- Data used in Study
```python
# 35 bream and 14 smelt
fish_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 30.0, 30.7, 31.0, 31.0,
                31.5, 32.0, 32.0, 32.0, 33.0, 33.0, 33.5, 33.5, 34.0, 34.0, 34.5, 35.0,
                35.0, 35.0, 35.0, 36.0, 36.0, 37.0, 38.5, 38.5, 39.5, 41.0, 41.0, 9.8,
                10.5, 10.6, 11.0, 11.2, 11.3, 11.8, 11.8, 12.0, 12.2, 12.4, 13.0, 14.3, 
                15.0]

fish_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 390.0, 450.0, 500.0, 475.0, 500.0,
                500.0, 340.0, 600.0, 600.0, 700.0, 700.0, 610.0, 650.0, 575.0, 685.0, 620.0, 680.0,
                700.0, 725.0, 720.0, 714.0, 850.0, 1000.0, 920.0, 955.0, 925.0, 975.0, 950.0, 6.7,
                7.5, 7.0, 9.7, 9.8, 8.7, 10.0, 9.9, 9.8, 12.2, 13.4, 12.2, 19.7, 19.9]

```
- Using **zip()** method, we can make 2nd dimension list from 2 lists
```python
fish_data = [[l, w] for l, w in zip(fish_length, fish_weight)]
```
- Made Target list of fish
```python
# 35 bream(1) and 14 smelt(0)
fish_target = [1] * 35 + [0] * 14
```
- import KNeighborsClassifier from sklearn and make an instance
```python
from sklearn.neighbors import KNeighborsClassifier
kn = KNeighborsClassifier
```
- Make Train data and Test data using *list slicing*
```python
train_input = fish_data[:35]
train_target = fish_target[:35]
test_input = fish_data[35:]
test_target = fish_target[35:]
```
- And Fit(train) and Score(test) to kn
```python
kn.fit(train_input, train_target)
kn.score(test_input, test_target)
# output : 0.0 
```
---
### Trouble Shooting (Sampling bias)
- I made Train set and Test set without balancing the number of fish type
- This phenomenon called **Sampling Bias**
- We should shuffle lists and get balanced Train Set and Test Set
- It is easy by using numpy library
```python
import numpy as np
```
- We need to transform list to numpy array
```python
input_arr = np.array(fish.data)
target_arr = np.array(fish_target)
```
- Numpy is much faster than list methods, when processing data
- We can know shape of data using **shape** method of numpy
```python
print(input_arr.shape)
# output : (49,2) 
# (number of samples, number of features)
```
- We must take same index from *input* and *target*
```python
# create an index list and shuffle
index = np.arange(49)
np.random.shuffle(index)
```
- Finally, make new train and test set
```python
train_input = input_arr[index[:35]]
train_target = target_arr[index[:35]]
test_input = input_arr[index[35:]]
test_target = target_arr[index[35:]]
```
---
### Full code of TIL
```python
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
kn = KNeighborsClassifier()


bream_length = [25.4, 26.3, 26.5, 29.0, 29.0, 29.7, 29.7, 30.0, 30.0, 30.7, 31.0, 31.0,
                31.5, 32.0, 32.0, 32.0, 33.0, 33.0, 33.5, 33.5, 34.0, 34.0, 34.5, 35.0,
                35.0, 35.0, 35.0, 36.0, 36.0, 37.0, 38.5, 38.5, 39.5, 41.0, 41.0]
bream_weight = [242.0, 290.0, 340.0, 363.0, 430.0, 450.0, 500.0, 390.0, 450.0, 500.0, 475.0, 500.0,
                500.0, 340.0, 600.0, 600.0, 700.0, 700.0, 610.0, 650.0, 575.0, 685.0, 620.0, 680.0,
                700.0, 725.0, 720.0, 714.0, 850.0, 1000.0, 920.0, 955.0, 925.0, 975.0, 950.0]

smelt_length = [9.8, 10.5, 10.6, 11.0, 11.2, 11.3, 11.8, 11.8, 12.0, 12.2, 12.4, 13.0, 14.3, 15.0]
smelt_weight = [6.7, 7.5, 7.0, 9.7, 9.8, 8.7, 10.0, 9.9, 9.8, 12.2, 13.4, 12.2, 19.7, 19.9]

fish_length = bream_length + smelt_length
fish_weight = bream_weight + smelt_weight

input_arr = np.array(fish_data)
target_arr = np.array(fish_target)

np.random.seed(42)
index = np.arange(49)
np.random.shuffle(index)

train_input = input_arr[index[:35]]
train_target = target_arr[index[:35]]
test_input = input_arr[index[35:]]
test_target = target_arr[index[35:]]

kn.fit(train_input, train_target)
kn.score(test_input, test_target)

kn.predict(test_input)
```

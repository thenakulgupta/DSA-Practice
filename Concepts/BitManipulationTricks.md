# Bit Manipulation Tricks.

### 1. **Checking Even/Odd**
```cpp
bool isEven = !(x & 1);
bool isOdd = x & 1;
```

### 2. **Finding Mid-Point**
```cpp
int mid = a + ((b - a) >> 1);
```

### 3. **Multiplying by 2**
```cpp
int multiplyByTwo = x << 1;
```

### 4. **Dividing by 2**
```cpp
int divideByTwo = x >> 1;
```

### 5. **Swapping Values**
```cpp
a ^= b;
b ^= a;
a ^= b;
```

### 6. **Checking if Power of Two**
```cpp
bool isPowerOfTwo = (x & (x - 1)) == 0;
```

### 7. **Rounding Up to Next Power of Two**
```cpp
x--;
x |= x >> 1;
x |= x >> 2;
x |= x >> 4;
x |= x >> 8;
x |= x >> 16;
x++;
```

### 8. **Setting a Bit at Position n**
```cpp
x |= (1 << n);
```

### 9. **Clearing a Bit at Position n**
```cpp
x &= ~(1 << n);
```

### 10. **Toggling a Bit at Position n**
```cpp
x ^= (1 << n);
```

### 11. **Extracting Least Significant Bit (LSB)**
```cpp
int lsb = x & -x;
```

### 12. **Removing Least Significant Bit (LSB)**
```cpp
x &= (x - 1);
```

### 13. **Finding Minimum and Maximum**
```cpp
int minValue = y ^ ((x ^ y) & -(x < y));
int maxValue = x ^ ((x ^ y) & -(x < y));
```

### 14. **Checking if Two Numbers Have Opposite Signs**
```cpp
bool oppositeSigns(int x, int y) {
    return (x ^ y) < 0;
}
```

### 14. **Finding the Only Non-Repeated Element in an Array (All Others Repeated Twice)**
```cpp
int findNonRepeated(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}
```

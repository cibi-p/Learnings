Done, Hackerank 30days Challenge ( most of all easy only )

See also:
common like shorting, searching, Binary Search Trees, traversals and other part in internet


# Algorithm ( Used in Coding Competition )

# Basic
### Binary Conversion
```c
int decimal_number;
char binary_array[MAX_SIZE]; // Or int binary_array[MAX_SIZE];
int i = MAX_SIZE - 1;

// ... (Get decimal number input)

while (decimal_number > 0) {
  binary_array[i] = decimal_number % 2;
  decimal_number /= 2;
  i--;
}

// ... (Print or process binary_array)
```

### GCD
```c
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
```

### LCM
```c
int lcm(int a, int b) {
  int gcd_val = gcd(a, b);
  return (a * b) / gcd_val;
}
```
# Medium

# Hard
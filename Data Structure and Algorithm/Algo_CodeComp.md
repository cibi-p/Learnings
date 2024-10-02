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

### Cllimbing the lealder board (hackerrank)
There will be the learder board, the new player plays n games, bases on the score of the new player need to update the leader board, if the two player has the same score, they allocated the same rank, next score follows the rank + 1.
Rank is sorted in descending order, and player score always be in ascending order

(optimal solution )solution:
1. remove the duplicate ranks
2. use the binary search to find the correct position of the score. and calucalate rank pased on the index.
3. since the new player score always in ascending, the next score is always greater that or equal to previous, so start the next iteration from where you find the previous score

( my solution )
I only followed the step 3 in the above, and handled the duplicated values
# Medium

# Hard

# ALGORITHM

## GREEDY
In computer science, a greedy algorithm is an algorithm that finds a solution to problems in the shortest time possible. It picks the path that seems optimal at the moment without regard for the overall optimization of the solution that would be formed.

https://www.freecodecamp.org/news/greedy-algorithms/

## TREE
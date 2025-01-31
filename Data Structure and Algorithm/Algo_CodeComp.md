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

### Utopian Tree  
https://www.hackerrank.com/challenges/utopian-tree/problem   
based on peried the tree height is increases
if period is even it increases by 1,
and if perirod is odd it increases as twices,

ex:
```
period: 0 1 2 3 4 5  6  7  8  9  10 11  12 ....
height: 1 2 3 6 7 14 15 30 31 62 63 126 127 ...
```

my solution ( worst ) O(n)
```rust
fn utopianTree(n: i32) -> i32 {
    let mut result:i32 = 1;
    for idx in 0..n {
        println!("{}",idx);
        if idx % 2 == 0 {
            result = result * 2;
        }
        else {
            result = result +  1;
        }
    }
    result
}
```

best solution O(n)
```c
int utopianTree(int n) {
    int ans = (1 << ((n / 2) + 1) ) - 1; // here istead finding the value for the 2^(n/2), they found using left shift operation for reducing the loop and instructions
    if(n % 2 == 1) ans*=2;
    // or simple as 
    // return ((1 << ((n / 2) + 1) ) - 1) << n%2;
    return ans;
}
```
# Medium

# Hard

# ALGORITHM

## GREEDY
In computer science, a greedy algorithm is an algorithm that finds a solution to problems in the shortest time possible. It picks the path that seems optimal at the moment without regard for the overall optimization of the solution that would be formed.

https://www.freecodecamp.org/news/greedy-algorithms/

## TREE
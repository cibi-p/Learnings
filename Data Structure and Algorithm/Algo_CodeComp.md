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
### giving chocolate to the prisonor, sitting them in the round table, last chocolate is the tastey chololate
https://www.hackerrank.com/challenges/save-the-prisoner/copy-from/420489484?isFullScreen=true  
n = nu of prisonors  
m = chocolate counts
s = chair start number  

return: chair number who get the last chocolate
( not completed )

Founded test cases are

```c
8
7 19 2
3 7 3
1 1 1 // only 1 prisonor, start with 1 ( special case )
5 5 2 // twisting the above case
7 8 7
7 9 7 // checking for rouding the chair if count execeed the nu of chair
7 20 7 // similar to above case max diff check
5 10 3
```

I tried a = (m%n) + s - 1; if a=0{return 1}; wrong solution
Answer
```
a = (m + s -1 )%n
if a == 0
  return n
```
# Medium

# Hard

# ALGORITHM

## GREEDY
In computer science, a greedy algorithm is an algorithm that finds a solution to problems in the shortest time possible. It picks the path that seems optimal at the moment without regard for the overall optimization of the solution that would be formed.

https://www.freecodecamp.org/news/greedy-algorithms/

## TREE

# LeetCode 150 Interview questions

**1. merge the two sorted array and the resulted array should be sorted**  
I try to run the make the algorithm O(M+N);
Note: size of array1 is (M + N); where M is the valid element in array1, and N is the array two lenght. 
size of array1 is given as (M+N) beacause we to return this array. ( this become advantage )
By iterating from the last element of the two arrays, i place the element hight in the last position of the size of the array1. By repeating the process i get a sorted array.

```c++
class Solution {
 public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
```

**2. Remove element in an array in in-place**
https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

in this solution iterate from the 0, if found the number in the array equal to the val, then i look from last to replace the number which is not equal to val.

time complexity: O(N)
```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nu_of_nonequal_val = 0;
        int nums_size          = nums.size();
        int idx = 0;
        for( idx = 0; idx <= nums_size - 1; idx++) {
            if(nums[idx] == val) {
                int  rep_idx = nums_size - 1;;
                for(; rep_idx > idx; rep_idx--) {
                    if(nums[rep_idx] != val) {
                        nums[idx] += nums[rep_idx];
                        nums[rep_idx] = nums[idx] - nums[rep_idx];
                        nums[idx] -= nums[rep_idx];
                        nu_of_nonequal_val++;
                        break;
                    }
                }
                if(nums[idx] == val)
                    break;
            }
            else {
                nu_of_nonequal_val++;
            }
        }
        return idx;
    }
};
```
**3.Duplicate element in the non-descending order array, need to remove the duplicate elements in the inplace and return the unique element size**
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqNumCn    = 1;
        int uniqPointIdx = uniqNumCn + 1;
        if(nums[0] == nums[nums.size() - 1])
            return 1;
        // iterate through the array from 2nd position, check if current element is <= to prev element. if so find the uniq num that is greater that prev element and update the founded uniq element to the current element and update the pointIdx to the founded uniq element index so that next time we can iterate from that point)
        for(; uniqNumCn < nums.size(); uniqNumCn++) {
            if(nums[uniqNumCn] <= nums[uniqNumCn - 1] ) {
                char updated = 0;
                while(uniqPointIdx < nums.size())
                {
                    if(nums[uniqPointIdx] > nums[uniqNumCn - 1]) {
                        nums[uniqNumCn] = nums[uniqPointIdx];
                        uniqPointIdx++;
                        updated = 1;
                        break;
                    }
                    uniqPointIdx++;
                }
                if(uniqPointIdx == nums.size()) {
                    if(updated == 1) 
                        uniqNumCn++;
                    break;
                }
            }
        }
        return uniqNumCn;
    }
};
```

**4. Remove duplicate elements II (Hard)**
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1548147003/?envType=study-plan-v2&envId=top-interview-150 
In this question only duplicate count of two number is allowed. 

The below one is the interesting solution, where the check the idx and k-2 values. if there is a lot of duplicates like 1,1,1,1,1,2. k will be in 2nd position and idx will go to the 5th index, untill ifcondition fails, after that point need to put 2 in the 2nd position, and it continues.
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqNumCn    = 2;
        if(nums.size() < 2)
            return 1;
        for(int idx = 2; idx < nums.size(); idx++) {
            if(nums[uniqNumCn - 2] != nums[idx]) {
                nums[uniqNumCn] = nums[idx];
                uniqNumCn++;
            }
        }
        return uniqNumCn;
    }
};
```

other method by tracking the pair, here order matter (taken more time to solve)
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, pair = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                pair++;
            else
                pair = 1;
            if (pair <= 2) {
                nums[count++] = nums[i];
            }
        }
        return count;

    }
};
```

**5. Find Majority Element k (k always > n/2)**
https://leetcode.com/problems/majority-element/submissions/1549117551/?envType=study-plan-v2&envId=top-interview-150


O(N) space and time complexity using map to track the count and return the max frequency of the number
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cn_map;
        int max = 0, max_nu = 0;
        for( int i = 0; i < nums.size(); i++)
        {
            cn_map[nums[i]] += 1;
            if( max < cn_map[nums[i]]) {
                max = cn_map[nums[i]];
                max_nu = nums[i];
            }
        }
        return max_nu;
    }
};
```

code for O(N) time and O(1) space complexity ( found in solution ). ( this solution only works for the case duplicate number count greate than the arraySize/2).

since the max duplicate count is always greater than arraySize/2, we can +1 or -1 the max_count, atlast we have the max number in variable max. NOTE: max_cn in this case may be wrong.
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // found this solution is only working for the repeaded number should greater n/2
        int max_cn = 0;
        int max    = 0;
        for( int i = 0; i < nums.size(); i++)
        {
            if(max_cn == 0)
                max = nums[i];
            
            max_cn += (max == nums[i])?1:-1;
        }
        return max;
    }
};
```

**(similar to above question) In this question k is alway > n/3**
https://leetcode.com/problems/majority-element-ii/description/

need to solve in the O(1) space and O(N) time complexity.

need understand the algorithm


**6. Rotate Array**  
https://leetcode.com/problems/rotate-array/submissions/1550856555/?envType=study-plan-v2&envId=top-interview-150
trying in O(N) time and O(1) space complexity

```c++
//(has bug)
//(not completed)
// it produce wrong out put for array.size() is even
// need to confirm for other test cases also
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = nums[0];
        int pos = 0;
        for(int idx = 0; idx < nums.size(); idx++)
        {
            pos = ( pos + k ) % nums.size();
            // replacing the var
            temp += nums[pos];
            nums[pos] = temp - nums[pos];
            temp = temp - nums[pos];
        }
    }
};
```

the below case solve execept the array size and k is even, and array_size / k is not equal to zero.
```c++
//(has bug)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = nums[0];
        int pos = 0;
        for(int idx = 0; idx < nums.size(); idx++)
        {
            pos = ( pos + k ) % nums.size();
            // replacing the var
            temp += nums[pos];
            nums[pos] = temp - nums[pos];
            temp = temp - nums[pos];
            if( nums.size() % 2 == 0 && (idx -1) % (nums.size()/k) == 0 ) {
                pos = ( pos + 1 ) % nums.size();
                temp = nums[pos];
            }
        }
        cout<<temp<<" "<<pos<<endl;
    }
};
```
The below updated part solves the above issue also, but the full solution works only if k < array size. 

The above issue also solved by k = k % nums.size();
```c++
//(has bug)
//...
            if( nums.size() % 2 == 0 && (idx+1) % (nums.size()/k) == 0 ) {
                pos = ( pos + 1 ) % nums.size();
                temp = nums[pos];
            }
//...
```
// Different thinking solution  
Reverse the entire array:  
Example: ( [1,2,3,4,5,6,7] ) → ( [7,6,5,4,3,2,1] )  
Reverse the first ( k ) elements:  
Example: ( [7,6,5,4,3,2,1] ) → ( [5,6,7,4,3,2,1] )  
Reverse the last ( n-k ) elements:  
Example: ( [5,6,7,4,3,2,1] ) → ( [5,6,7,1,2,3,4] )

```c++
// code for above solution
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    void rotate(vector<int>&nums,int k){
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
```

// Other great solution
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        int count = 0;
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (current != start);
        }
    }
};
```

**7. Best time to Buy and sell stock**  
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

prices in an array will be given on the days, need to find the max profit

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int profit = 0;
        for(int idx = 0; idx < prices.size(); idx++) {
            if(prices[idx] < min_price)
                min_price = prices[idx];
            int current_profit = prices[idx] - min_price;
            if(current_profit > profit)
                profit = current_profit;
        }
        return profit;   
    }
}; 
```

**8. Buy and sell stock - II**  
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

Input: prices = [7,1,5,3,6,4]  
Output: 7  
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_price = prices[0];
        int profit = 0;
        for( int idx = 1; idx < prices.size(); idx++)
        {
            if(prices[idx] < min_price) {
                min_price = prices[idx];
                max_price = prices[idx];
            }
            if(prices[idx] > max_price){
                max_price = prices[idx];
                profit += (max_price - min_price);
                min_price = max_price;
            }
        }
        return profit;
    }
};
```

**9. Jump Game**
https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise

completed solution passed all testcases but worst time complexity, can be reduced
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool b_canJump = false;
        for(int idx = 0; idx < nums.size(); ) {
            if (nums[idx] >= nums.size() - idx - 1) {
                b_canJump = true;
                break;
            }
            else {
                if (nums[idx] == 0)
                    break;
                int temp = nums[idx];
                idx++;
                int max_idx = idx;
                bool start = 0;
                while (temp) {
                    if(start == 0 || nums[idx] >= nums[max_idx]){
                        if(idx + nums[idx] >= nums.size() - idx - 1 || nums[idx+nums[idx]] != 0) {
                            max_idx = idx;
                            start = 1;
                        }
                    }
                    idx++;
                    temp--;
                }
                idx = max_idx;
            }
        }
        return b_canJump;
    }
};
```
time taken test case: [4,2,0,0,1,1,4,4,4,0,4,0]


*below is my next correct solution*

loop from last element. if 0 is found, check any of the element can jump zero's index. if jump continue on, else return false.
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool b_canJump = true;
        if(nums.size() <= 1)
            return 1;
        if(nums[0] == 0)
            return 0;
        for (int idx = nums.size() - 1; idx > 0; idx--) {
            if (nums[idx] == 0) {
                int zero_idx = idx;
                idx--;
                while(idx >= 0) {
                    if(nums[idx] > (zero_idx - idx) || (nums[idx] > (zero_idx - idx - 1) && zero_idx == nums.size() - 1)) {
                        break;
                    }
                    idx--;
                    if(idx < 0) {
                        b_canJump = false;
                    }
                }
            }
        }
        return b_canJump;
    }
};
```

other best solution from solutions:

need to set the goal from last. reaching the goal is based on the previous element, if it is non-zero, then using that previous element we can reach the goal. so set the prev element for the goal.
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
```

**10.Jump Game II (find min step to reach the end)**
https://leetcode.com/problems/jump-game-ii/
Input: nums = [2,3,1,1,4]  
Output: 2  
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.  

My wrong solution, which is taken from the previous one and counted the steps
```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        bool b_canJump = false;
        int steps = 1;
        if(nums.size() <= 1)
            return 0;
        for(int idx = 0; idx < nums.size(); ) {
            if (nums[idx] >= nums.size() - idx - 1) {
                b_canJump = true;
                break;
            }
            else {
                if (nums[idx] == 0)
                    break;
                int temp = nums[idx];
                idx++;
                int max_idx = idx;
                bool start = 0;
                while (temp) {
                    if(start == 0 || nums[idx] >= nums[max_idx]){
                        if(idx + nums[idx] >= nums.size() - idx - 1 || nums[idx+nums[idx]] != 0) {
                            max_idx = idx;
                            start = 1;
                        }
                    }
                    idx++;
                    temp--;
                }
                steps++;
                idx = max_idx;
            }
        }
        return steps;
    }
};
```

failed test case: [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0]


correct solution and best effienent.

find the maxJump which is the currentEnd here.

in the intermediate find the max_step_sz,

if max_jump is reached, increase the jump and update max_jump to the max_Step_size
https://leetcode.com/problems/jump-game-ii/solutions/6329832/most-optimal-solution-beats-100-c-java-python-javascript/?envType=study-plan-v2&envId=top-interview-150
```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, max_step_sz = 0, currentEnd = 0;
        for( int i = 0; i < nums.size() - 1; i++) {
            max_step_sz = max(i+nums[i], max_step_sz);
            if(i == currentEnd)
            {
                currentEnd = max_step_sz;
                step++;
            }
        }
        return step;
    }
};
```
# Problem Solving


## Greedy
1. **Transforms Array to All Equal Elements**  
[link](https://leetcode.com/problems/transform-array-to-all-equal-elements/description/)
You are given an integer array nums of size n containing only 1 and -1, and an integer k.  
You can perform the following operation at most k times:  
Choose an index i (0 <= i < n - 1), and multiply both nums[i] and nums[i + 1] by -1.  
Note that you can choose the same index i more than once in different operations.  
Return true if it is possible to make all elements of the array equal after at most k operations, and false otherwise.
 

Example 1:  
Input: nums = [1,-1,1,-1,1], k = 3  
Output: true  

Example 2:  
Input: nums = [-1,-1,-1,1,1,1], k = 5  
Output: false  


```C
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }

    bool check(vector<int> nums, int k, int tar) {
        int n = nums.size(), count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != tar) {
                nums[i] *= -1;
                nums[i + 1] *= -1;
                count++;
                if (count > k) return false;
            }
        }

        return nums[n - 1] == tar;
    }
};
```
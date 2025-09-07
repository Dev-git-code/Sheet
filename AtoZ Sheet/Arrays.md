```table-of-contents
title: 
style: nestedList # TOC style (nestedList|nestedOrderedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
include: 
exclude: 
includeLinks: true # Make headings clickable
hideWhenEmpty: false # Hide TOC if no headings are found
debugInConsole: false # Print debug info in Obsidian console
```
### 1. Second Largest Element in a array

```embed
title: "Second Largest | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1. Note: The second largest element should not be equal to the largest element. Examples: Input: arr"
url: "https://www.geeksforgeeks.org/problems/second-largest3735/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
int getSecondLargest(vector<int> &arr) {
       
       int maxe = -1;
       int s_max = -1;
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]<maxe && arr[i]>s_max){ // current max se chota prev max se bda
                s_max = arr[i];
            }
            
            if(maxe<arr[i]){
                s_max = maxe; // prev maximum 
                maxe = arr[i];
            }
            
        }
        
        return s_max;
    }
```

### 2. Check if Array Is Sorted and Rotated

```embed
title: "Check if Array Is Sorted and Rotated - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Check if Array Is Sorted and Rotated - Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.  There may be duplicates in the original array.  Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.     Example 1:   Input: nums = [3,4,5,1,2] Output: true Explanation: [1,2,3,4,5] is the original sorted array. You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].   Example 2:   Input: nums = [2,1,3,4] Output: false Explanation: There is no sorted array once rotated that can make nums.   Example 3:   Input: nums = [1,2,3] Output: true Explanation: [1,2,3] is the original sorted array. You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.                 Constraints:   * 1 <= nums.length <= 100  * 1 <= nums[i] <= 100"
url: "https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/"
favicon: ""
aspectRatio: "52"
```

```cpp 
 bool check(vector<int>& nums) {
      int count = 0;
      int n = nums.size();
      for(int i = 0;i<n;i++){
        if(nums[i] > nums[(i+1)%n]){ //%n is used to compare last ele with first
            count ++;
        }
      }

      return count<=1; //nums = [1, 1, 1, 1] for this case < is used
    }

```

#### 🧠 **What to Remember:**

- A **rotated sorted array** has **at most one drop** where `nums[i] > nums[i+1]` (including circular check).
- If count of such drops is ≤ 1 → array is valid rotated sorted.


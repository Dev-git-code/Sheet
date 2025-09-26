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
title: "Find Second Largest Element in Array | Remove duplicates from Sorted Array | Arrays Intro Video"
image: "https://i.ytimg.com/vi/37E9ckMDdTk/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/37E9ckMDdTk?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=398"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Second Largest | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1. Note: The second largest element should not be equal to the largest element. Examples: Input: arr"
url: "https://www.geeksforgeeks.org/problems/second-largest3735/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
int getSecondLargest(int *arr, int n) {
    // code here
    int largest = -1; //INT_MIN
    int second_largest = -1; //INT_MIN
    
    for(int i = 0; i<n;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }else if (arr[i]<largest && arr[i]>second_largest){
            second_largest = arr[i];
        }
    }
    
    //if(second_largest==INT_MIN) return -1;
    return second_largest;
}
```
- the above code will not work for the case `[10, INT_MIN, 10]`
- can think about if the array has negative as well as repeating elements. 

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
	  for(int i = 0;i<n;i++){ // iterate using the complete indexes of the array! so that last can be compared with first.
		if(nums[i] > nums[(i+1)%n]){ //%n is used to compare last ele with first
			count ++;
		}
	  }
	
	  return count<=1; //nums = [1, 1, 1, 1] for this case < is used
}

```

- A **rotated sorted array** has **at most one drop** where `nums[i] > nums[i+1]` (including circular check).
- If count of such drops is ≤ 1 → array is valid rotated sorted.






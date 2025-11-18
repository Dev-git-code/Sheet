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

Link : https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
## Easy 
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

### 3. Remove Duplicated from Sorted Array

```embed
title: "Find Second Largest Element in Array | Remove duplicates from Sorted Array | Arrays Intro Video"
image: "https://i.ytimg.com/vi/37E9ckMDdTk/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/37E9ckMDdTk?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=1968"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Remove Duplicates from Sorted Array - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Remove Duplicates from Sorted Array - Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place [https://en.wikipedia.org/wiki/In-place_algorithm] such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.  Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:   * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.  * Return k.  Custom Judge:  The judge will test your solution with the following code:   int[] nums = [...]; // Input array int[] expectedNums = [...]; // The expected answer with correct length  int k = removeDuplicates(nums); // Calls your implementation  assert k == expectedNums.length; for (int i = 0; i < k; i++) {     assert nums[i] == expectedNums[i]; }   If all assertions pass, then your solution will be accepted.     Example 1:   Input: nums = [1,1,2] Output: 2, nums = [1,2,_] Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively. It does not matter what you leave beyond the returned k (hence they are underscores).   Example 2:   Input: nums = [0,0,1,1,1,2,2,3,3,4] Output: 5, nums = [0,1,2,3,4,_,_,_,_,_] Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you leave beyond the returned k (hence they are underscores).      Constraints:   * 1 <= nums.length <= 3 * 104  * -100 <= nums[i] <= 100  * nums is sorted in non-decreasing order."
url: "https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/"
favicon: ""
aspectRatio: "52"
```

- Use set as the brute force approach 
```cpp 
int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int idx = 0;
        for(auto it:st){
            nums[idx] = it;
            idx++;
        }
        return idx;
}
```

- Optimal solution is two pointer approach 

```cpp 
 int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 1;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[++i] = nums[j];
            }
        }
        return i+1;
}
```

### 4. Left Rotate the array by 'D' places 

```embed
title: "Rotate Array by K places | Union, Intersection of Sorted Arrays | Move Zeros to End | Arrays Part-2"
image: "https://i.ytimg.com/vi/wvcQg43_V8U/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/wvcQg43_V8U?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=494"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Rotate Array - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Rotate Array - Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.     Example 1:   Input: nums = [1,2,3,4,5,6,7], k = 3 Output: [5,6,7,1,2,3,4] Explanation: rotate 1 steps to the right: [7,1,2,3,4,5,6] rotate 2 steps to the right: [6,7,1,2,3,4,5] rotate 3 steps to the right: [5,6,7,1,2,3,4]   Example 2:   Input: nums = [-1,-100,3,99], k = 2 Output: [3,99,-1,-100] Explanation:  rotate 1 steps to the right: [99,-1,-100,3] rotate 2 steps to the right: [3,99,-1,-100]      Constraints:   * 1 <= nums.length <= 105  * -231 <= nums[i] <= 231 - 1  * 0 <= k <= 105     Follow up:   * Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.  * Could you do it in-place with O(1) extra space?"
url: "https://leetcode.com/problems/rotate-array/"
favicon: ""
aspectRatio: "52"
```
- In the video it is left rotate but in the question it is right rotate. The code is according to the question.

```cpp 
// Brute 
// dry run [1,2,3,4,5,6,7]
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> temp;
	for(int i = 0;i<n-k;i++){ // 0 to 3
		temp.push_back(nums[i]); 
	}
	// temp [1, 2, 3, 4]

	for(int i = n-k;i<n;i++){ // 4 to 6 
		nums[i-(n-k)] = nums[i]; // nums[0] = nums[4] .. 
	}
	// nums [5, 6, 7, 4, 5, 6, 7]

	for(int i = 0;i<temp.size();i++){  // 0 to 3
		nums[k+i] = temp[i]; // nums[3] = temp[0] .. 
	}

	// nums [5, 6,7, 1, 2, 3, 4]
}
```

- **Optimal** : The function `reverse(first, last)` in `<algorithm>` reverses the elements in the **half-open range**:
	`[first, last)   // inclusive of first, exclusive of last`
```cpp
// based on observation // ratta maar
// dry run [1,2,3,4,5,6,7]
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	reverse(nums.begin(), nums.begin()+n-k); // reverse the first n-k elements
	// [4,3,2,1,5,6,7]
	reverse(nums.begin()+n-k, nums.end());
	// [4,3,2,1,7,6,5]
	reverse(nums.begin(), nums.end()); 
	// [5,6,7,1,2,3,4]
}
```

### 5.  Move Zeroes to the End 

```embed
title: "Rotate Array by K places | Union, Intersection of Sorted Arrays | Move Zeros to End | Arrays Part-2"
image: "https://i.ytimg.com/vi/wvcQg43_V8U/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/wvcQg43_V8U?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=2021"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Move Zeroes - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Move Zeroes - Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.  Note that you must do this in-place without making a copy of the array.     Example 1:  Input: nums = [0,1,0,3,12] Output: [1,3,12,0,0]   Example 2:  Input: nums = [0] Output: [0]      Constraints:   * 1 <= nums.length <= 104  * -231 <= nums[i] <= 231 - 1     Follow up: Could you minimize the total number of operations done?"
url: "https://leetcode.com/problems/move-zeroes/description/"
favicon: ""
aspectRatio: "52"
```

- Brute force solution is very basic.
- Optimal solution uses two pointer approach: 

```cpp 
 // dry run [1,2,0,3,4,0,0,0,5,6]
void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	int j = -1;

	for(int i = 0;i<n;i++){
		if(nums[i] == 0){
			j = i;
			break;
		}
	}
	// j = 2
    if(j == -1) return; // for case [1] or if there are no zeroes in the entire nums
	for(int i = j+1;i<n;i++){ // j will always point to the zero 
		if(nums[i] != 0){                                 
			swap(nums[i], nums[j]); //swap(0,3) => [1,2,3,0,4,0,0,0,5,6] .. 
			j++; //j = 3 .. 
		}
	}

}
```

### 6. Union of 2 Sorted Arrays

```embed
title: "Rotate Array by K places | Union, Intersection of Sorted Arrays | Move Zeros to End | Arrays Part-2"
image: "https://i.ytimg.com/vi/wvcQg43_V8U/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/wvcQg43_V8U?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=3012"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Union of 2 Sorted Arrays | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two sorted&nbsp;arrays&nbsp;a[]&nbsp;and&nbsp;b[], where each array may contain duplicate&nbsp;elements , the task is to return the elements in the&nbsp;union of the two arrays in sorted order.Union of two arrays can be defined as the set conta"
url: "https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1"
favicon: ""
aspectRatio: "100"
```

- the brute force is simple just use set to solve the problem.
- optimal approach is based on two pointer method

```cpp 
 void checkAndPushIntoUnionArr(vector<int> &union_arr, int ele){
	if(union_arr.size()==0 || union_arr.back() != ele){
		union_arr.push_back(ele);
	}
}
    
vector<int> findUnion(vector<int> &a, vector<int> &b) {

	int a_size = a.size();
	int b_size = b.size();
	vector<int> union_arr;
	int i = 0, j = 0;
	
	while (i<a_size && j<b_size){
		if(a[i] <= b[j]){
			checkAndPushIntoUnionArr(union_arr, a[i]);
			i++;
		}else{
			checkAndPushIntoUnionArr(union_arr, b[j]);
			j++;
		}
	}
	
	while(i<a_size){
		checkAndPushIntoUnionArr(union_arr, a[i]);
		i++;
	}
	
	 while(j<b_size){
		checkAndPushIntoUnionArr(union_arr, b[j]);
		j++;
	}
	
	return union_arr;
}
```

### 7. Intersection of two sorted arrays

```embed
title: "Rotate Array by K places | Union, Intersection of Sorted Arrays | Move Zeros to End | Arrays Part-2"
image: "https://i.ytimg.com/vi/wvcQg43_V8U/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/wvcQg43_V8U?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=3548"
favicon: ""
aspectRatio: "56.25"
```


```embed
title: "Intersection of two sorted arrays | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.Intersection of two arrays is said to be elements that are common in both arrays.&nbsp;The intersection should not count duplicate elements.Note: If the"
url: "https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1"
favicon: ""
aspectRatio: "100"
```

- In the problem, duplicate elements are not allowed but in the video solutions duplicated elements are allowed in the result array.
- Brute forces uses nested for loop
```cpp 
 vector<int> intersection(vector<int> &a, vector<int> &b) {
       // brute force 
       int n1 = a.size();
       int n2 = b.size();
       
       vector<int> visited(n2, 0);
       vector<int> intersect_arr;
       
       for(int i = 0;i<n1;i++){
           for(int j = 0;j<n2;j++){
               if(a[i] == b[j] && visited[j] == 0){
                   if(intersect_arr.size() == 0 || intersect_arr.back() != b[j]){ // to not allow duplicated elements 
                        intersect_arr.push_back(b[j]);
                        visited[j] = 1;
                   }
               }
           }
       }
       
       return intersect_arr;
}
```

- Optimal approach is based on two pointers
```cpp 
vector<int> intersection(vector<int> &a, vector<int> &b) {
        //optimal approach 
        int n1 = a.size();
        int n2 = b.size();
        vector<int> intersectArr;
        int i = 0, j = 0;
        
        while(i<n1 && j<n2){
            if(a[i] < b[j]) i++;
            else if(b[j] < a[i]) j++;
            else if(a[i] == b[j]) {
                if(intersectArr.size() == 0 || intersectArr.back()!=a[i]){
                    intersectArr.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
        
        return intersectArr;
}
```

### 8. Find the missing Number 

```embed
title: "Find element that appears once | Find missing number | Max Consecutive number of 1's | Arrays Part-3"
image: "https://i.ytimg.com/vi/bYWLJb3vCWY/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/bYWLJb3vCWY?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=57"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Missing Number - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Missing Number - Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.     Example 1:  Input: nums = [3,0,1]  Output: 2  Explanation:  n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.  Example 2:  Input: nums = [0,1]  Output: 2  Explanation:  n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.  Example 3:  Input: nums = [9,6,4,2,3,5,7,0,1]  Output: 8  Explanation:  n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.                Constraints:   * n == nums.length  * 1 <= n <= 104  * 0 <= nums[i] <= n  * All the numbers of nums are unique.     Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?"
url: "https://leetcode.com/problems/missing-number/"
favicon: ""
aspectRatio: "52"
```

- In brute force we can either sort the array or else we can use nested loop to check each number.
```cpp 
// Brute force -- My solution
 int missingNumber(vector<int>& nums) {
   int n = nums.size();
   sort(nums.begin(), nums.end());
   for(int i = 0;i<n;i++){
	if(nums[i]!=i) return i;
   } 

   return n;
}
```

```cpp
// Brute force using nested loops checking for each number.
int missingNumber(vector<int>& nums) {
  int n = nums.size();
  for(int i = 0;i<=n;i++){
	bool exists = false;
	for(int j = 0;j<n;j++){
		if(nums[j] == i){
			exists = true;
			break;
		}
	}
	if(exists == false){
		return i;
	}
  }
  return -1;
}
```

- The better approach involves hashing 
```cpp 
int missingNumber(vector<int>& nums) {
	int n = nums.size();
	vector<int> existsArr(n+1,0); //hash array

	for(int i = 0;i<n;i++){
		existsArr[nums[i]] = 1;
	}

	for(int i = 0;i<=n;i++){
		if(existsArr[i] == 0) return i;
	}

	return -1;
}
```

- The optimal approach is to use sum or `xor` operation. ( the `xor` approach with only one for loop works better.)

```cpp 
// sum based optimal approach
int missingNumber(vector<int>& nums) {
	int n = nums.size();
	long sum = n*(n+1)/2; // this can go to long there taking more space than xor based approach
	int arrSum = 0;

	for(int i = 0;i<n;i++){
		arrSum += nums[i];
	}

	return sum - arrSum;

}
```

```cpp 
// XOR based approach using the fact : num^num = 0
int missingNumber(vector<int>& nums) {
	int n = nums.size();
	int xorArr = 0;
	int xorNum = 0;
	for(int i = 0;i<n;i++){
		xorArr = xorArr^nums[i];
		xorNum = xorNum^i;
	}

	xorNum = xorNum^n;
	return xorArr^xorNum;

}
```

### 9. Single Number

```embed
title: "Find element that appears once | Find missing number | Max Consecutive number of 1's | Arrays Part-3"
image: "https://i.ytimg.com/vi/bYWLJb3vCWY/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/bYWLJb3vCWY?list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&t=1507"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Single Number - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Single Number - Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.  You must implement a solution with a linear runtime complexity and use only constant extra space.     Example 1:  Input: nums = [2,2,1]  Output: 1  Example 2:  Input: nums = [4,1,2,1,2]  Output: 4  Example 3:  Input: nums = [1]  Output: 1     Constraints:   * 1 <= nums.length <= 3 * 104  * -3 * 104 <= nums[i] <= 3 * 104  * Each element in the array appears twice except for one element which appears only once."
url: "https://leetcode.com/problems/single-number/description/"
favicon: ""
aspectRatio: "52"
```

- the brute force uses nested for loop checking the count of each element.
- the better approach uses unordered map.

```cpp 
 int singleNumber(vector<int>& nums) {
	unordered_map<int, int> countMap;
	for(int i = 0;i<nums.size();i++){
		countMap[nums[i]]++;
	}

	for(auto it: countMap){
		if(it.second == 1){
			return it.first;
		}
	}

	return -1;
}
```

- the optimal approach uses the `xor` operation since `num^num = 0`

```cpp 
int singleNumber(vector<int>& nums) {
	int xorNums = 0;
	for(int i = 0;i<nums.size();i++){
		xorNums = xorNums ^ nums[i];
	}
	return xorNums;
}
```

### 10. Longest Subarray with sum K

```embed
title: "Longest Subarray with sum K | Brute - Better - Optimal | Generate Subarrays"
image: "https://i.ytimg.com/vi/frf7qxiN2qU/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/frf7qxiN2qU?t=55"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Longest Subarray with Sum K | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value&nbsp;k. If there is no subarray with sum equal to&nbsp;k, return 0. Examples:"
url: "https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1"
favicon: ""
aspectRatio: "100"
```

- The brute force uses 3 nested loop, straight forward approach.
```cpp 
int longestSubarray(vector<int>& arr, int k) {
   int n = arr.size();
   int longestLen = 0;
   for(int i = 0;i<n;i++){
	   for(int j = i;j<n;j++){
		   int sum = 0;
		   for(int l = i;l<=j;l++){
			   sum += arr[l];
		   }
		   if(sum == k){
				  longestLen = max(longestLen, j-i+1);
		   }
	   }
   }
   return longestLen;
	
}
```

- For better brute instead of using another loop for calculating the sum, just use the new j element only.

```cpp 
int longestSubarray(vector<int>& arr, int k) {
   int n = arr.size();
   int longestLen = 0;
   for(int i = 0;i<n;i++){
	   int sum = 0;
	   for(int j = i;j<n;j++){
		   sum += arr[j];
		   if(sum == k){
				longestLen = max(longestLen, j-i+1);
		   }
	   }
   }
   return longestLen;
        
}
```

 - The better approach involves using hashing ( hash-map ) and using prefix sum concept.
```cpp 
int longestSubarray(vector<int>& arr, int k) {
   int n = arr.size();
   int longestLen = 0;
   unordered_map<int, int> prefixSumMap;
   int sum = 0;
   for(int i = 0;i<n;i++){
	  sum += arr[i];
	  if(sum == k ) longestLen = max(longestLen, i+1);
	  int key = sum - k;
	  if(prefixSumMap.find(key) != prefixSumMap.end()){
		  longestLen = max(longestLen, i - prefixSumMap[key]);
	  }
	  prefixSumMap[sum] = i;
   }
   return longestLen;
}
// this code does not work for array having zeroes
```

- For the above code to work for array having zeroes, the map should not be updated for values of sum already in the map.
```cpp 
int longestSubarray(vector<int>& arr, int k) {
   int n = arr.size();
   int longestLen = 0;
   unordered_map<int, int> prefixSumMap;
   int sum = 0;
   for(int i = 0;i<n;i++){
	  sum += arr[i];
	  if(sum == k ) longestLen = max(longestLen, i+1);
	  int key = sum - k;
	  if(prefixSumMap.find(key) != prefixSumMap.end()){
		  longestLen = max(longestLen, i - prefixSumMap[key]);
	  }
	  if(prefixSumMap.find(sum) == prefixSumMap.end()){ // this will make it work for zeroes in the array too 
		  prefixSumMap[sum] = i;
	  }
   }
   return longestLen;
} // this is the optimal solutions for all numbers.
```

- If there are only non-negative numbers then use sliding window for optimal solution.
```cpp 
int longestSubarray(vector<int>& arr, int k) {
   int n = arr.size();
   int sum = 0;
   int l = 0;
   int longestLen = 0;
   
   for(int r = 0;r<n;r++){
	   sum += arr[r]; // add the right element
	   while(l<=r && sum > k){ // remove the left elements
		   sum -= arr[l];
		   l++;
	   }
	   if(sum == k) longestLen = max(longestLen, r-l+1); // find the max length
	   
   }
   
   return longestLen;
} // this code is different from video but uses the same idea ( video code is un-neccessarily complex)
```


## Medium 

### 1. 2 Sum 

```embed
title: "2 Sum Problem | 2 types of the same problem for Interviews | Brute-Better-Optimal"
image: "https://i.ytimg.com/vi/UXDSeD9mN-k/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=UXDSeD9mN-k"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Two Sum - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Two Sum - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.  You may assume that each input would have exactly one solution, and you may not use the same element twice.  You can return the answer in any order.     Example 1:   Input: nums = [2,7,11,15], target = 9 Output: [0,1] Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].   Example 2:   Input: nums = [3,2,4], target = 6 Output: [1,2]   Example 3:   Input: nums = [3,3], target = 6 Output: [0,1]      Constraints:   * 2 <= nums.length <= 104  * -109 <= nums[i] <= 109  * -109 <= target <= 109  * Only one valid answer exists.     Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?"
url: "https://leetcode.com/problems/two-sum"
favicon: ""
aspectRatio: "52"
```

- For brute force just use the nested for loops
```cpp 
vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){ // this for loop can be optimized 
			if (i==j) continue;
			if(nums[i] + nums[j] == target)
			return {i,j};
		}
	}
	return {-1,-1};
}
```

- For slightly better brute force, `for the j for loop iterate from i+1 instead of 0`.

```cpp 
vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size();
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(nums[i] + nums[j] == target)
			return {i,j};
		}
	}
	return {-1,-1};
}
```

- The optimal approach involves using `hashmap with key : element and value : index `

```cpp 
vector<int> twoSum(vector<int>& nums, int target) {
	int n = nums.size();
	unordered_map<int, int> numsMap;
	for(int i = 0;i<n;i++){
		int diff = target - nums[i];
		if(numsMap.find(diff) != numsMap.end()){
			return {numsMap[diff], i};
		}
		numsMap[nums[i]] = i;
	}

	return {-1, -1};
}
```

### 2. Sort an array of 0's 1's and 2's

```embed
title: "Sort an array of 0's 1's & 2's | Intuition of Algo🔥 | C++ Java Python | Brute-Better-Optimal"
image: "https://i.ytimg.com/vi/tp8JIuCXBaU/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/tp8JIuCXBaU?t=40"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Sort Colors - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Sort Colors - Given an array nums with n objects colored red, white, or blue, sort them in-place [https://en.wikipedia.org/wiki/In-place_algorithm] so that objects of the same color are adjacent, with the colors in the order red, white, and blue.  We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.  You must solve this problem without using the library's sort function.     Example 1:   Input: nums = [2,0,2,1,1,0] Output: [0,0,1,1,2,2]   Example 2:   Input: nums = [2,0,1] Output: [0,1,2]      Constraints:   * n == nums.length  * 1 <= n <= 300  * nums[i] is either 0, 1, or 2.     Follow up: Could you come up with a one-pass algorithm using only constant extra space?"
url: "https://leetcode.com/problems/sort-colors"
favicon: ""
aspectRatio: "52"
```

- Brute force: directly sort the array.
- Better approach: iterate the array, count the 0s 1s and 2s and then fill them back back into the array according to the count starting from 0 going till 2.
- The best solution uses Dutch National Flag Algorithm to sort the array.

```cpp 
void sortColors(vector<int>& nums) {
	// Dutch National Flag algorithm 
	int low = 0, mid = 0, high = nums.size()-1;

	while(mid<=high){
		if(nums[mid] == 0){
			swap(nums[mid], nums[low]);
			mid++;
			low++;
		}else if(nums[mid] == 1){
			mid++;
		}else if(nums[mid] == 2){
			swap(nums[mid], nums[high]);
			high--;
		}
	}
}
```

### 3. Majority Element (>n/2 times)

```embed
title: "Majority Element I | Brute-Better-Optimal | Moore's Voting Algorithm | Intuition 🔥|Brute to Optimal"
image: "https://i.ytimg.com/vi/nP_ns3uSh80/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/nP_ns3uSh80?t=40"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Majority Element - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Majority Element - Given an array nums of size n, return the majority element.  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.     Example 1:  Input: nums = [3,2,3] Output: 3   Example 2:  Input: nums = [2,2,1,1,1,2,2] Output: 2      Constraints:   * n == nums.length  * 1 <= n <= 5 * 104  * -109 <= nums[i] <= 109     Follow-up: Could you solve the problem in linear time and in O(1) space?"
url: "https://leetcode.com/problems/majority-element/description"
favicon: ""
aspectRatio: "52"
```

- Brute force : iterate using nested loop getting count of each element and comparing the count to check if it is majority element.
```cpp 
int majorityElement(vector<int>& nums) {
	int n = nums.size();
	for(int i = 0;i<n;i++){
		int count = 0;
		for(int j = 0;j<n;j++){
			if(nums[i] == nums[j]) count++;
		}
		if(count > n/2) return nums[i];
	}

	return -1;
}
```

- Better approach : use hash map to store the count and then iterate the hash map to the count of the majority element.

```cpp 
int majorityElement(vector<int>& nums) {
	int n = nums.size();
	unordered_map<int,int> countMap;
	for(int i = 0;i<n;i++){
	   countMap[nums[i]]++;
	}
	for(auto it: countMap){
		if(it.second > n/2){
			return it.first;
		}
	}

	return -1;
}
```

- Best approach : use Moore's Voting algo to get the possible majority element and then verify that it is majority element by iterating the array.

```cpp 
int majorityElement(vector<int>& nums) {
	int n = nums.size();
	int count = 0;
	int element = nums[0];
	
	// moore's voting algo 
	for(int i = 0;i<n;i++){
	  if(count == 0){
		element = nums[i];
		count = 1;
	  }
	  else if(nums[i] == element){
		count++;
	  }else{
		count--;
	  }
	}

	// verify the majority element
	int majCount = 0;
	for(int i = 0;i<n;i++){
		if(element == nums[i]){
			majCount++;
		}
	}

	if(majCount > n/2){
		return element;
	}
	
	return -1;
}
```

### 4. Kadane's Algorithm, maximum subarray sum

```embed
title: "Kadane's Algorithm | Maximum Subarray Sum | Finding and Printing"
image: "https://i.ytimg.com/vi/AHZpyENo7k4/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/AHZpyENo7k4?t=136"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Maximum Subarray - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Maximum Subarray - Given an integer array nums, find the subarray with the largest sum, and return its sum.     Example 1:   Input: nums = [-2,1,-3,4,-1,2,1,-5,4] Output: 6 Explanation: The subarray [4,-1,2,1] has the largest sum 6.   Example 2:   Input: nums = [1] Output: 1 Explanation: The subarray [1] has the largest sum 1.   Example 3:   Input: nums = [5,4,-1,7,8] Output: 23 Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.      Constraints:   * 1 <= nums.length <= 105  * -104 <= nums[i] <= 104     Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle."
url: "https://leetcode.com/problems/maximum-subarray"
favicon: ""
aspectRatio: "52"
```

- The brute force involves using 3 nested loops to get the sum of each subarray.
- The better approach involves just using the last j element to add to the sum therefore just using nested for loop
- The optimal approach involves the Kadane's algorithm. Don't carry the negative sum.

```cpp 
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int maxSum = INT_MIN;
	int sum = 0;
	//kadane's algorithm
	for(int i = 0;i<n;i++){
		sum += nums[i];
		maxSum = max(maxSum, sum);
		if(sum < 0) sum = 0; // don't carry negative sum
	}
	return maxSum;
}
```

- Modified problem where the subarray also need to be returned.

```cpp 
vector<int> findSubarray(vector<int>& arr) {
	
	int n = arr.size();
	int sum = 0;
	int maxSum = INT_MIN;
	int maxStart = -1;
	int maxEnd = -1;
	int start = 0;
	
	for(int i = 0;i<n;i++){
		
		if(sum == 0) start = i;
		
		sum += arr[i];
		
		if(sum > maxSum){
			maxSum = sum;
			maxStart = start;
			maxEnd = i;
		}
		
		if(sum < 0) sum = 0;
		
	}
	
	if(maxStart != -1 && maxEnd != -1){
		return vector<int>(arr.begin()+maxStart, arr.begin()+maxEnd+1);
	}
}
```

### 5. Rearrange the array in alternating positive and negative items

```embed
title: "Rearrange Array Elements by Sign - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Rearrange Array Elements by Sign - You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.  You should return the array of nums such that the the array follows the given conditions:   1. Every consecutive pair of integers have opposite signs.  2. For all integers with the same sign, the order in which they were present in nums is preserved.  3. The rearranged array begins with a positive integer.  Return the modified array after rearranging the elements to satisfy the aforementioned conditions.     Example 1:   Input: nums = [3,1,-2,-5,2,-4] Output: [3,-2,1,-5,2,-4] Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4]. The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4]. Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.     Example 2:   Input: nums = [-1,1] Output: [1,-1] Explanation: 1 is the only positive integer and -1 the only negative integer in nums. So nums is rearranged to [1,-1].      Constraints:   * 2 <= nums.length <= 2 * 105  * nums.length is even  * 1 <= |nums[i]| <= 105  * nums consists of equal number of positive and negative integers.     It is not required to do the modifications in-place."
url: "https://leetcode.com/problems/rearrange-array-elements-by-sign"
favicon: ""
aspectRatio: "52"
```

- Brute force uses different arrays for positive and negative elements instead of using the indexes directly.
```cpp 
vector<int> rearrangeArray(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans(n);
	int posIdx = 0;
	int negIdx = 1;
	
	for(int i = 0;i<n;i++){
		if(nums[i]>=0){
			ans[posIdx] = nums[i];
			posIdx += 2;
		}else{
			ans[negIdx] = nums[i];
			negIdx += 2;
		}
	}
	
	return ans;
}
```

### 6. Next Permutation

```embed
title: "Next Permutation - Intuition in Detail 🔥 | Brute to Optimal"
image: "https://i.ytimg.com/vi/JDOXKqF60RQ/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/JDOXKqF60RQ?t=37"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Next Permutation - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Next Permutation - A permutation of an array of integers is an arrangement of its members into a sequence or linear order.   * For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].  The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).   * For example, the next permutation of arr = [1,2,3] is [1,3,2].  * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].  * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.  Given an array of integers nums, find the next permutation of nums.  The replacement must be in place [http://en.wikipedia.org/wiki/In-place_algorithm] and use only constant extra memory.     Example 1:   Input: nums = [1,2,3] Output: [1,3,2]   Example 2:   Input: nums = [3,2,1] Output: [1,2,3]   Example 3:   Input: nums = [1,1,5] Output: [1,5,1]      Constraints:   * 1 <= nums.length <= 100  * 0 <= nums[i] <= 100"
url: "https://leetcode.com/problems/next-permutation"
favicon: ""
aspectRatio: "52"
```

![[Arrays-1760243358660.png|494x411]]

```cpp 
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int breakPtIdx = -1;
	
	// find the breakpoint
	for(int i = n-2;i>=0;i--){
		if(nums[i] < nums[i+1]){
			breakPtIdx = i;
			break;
		}
	}

	// return reverse if there is no breakpoint
	if(breakPtIdx == -1){
		reverse(nums.begin(),nums.end());
		return;
	}

	// swap the next largest element from right side of the array 
	// which is sorted as it is in increasing order
	for(int i = n-1;i>breakPtIdx;i--){
		if(nums[i] > nums[breakPtIdx]){
			swap(nums[i], nums[breakPtIdx]);
			break;
		}
	}
	
	// since even after the swap the array on the right is still sorted 
	// reverse it to get the smallest permutation out of it 
	reverse(nums.begin()+breakPtIdx+1, nums.end());
}
```

### 7. Next Leader 

```embed
title: "Leaders in an Array | Brute - Optimal | Strivers A2Z DSA Course"
image: "https://i.ytimg.com/vi/cHrH9CQ8pmY/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=cHrH9CQ8pmY"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Array Leaders | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader. Examples: Inp"
url: "https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
//Brute Force
vector<int> leaders(vector<int>& arr) {
	// Code here
	vector<int> ans;
	int n = arr.size();
	for(int i = 0;i<n;i++){
		bool isLeader = true;
		for(int j = i+1;j<n;j++){
			if(arr[j] > arr[i]){
				isLeader = false;
				break;
			}
		}
		if(isLeader == true) ans.push_back(arr[i]);
	}
	
	return ans;
}
```

```cpp 
//optimal solution
vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i = n-1;i>=0;i--){
            if(arr[i]>=maxi){ // handle if there are duplicate elements
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(), ans.end()); // reverse due to the format and answer acceptance of the question on GFG.
        return ans;
    }
```

### 8. Longest Consecutive Subsequence

```embed
title: "Longest Consecutive Sequence | Google Interview Question | Brute Better Optimal"
image: "https://i.ytimg.com/vi/oO5uLE7EUlM/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=oO5uLE7EUlM"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Longest Consecutive Subsequence | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. Examples: Input: arr[] = [2, 6, 1, 9, 4, 5, 3] Out"
url: "https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
// brute force
bool linearSearch(vector<int> arr, int ele){
	for(int i = 0;i<arr.size();i++){
		if(arr[i] == ele) return true;
	}
	return false;
}
// Function to return length of longest subsequence of consecutive integers.
int longestConsecutive(vector<int>& arr) {
	// Your code here
	int n = arr.size();
	int longest = 1;
	for(int i = 0;i<n;i++){
		int ele = arr[i];
		int count = 1;
		while(linearSearch(arr, ele+1)){
			ele++;
			count++;
		}
		longest = max(longest, count);
	}
	return longest;
}
```

```cpp 
// Better approach
int longestConsecutive(vector<int>& arr) {
	sort(arr.begin(),arr.end());
	int n = arr.size();
	int lastSmall = INT_MIN;
	int longest = 1;
	int currCnt = 1;
	for(int i = 0;i<n;i++){
		if(arr[i] == lastSmall + 1){
			currCnt++;
			lastSmall = arr[i];
		}else if(arr[i] != lastSmall){ // In case of else condition duplicates are not handled
			currCnt = 1;
			lastSmall = arr[i];
		}
		longest = max(currCnt, longest);
	}
	return longest;
}
```

```cpp 
// Optimal 
int longestConsecutive(vector<int>& arr) {
	int n = arr.size();
	if(n==0) return 0;
	int longest = 1;
	unordered_set<int> st;
	for(int i = 0;i<n;i++){
		st.insert(arr[i]);
	}
	
	for(auto ele: st){
		if(st.find(ele-1) == st.end()){
			int cnt = 1;
			int x = ele;
			while(st.find(x+1) != st.end()){
				x = x + 1;
				cnt++;
			}
			longest = max(longest, cnt);
		}
	}
	return longest;
}
```


[[Aditya Verma Recursion Playlist]]

### 1. myPow

```embed
title: "Pow(x, n) - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Pow(x, n) - Implement pow(x, n) [http://www.cplusplus.com/reference/valarray/pow/], which calculates x raised to the power n (i.e., xn).     Example 1:   Input: x = 2.00000, n = 10 Output: 1024.00000   Example 2:   Input: x = 2.10000, n = 3 Output: 9.26100   Example 3:   Input: x = 2.00000, n = -2 Output: 0.25000 Explanation: 2-2 = 1/22 = 1/4 = 0.25      Constraints:   * -100.0 < x < 100.0  * -231 <= n <= 231-1  * n is an integer.  * Either x is not zero or n > 0.  * -104 <= xn <= 104"
url: "https://leetcode.com/problems/powx-n/"
favicon: ""
aspectRatio: "52"
```

```cpp 
double solve(double x, long long n){
	if(n==0) return 1.0;

	double half = solve(x,n/2);

	if(n%2==0){
		return half*half;
	}else{
		return half*half*x;
	}
}

double myPow(double x, int n) {
  long long N = n;
  if(N<0){
	x = 1/x;
	N = -N;
  }

  return solve(x,N);
}
```

- There is also a different solution for this using bits, will check that later on.
### 2. Count or check subsequences/subsets with sum k

```embed
title: "L7. All Kind of Patterns in Recursion | Print All | Print one | Count"
image: "https://i.ytimg.com/vi/eQCS_v3bw0Q/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=eQCS_v3bw0Q"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Code 360 by Coding Ninjas"
image: "data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wI iBlbmNvZGluZz0iVVRGLTgiPz48c3ZnIHdpZHRoPSI5OTk5OXB4IiBoZWlnaHQ9Ijk5OTk5cHgiIHZpZXdCb3g9IjAgMCA5OTk5OSA5OTk5OSIgdmVyc2lvbj0iMS4xIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8v d3d3LnczLm9yZy8xOTk5L3hsaW5rIj48ZyBzdHJva2U9Im5vbmUiIGZpbGw9Im5vbmUiIGZpbGwtb3BhY2l0eT0iMCI+PHJlY3QgeD0iMCIgeT0iMCIgd2lkdGg9Ijk5OTk5IiBoZWlnaHQ9Ijk5OTk5Ij48L3JlY3Q+IDwvZz4gPC9zdmc+"
description: ""
url: "https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM"
favicon: ""
aspectRatio: "100"
```

- For the above problem using the code : all the test cases will not pass, but that's fine because the goal here is to learn recursion and backtracking.
```cpp 

// this is simple recursion this can be written using backtracking also, as given in the above video
void solve(vector<int>& arr,int idx, int k, long long sum, long long& ways){
	if(sum > k) return;
	if(idx == arr.size()){
		if(sum == k) ways++;
		return;
	}

	long long sum1 = sum;
	long long sum2 = sum;

	sum1 += arr[idx];

	solve(arr,idx+1,k,sum1,ways); // take
	solve(arr,idx+1,k,sum2,ways); // not take
}


int findWays(vector<int>& arr, int k)
{
	long long ways = 0;
	long long sum = 0;
	int mod = 1e9 + 7;
	int idx = 0;
	solve(arr, idx, k, sum, ways);
	return ways % mod;
}

```

```cpp 
void solve(vector<int>& arr,int idx, int k, long long sum, long long& ways){
	
	if(sum > k) return;
	if(idx == arr.size()){
		if(sum == k) ways++;
		return;
	}
	
	sum += arr[idx];
	solve(arr,idx+1,k,sum1,ways); // take
	sum -= arr[idx]; // backtrack (remove the take element from the sum while coming back from recursion)
	
	solve(arr,idx+1,k,sum2,ways); // not take
}


int findWays(vector<int>& arr, int k)
{
	long long ways = 0;
	long long sum = 0;
	int mod = 1e9 + 7;
	int idx = 0;
	solve(arr, idx, k, sum, ways);
	return ways % mod;
}

```

- In the above code I have passed ways as a parameter to the recursive function but we can also write proper recursion for this.

```cpp 
int solve(vector<int>& arr,int& n,int idx, int k, long long sum){
	
	if(sum > k) return 0;
	if(idx == n){
		if(sum == k) return 1;
		else return 0;
	}

	long long sum1 = sum;
	long long sum2 = sum;

	sum1 += arr[idx];

	int l = solve(arr,n,idx+1,k,sum1); // take
	int r = solve(arr,n,idx+1,k,sum2); // not take
	
	return l+r;
}


int findWays(vector<int>& arr, int k)
{
	long long sum = 0;
	int mod = 1e9 + 7;
	int idx = 0;
	int n = arr.size();
	return solve(arr, n, idx, k, sum);
}
```

```cpp 
// solution using backtracking

int solve(vector<int>& arr,int& n,int idx, int k, long long sum){
	
	if(sum > k) return 0;
	if(idx == n){
		if(sum == k) return 1;
		else return 0;
	}
	
	sum += arr[idx];
	int l = solve(arr,n,idx+1,k,sum); // take
	sum -= arr[idx]; // backtrack
	
	int r = solve(arr,n,idx+1,k,sum); // not take
	
	return l+r;
}


int findWays(vector<int>& arr, int k)
{
	long long sum = 0;
	int mod = 1e9 + 7;
	int idx = 0;
	int n = arr.size();
	return solve(arr, n, idx, k, sum);
}
```

- In Aditya verma notes, in the subset he remove the element from the input which is costly especially for an array, but here we use size and index to handle that, so for aditya verma code, write the codes once again with size and idx.

```embed
title: "Check if there exists a subsequence with sum K | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr&nbsp;and&nbsp;target sum k,&nbsp;check whether&nbsp;there exists a subsequence&nbsp;such that the sum of all elements in the subsequence equals the given&nbsp;target sum(k).   Example:   Input:  arr = [10,1,2,7,6,1,5], k = 8."
url: "https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
bool solve(vector<int>& arr, int& n, int i, int& k, int sum){
	if(sum > k) return false;
	if(i==n){
		if(sum == k) return true;
		else return false;
	}
	
	int sum1 = sum + arr[i];
	int sum2 = sum;
	
	if(solve(arr, n, i+1, k, sum1) == true){
		return true;
	}
	if(solve(arr, n, i+1, k, sum2) == true){
		return true;
	}
	
	return false;
}
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
	int i = 0;
	int sum = 0;
	return solve(arr,n,i,k,sum);
	
}
```

```cpp 
// using backtracking 
bool solve(vector<int>& arr, int& n, int i, int& k, int sum){

	if(sum > k) return false;
	if(i==n){
		if(sum == k) return true;
		else return false;
	}
	
	sum = sum + arr[i];
	if(solve(arr, n, i+1, k, sum) == true){
		return true;
	}
	sum = sum - arr[i];
	
	if(solve(arr, n, i+1, k, sum) == true){
		return true;
	}
	
	return false;
}
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
	int i = 0;
	int sum = 0;
	return solve(arr,n,i,k,sum);
	
}
```
### 3. Combination Sum

```embed
title: "L8. Combination Sum | Recursion | Leetcode | C++ | Java"
image: "https://i.ytimg.com/vi/OyZFFqQtu98/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=OyZFFqQtu98"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Combination Sum - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Combination Sum - Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.  The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.  The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.     Example 1:   Input: candidates = [2,3,6,7], target = 7 Output: [[2,2,3],[7]] Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times. 7 is a candidate, and 7 = 7. These are the only two combinations.   Example 2:   Input: candidates = [2,3,5], target = 8 Output: [[2,2,2,2],[2,3,3],[3,5]]   Example 3:   Input: candidates = [2], target = 1 Output: []      Constraints:   * 1 <= candidates.length <= 30  * 2 <= candidates[i] <= 40  * All elements of candidates are distinct.  * 1 <= target <= 40"
url: "https://leetcode.com/problems/combination-sum/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
// using simple recursion 
void solve(vector<int>& candidates, int& n, int i, int target, int sum , vector<int> arr, vector<vector<int>>& ans){

	if(i==n){
		if(sum == target) ans.push_back(arr);
		return;
	}

	if(sum <= target){
		int sum1 = sum + candidates[i];
		vector<int> arr1 = arr;
		arr1.push_back(candidates[i]);
		solve(candidates,n,i, target, sum1, arr1, ans); // i does not go to i+1 
		// because one element can be picked multiple times
	}
	
	solve(candidates,n,i+1, target, sum, arr, ans);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int n = candidates.size();
	int i = 0;
	vector<int> arr;
	int sum = 0;
	solve(candidates,n,i,target,sum,arr,ans);
	return ans;
}
```

```cpp 
// using backtracking 

void solve(vector<int>& candidates, int& n, int i, int target, int sum , vector<int> arr, vector<vector<int>>& ans){

	if(i==n){
		if(sum == target) ans.push_back(arr);
		return;
	}

	if(sum <= target){
		sum = sum + candidates[i];
		arr.push_back(candidates[i]);
		
		solve(candidates,n,i, target, sum, arr, ans); // i does not go to i+1 
		// because one element can be picked multiple times
		
		// backtrack
		sum = sum - candidates[i];
		arr.pop_back();
	}
	
	solve(candidates,n,i+1, target, sum, arr, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int n = candidates.size();
	int i = 0;
	vector<int> arr;
	int sum = 0;
	solve(candidates,n,i,target,sum,arr,ans);
	return ans;
}
```
### 4. Combination Sum-II

```embed
title: "L9. Combination Sum II | Leetcode | Recursion | Java | C++"
image: "https://i.ytimg.com/vi/G1fRTGRxXU8/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=G1fRTGRxXU8"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Combination Sum II - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Combination Sum II - Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.  Each number in candidates may only be used once in the combination.  Note: The solution set must not contain duplicate combinations.     Example 1:   Input: candidates = [10,1,2,7,6,1,5], target = 8 Output:  [ [1,1,6], [1,2,5], [1,7], [2,6] ]   Example 2:   Input: candidates = [2,5,2,1,2], target = 5 Output:  [ [1,2,2], [5] ]      Constraints:   * 1 <= candidates.length <= 100  * 1 <= candidates[i] <= 50  * 1 <= target <= 30"
url: "https://leetcode.com/problems/combination-sum-ii/"
favicon: ""
aspectRatio: "52"
```

```cpp 
// using simple recursion 
void solve(vector<int>& candidates, int& n, int idx, int& target, int sum,vector<int> arr, vector<vector<int>>& ans){
	if(sum > target) return;

	if(sum == target){
		ans.push_back(arr);
		return;
	}

	for(int i = idx;i<n;i++){
		if(i == idx || candidates[i] != candidates[i-1]){ // the condition in the video is complex whereas this condition is straight forward...
			vector<int> arr1 = arr;
			arr1.push_back(candidates[i]);
			int sum1 = sum + candidates[i];
			solve(candidates,n,i+1,target, sum1, arr1, ans);
		}
	}
	

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int idx = 0;
	int n = candidates.size();
	vector<int> arr;
	sort(candidates.begin(), candidates.end());
	int sum = 0;
	solve(candidates,n,idx,target,sum,arr,ans);

	return ans;
}
```

```cpp 
// using backtracking 

void solve(vector<int>& candidates, int& n, int idx, int& target, int sum,vector<int> arr, vector<vector<int>>& ans){
	if(sum > target) return;

	if(sum == target){
		ans.push_back(arr);
		return;
	}

	for(int i = idx;i<n;i++){
		if(i == idx || candidates[i] != candidates[i-1]){ // the condition in the video is complex whereas this condition is straight forward...
			arr.push_back(candidates[i]);
			sum = sum + candidates[i];
			solve(candidates,n,i+1,target, sum, arr, ans);
			// backtrack
			sum = sum - candidates[i];
			arr.pop_back();
		}
	}

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	int idx = 0;
	int n = candidates.size();
	vector<int> arr;
	sort(candidates.begin(), candidates.end());
	int sum = 0;
	solve(candidates,n,idx,target,sum,arr,ans);

	return ans;
}
```

### 5. Subset Sum I 

```embed
title: "L10. Subset Sum I | Recursion | C++ | Java"
image: "https://i.ytimg.com/vi/rYkfBRtMJr8/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=rYkfBRtMJr8"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Subset Sums | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: " Given a array arr of integers, return the sums of all subsets in the list.&nbsp; Return the sums in any order. Examples: Input: arr[] = [2, 3] Output: [0, 2, 3, 5] Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum ="
url: "https://www.geeksforgeeks.org/problems/subset-sums2234/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
// using simple recursion
void solve(vector<int>& arr, int& n, int i, int sum, vector<int>& ans){
	if(i==n){
		ans.push_back(sum);
		return;
	}
	
	int sum1 = sum + arr[i];
	solve(arr, n, i+1, sum1, ans);
	solve(arr, n, i+1, sum, ans);
}
vector<int> subsetSums(vector<int>& arr) {
	int n = arr.size();
	int i = 0;
	vector<int> ans;
	int sum = 0;
	solve(arr,n,i,sum,ans);
	return ans;
}
```

```cpp 
//using backtracking
void solve(vector<int>& arr, int& n, int i, int sum, vector<int>& ans){
	if(i==n){
		ans.push_back(sum);
		return;
	}
	
	sum = sum + arr[i];
	solve(arr, n, i+1, sum, ans);
	sum = sum - arr[i];
	solve(arr, n, i+1, sum, ans);
}
vector<int> subsetSums(vector<int>& arr) {
	int n = arr.size();
	int i = 0;
	vector<int> ans;
	int sum = 0;
	solve(arr,n,i,sum,ans);
	return ans;
}
```

### 6. Subsets II

```embed
title: "L11. Subset Sum II | Leetcode | Recursion"
image: "https://i.ytimg.com/vi/RIn3gOkbhQE/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=RIn3gOkbhQE"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Subsets II - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Subsets II - Given an integer array nums that may contain duplicates, return all possible subsets (the power set).  The solution set must not contain duplicate subsets. Return the solution in any order.     Example 1:  Input: nums = [1,2,2] Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]   Example 2:  Input: nums = [0] Output: [[],[0]]      Constraints:   * 1 <= nums.length <= 10  * -10 <= nums[i] <= 10"
url: "https://leetcode.com/problems/subsets-ii/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
// using simple recursion 
void subsets(vector<int>& nums, int& n, int idx, vector<int> arr, vector<vector<int>>& ans){

	ans.push_back(arr);

	for(int i = idx;i<n;i++){
		if(i == idx || nums[i]!=nums[i-1]){
			vector<int> arr1 = arr;
			arr1.push_back(nums[i]);
			subsets(nums, n, i+1, arr1, ans);
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> arr;
	int idx = 0;
	subsets(nums, n, idx, arr, ans);
	return ans;
}
```

```cpp 
// using backtracking
void subsets(vector<int>& nums, int& n, int idx, vector<int> arr, vector<vector<int>>& ans){

	ans.push_back(arr);

	for(int i = idx;i<n;i++){
		if(i == idx || nums[i]!=nums[i-1]){
			arr.push_back(nums[i]);
			subsets(nums, n, i+1, arr, ans);
			arr.pop_back();
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	vector<int> arr;
	int idx = 0;
	subsets(nums, n, idx, arr, ans);
	return ans;
}
```
### 7. Combination Sum III

```embed
title: "Combination Sum III - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Combination Sum III - Find all valid combinations of k numbers that sum up to n such that the following conditions are true:   * Only numbers 1 through 9 are used.  * Each number is used at most once.  Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.     Example 1:   Input: k = 3, n = 7 Output: [[1,2,4]] Explanation: 1 + 2 + 4 = 7 There are no other valid combinations.  Example 2:   Input: k = 3, n = 9 Output: [[1,2,6],[1,3,5],[2,3,4]] Explanation: 1 + 2 + 6 = 9 1 + 3 + 5 = 9 2 + 3 + 4 = 9 There are no other valid combinations.   Example 3:   Input: k = 4, n = 1 Output: [] Explanation: There are no valid combinations. Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.      Constraints:   * 2 <= k <= 9  * 1 <= n <= 60"
url: "https://leetcode.com/problems/combination-sum-iii/"
favicon: ""
aspectRatio: "52"
```

```cpp 
void solve(vector<int>& nums, int i, int& k, int& n, int& sum, vector<int>& arr, vector<vector<int>>& ans){

	if(sum > n) return;
	
	if(arr.size() == k){
		if(sum == n){
			ans.push_back(arr);
		}
		return;
	}
	
	if(i == 9) return; //this condition cannot come at the start as it will not allow to print the ans when [0..8] nums is considered
	// giving wrong ans for k = 9 and n = 45
   
	sum = sum + nums[i];
	arr.push_back(nums[i]);

	solve(nums, i+1, k, n, sum, arr, ans);

	sum = sum - nums[i];
	arr.pop_back();

	solve(nums, i+1, k, n, sum, arr, ans);
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> nums = {1,2,3,4,5,6,7,8,9};
	vector<vector<int>>  ans;
	vector<int> arr;
	int sum = 0;
	int i = 0;
	solve(nums,i,k,n,sum,arr,ans);
	return ans;
}
```

### 8. Letter Combinations of a Phone Number

```embed
title: "Letter Combinations of a Phone Number - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Letter Combinations of a Phone Number - Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.  A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.  [https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png]     Example 1:   Input: digits = \"23\" Output: [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"]   Example 2:   Input: digits = \"2\" Output: [\"a\",\"b\",\"c\"]      Constraints:   * 1 <= digits.length <= 4  * digits[i] is a digit in the range ['2', '9']."
url: "https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
void solve(string& digits, int& n, unordered_map<char, vector<char>>& digitAlphaMap, int i, string op, vector<string>& ans){
	if(digits == "") return;

	if(i==n){
		ans.push_back(op);
		return;
	}


	vector<char> characters = digitAlphaMap[digits[i]];
	for(int k = 0;k<characters.size();k++){
		op.push_back(characters[k]);
		solve(digits, n, digitAlphaMap, i+1, op, ans);
		op.pop_back();
	}

}
vector<string> letterCombinations(string digits) {

	unordered_map<char, vector<char>> digitAlphaMap;
	vector<string> ans;
	int n = digits.size();

	digitAlphaMap.insert({'2',{'a','b','c'}});
	digitAlphaMap.insert({'3',{'d','e','f'}});
	digitAlphaMap.insert({'4',{'g','h','i'}});
	digitAlphaMap.insert({'5',{'j','k','l'}});
	digitAlphaMap.insert({'6',{'m','n','o'}});
	digitAlphaMap.insert({'7',{'p','q','r','s'}});
	digitAlphaMap.insert({'8',{'t','u','v'}});
	digitAlphaMap.insert({'9',{'w','x','y','z'}});

	int i = 0;
	string op = "";
	solve(digits, n, digitAlphaMap, i, op, ans);
	return ans;

}
```


### 9. Palindrome Partitioning

```embed
title: "L17. Palindrome Partitioning | Leetcode | Recursion | C++ | Java"
image: "https://i.ytimg.com/vi/WBgsABoClE0/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=WBgsABoClE0"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Palindrome Partitioning - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Palindrome Partitioning - Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.     Example 1:  Input: s = \"aab\" Output: [[\"a\",\"a\",\"b\"],[\"aa\",\"b\"]]   Example 2:  Input: s = \"a\" Output: [[\"a\"]]      Constraints:   * 1 <= s.length <= 16  * s contains only lowercase English letters."
url: "https://leetcode.com/problems/palindrome-partitioning/"
favicon: ""
aspectRatio: "52"
```

```cpp 
bool isPalindrome(string& str, int s, int e){
	while(s<=e){
		if(str[s] != str[e]){
			return false;
		}
		s++,e--;
	}
	return true;
}
void solve(string& s, int& n, int ind, vector<string> op, vector<vector<string>>& ans){
	if(ind == n){
		ans.push_back(op);
		return;
	}

	for(int i = ind; i<n;i++){
		if(isPalindrome(s,ind,i)){
			op.push_back(s.substr(ind,i-ind+1));
			solve(s,n,i+1,op,ans);
			op.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	int n = s.size();
	int ind = 0;
	vector<string> op;
	vector<vector<string>> ans;

	solve(s,n,ind,op,ans);
	return ans;
}
```

### 10. N-Queen

```embed
title: "L14. N-Queens | Leetcode Hard | Backtracking"
image: "https://i.ytimg.com/vi/i05Ju7AftcM/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=i05Ju7AftcM"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "N-Queens - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? N-Queens - The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.     Example 1:  [https://assets.leetcode.com/uploads/2020/11/13/queens.jpg]   Input: n = 4 Output: [[\".Q..\",\"...Q\",\"Q...\",\"..Q.\"],[\"..Q.\",\"Q...\",\"...Q\",\".Q..\"]] Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above   Example 2:   Input: n = 1 Output: [[\"Q\"]]      Constraints:   * 1 <= n <= 9"
url: "https://leetcode.com/problems/n-queens/"
favicon: ""
aspectRatio: "52"
```

```cpp 
bool isSafeLeft(vector<string>& board, int row, int col){
	while(col>=0){
		if(board[row][col] == 'Q') return false;
		col--;
	}
	return true;
}

bool isSafeUpperDiagonal(vector<string>& board, int row, int col){
	while(col>=0 && row>=0){
		if(board[row][col] == 'Q') return false;
		row--, col--;
	}
	return true;
}

bool isSafeLowerDiagonal(vector<string>& board, int row, int col){
	int n = board.size();
	while(row<n && col >= 0){
		if(board[row][col] == 'Q') return false;
		row++, col--;
	}
	return true;
}

bool isSafe(vector<string>& board, int row, int col){
	return isSafeLeft(board, row, col) && isSafeUpperDiagonal(board, row, col) && isSafeLowerDiagonal(board, row, col);
}

void solve(vector<string> board, int colIdx, int& n, vector<vector<string>>& ans){

	if(colIdx == n){
	   ans.push_back(board);
	   return;
	}

	for(int rowIdx = 0;rowIdx<n;rowIdx++){
		if(isSafe(board, rowIdx, colIdx)){
			board[rowIdx][colIdx] = 'Q';
			solve(board,colIdx+1,n,ans);
			board[rowIdx][colIdx] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board;
	string row(n,'.');
	for(int i = 0;i<n;i++) board.push_back(row);

	int colIdx = 0;
	solve(board, colIdx, n, ans);
	return ans;
}
```

- There is also a hashing solution for the board, but that is quite complex and not required for the interview. 
### 11. Rat in a Maze

```embed
title: "L19. Rat in A Maze | Backtracking"
image: "https://i.ytimg.com/vi/bLGZhJlt4y0/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=bLGZhJlt4y0"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Rat in a Maze | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions:&nbsp;'U'(up),&nbsp;'D'(down),&nbsp;'L' (left),&nbsp;'R' (rig"
url: "https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
void solve(vector<vector<int>>& maze, int& n, vector<vector<int>>& visited, int i, int j, string move, vector<string>& ans){
	if(i == n-1 && j == n-1){
		ans.push_back(move);
		return;
	}
	
	// down
	if(i+1<n && !visited[i+1][j] && maze[i+1][j]==1){
		visited[i][j] = 1;
		solve(maze, n, visited, i+1, j, move+"D", ans);
		visited[i][j] = 0;
	}
	
	// left
	if(j-1>=0 && !visited[i][j-1] && maze[i][j-1]==1){
		visited[i][j] = 1;
		solve(maze, n, visited, i, j-1, move+"L", ans);
		visited[i][j] = 0;
	}
	
	// right
	if(j+1<n && !visited[i][j+1] && maze[i][j+1]==1){
		visited[i][j] = 1;
		solve(maze, n, visited, i, j+1, move+"R", ans);
		visited[i][j] = 0;
	}
	
	// up
	if(i-1>=0 && !visited[i-1][j] && maze[i-1][j]==1){
		visited[i][j] = 1;
		solve(maze, n, visited, i-1, j, move+"U", ans);
		visited[i][j] = 0;
	}
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
	
	vector<string> ans;
	int n = maze.size();
	vector<vector<int>> visited(n,vector<int> (n,0));
	
	int i = 0, j = 0;
	string move = "";
	
	if(maze[0][0] == 1) solve(maze,n, visited, i, j, move, ans);
	return ans;
}
```

### 12. Word Break

```embed
title: "Word Break - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Word Break - Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.  Note that the same word in the dictionary may be reused multiple times in the segmentation.     Example 1:   Input: s = \"leetcode\", wordDict = [\"leet\",\"code\"] Output: true Explanation: Return true because \"leetcode\" can be segmented as \"leet code\".   Example 2:   Input: s = \"applepenapple\", wordDict = [\"apple\",\"pen\"] Output: true Explanation: Return true because \"applepenapple\" can be segmented as \"apple pen apple\". Note that you are allowed to reuse a dictionary word.   Example 3:   Input: s = \"catsandog\", wordDict = [\"cats\",\"dog\",\"sand\",\"and\",\"cat\"] Output: false      Constraints:   * 1 <= s.length <= 300  * 1 <= wordDict.length <= 1000  * 1 <= wordDict[i].length <= 20  * s and wordDict[i] consist of only lowercase English letters.  * All the strings of wordDict are unique."
url: "https://leetcode.com/problems/word-break/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
// this code will give TLE, this can be optimized using dp.
void solve(string& s, int& n, int ind, vector<string>& wordDict, bool& ans){
	if(ind == n){
		ans =  true;
		return;
	}

	for(int i = ind; i<n;i++){
		string word = s.substr(ind, i-ind+1);
		if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
			solve(s,n,i+1,wordDict,ans);
		}
	}
}
bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	int ind = 0;
	bool ans;
	solve(s, n, ind, wordDict, ans);
	return ans;
}
```

### 13. 
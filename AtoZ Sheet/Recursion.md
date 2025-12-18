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

```cpp 
void solve(vector<int>& arr,int idx, int k, long long sum, long long& ways){
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

- In the above code I have passed ways as a parameter to the recursive function but we can also write proper recursion for this.

```cpp 
int solve(vector<int>& arr,int& n,int idx, int k, long long sum){

	if(sum == k) return 0;
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


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

### Count subsequences/subsets with sum k

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

- In Aditya verma notes, in the subset he remove the element from the input which is costly especially for an array, but here we use size and index to handle that, so for aditya verma code, write the codes once again with size and idx.



```embed
title: "Sliding Window Algorithm | Face to Face Interviews"
image: "https://i.ytimg.com/vi/EHCGAZBbB88/hqdefault.jpg?sqp=-oaymwEXCOADEI4CSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLAAfI0MNTlCNOUVpvi7ZEdVdo5Dmw&days_since_epoch=20433"
description: "Sliding window technique is useful for solving problems in array or string, especially it is considered as a technique that could reduce the time complexity ..."
url: "https://www.youtube.com/playlist?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj"
favicon: ""
aspectRatio: "56.25"
```

### 1. Maximum Sum Subarray of size K

```embed
title: "Maximum Sum Subarray of size K | Sliding Window"
image: "https://i.ytimg.com/vi/KtpqeN0Goro/maxresdefault.jpg"
description: "Patreon Link: https://www.patreon.com/adityaVermaVideo Pdf Notes And Code: https://www.patreon.com/posts/41937811Playlist Link: https://www.youtube.com/playl..."
url: "https://www.youtube.com/watch?v=KtpqeN0Goro"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Max Sum Subarray of size K | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array of integers arr[]&nbsp; and a number k. Return&nbsp;the maximum sum of a subarray of size k. Note: A subarray is a contiguous part of any given array. Examples: Input: arr[] = [100, 200, 300, 400], k = 2 Output: 700 Explanation: arr2 +"
url: "https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
int maxSubarraySum(vector<int>& arr, int k) {
	int n = arr.size();
	
	int i = 0, j= 0;
	int maxSum = 0, sum =0;
	
	while(j<n){
		sum = sum + arr[j];
		if(j-i+1 < k) j++;
		else if(j-i+1 == k){
			maxSum = max(maxSum, sum);
			sum = sum - arr[i];
			i++,j++;
		}
	}
	
	return maxSum;
}
```

### 2. 
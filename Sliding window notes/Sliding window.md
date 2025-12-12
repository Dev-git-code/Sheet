
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

### 2. First Negative Number in every Window of Size K

```embed
title: "First Negative Number in every Window of Size K | Sliding Window"
image: "https://i.ytimg.com/vi/uUXXEgK2Jh8/maxresdefault.jpg"
description: "Patreon Link: https://www.patreon.com/adityaVermaVideo Pdf Notes And Code: https://www.patreon.com/posts/43359058Playlist Link: https://www.youtube.com/playl..."
url: "https://www.youtube.com/watch?v=uUXXEgK2Jh8"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "First negative in every window of size k | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr[] &nbsp;and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k. Note:&nbsp;If a window does not contain a negative integer, then return 0 for that window. Examples: Input:"
url: "https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
vector<int> firstNegInt(vector<int>& arr, int k) {
	
	int n = arr.size();
	
	queue<int> q;
	vector<int> res;
	int i = 0, j=0;
	
	while(j<n){
	
		if(arr[j]<0){
			q.push(arr[j]);
		}
		
		if(j-i+1 < k){
			j++;
		} 
		else if (j-i+1 == k){
			if(q.size() == 0){
				res.push_back(0);
			}else{
				res.push_back(q.front());
				if(arr[i] == q.front()){
					q.pop();
				}
			}
			
			i++,j++;
			
		}
	}
	return res;
}
```
### 3. Count Occurrences Of Anagrams

```embed
title: "Count Occurrences Of Anagrams | Sliding Window"
image: "https://i.ytimg.com/vi/MW4lJ8Y0xXk/maxresdefault.jpg"
description: "Patreon Link: https://www.patreon.com/adityaVermaVideo Pdf Notes And Code: https://www.patreon.com/posts/43529429Playlist Link: https://www.youtube.com/playl..."
url: "https://www.youtube.com/watch?v=MW4lJ8Y0xXk"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Count Occurences of Anagrams | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a word pat&nbsp;and a text txt. Return the count of the occurrences of anagrams of the word in the text. Example 1: Input: txt = \"forxxorfxdofr\", pat = \"for\" Output: 3 Explanation: for, orf and ofr appears in the txt, hence answer is 3.  Exampl"
url: "https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
int search(string &pat, string &txt) {
	int n = txt.size();
	int k = pat.size();
	unordered_map<char, int> freqMap;
	
	for(int i = 0;i<k;i++){
		freqMap[pat[i]]++;
	}
	
	int distinctCnt = freqMap.size();
	int cnt = 0;
	
	int i =0, j=0;
	
	while(j<n){
		
		if(freqMap.find(txt[j])!=freqMap.end()){
			freqMap[txt[j]]--;
			if(freqMap[txt[j]] == 0){
				distinctCnt --;
			}
		}
		
		if(j-i+1 < k){
			j++;
		}else if(j-i+1 == k){
		
			if(distinctCnt == 0){
				cnt++;
			}
			
			if(freqMap.find(txt[i]) != freqMap.end()){
				freqMap[txt[i]]++;
				if(freqMap[txt[i]] == 1){
					distinctCnt ++;
				}
			}
			
			i++, j++;
		}
	}
	
	return cnt;
}
```
### 4. Maximum of all subarrays of size k

```embed
title: "Maximum of all subarrays of size k | Sliding Window"
image: "https://i.ytimg.com/vi/xFJXtB5vSmM/maxresdefault.jpg"
description: "Patreon Link: https://www.patreon.com/adityaVermaVideo Pdf Notes And Code: https://www.patreon.com/posts/43956990Playlist Link: https://www.youtube.com/playl..."
url: "https://www.youtube.com/watch?v=xFJXtB5vSmM"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "K Sized Subarray Maximum | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array&nbsp;arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray. Examples: Input: arr[] = [1, 2, 3"
url: "https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
	int n = arr.size();
	vector<int> maxSubarray;
	deque<int> maxQueue;
	
	int i = 0, j=0;
	
	while(j<n){
		
		while(maxQueue.size() > 0 && maxQueue.back() < arr[j]){
			maxQueue.pop_back();
		}
		maxQueue.push_back(arr[j]);
		
		if(j-i+1 < k){
			j++;
		}else if(j-i+1 ==k){
			maxSubarray.push_back(maxQueue.front());
			if(arr[i] == maxQueue.front()){
				maxQueue.pop_front();
			}
			i++, j++;
		}
	}
	
	return maxSubarray;
}
```

### 5. Longest Substring with K Uniques

```embed
title: "Longest Substring With K Unique Characters | Variable Size Sliding Window"
image: "https://i.ytimg.com/vi/Lav6St0W_pQ/maxresdefault.jpg"
description: "Become a Competitive Programming Hero with this structured batch to help all levels of programmers sharpen their skills: http://unacademy.cc/AVBAT[FREE] Begi..."
url: "https://www.youtube.com/watch?v=Lav6St0W_pQ"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Longest Substring with K Uniques | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters. Note : If no such substring exists, return -1.&nbsp; Examples: Input:"
url: "https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
int longestKSubstr(string &s, int k) {
   int n = s.size();
   
   int i = 0, j= 0;
   int maxLen = -1;
   unordered_map<char, int> freqMap;
   
   while(j<n){
	   freqMap[s[j]]++;
	   
	   if(freqMap.size() < k){
		   j++;
	   }else if(freqMap.size() == k){
		   maxLen = max(maxLen, j-i+1);
		   j++;
	   }else if(freqMap.size() > k){
		   while(freqMap.size() > k){
			   freqMap[s[i]]--;
			   if(freqMap[s[i]] == 0){
				   freqMap.erase(s[i]);
			   }
			   i++;
		   }
		   j++;
	   }
   }
   
   return maxLen;

}
```

### 6. Longest Substring With Without Repeating Characters

```embed
title: "Longest Substring With Without Repeating Characters | Variable Size Sliding Window"
image: "https://i.ytimg.com/vi/L6cffskouPQ/maxresdefault.jpg"
description: "Learn about the course from our Educator: https://www.youtube.com/watch?v=CAWFakxREV8&amp%3Bt=1008sCheck out Unacademy's batch schedule and details here: htt..."
url: "https://www.youtube.com/watch?v=L6cffskouPQ"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Longest Substring Without Repeating Characters - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Longest Substring Without Repeating Characters - Given a string s, find the length of the longest substring without duplicate characters.     Example 1:   Input: s = \"abcabcbb\" Output: 3 Explanation: The answer is \"abc\", with the length of 3. Note that \"bca\" and \"cab\" are also correct answers.   Example 2:   Input: s = \"bbbbb\" Output: 1 Explanation: The answer is \"b\", with the length of 1.   Example 3:   Input: s = \"pwwkew\" Output: 3 Explanation: The answer is \"wke\", with the length of 3. Notice that the answer must be a substring, \"pwke\" is a subsequence and not a substring.      Constraints:   * 0 <= s.length <= 5 * 104  * s consists of English letters, digits, symbols and spaces."
url: "https://leetcode.com/problems/longest-substring-without-repeating-characters/"
favicon: ""
aspectRatio: "52"
```

```cpp 
int lengthOfLongestSubstring(string s) {
	int n = s.size();

	int i = 0, j = 0;
	unordered_map<char, int> freqMap;
	int maxLen = 0;

	while(j<n){
		freqMap[s[j]]++;

		if(freqMap.size() == j-i+1){
			maxLen = max(maxLen, j-i+1);
			j++;
		}else if(freqMap.size() < j-i+1){ // has repeating chars
			while(freqMap.size() < j-i+1){
				freqMap[s[i]]--;
				if(freqMap[s[i]] == 0){
					freqMap.erase(s[i]);
				}
				i++;
			}
			j++;
		}
	}

	return maxLen;
}
```

### 7. Minimum Window Substring

```embed
title: "Minimum Window Substring | Variable Size Sliding Window"
image: "https://i.ytimg.com/vi/iwv1llyN6mo/maxresdefault.jpg"
description: "Check out the batches here: https://unacademy.com/goal/competitive-programming/LEARNCP/batchesCheck out all the free classes in the current week here: http:/..."
url: "https://www.youtube.com/watch?v=iwv1llyN6mo"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "L12. Minimum Window Substring | 2 Pointers and Sliding Window Playlist"
image: "https://i.ytimg.com/vi/WJaij9ffOIY/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=WJaij9ffOIY"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Minimum Window Substring - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Minimum Window Substring - Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string \"\".  The testcases will be generated such that the answer is unique.     Example 1:   Input: s = \"ADOBECODEBANC\", t = \"ABC\" Output: \"BANC\" Explanation: The minimum window substring \"BANC\" includes 'A', 'B', and 'C' from string t.   Example 2:   Input: s = \"a\", t = \"a\" Output: \"a\" Explanation: The entire string s is the minimum window.   Example 3:   Input: s = \"a\", t = \"aa\" Output: \"\" Explanation: Both 'a's from t must be included in the window. Since the largest window of s only has one 'a', return empty string.      Constraints:   * m == s.length  * n == t.length  * 1 <= m, n <= 105  * s and t consist of uppercase and lowercase English letters.     Follow up: Could you find an algorithm that runs in O(m + n) time?"
url: "https://leetcode.com/problems/minimum-window-substring/"
favicon: ""
aspectRatio: "52"
```

```cpp 
string minWindow(string s, string t) {
	int n = s.size();

	unordered_map<char, int> freqMap;
	for(int i = 0;i<t.size();i++){
		 freqMap[t[i]]++;
	}
	int count = freqMap.size();
	
	int minLen = INT_MAX;
	int bestStart = -1;

	int i = 0, j = 0;

	while(j<n){

		if(freqMap.find(s[j]) != freqMap.end()){
			freqMap[s[j]]--;
			if(freqMap[s[j]] == 0){
				count--;
			}
		}

		if(count > 0){
			j++;
		}else if(count == 0){
			while(count == 0 && i<=j){

				if(minLen > j-i+1){
					minLen = j-i+1;
					bestStart = i;
				}

				if(freqMap.find(s[i]) != freqMap.end()){
					freqMap[s[i]]++;
					if(freqMap[s[i]] == 1) count++;
				}
				i++;

			}
			j++;
		}
	}
	if(minLen == INT_MAX) return "";
	return s.substr(bestStart, minLen);
}
```

### 8. Number of Substrings Containing All Three Characters

```embed
title: "Fetching"
image: "data:image/svg+xml;base64,PHN2ZyBjbGFzcz0ibGRzLW1pY3Jvc29mdCIgd2lkdGg9IjgwcHgiICBoZWlnaHQ9IjgwcHgiICB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMDAgMTAwIiBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJ4TWlkWU1pZCI+PGcgdHJhbnNmb3JtPSJyb3RhdGUoMCkiPjxjaXJjbGUgY3g9IjgxLjczNDEzMzYxMTY0OTQxIiBjeT0iNzQuMzUwNDU3MTYwMzQ4ODIiIGZpbGw9IiNlMTViNjQiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM0MC4wMDEgNDkuOTk5OSA1MCkiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49IjBzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9Ijc0LjM1MDQ1NzE2MDM0ODgyIiBjeT0iODEuNzM0MTMzNjExNjQ5NDEiIGZpbGw9IiNmNDdlNjAiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM0OC4zNTIgNTAuMDAwMSA1MC4wMDAxKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMDYyNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iNjUuMzA3MzM3Mjk0NjAzNiIgY3k9Ijg2Ljk1NTE4MTMwMDQ1MTQ3IiBmaWxsPSIjZjhiMjZhIiByPSI1IiB0cmFuc2Zvcm09InJvdGF0ZSgzNTQuMjM2IDUwIDUwKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMTI1cyI+PC9hbmltYXRlVHJhbnNmb3JtPgo8L2NpcmNsZT48Y2lyY2xlIGN4PSI1NS4yMjEwNDc2ODg4MDIwNyIgY3k9Ijg5LjY1Nzc5NDQ1NDk1MjQxIiBmaWxsPSIjYWJiZDgxIiByPSI1IiB0cmFuc2Zvcm09InJvdGF0ZSgzNTcuOTU4IDUwLjAwMDIgNTAuMDAwMikiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49Ii0wLjE4NzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9IjQ0Ljc3ODk1MjMxMTE5NzkzIiBjeT0iODkuNjU3Nzk0NDU0OTUyNDEiIGZpbGw9IiM4NDliODciIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM1OS43NiA1MC4wMDY0IDUwLjAwNjQpIj4KICA8YW5pbWF0ZVRyYW5zZm9ybSBhdHRyaWJ1dGVOYW1lPSJ0cmFuc2Zvcm0iIHR5cGU9InJvdGF0ZSIgY2FsY01vZGU9InNwbGluZSIgdmFsdWVzPSIwIDUwIDUwOzM2MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiIGJlZ2luPSItMC4yNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iMzQuNjkyNjYyNzA1Mzk2NDE1IiBjeT0iODYuOTU1MTgxMzAwNDUxNDciIGZpbGw9IiNlMTViNjQiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDAuMTgzNTUyIDUwIDUwKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMzEyNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iMjUuNjQ5NTQyODM5NjUxMTc2IiBjeT0iODEuNzM0MTMzNjExNjQ5NDEiIGZpbGw9IiNmNDdlNjAiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDEuODY0NTcgNTAgNTApIj4KICA8YW5pbWF0ZVRyYW5zZm9ybSBhdHRyaWJ1dGVOYW1lPSJ0cmFuc2Zvcm0iIHR5cGU9InJvdGF0ZSIgY2FsY01vZGU9InNwbGluZSIgdmFsdWVzPSIwIDUwIDUwOzM2MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiIGJlZ2luPSItMC4zNzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9IjE4LjI2NTg2NjM4ODM1MDYiIGN5PSI3NC4zNTA0NTcxNjAzNDg4NCIgZmlsbD0iI2Y4YjI2YSIgcj0iNSIgdHJhbnNmb3JtPSJyb3RhdGUoNS40NTEyNiA1MCA1MCkiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49Ii0wLjQzNzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT48L2c+PC9zdmc+"
description: "Fetching https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/"
url: "https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/"
favicon: ""
```

```cpp
int numberOfSubstrings(string s) {
    int n = s.size();

    int i = 0, j = 0;   // sliding window pointers

    string req = "abc";           // we need at least one 'a', one 'b', and one 'c'
    unordered_map<char, int> required;

    // Build frequency map for required characters
    // required['a'] = 1, required['b'] = 1, required['c'] = 1
    for (int k = 0; k < (int)req.size(); k++) {
        required[req[k]]++;
    }

    int count = 3;  // number of distinct characters STILL NEEDED in the window
                    // Once count reaches 0 → window [i..j] contains all 'a','b','c'

    int numOfSubstr = 0; // answer

    while (j < n) {

        // Include s[j] into the window
        required[s[j]]--;               // decrement its needed frequency

        // If frequency became 0, it means THIS particular char is now fully satisfied
        if (required[s[j]] == 0) {
            count--;                    // one required char type satisfied
        }

        // If we still do NOT have all 3 characters in the window, expand j more
        if (count > 0) {
            j++;
        }
        else {  
            // count == 0 → window [i..j] contains at least one 'a', one 'b', one 'c'

            // Now, every substring that starts at i and ends anywhere from j to n-1
            // will also contain all 3 characters.
            // So total added substrings for this 'i' is (n - j)
            while (count == 0 && i <= j) {

                numOfSubstr += (n - j);    // <-- KEY LOGIC

                // Now try to shrink window from the left by removing s[i]
                required[s[i]]++;

                // If a required character becomes strictly positive again,
                // it means we are now MISSING that character in the window
                // → so window is no longer valid
                if (required[s[i]] == 1) {
                    count++;          // we lost a needed character
                }

                i++;   // shrink left side
            }

            j++;   // after shrinking, expand right side again
        }
    }

    return numOfSubstr;
}
```

### 9. 
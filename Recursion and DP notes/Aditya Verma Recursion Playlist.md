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

```embed
title: "Recursion Playlist | Coding | Interview Questions | Algorithm | Tutorials - YouTube"
image: "https://i.ytimg.com/vi/kHi1DUhp9kM/default.jpg?days_since_epoch=19765"
description: "This playlist explains Recursion in a concise way. Explaining how to approach a Recursive problem and moreover how to identify it first."
url: "https://youtube.com/playlist?list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&si=mOmyqGMl8c9WVGqi"
```

# 💡 General Template for Writing Recursion Using Induction

```cpp
	ReturnType functionName(Parameters) {
	    // Base case
	    if (base_condition)
	        return base_value;
	
	    // Hypothesis
	    ReturnType smallerResult = functionName(smaller_input);
	
	    // Induction step
	    ReturnType finalResult = build_from(smallerResult);
	
	    return finalResult;
	}

```

In recursion you return to the place where you left off. (stack makes more sense here)

**Basic Impl of Recursion:**
```embed
title: "Recursion in C"
image: "https://i.ytimg.com/vi/kepBmgvWNDw/maxresdefault.jpg"
description: "C Programming & Data Structures: Recursion in C Topics discussed:1) Definition of Recursion.2) A program to demonstrate the recursion in C.3) Homework proble..."
url: "https://www.youtube.com/watch?v=kepBmgvWNDw"
favicon: ""
aspectRatio: "56.25"
```

# videos(v) and questions 
## v5 - Max Depth of Binary Tree
```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/maximum-depth-of-binary-tree "
```

## v6 - Sort an Array
```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/sort-an-array/"
```

```cpp
void insert(vector<int>& nums, int temp){
	int n = nums.size();
	if(nums.size()==0 || nums[n-1]<=temp){
		nums.push_back(temp);
		return;
	}
	int val = nums[n-1];
	nums.pop_back();
	insert(nums,temp);
	nums.push_back(val);
}
vector<int> sortArray(vector<int>& nums) {
	int n = nums.size();
	if(nums.size()==1){
		return nums;
	}
	int temp = nums[n-1];
	nums.pop_back();
	sortArray(nums);
	insert(nums,temp);
	return nums;
}
```
## v7 - Sort a stack
```embed
title: "Sort a stack | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a stack, the task is to sort&nbsp;it such that the top of the stack has the greatest&nbsp;element. Example 1: Input: Stack: 3 2 1 Output: 3 2 1 Example 2: Input: Stack: 11 2 32 3 41 Output: 41 32 11 3 2 Your Task:&nbsp;You don’t have to read i"
url: " https://practice.geeksforgeeks.org/problems/sort-a-stack/1 "
```

```cpp
void insert(stack<int> &s,int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}
void SortedStack :: sort()
{
   if(s.size() == 1){
       return;
   }
   int temp = s.top();
   s.pop();
   sort();
   insert(s,temp);
   return;
}
```

## v8 - Delete middle of a stack
```embed
title: "Delete middle element of a stack | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a stack, delete the&nbsp;middle element of the stack&nbsp;without using any additional data structure.Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack. Note: The output shown by the compiler is the stack f"
url: "https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1"
```


```cpp
void solve(stack<int>& s, int k){
	if(k==1){
		s.pop();
		return;
	}
	int temp = s.top();
	s.pop();
	solve(s,k-1);
	s.push(temp);
}
void deleteMid(stack<int>&s, int n)
{
	if(n==0) return;
	int k = n/2+1;
	solve(s,k);
}
```
## v9 - Reverse a Stack 
```embed
title: "Reverse a Stack | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given a stack St. You have to reverse the stack using recursion. Example 1: Input: St = {3,2,1,7,6} Output: {6,7,1,2,3}Explanation:Input stack after reversing will look like the stack in the output. Example 2: Input: St = {4,3,9,6} Output: {6"
url: "https://www.geeksforgeeks.org/problems/reverse-a-stack/1"
```

```cpp
void insert(stack<int>& s, int temp){
	if(s.size()==0){
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,temp);
	s.push(val);
}
void reverse(stack<int> &s){
	int n = s.size();
	if(n==1) return;
	int temp = s.top();
	s.pop();
	Reverse(s);
	insert(s,temp);
}
```
## v10 - Kth Symbol in Grammar 

```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/k-th-symbol-in-grammar/"
```

```cpp
int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;
        int mid = pow(2,n-1)/2;
        if(k<=mid){
            // aage wale portion me hh 
            return kthGrammar(n-1,k);
        }else{
            // peeche wale portion me hh
            return !kthGrammar(n-1,k-mid);
        }
    }
```
## v11 - Tower of Hanoi
```embed
title: "Tower Of Hanoi | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all th"
url: "https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1"
```

```cpp
void towerHanoi(int N, int start, int end, int h, long long &count){
	if(N==1){
		cout<<"move disk "<< N <<" from rod "<<start<<" to rod "<<end<<endl;
		count++;
		return;
	}
	towerHanoi(N-1,start,h,end,count);
	cout<<"move disk "<< N <<" from rod "<<start<<" to rod "<<end<<endl;
	count++;
	towerHanoi(N-1,h,end,start,count);
	
}

long long toh(int N, int from, int to, int aux) {
	long long count = 0;
	towerHanoi(N, 1,3,2, count);
	return count;
}
```

## v12 - Print Subsets 
![[654d29ace2f0f94c51a7a6596fae0095_MD5.png]]

- Once you draw the recursion tree for the problem, the leaf nodes will give the base condition.
- Write the logic for forming the child nodes and then call the recursive function on the child nodes. 

### For the subsets problems 
 - Draw the recursive tree 
 - ![[a9b5686ef20afd54d55a538d06d5898c_MD5.png]]

 - here we take the input string and the o/p string and either take the current char from the ip and add it to op or do not take the char. 
 - the leaf nodes, in which the input becomes empty gives the subsets. 
 
```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/subsets"
```
 ```cpp
void solve(vector<int> ip, vector<int> op, vector<vector<int>> &ans){
	if(ip.empty()){
		ans.push_back(op);
		return;
	}
	vector<int> op1 = op;
	vector<int> op2 = op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	solve(ip,op1,ans);
	solve(ip,op2,ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> op;
	vector<vector<int>> ans;
	solve(nums,op,ans);
	return ans;
}
```

## v13 - Print unique subsets And Variations
- Power set is also all subsets of a set so the above code can be used to find Power set also. 
### Substring vs Subsequence vs Subsets 

1. **Substring:**
   - **Definition:** A substring is a contiguous sequence of characters within a string. It is formed by selecting characters from the original string in a consecutive manner.
   - **Example:** In the string "example," "exam" and "ple" are substrings.

2. **Subsequence:**
   - **Definition:** A subsequence is a sequence of characters that appears in the same order as they appear in the original string, but not necessarily consecutively.
   - **Example:** For the string "abc," "ac" is a subsequence, but "abec" is not a subsequence.

3. **Subset:**
   - **Definition:** A subset is a set of elements that are selected from a larger set. In the context of strings, a subset refers to a selection of characters from a string.
   - **Example:** For the string "hello," the set of characters {"h", "l", "o"} is a subset.

**Difference:**
- A **substring** must be a contiguous sequence of characters within the string.
- A **subsequence** does not have to be contiguous; it maintains the order of characters but allows for gaps.
- A **subset** is a selection of elements.

**Examples:**
- Consider the string "abcde":
  - Substring: "bcd"
  - Subsequence: "bd" (characters in order, not necessarily consecutive)
  - Subset: {"b", "d"} (selected characters in the same order)

```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: " https://leetcode.com/problems/subsets-ii"
```

```cpp
void solve(vector<int> ip,vector<int> op, set<vector<int>> &s){
	// base case 
	if(ip.empty()){
		sort(op.begin(),op.end());
		s.insert(op);
		return;
	}
	// ch1 :dont take ip[0] from ip to op
	vector<int> op1 = op;
	op1.push_back(ip[0]);
	ip.erase(ip.begin()+0); // ip[0] erased
	solve(ip,op1,s);
	// ch2 :take ip[0] from ip to op
	solve(ip,op,s);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	set<vector<int>> s;
	vector<int> op; // subset
	vector<vector<int>> ans;
	solve(nums,op,s);
	for(auto &e:s){
		ans.push_back(e);
	}
	return ans;

}
```
- this is not the best solution, learn backtracking and then see the solutions for this problem.
## v14 - Permutation with spaces
```embed
title: "Permutation with Spaces | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings Example 1: Input: S = &quot;ABC&quot; Output: (A B C)"
url: "https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1"
```

- Other than the first element, for all of them I have these two choices 
	- ch 1: include the element with space 
	- ch 2: include the element without space
![[0a0d453c9a24101e0a7ef681f8082e32_MD5.png]]

![[0ec2399b5de38889dde20b8ba9041214_MD5.png]]


```cpp
void solve(string ip,string op,vector<string> &ans){
	// base case 
	if(ip.size()==0){
		ans.push_back(op);
		return;
	}
	// ch1: include element from ip to op with space
	string op1 = op + " " + ip[0];
	// ch2: include element from ip to op without space
	string op2 = op + ip[0];
	// make the ip smaller
	ip.erase(ip.begin()+0); // ip[0] erased
	// call solve for child nodes 
	solve(ip,op1,ans);
	solve(ip,op2,ans);
}

vector<string> permutation(string s){
	vector<string> ans;
	string op;
	op.push_back(s[0]);
	s.erase(s.begin()+0); // s[0] erased
	solve(s,op,ans);
	sort(ans.begin(),ans.end());
	return ans;
}
```


## v15 and v16 - Permutation with Case Change & Letter Case Permutation
```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: " https://leetcode.com/problems/letter-case-permutation/"
```

![[fc437d94ec3e278ed74d3d7d7b221fac_MD5.png]]

- if the current char (ip[0]) is alphabet then we have two choices:
	- ch1: add lowercase to op
	- ch2: add uppercase to op
- if it is not then just one choice
	- ch: add the number to the op
```cpp
void solve(string ip, string op, vector<string>& ans){
	// base case
	if(ip.size()==0){
		ans.push_back(op);
		return;
	}
	// if alpha
	if(isalpha(ip[0])){
		// ch1: add lowercase
		string op1 = op;
		op1.push_back(tolower(ip[0]));
		// ch2: add uppercase
		string op2 = op;
		op2.push_back(toupper(ip[0]));
		// make the ip smaller
		ip.erase(ip.begin()+0); // ip[0] erased
		solve(ip,op1,ans);
		solve(ip,op2,ans);

	}else{
		 // add the number
		 string op1 = op;
		 op1.push_back(ip[0]);
		 ip.erase(ip.begin()+0);
		 solve(ip,op1,ans); 
	}

}
vector<string> letterCasePermutation(string s) {
	vector<string> ans;
	solve(s,"",ans);
	return ans;
}
```

## v17 - Generate all Balanced Parentheses
```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/generate-parentheses"
```

![[48cb4dbb7ad10819e94c3bd8f573959b_MD5.png]]

- here , close = number of close brackets still left ; open = number of open brackets still left 
- From observation of recursive tree we can see: 
	- if open!=0, then we always have choice to add open bracket
	- if close > open, then we  have choice to add close bracket

```cpp
void solve(string op, int open, int close, vector<string>& ans){
	if(open == 0 && close == 0){
		ans.push_back(op);
		return;
	}

	if(open!=0){ // open 1
		string op1 = op;
		op1.push_back('(');
		solve(op1, open-1, close, ans);
	}
	
	if(close > open){ // open 1 close 3
		string op2 = op;
		op2.push_back(')');
		solve(op2, open, close-1, ans);
	}
}
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	int open = n, close = n;
	string op = "";
	solve(op, open, close, ans);
	return ans;
}
```

## v18 - Print N-bit binary numbers having more 1’s than 0’s for any prefix
```embed
title: "Print N-bit binary numbers having more 1s than 0s | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1&rsquo;s than 0&rsquo;s for any prefix of the number. Example 1: Input: N = 2 Output: 11 10 Explanation: 11 and 10 have more than or"
url: "https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1"
```

![[5a19a5fa1970b99ddb380cb3536119dc_MD5.png]]

 - We can see from the recursive tree that: 
	 - choice of 1 is always available 
	 - choice of 0 is available only when no. of ones > no. of zeros
```cpp
void solve(int ones,int zeros, string op, int n, vector<string> &ans){
	// base case
	if(n==0){
		ans.push_back(op);
		return; // never forget
	}
	// choice of 1 always there
	string op1 = op;
	op1.push_back('1');
	solve(ones+1,zeros,op1,n-1,ans);
	// choice of zero only when ones>zeros
	if(ones>zeros){
		string op2 = op;
		op2.push_back('0');
		solve(ones,zeros+1,op2,n-1,ans);
	}
}
vector<string> NBitBinary(int N)
{
	vector<string> ans;
	solve(0,0,"",N,ans);
	return ans;
}
```
## v19 - Josephus Problem | Game of Death in a circle | Execution in Circle
```embed
title: "Josephus problem | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "A total of n people are standing in a circle, and you are one of them playing a game. Starting from a person, k persons will be counted in order along the circle, and the kth person will be killed. Then the next k persons will be counted along the ci"
url: "https://practice.geeksforgeeks.org/problems/josephus-problem/1"
```

```cpp
 void solve(vector<int> v, int k,int index,int &ans){
        // base case 
        if(v.size()==1){
            ans = v[0];
            return;
        }
        // Induction : which person to kill
        index = (index+k)%v.size();
        // smaller input
        v.erase(v.begin()+index);
        // recursive call
        solve(v,k,index,ans);
    }
    int josephus(int n, int k)
    {
       vector<int> v;
       int ans;
       // vector with all the people
       for(int i =1;i<=n;i++) v.push_back(i);
       solve(v,k-1,0,ans);
       return ans;
       
    }
```

### Find the Winner of the Circular Game --> same as josephs problem

```embed
title: "LeetCode - The World’s Leading Online Programming Learning Platform"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/find-the-winner-of-the-circular-game/"
```

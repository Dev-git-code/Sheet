# Longest Common Subsequence

```table-of-contents
title: 
style: nestedList # TOC style (nestedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
includeLinks: true # Make headings clickable
debugInConsole: false # Print debug info in Obsidian console
```


```embed
title: "YouTube"
image: "https://img.youtube.com/vi/4dMlCZTONj8/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=4dMlCZTONj8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=18"
```

## LCS - recursive 

- While thinking of the recursive code, we should keep in mind 3 things:
		1. Base Condition 
		2. Choice diagram 
		3. How to make the input smaller

- Making the input smaller: we will take a decision for the last element of the string and then make the next call for n-1 elements.
![[b60f1c93c16c8b63b7e1c24d22279932_MD5.png]]

- Base Condition: Think of the smallest valid input
```cpp
// base conditon : either of the strings are empty
if(n==0 || m==0) return 0;
```

- Choice diagram: 
```embed
title: "19 Longest common subsequence Recursive"
image: "https://img.youtube.com/vi/4Urd0a0BNng/maxresdefault.jpg"
description: "Longest Common Subsequence Problem solution using recursionGiven two sequences, find the length of longest subsequence present in both of them.A subsequence…"
url: "https://youtu.be/4Urd0a0BNng?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&t=1082"
```

![[59fb7972c2cb8e43b800e6235eb36b49_MD5.png|1060x534]]

- if the last two elements of the string x and y matches then we pass n-1 elements of x and m-1 elements of y in the next call. 
- if the two values do not match then we pass n elements of x and m-1 elements of y and vice versa. since longest is asked we take the max of the two calls.

```cpp
// code from video 
int LCS(string x, string y, int n , int m){
	// base condition 
	if(n==0 || m==0) return 0;
	// choice diagram
	if(x[n-1]==y[m-1]){
		return 1+LCS(x,y,n-1,m-1); // we get one element in the subsequence
	}else{
		return max(LCS(x,y,n,m-1),
				   LCS(x,y,n-1,m));
	}
}
```

## LCS - memoized 

```embed
title: "20 Longest common subsequence Memoization"
image: "https://img.youtube.com/vi/g_hIx4yn9zg/maxresdefault.jpg"
description: "Longest Common Subsequence Problem solution using MemoizationGiven two sequences, find the length of longest subsequence present in both of them.A subsequenc…"
url: "https://www.youtube.com/watch?v=g_hIx4yn9zg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=20"
```

- the memoized table is made using only the variables which are repeated in the recursive call. 
- In this problem, `m and n` changes therefore the tables will be `t[n+1][m+1]`
- Initialize the matrix with `-1` and if the value is not `-1` that means the values has been updated.

```cpp
// code from video
int t[1001][1001];

int lcs(string x,string y,int m, int n){
    if(m==0 || n==0) return 0;
    if(t[m][n]!=-1) return t[m][n];
    if(x[m-1]==y[n-1]){
        return t[m][n] = 1+lcs(x,y,m-1,n-1);
    }else{
        return t[m][n] = max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
    }
}

int lcs_driver(String x, string y, int m, int n){
	memset(t,-1,sizeof(t));
	return lcs(x,y,m,n);
}

```

## LCS - Tabulation

```embed
title: "21 Longest common subsequence Top down DP"
image: "https://img.youtube.com/vi/hR3s9rGlMTU/maxresdefault.jpg"
description: "Longest Common Subsequence Problem solution using TOP DOWN APPROACHGiven two sequences, find the length of longest subsequence present in both of them.A subs…"
url: "https://www.youtube.com/watch?v=hR3s9rGlMTU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=21"
```

- the base condition changes to initialization, so we fill all the values of 0th row and 0th column with 0.
```cpp
// matrix initialization 
int t[m+1][n+1];
for(int i = 0;i<m+1;i++){
	for(int j = 0;j<n+1;j++){
		if(i==0 || j==0) t[i][j] = 0;
	}
}
```

- choice diagram to iterative code equations : 
```cpp
// recursive choice diagram code
if(x[m-1]==y[n-1]){
	return t[m][n] = 1+lcs(x,y,m-1,n-1);
}else{
	return t[m][n] = max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
}

// from the above code the equations are 
if(x[m-1]==y[n-1])
	t[m][n] = 1 + t[m-1][n-1];
else 
	t[m][n] = max(t[m][n-1],t[m-1][n]);

```

```cpp
// iterative code
// i --> m and j --> n

for(int i = 1;i<m+1;i++){
	for(int j = 1;j<n+1;j++){
		if(x[i-1]==y[j-1])
			t[i][j] = 1 + t[i-1][j-1];
		else 
			t[i][j] = max(t[i][j-1],t[i-1][j]);
	}
}
```

## LCS ques
#companies `Paytm, Microsoft, Amazon, VMWare`

```embed
title: "Longest Common Subsequence | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets. Example 1: Input: A = 6, B = 6 str1 = ABCDGH str2 = AEDFHR Output: 3 Explanation: LCS for input strings &ldquo;ABCDG"
url: "https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1"
```

```cpp
 //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        if(n==0 || m==0) return 0;
        if(s1[n-1]==s2[m-1]) return 1+lcs(n-1,m-1,s1,s2);
        else return max(lcs(n,m-1,s1,s2),lcs(n-1,m,s1,s2));
    }
// recursive code gives TLE
```

```cpp
// memoization code

    int t[1001][1001];
    // lcs memoization function 
    int lcs_memo(int n, int m, string x, string y){
        if(n==0 || m==0) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(x[n-1]==y[m-1]){
            return t[n][m] = 1+lcs_memo(n-1,m-1,x,y);
        }else{
            return t[n][m] = max(lcs_memo(n,m-1,x,y),
                                 lcs_memo(n-1,m,x,y));
        }
    }
	// driver function 
    int lcs(int n, int m, string x, string y)
    {
        memset(t,-1,sizeof(t));
        return lcs_memo(n,m,x,y);
    }
// this code give TLE at 462
```

```cpp
// tabulation code 

   int lcs(int m, int n, string x, string y)
    {
        int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        return t[m][n];

    }
// does not give TLE - all passed
```
## LCS based Problems 
 ![[0bca639e7f7a5aa84f1e688c30da2284_MD5.png|991x764]] 
### Print LCS b/w two strings

```embed
title: "watch?v=x5hQvnUcjiM"
image: "https://img.youtube.com/vi/x5hQvnUcjiM/maxresdefault.jpg"
description: "Printing Longest Common Subsequence Given two sequences, print the longest subsequence present in both of them. Example: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/printin... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=x5hQvnUcjiM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=23"
```

![[b322d959ebd4cc7ea904e15094dd1915_MD5.png|1041x586]]

- If you have to print something related to dp then once fill the table and then think of going backwards from last cell. 
- we start from the last cell of the table and check if the current character matches in both the strings: 
```cpp
// pseudo- code
if equal i,j --> store the lcs and i--,j--;
if not equal i,j --> max((i-1,j),
						(i,j-1));
```
- we do this till we reach `i=0(string x empty) or j=0(string y empty)` 

```cpp
// print the lcs string 
int i = m;
int j = n;
string s = "";
while(i>0 && j>0){
	if(a[i-1]==b[j-1]){
		s+=a[i-1]; // we start from last so string is in reverse 
		i--;
		j--;
	}else{
		//max((i-1,j),(i,j-1));
		if(t[i][j-1]<t[i-1][j]) i--;
		else j--;
	}
}
// reverse the string s to get the answer 
reverse(s.begin(),s.end());
```
- This will print only one longest common subsequence. 

```embed
title: "Techie Delight"
image: "https://www.techiedelight.com/wp-content/uploads/profile_pic.png"
description: "Techie Delight provides huge collection of data structure articles on various topics which are useful for technical interview preparation to crack interviews of top IT companies."
url: "https://www.techiedelight.com/?problem=LongestCommonSubsequenceII"
```

```cpp
/*

Given two sequences, return the longest common subsequence (LCS) present in it. The LCS is the longest sequence which can be obtained from the first sequence by deleting some items and from the second sequence by deleting other items.

Input: X = "XMJYAUZ", Y = "MZJAWXU"
Output: "MJAU"

The longest common subsequence is not guaranteed to be unique. If multiple longest common subsequence exists, the solution should return any one of them.

Input: X = "ABCBDAB", Y = "BDCABA"
Output: "BDAB" or "BCAB" or "BCBA"

*/

class Solution
{
public:
	string findLCS(string x, string y)
	{
		int m = x.size(),n=y.size();
		int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        // print the lcs string 
		int i = m;
		int j = n;
		string s = "";
		while(i>0 && j>0){
			if(x[i-1]==y[j-1]){
				s.push_back(x[i-1]); // we start from last so string is in reverse 
				i--;
				j--;
			}else{
				//max((i-1,j),(i,j-1));
				if(t[i][j-1]>t[i-1][j]) j--;
				else i--;
			}
		}
		// reverse the string s to get the answer 
		reverse(s.begin(),s.end());
		
		return s;
	}
};

```

### Longest common Substring 

```embed
title: "22 Longest Common Substring"
image: "https://img.youtube.com/vi/HrybPYpOvz0/maxresdefault.jpg"
description: "Longest Common Substring(Dynamic Programming)Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.Examples:Input : X = “GeeksforGee…"
url: "https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22"
```

- matrix initialization is same as the LCS one.
- Code Variation:
	- If the sequence becomes discontinuous then we re-initialize length to 0, because here want want the sequence to be continuous.
 ![[75dd2d4f671e69f36c22b3b1c149e968_MD5.png]]
```cpp
// lcs code 
if(x[i-1]==y[j-1])
	t[i][j] = 1 + t[i-1][j-1];
else 
	t[i][j] = max(t[i][j-1],t[i-1][j]);
```

- In LCS, we take the `max` if the characters do not match but here we will write the value as zero because we want the sequence to be continuous. 

```cpp
// longest common substring code
if(x[i-1]==y[j-1])
	t[i][j] = 1+ t[i-1][j-1];
else 
	t[i][j] = 0;
```

- at last we have to return the max value in the matrix and not `t[m][n]`. Just traverse through the matrix once and store max value in a variable and return that. Why it is so? because substring can exist anywhere in between.

```embed
title: "Longest Common Substring | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two strings. The task is to find the length of the longest common substring. Example 1: Input: S1 = &quot;ABCDGH&quot;, S2 = &quot;ACDGHR&quot;, n = 6, m = 6 Output: 4 Explanation: The longest common substring is &quot;CDGH&quot; w"
url: "https://www.geeksforgeeks.org/problems/longest-common-substring1452/1"
```

```cpp
  
int longestCommonSubstr (string x, string y, int m, int n)
{
	int t[m+1][n+1];
	int max_len = -1;
	for(int i = 0;i<m+1;i++){
		for(int j = 0;j<n+1;j++){
			if(i==0 || j==0) t[i][j] = 0;
		}
	}
	
	for(int i = 1;i<m+1;i++){
		for(int j = 1;j<n+1;j++){
			if(x[i-1]==y[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else 
				t[i][j] =0;
		}
	}
	
	// substring can be present anywhere so return max value in the matrix
	for(int i = 0;i<m+1;i++){
		for(int j = 0;j<n+1;j++){
			max_len = max(max_len,t[i][j]);
		}
	}
	return max_len;
}
```
### Shortest Common Super Sequence 

```embed
title: "24 Shortest Common SuperSequence"
image: "https://img.youtube.com/vi/823Grn4_dCQ/maxresdefault.jpg"
description: "Shortest Common SuperSequenceGiven two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.Examples:Input: str1 = ”…"
url: "https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24"
```

- we can see in the below example that to make the super-sequence shorter, we use the elements that appear in both the strings (in same order) only once. 
- ![[9132f6f2c519f7c721930a12c4c2d653_MD5.png]]

- If we observe then we can see that - the elements which we used only once are the LCS of both the strings and appear in both the strings. 
- ![[67c741a5822e37de5921e1be6583e721_MD5.png]]
- therefore If I add both the strings directly and then subtract the LCS from the concatenation the I will get the shortest super-sequence.
	- `a.size()+b.size()-LCS(a,b)` gives the length of shortest super-sequencce.

```embed
title: "Shortest Common Supersequence | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two&nbsp;strings X and Y&nbsp;of lengths&nbsp;m and n&nbsp;respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.Note:&nbsp;X&nbsp;and Y can have both uppercase and lowercase letters. Example 1 Input:"
url: "https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1"
```

```cpp
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m+n-lcs(m,n,X,Y);
    }
    
    int lcs(int m, int n, string x, string y)
    {
        int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        return t[m][n];

    }
```

### Print shortest Common Super-sequence
```embed
title: "YouTube"
image: "https://img.youtube.com/vi/VDhRg-ZJTuc/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=28"
```

- this is similar to printing the LCS, here while taking the max choice, we also add the element in the ans before moving to the max choice between `(i,j-1) and (i-1,j)` where `i--> a string iterator` `j--> b string iterator`
- At the end one of the string will be left, but we need to process that also for which we will use a while loop for both the strings.

```cpp
int i = m;
int j = n;
string s ="";
while(i>0 && j>0){
	if(a[i-1]==b[j-1]){
		s.push_back(a[i-1]);
		i--;
		j--;
	}else{
		if(t[i][j-1]>t[i-1][j]){
			// move towards j-1
			s.push_back(b[j-1]);
			j--;
		}else{
			// move towars i-1
			s.push_back(a[i-1]);
			i--;
		}
	}
}

// add the remaining elements 
while(i>0){
	s.push_back(a[i-1]);
	i--;
}
while(j>0){
	s.push_back(b[j-1]);
	j--;
}

reverse(s.begin(),s.end());
```

```embed
title: "Techie Delight"
image: "https://www.techiedelight.com/wp-content/uploads/profile_pic.png"
description: "Techie Delight provides huge collection of data structure articles on various topics which are useful for technical interview preparation to crack interviews of top IT companies."
url: "https://www.techiedelight.com/?problem=ShortestCommonSupersequenceII"
```

```cpp
/*

Given two sequences, find the length of the shortest supersequence 'Z' of given sequences 'X' and 'Y' such that both 'X' and 'Y' are subsequences of 'Z'.

The shortest common supersequence is not guaranteed to be unique. If multiple shortest common supersequence exists, the solution should return any one of them.

Input: X = "ABCBDAB", Y = "BDCABA"
Output: "ABCBDCABA" or "ABDCABDAB" or "ABDCBDABA"

*/

class Solution
{
public:
	string findSCS(string x, string y)
	{
		int m = x.size();
		int n = y.size();
		
		int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        int i = m;
		int j = n;
		string s ="";
		while(i>0 && j>0){
			if(x[i-1]==y[j-1]){
				s.push_back(x[i-1]);
				i--;
				j--;
			}else{
				if(t[i][j-1]>t[i-1][j]){
					// move towards j-1
					s.push_back(y[j-1]);
					j--;
				}else{
					// move towars i-1
					s.push_back(x[i-1]);
					i--;
				}
			}
		}
		
		// add the remaining elements 
		while(i>0){
			s.push_back(x[i-1]);
			i--;
		}
		while(j>0){
			s.push_back(y[j-1]);
			j--;
		}
		
		reverse(s.begin(),s.end());
		return s;
	}
};

```
### Minimum number of insertion and deletion

```embed
title: "watch?v=-fx6aDxcWyg"
image: "https://img.youtube.com/vi/-fx6aDxcWyg/maxresdefault.jpg"
description: "Minimum number of deletions and insertions to transform one string into another Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point. Example: Input : str1 = “geeksforgeeks”, str2 = “geeks” Output : Minimum Deletion = 8 Minimum Insertion = 0 PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/minimum... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25"
```

![[d4065c485b6e66c47204723abcaeab79_MD5.png|1231x692]]
- Instead of directly converting the string, we go through LCS: 
	- remove the elements from string a to get to LCS 
		- `number of deletion = a.length() - LCS`
	- add the elements to LCS to get to string b
		- `number of inserton = b.length() - LCS`

```embed
title: "Minimum number of deletions and insertions. | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and insert"
url: "https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1"
```


```cpp
	int minOperations(string x, string y) 
	{ 
	    int l = lcs(x.size(),y.size(),x,y);
	    int deletion = x.size()-l;
	    int insertion = y.size()-l;
	    return insertion+deletion;
	    
	}
	
	 int lcs(int m, int n, string x, string y)
    {
        int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        return t[m][n];

    }
```

### Longest Palindromic Subsequence

```embed
title: "watch?v=wuOOOATz_IA"
image: "https://img.youtube.com/vi/wuOOOATz_IA/maxresdefault.jpg"
description: "Longest Palindromic Subsequence Given a sequence, find the length of the longest palindromic subsequence in it. Example : Input:“bbbab” Output:4 PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26"
```

![[476d5dd8cc3331a5b433e5be7125dd85_MD5.png|1051x591]]
- to find LPS we can find the LCS for the given string and its reverse string. 

```embed
title: "Longest Palindromic Subsequence | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a String, find the longest palindromic subsequence. NOTE: Subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements Example 1:"
url: "https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1"
```

```cpp
    int longestPalinSubseq(string x) {
        string temp =x;
        reverse(x.begin(),x.end());
        return lcs(temp.size(),x.size(),temp,x);
    }
    
    int lcs(int m, int n, string x, string y)
    {
        int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        return t[m][n];

    }
```

### Minimum number of Deletion in a string to make it palindrome

```embed
title: "YouTube"
image: "https://img.youtube.com/vi/CFwCCNbRuLY/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=CFwCCNbRuLY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27"
```

- the number of deletion will be minimum if we find the LPS and delete only those elements which not in the LPS.
	- `str.length()-LPS`


```embed
title: "Minimum number of deletions. | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a string &#39;str&#39;&nbsp;of size &lsquo;n&rsquo;. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove. Note:"
url: "https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1"
```

```cpp
int lcs(int m, int n, string x, string y)
{
    int t[m+1][n+1];
    for(int i = 0;i<m+1;i++){
    	for(int j = 0;j<n+1;j++){
    		if(i==0 || j==0) t[i][j] = 0;
    	}
    }
    
    for(int i = 1;i<m+1;i++){
    	for(int j = 1;j<n+1;j++){
    		if(x[i-1]==y[j-1])
    			t[i][j] = 1 + t[i-1][j-1];
    		else 
    			t[i][j] = max(t[i][j-1],t[i-1][j]);
    	}
    }
    
    return t[m][n];

}

int lps(string x) {
    string temp =x;
    reverse(x.begin(),x.end());
    return lcs(temp.size(),x.size(),temp,x);
}

int minDeletions(string str, int n) { 
    return n - lps(str); 
} 
    
```

### Minimum number of Insertion in a string to make it Palindrome

```embed
title: "32 Minimum number of insertion in a string to make it a palindrome"
image: "https://img.youtube.com/vi/AEcRW4ylm_c/maxresdefault.jpg"
description: "Minimum number of insertions to make a string palindromeGiven a string, find the minimum number of characters to be inserted to form Palindrome string out of…"
url: "https://www.youtube.com/watch?v=AEcRW4ylm_c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31"
```

- to get deletions we remove the elements which are not in LPS, similarly to get the insertions we add the elements which we were deleting before, so that pairs can be formed for those elements to complete the palindrome. 
- therefore `no of insertions = no of deletions = str.length() - lps`  
### Longest Repeating Subsequence 

```embed
title: "30 Longest repeating subsequence"
image: "https://www.youtube.com/s/desktop/fe730087/img/favicon_144x144.png"
description: "Longest Repeating SubsequenceGiven a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same p…"
url: "https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29"
```

- while finding the LCS of the string with itself we will just make sure that `i!=j`
- ![[6a600ad7459c61608807c6458efa906d_MD5.png]]
- we don't want the same index character, as it will not be repeating there so we add the condition `i!=j` while finding the LCS. 
```cpp
// code from video
if(a[i-1]==b[j-1] && (i!=j)){
	t[i][j] = 1+t[i-1][j-1];
}else{
	t[i][j] = max(t[i][j-1],t[i-1][j]);
}
```

```embed
title: "Longest Repeating Subsequence | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character h"
url: "https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1"
```

```cpp
		int LongestRepeatingSubsequence(string str){
		    int m = str.size();
		    return lcsWithRepeating(m,m,str,str);
		}
        
       int lcsWithRepeating(int m, int n, string x, string y)
        {
            int t[m+1][n+1];
            for(int i = 0;i<m+1;i++){
            	for(int j = 0;j<n+1;j++){
            		if(i==0 || j==0) t[i][j] = 0;
            	}
            }
            
            for(int i = 1;i<m+1;i++){
            	for(int j = 1;j<n+1;j++){
            		if(x[i-1]==y[j-1] && i!=j)
            			t[i][j] = 1 + t[i-1][j-1];
            		else 
            			t[i][j] = max(t[i][j-1],t[i-1][j]);
            	}
            }
            
            return t[m][n];
    
        }
```

### Sequence Pattern Matching 

```embed
title: "YouTube"
image: "https://img.youtube.com/vi/QVntmksK2es/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=QVntmksK2es&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=30"
```

- check if the LCS is a itself then return true.
- we don't need to find the LCS, only length will be sufficient, because length of LCS will be shorter than both. 
	- the range of LCS can be from `0 to max(m,n)`

```embed
title: "- LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? - Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
url: "https://leetcode.com/problems/is-subsequence/"
```

```cpp
class Solution {
private: 
   int lcs(int m, int n, string x, string y)
    {
        int t[m+1][n+1];
        for(int i = 0;i<m+1;i++){
        	for(int j = 0;j<n+1;j++){
        		if(i==0 || j==0) t[i][j] = 0;
        	}
        }
        
        for(int i = 1;i<m+1;i++){
        	for(int j = 1;j<n+1;j++){
        		if(x[i-1]==y[j-1])
        			t[i][j] = 1 + t[i-1][j-1];
        		else 
        			t[i][j] = max(t[i][j-1],t[i-1][j]);
        	}
        }
        
        return t[m][n];

    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return lcs(m,n,s,t) == m;
    }
};
```

## Problems not covered 

- length of longest subsequence of a which is a substring in b. 
- Longest Palindromic substring 
- Count of palindromic substring 
- Count how many times a appear as a subsequence in b. 
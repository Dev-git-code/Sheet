# Knapsack Problems

```table-of-contents
title: 
style: nestedList # TOC style (nestedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
includeLinks: true # Make headings clickable
debugInConsole: false # Print debug info in Obsidian console
```

## 0/1 Knapsack Problem

![[40edb344e729aef692cecc723ae8396c_MD5.png]]

### Knapsack recursive solution 
```embed
title: "3 01 Knapsack Recursive"
image: "https://img.youtube.com/vi/kvyShbFVaY8/maxresdefault.jpg"
description: "0-1 Knapsack Problem solution using recursion(Overlapping Subproblems).Example: Given weights and values of n items, put these items in a knapsack of capacit…"
url: "https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3"
```

- For recursive code make the **choice diagram.**
![[0275d6cf7b4f6d4637f8565d86c58e32_MD5.png]]

```cpp
// template of recursive function
function (){
	Base condition; 
	Choice diagram;
}
```

- for base condition: think of the smallest valid input. 

![[90008b978e29504fe66dc387bf971f28_MD5.png]]

- we will check the weight and value array from the last then remove the element and make recursive call for smaller input
```cpp
// Recursive code from video
int knapsack(int wt[], int val[], int w, int n){
	// base condition 
	if(n==0 || w==0)
		return 0;
	// choice diagram
	// when weight of object is less than or equal to knapsack capacity
	if(wt[n-1]<=w){
		// choice 1 => take the object in knapsack
		// choice 2 => dont take the object
		// return the max choice 
		return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    // when weight of object is greater than knapsack
	}else if(wt[n-1]>w){
		return knapsack(wt,val,w,n-1);
	}
}
```
### Knapsack memoization solution

```embed
title: "YouTube"
image: "https://img.youtube.com/vi/fJbIuhs24zQ/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4"
```

- In the recursive code only `n and w` are changing, so we have to make the matrix for those variables only which are changing. 
- In the matrix we have to store till `n and w` so we make a matrix of `n+1 and w+1 ` size 
	- `int t[n+1][w+1]`
- use `memset function ` to fill the matrix with `-1`
	- `memset(t,-1,sizeOf(t))`
- Before calling the recursive function, we will check if the value is present in the table, if the value is not `-1`, then it is present. 
	- If the value is present then we will not call the recursive function and directly return the value.
	- If the value is not present then call the recursive function and store the value in the table. 

```cpp
 int knapsack(int wt[],int val[], int w, int n, vector<vector<int>> &t){
        if(n==0 || w==0) return 0;
        // check if value is present in table
        if(t[n][w]!=-1) return t[n][w];
        // if value not present then add in table
        if(wt[n-1]<=w){
            return t[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,t),
                       knapsack(wt,val,w,n-1,t));
        }else{
            return t[n][w] = knapsack(wt,val,w,n-1,t);
    }

int knapsackDriver(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> t(n+1, vector<int>(w+1,-1));
        return knapsack(wt,val,w,n,t);     
    }
```

### Knapsack Top Down Approach 

```embed
title: "watch?v=ntCGbPMeqgg"
image: "https://img.youtube.com/vi/ntCGbPMeqgg/maxresdefault.jpg"
description: "0-1 Knapsack Problem solution using Tabulataion Method. TOP DOWN APPROACH Example: Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property). PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5"
```

- We aim to remove the recursive calls in the code of memoization to get to the top down approach. 
- There are two steps to convert the memoization code into top down
	- Initialize 
	- Change the recursive calls to iterative. 
- The base condition of the recursive code becomes the initialisation step for the table. 

```cpp
// base condition 
if(n==0 || w==0) 
	return 0;
// changes to ------------------------------------
// initialisation of the matrix
for(int i = 0;i<n+1;i++){
	for(int j = 0;j<n+1;j++){
		if(i==0 || j==0)
			t[i][j] = 0;
	}
}
```
- We need to convert the choice diagram from recursive to iterative.
	- replace the recursive calls with the values in the table corresponding to that call. 
	
```cpp 
// recursive memoized code
if(wt[n-1]<=w){
	return t[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,t),
			   knapsack(wt,val,w,n-1,t));
}else{
	return t[n][w] = knapsack(wt,val,w,n-1,t);
}

// changes to --------------------------------------------------------------

// table equations 
if(wt[n-1]<=w){
	return t[n][w] = max(val[n-1]+ t[n-1][w-wt[n-1]], t[n-1][w]);
}else{
	return t[n][w] = t[n-1][w];
}

```

- we will get the equations from the recursive memoized code of choice diagram, just by replacing the recursive calls with corresponding values in the table. 
- we use these equations to write the iterative code replace `n with i` and `w with j`.
- here `n and i ` represent object number and `w and j` represent knapsack capacity.
```cpp
// final iterative code
// here i --> object number (1 based indexing)
// and j --> knapsack capacity
for(int i = 1;i<n+1;i++){
	for(int j = 1;j<w+1;j++){
		if(wt[i-1]<=j){
			t[i][j] = max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
		}else{
			t[i][j] = t[i-1][j];
		}
	}
}
```

- NOTE : Here we have` i` starting from the 1st object whereas for recursive solution we started from the last object.  The answer is correct because the order of processing the objects does not affect the result. The recursive code can also be written such that it iterates from the 1st to the last object.  In memoization, when we enter values in the table, those values are filled in bottom up fashion, therefore i can be directly corelated with n.
  ![[372a69adecc71c71ea65be238c273dba_MD5.jpg]]
- [[Program that generates the memoization table for the above example]]

#### Top down approach code

```cpp
int knapSack(int w, int wt[], int val[], int n) 
    { 
       // initialise the table 
       int t[n+1][w+1];
       for(int i = 0;i<n+1;i++){
           for(int j = 0;j<w+1;j++){
               if(i==0||j==0)
                 t[i][j] = 0;
           }
       }
       
       // iterative approach for choice diagram
       for(int i = 1;i<n+1;i++){
           for(int j = 1;j<w+1;j++){
               if(wt[i-1]<=j)
                 t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
               else
                 t[i][j] = t[i-1][j];
           }
       }
       
       return t[n][w];
    }
```
- [[Space optimized Approach for 01 Knapsack Problem using Dynamic Programming]]

```embed
title: "0 - 1 Knapsack Problem | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N"
url: "https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp 
// memoized code 
int t[1001][1001];
int solve(int w, int wt[], int val[], int n){
   if(n==0 || w==0) return 0;
   if(t[n][w]!=-1) return t[n][w];
   
   if(wt[n-1]<=w){
	   return t[n][w] = max(val[n-1]+ knapSack(w-wt[n-1],wt,val,n-1) , knapSack(w,wt,val,n-1));
   }
   else {
	   return t[n][w] = knapSack(w,wt,val,n-1);
   }
}
int knapSack(int w, int wt[], int val[], int n) 
{
	
  memset (t,-1,sizeof(t));
  return solve(w,wt,val,n);
   
}
// gives TLE
```

```cpp 
 // top down code 
int solve(int w, int wt[], int val[], int n){
   
   int t[n+1][w+1];
   for(int i = 0;i<=n;i++){
	   for (int j = 0;j<=w;j++){
		   if(i==0 || j==0) t[i][j] =0;
	   }
   }
  
   for(int i = 1;i<=n;i++){
	   for(int j = 1;j<=w;j++){
		   if(wt[i-1]<=j){
			   t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
		   }
		   else {
			   t[i][j] = t[i-1][j];
		   }
	   }
   }
   
   return t[n][w];
   
}
int knapSack(int w, int wt[], int val[], int n) 
{
	
  return solve(w,wt,val,n);
   
}
```

### Identification of Knapsack Type Problem 
```embed
title: "watch?v=iBnWHZmlIyY"
image: "https://img.youtube.com/vi/iBnWHZmlIyY/maxresdefault.jpg"
description: "Identification of Knapsack Problem. Identify the problem that ii belons to Knapsack or not PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=iBnWHZmlIyY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=6"
```

#### Basic code of Knapsack 
 ![[0275d6cf7b4f6d4637f8565d86c58e32_MD5.png]]
```cpp
// can be easily generated using the above choice diagram
 if(wt[i-1]<=j)
    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
 else
    t[i][j] = t[i-1][j];
```

- If the input has an item array (weight and value are properties of item only) and a certain maximum capacity then it is a knapsack type problem. 

## 0/1 Knapsack type Problems 

### Subset Sum Problem 

```embed
title: "7 Subset Sum Problem"
image: "https://img.youtube.com/vi/_gPcYovP7wc/maxresdefault.jpg"
description: "Subset Sum Problem(Dynamic Programming)Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal…"
url: "https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7"
```

- Similarity to knapsack: 
	- we make a choice for each element to either include it or not. 
	- and there is a sum which is similar to knapsack capacity. 
- Matrix Initialisation: 
	- when `arr.size()= 0` and `sum = 0` then we can make empty subset, so value in table should be `true`. 
	- when `arr.size()>0` and `sum = 0` then we can always make an empty subset, so value in table should be `true`. 
	- when `arr.size()= 0` and `sum > 0` then we cannot make any subset, so value in table should be `false` 
	
![[db5b6a5c648a87751620950c8bb62f10_MD5.png]]
```cpp 
// matrix initialisation 
// i --> arr.size()
// j --> sum
for(int i = 0;i<n+1;i++){
	for(int j = 0;j<sum+1;j++){
		if(i==0) t[i][j] = false; // fill row 0 with false
		if(j==0) t[i][j] = true; // fill col 0 with true
	}
}
```

#### Changes in the knapsack choice code
```cpp 
 if(wt[i-1]<=j)
    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
 else
    t[i][j] = t[i-1][j];
```

- here `wt[] --> arr[]` and `w --> sum`
- table `t` stores `true` or `false` 
- here `t[i-1][j-arr[i-1]]` represents that I have taken the element and `t[i-1][j]` represents that I have not taken the element. 
- If even one of the above conditions give the required subset then we make the cell value true else we make it false. Therefore we use the or condition instead of max.
- [watch this to understand the why we have taken or condition instead of max](https://youtu.be/_gPcYovP7wc?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&t=1330) 
```cpp
if(arr[i-1]<=j) // when element is less than sum
// choice 1: take the element
// choice 2: dont take the element
// if even one condition gives the required subset the we make value of cell true else it will be false.
	t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
else // element is greater than sum
	// only one choice : cannot take the element
	t[i][j] = t[i-1][j];
```
 
```embed
title: "Subset Sum Problem | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.&nbsp; Example 1: Input: N = 6 arr[] = {3, 34, 4, 12, 5, 2} sum = 9 Output:&nbsp;1&nbsp; Explanation: Here there exi"
url: "https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp
    bool isSubsetSum(vector<int>arr, int sum){
         // matrix initialisation 
        int n = arr.size();
        bool t[n+1][sum+1];
        for(int i= 0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j] = false;
                if(j==0) t[i][j] = true;
            }
        }
        
        // choice diagram iterative code
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<sum+1;j++){
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else 
                    t[i][j] = t[i-1][j];
            }
        }
     
        return t[n][sum];
    }
```


### Equal sum Partition Problem

```embed
title: "Equal Sum Partition Problem"
image: "https://img.youtube.com/vi/UmMh7xp07kY/maxresdefault.jpg"
description: "Equal Sum Partition ProblemPartition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both su…"
url: "https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8"
```

- If the sum of all the elements is odd then I cannot to equal partition, so if the sum is odd then I will directly return false.
- If the sum is even then we just have to find the subset with `sum = sum/2` as the other subset will have `sum = sum/2` automatically. 
- Now to find the subset with a particular sum, we use the above subset sum function from the previous ques.

```embed
title: "Partition Equal Subset Sum | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array&nbsp;arr[] of size&nbsp;N, check if&nbsp;it can be partitioned into two parts such that the sum of elements in both parts&nbsp;is the same. Example 1: Input: N = 4 arr = {1, 5, 11, 5} Output: YES Explanation: The two parts are {1, 5,"
url: "https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1"
```

```cpp
int equalPartition(int N, int arr[])
{
   int sum = 0;
   for(int i = 0;i<N;i++){
	   sum += arr[i]; 
   }
   if(sum%2!=0) return 0;
   else return isSubsetSum(arr,sum/2,N);
}

int isSubsetSum(int arr[], int sum, int n){
	 // matrix initialisation 
	bool t[n+1][sum+1];
	for(int i= 0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0) t[i][j] = false;
			if(j==0) t[i][j] = true;
		}
	}
	
	// choice diagram iterative code
	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<sum+1;j++){
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			else 
				t[i][j] = t[i-1][j];
		}
	}
 
	return (int)t[n][sum];
}
```

### Count of Subset Sum

```embed
title: "9 Count of Subsets Sum with a Given Sum"
image: "https://img.youtube.com/vi/F7wqWbqYn9g/maxresdefault.jpg"
description: "Count of subsets sum with a Given sumGiven an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.Example…"
url: "https://youtu.be/F7wqWbqYn9g?si=1kovF36X2xdmmb7v"
```
	
 - Matrix Initialization 
	 - the rows represent the array size and the columns represent the sum.
	 - when `arr.size()=0 and sum>0` then we have no subsets so fill all cells in 0th  row with 0 (except the first cell).
	 - when `arr.size()>=0 and sum = 0` then we always have an empty subset, so fill all values of 0th column with 1.
- Main code difference: 
```cpp 
// subset sum code 
if(arr[i-1]<=j)
	t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
else 
	t[i][j] = t[i-1][j];

Here t[i-1][j] means element is excluded
and  t[i-1][j-arr[i-1]] means element is included
```
 - `t[i][j]` for this problem represents the count of subsets for particular array size and sum. 
- In this problem, if we get a subset, either by including or excluding the element then we have to add it to the count of the subsets. So, we use `+` instead of `or` here. 

```cpp
// subset count code
if(arr[i-1]<=j)
	t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
else 
	t[i][j] = t[i-1][j];
```

- when we have to find count, we add all the choices that we have`

```embed
title: "Perfect Sum Problem | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr&nbsp;of non-negative integers and an integer sum, the task is to count&nbsp;all subsets of the given array with a sum equal to a given sum. Note: Answer can be very large, so, output answer modulo 109+7. Example 1: Input: N = 6arr"
url: "https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1"
```

```cpp
	int perfectSum(int arr[], int n, int sum)
	{
        // matrix initialisation 
        int mod = 1e9+7;
        int t[n+1][sum+1];
        for(int i= 0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j] = 0;
                if(i==0 && j==0) t[i][j] = 1;
            }
        }
        
        // choice diagram iterative code
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<sum+1;j++){ // ele in array can also be 0
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
                else 
                    t[i][j] = t[i-1][j];
            }
        }
     
        return t[n][sum];
	}
	  
```

```cpp 
// memoization code 
int mod = 1e9 + 7;
vector<vector<int>> t;
int solve(int arr[], int n, int sum){
	// base condition does not deal with n>0 because in that case ele 
	// can also be zero 
	// If we initialize it with 1 in the start then when -1 is not found in table we get 
	// only 1 subset from there but if we include the 0 we can have more subsets...
	if(n==0 && sum ==0 ) return 1;
	if(n==0 && sum > 0) return 0;
	// more adv version of bc 
	//if(n==0) return sum ==0;
   
   
	if(t[n][sum] != -1) return t[n][sum];

	if(arr[n-1]<=sum){
		 t[n][sum] = (solve(arr,n-1, sum - arr[n-1])+ solve(arr,n-1,sum))%mod;
	}else{
		 t[n][sum] = solve(arr,n-1, sum)%mod;
	}
	return t[n][sum];
}

int perfectSum(int arr[], int n, int sum)
{
	t.assign(n+1,vector<int>(sum+1,-1));
	return solve(arr,n,sum);
}
```
- the constraint` 0 ≤ arr[i] ≤ 10^6` allows element in array to be 0 also, so for array size zero , we can have more than one subsets too. Therefore we start j from zero. 

### Minimum Subset Sum Difference `Imp ques` 

```embed
title: "watch?v=-GtpxG6l_Mc?si=b_1T3D6j6RUbSDfs"
image: "https://img.youtube.com/vi/-GtpxG6l_Mc/maxresdefault.jpg"
description: "Sum of subset differences Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum. Example: Input: arr[] = {1, 6, 11, 5} Output: 1 Explanation: Subset1 = {1, 5, 6}, sum of Subset1 = 12 Subset2 = {11}, sum of Subset2 = 11 PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://youtu.be/-GtpxG6l_Mc?si=b_1T3D6j6RUbSDfs"
```

- we need two subsets such that `abs(S2-S1)` is minimum. 
- S1 and S2 subset can take value from 0 to sum of all elements of the array. Therefore the range of S1 and S2 will be `[0,sum(arr[i])]`
- we know that `S1 + S2 = sum(arr[i])` , hence `S2-S1` can be written as `sum(arr[i]) - 2S1`. 
- If we consider S1 to have smaller subset sum and S2 to have greater subset sum, then S1 should belong to the range `[0,sum(arr[i])/2]`
- ![[2d126b9f2c4367b9aa330df9c105a64c_MD5.jpg]]


- Since `sum(arr[i])` is constant, so for the min value of `sum(arr[i]) - 2S1` , we just need to find the max value of S1.
- Now, in the range `[0,sum(arr[i])/2]` we just need to find what are the possible values which S1 can take, this can be done using the subset sum problem.
- ![[dd6fd8517e6d0accc7094c6434350b14_MD5.png]]
- the table of subset sum checks whether subset S1 can be formed for values in the range  `[0,sum(arr[i])/2]` 
- the max value subset S1 can take will give us the minimum subset sum difference.

```embed
title: "Minimum sum partition | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array&nbsp;arr of size n&nbsp;containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference Example 1: Input: N ="
url: "https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp
int minDifference(int arr[], int n)  { 
		int sum = 0;
		for(int i = 0;i<n;i++) sum+=arr[i];
		int S1 =  isSubsetSum(arr,sum/2,n);
		return (sum - 2*S1);
} 

int isSubsetSum(int arr[], int sum, int n){
	 // matrix initialisation 
	bool t[n+1][sum+1];
	for(int i= 0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0) t[i][j] = false;
			if(j==0) t[i][j] = true;
		}
	}
	
	// choice diagram iterative code
	for(int i = 1;i<n+1;i++){
		for(int j = 0;j<sum+1;j++){
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			else 
				t[i][j] = t[i-1][j];
		}
	}
	
	// iterate the last row from back to find the max value of S1
	for(int j = sum;j>=0;j--){
		if(t[n][j]==true) return j;
	}
}
```
### Count the no of subset with given difference 

```embed
title: "11 Count the number of subset with a given difference"
image: "https://img.youtube.com/vi/ot_XBHyqpFc/maxresdefault.jpg"
description: "Given an array Arr[] and a difference diff, find the number of subsets that array can be divided so that each the difference between the two subset is the gi…"
url: "https://youtu.be/ot_XBHyqpFc?si=4Cb2Vteek6vQyf4w"
```

- In the ques we have two equations: 
	- `s1 + s2 = sum` and `s1-s2 = diff` , adding these equations we get `2*s1 = sum + diff`
	- from the above equation we can see that `sum + diff` is always even, so incase `sum+diff` is odd we return 0. 
	- also in case `sum < diff` then partition is not possible, therefore we return 0 in this case also. 

- eventually the problem reduces to count subset with given sum, which we have covered earlier.

```embed
title: "Partitions with Given Difference | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2.&nbsp; Given a difference d, count the number of partitions in which S1 is gre"
url: "https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1"
```

```cpp
 int countPartitions(int n, int d, vector<int>& arr) {
   int sum = 0;
   for(auto &e:arr) sum+=e;
   if((sum+d)%2!=0 || sum<d) return 0;
   int S1 = (sum+d)/2; 
   return perfectSum(arr,n,S1);
}
    
int perfectSum(vector<int>& arr, int n, int sum)
{
	// matrix initialisation 
	int mod = 1e9+7;
	// t[n+1][sum+1] gave seg fault
	vector<vector<int>> t(n+1,vector<int>(sum+1));
	for(int i= 0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0) t[i][j] = 0;
			if(i==0 && j==0) t[i][j] = 1;
		}
	}
	
	// choice diagram iterative code
	for(int i = 1;i<n+1;i++){
		for(int j = 0;j<sum+1;j++){ // ele in array can also be 0 leading to sum =0
			if(arr[i-1]<=j)
				t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j])% mod;
			else 
				t[i][j] = t[i-1][j];
		}
	}
 
	return t[n][sum];
}
```

### Target Sum 

```embed
title: "YouTube"
image: "https://img.youtube.com/vi/Hw6Ygp3JBYw/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12"
```

- the problem is same as the last one, but here we have negative input also. 
- But if we change the negative numbers to non negative ones and take absolute value of difference, we can reduce the problem to previous one. 
- the two subsets: subset s1 will have all positive numbers and subset s2 will have all negative numbers, and the sign of a number can be controlled by us because of the nature of the question that allows as much signs as you want to get the difference.

```embed
title: "Target Sum | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an array of integers A[] of length N and an integer target.You want to build an expression&nbsp;out of A&nbsp;by adding one of the symbols ‘+’ and ‘-’ before each integer in A&nbsp;and then concatenate all the integers. For example, if arr&nbs"
url: "https://www.geeksforgeeks.org/problems/target-sum-1626326450/1"
```

```cpp
    int findTargetSumWays(int n, vector<int>&arr ,int d) {
       int sum = 0;
       d = abs(d); // take absolute of the differnce
       for(auto &e:arr){
            if(e<0) e = -1*e; // remove the negative numbers 
            sum+=e;
       }
       if((sum+d)%2!=0 || sum<d) return 0;
       int S1 =d +( sum-d)/2; 
       return perfectSum(arr,n,S1);
    }
    
    int perfectSum(vector<int>& arr, int n, int sum)
	{
        // matrix initialisation 
        int mod = 1e9+7;
        // t[n+1][sum+1] gave seg fault
        vector<vector<int>> t(n+1,vector<int>(sum+1));
        for(int i= 0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) t[i][j] = 0;
                if(j==0) t[i][j] = 1;
            }
        }
        
        // choice diagram iterative code
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<sum+1;j++){ // ele in array can also be 0 leading to sum =0
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j])% mod;
                else 
                    t[i][j] = t[i-1][j];
            }
        }
     
        return t[n][sum];
	}
```

## Unbounded Knapsack

```embed
title: "YouTube"
image: "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAeAAAAFoCAYAAACPNyggAAAOn0lEQVR4Xu3VsQnDQBBFwd3AakTuv8UTOHQuXjJXwC0MH97OzBmPAAECBAgQeFVgd+ecM/f9nev6zArwq94+J0CAAAECPwEBNgQCBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBD4D/ADV99NUy08rgcAAAAASUVORK5CYII="
description: "Share your videos with friends, family, and the world"
url: "https://youtu.be/aycn9KO8_Ls?si=bEqali020OQpbAup"
```

- Unbounded knapsack allows multiple occurrences of a object in the knapsack. 
- In 0/1 knapsack, whether a object is taken or not taken( in the knapsack), it is considered processed and we don't visit the element again. 
- Whereas in unbounded knapsack, if a item is not taken then only it is considered processed. In case the item is taken, it is still considered unprocessed and we can take the element again and again.
### Code variation from 0/1 knapsack

```embed
title: "watch?v=aycn9KO8_Ls?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go"
image: "https://img.youtube.com/vi/aycn9KO8_Ls/maxresdefault.jpg"
description: "Unbounded Knapsack (Repetition of items allowed) Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate minimum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item. Examples: Input : W = 100 val[] = {1, 30} wt[] = {1, 50} Output : 100 There are many ways to fill knapsack. 1) 2 instances of 50 unit weight item. 2) 100 instances of 1 unit weight item. 3) 1 instance of 50 unit weight item and 50 instances of 1 unit weight items. We get maximum value with option 2. PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://youtu.be/aycn9KO8_Ls?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&t=629"
```


```cpp
// 0/1 knapsack code
if(wt[i-1]<=j){
	t[i][j] = max(t[i-1][j], t[i-1][j-wt[i-1]]+val[i-1]);
else{
	t[i][j] = t[i-1][j];
}
```

```cpp
// unbounded knapsack code
if(wt[i-1]<=j){
	t[i][j] = max(t[i-1][j], t[i][j-wt[i-1]]+val[i-1]); // we find the prev solution of subproblem at the same index even after selecting the item.
else{
	t[i][j] = t[i-1][j];
}
```

```embed
title: "Knapsack with Duplicate Items | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a set of N items, each with a weight and a value, represented by the array w&nbsp;and&nbsp;val&nbsp;respectively.&nbsp;Also, a knapsack with weight limit W.The task is to fill the knapsack in such a way that we can get the maximum profit. Retur"
url: "https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1"
```

```cpp
int knapSack(int n, int w, int val[], int wt[])
    {
        int t[n+1][w+1]; 
        
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<w+1;j++){
                if(i==0||j==0) t[i][j] = 0;
            }
        }
        
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<w+1;j++){
                if(wt[i-1]<=j){
                    t[i][j] = max(t[i-1][j],val[i-1]+t[i][j-wt[i-1]]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][w];
    }
```

### Unbounded Knapsack Further Reading 

```embed
title: "Unbounded Knapsack (Repetition of items allowed) - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "A Computer Science portal for geeks. It contains well written, well thought and well explained computer science and programming articles, quizzes and practice/competitive programming/company interview Questions."
url: "https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/"
```

```embed
title: "DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach"
image: "https://img.youtube.com/vi/OgvOZ6OrJoY/maxresdefault.jpg"
description: "Lecture Notes/C++/Java Codes: https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/Problem Link: https://bit.ly/3IvPdX…"
url: "https://www.youtube.com/watch?v=OgvOZ6OrJoY"
```

## Unbounded Knapsack type problem

### Rod Cutting Problem 

```embed
title: "14 Rod Cutting Problem"
image: "https://img.youtube.com/vi/SZqAQLjDsag/maxresdefault.jpg"
description: "Rod Cutting Problem Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum v…"
url: "https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14"
```

- This problem is same as knapsack because the `price[] --> val[]` , `N --> W` and `length[] --> wt[]` 
- we can cut the rod at same length any number of times, so for that particular length you can consider the price multiple times, this is similar to taking multiple instances of the object, therefore this problem is similar to unbounded knapsack.
![[96023c70e833b023b327767fe221de3f_MD5.png]]


```embed
title: "Rod Cutting | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces. Note: Consider 1-based indexing. Example 1: Input:"
url: "https://www.geeksforgeeks.org/problems/rod-cutting0840/1"
```

```cpp
    int cutRod(int price[], int n) {
    
        int t[n+1][n+1];
        
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<n+1;j++){
                if(i==0||j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<n+1;j++){
                if(i<=j){ // i takes the values of length from 1 to n.
                    t[i][j] = max(t[i-1][j],price[i-1]+t[i][j-i]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
```

### Coin change Problem - Maximum number of ways

```embed
title: "15 Coin change problem: Maximum number of ways"
image: "https://img.youtube.com/vi/I4UR2T6Ro3w/maxresdefault.jpg"
description: "Coin Change Problem Maximum Number of waysGiven a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , S…"
url: "https://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15"
```

- This ques is similar to count of subset sum, only difference is here we can select multiple instances of the object.

```embed
title: "Coin Change | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an integer&nbsp;array coins[ ] of size N&nbsp;representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. &nbsp;Note: Assume that you have an infin"
url: "https://www.geeksforgeeks.org/problems/coin-change2448/1"
```

```cpp
long long int count(int coins[], int n, int sum) {
	long long int t[n+1][sum+1];
	// matrix initialisation 
	for(int i = 0;i<n+1;i++){
		for(int j = 0;j<sum+1;j++){
			if(i==0) t[i][j] = 0;
			if(j==0) t[i][j] = 1;
		}
	}
	
	// choice: take coin or not take coin. 
	for(int i = 1;i<n+1;i++){
		for(int j = 1;j<sum+1;j++){
			if(coins[i-1]<=j){
				t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	
	return t[n][sum];
}
```
### Coin Change - Minimum number of coins (typical ques)

```embed
title: "watch?v=I-l6PBeERuc"
image: "https://img.youtube.com/vi/I-l6PBeERuc/maxresdefault.jpg"
description: "Coin Change Problem Minimum Numbers of coins Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? Example: Input: coins[] = {25, 10, 5}, V = 30 Output: Minimum 2 coins required We can use one coin of 25 cents and one of 5 cents PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-mi... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16"
```

- **Matrix Initialization** 
	- ![[d7d728ee7980e4848f837339031a1cfc_MD5.jpg]]
	- If the coins required is not a whole number then, no matter how many coins I take I cannot reach the sum or the target values, so we represent this possibility using infinity.
	- we initialize the 0th row with `INT_MAX-1` as to create a sum from no coins will required minimum infinite coins. [reason for INT_MAX-1](https://www.youtube.com/watch?v=rMfOgY07TFs&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=17)
	- when `sum = 0` , we need min `0 coins` to form the sum, therefore we initialize the 0th column with `0`
	- this is a unique type of question in which we have to initialize the 1st row also, using the first point.
```cpp
// matrix initialisation 
for(int i = 0;i<n+1;i++){
	for(int j = 0;j<sum+1;j++){
		if(i==0) t[i][j] = INT_MAX-1;
		// 1st row intialisation 
		if(i==1){
			if(j%coins[0]==0) t[i][j] = j/coins[0];
			else t[i][j] = INT_MAX-1;
		}
		if(j==0) t[i][j] = 0;
	}
}
```

- Code variation from unbounded knapsack
	- when we take the coin then add 1 to cell `t[i][j-coins[i-1]]` (because of adding this 1 , we take `INT_MAX-1` for the edge case).
```cpp
if(coins[i-1]<=j){
	t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
}else{
	t[i][j] = t[i-1][j];
}
```

```embed
title: "Number of Coins | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not po"
url: "https://www.geeksforgeeks.org/problems/number-of-coins1824/1"
```

```cpp
	int minCoins(vector<int> &coins, int n, int sum) 
	{ 
	    int inf = INT_MAX-1;
	    int t[n+1][sum+1];
	    
	    for(int i = 0;i<n+1;i++){
	        for(int j = 0;j<sum+1;j++){
		        if(i==0) t[i][j] = inf;
		        // 1st row intialisation 
		        if(i==1){
			        if(j%coins[0]==0) t[i][j] = j/coins[0];
			        else t[i][j] = inf;
		        }
		        if(j==0) t[i][j] = 0;
	        }
        }
        
        for(int i =2;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coins[i-1]<=j){
	                t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
                }else{
	                t[i][j] = t[i-1][j];
                }
            }
        }
        if(t[n][sum]<inf) return t[n][sum];
        else return -1; // no possible ways 
	} 
```

```table-of-contents
title: 
style: nestedList # TOC style (nestedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
includeLinks: true # Make headings clickable
debugInConsole: false # Print debug info in Obsidian console
```

# MCM Problem 

```embed
title: "watch?v=D7AFvtnDeMU"
image: "https://img.youtube.com/vi/D7AFvtnDeMU/maxresdefault.jpg"
description: "Matrix Chain Multiplication Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/matrix-... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=D7AFvtnDeMU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33"
```

- Break the problem for i to j at multiple points k, and for each k, we get a temporary value, on these temp values we apply a function `max or min` and finally get a answer. 
![[dd8b93e35e5a900e29ccb63cf94c1b2f_MD5.png]]
- For the base condition either think of the smallest valid input or think of the first invalid input. Here, we use the case where we think of the first invalid input. `i>j`
## Format code for MCM 
- steps:
	- find i and j ( close to left and right end index )
	- find Base condition 
	- find k loop scheme 
	- find accurate answer from temporary answer
```cpp 
// basic format for MCM type problem 
int solve(int arr[], int i, int j){
	if(i>j){
		return 0;
	}
	
	for(int k = i;k<j;k++){// k goes from i to j
		// calculate temp ans 
		temp_ans = solve(arr,i,k) + solve(arr,k+1,j);
		ans = fcn(temp_ans); // fcn can be max min or some other function
	}
	return ans;
}
```

## MCM Recursive 

```embed
title: "34 Matrix Chain Multiplication Recursive"
image: "https://img.youtube.com/vi/kMK148J9qEE/maxresdefault.jpg"
description: "Matrix Chain Multiplication using Recursion Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not…"
url: "https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33"
```

- here we cannot have `i==j` as for each matrix, we at least need two values to form a matrix, therefore `i==j` becomes a invalid input.
- we need to iterate a sample array to see which values k can take, In this problem the values range from `i to j-1`.
![[9d1c545dab8ed84dd6abb4153b970f90_MD5.png]]
- to get the value for multiplication of both matrix, obtained from `solve(i to k) and solve (k+1 to j)` , the values comes to be `arr[i-1]*arr[k]*arr[j]`.
- Finally, we take the minimum cost from all the temporary answers. 
```cpp
// code from video
int solve(int arr[],int i , int j){
	// base condition 
	if(i>=j) return 0; // first invalid input
	int ans = INT_MAX;
	// what values k takes...
	for(int k = i;k<=j-1;k++){
		int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		if(temp<ans) ans = temp;
	}
	return ans;
}
```

## MCM Memoization

```embed
title: "35 Matrix chain multiplication Memoization"
image: "https://img.youtube.com/vi/9uUVFNOT3_Y/maxresdefault.jpg"
description: "EDIT: SORRY FOR THE LAGGING AUDIO, WILL FIX IT SOON !! THANKS FOR YOUR PATIENCE.Matrix Chain Multiplication using Memoization Given a sequence of matrices, f…"
url: "https://www.youtube.com/watch?v=9uUVFNOT3_Y&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=34"
```

- declare `t[1001][1001]` globally and initialize with `-1`. 

```cpp 
// video code
int t[1001][1001]; // i and j max value 1000 given

int solve(int arr[], int i, int j){
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	int mn = INT_MAX;
	for(int k = i;k<j;k++){
		int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		if(temp<mn) mn = temp;
	}
	return t[i][j] = mn;
}

int main(){
	memset(t,-1,sizeof(t));
	solve(arr,1,arr.size()-1); 
}
```
## MCM ques 

```embed
title: "Matrix Chain Multiplication | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a sequence of matrices, find the most efficient way to multiply these matrices together.&nbsp;The efficient way is the one that involves&nbsp;the least number of&nbsp;multiplications. The dimensions of the matrices are given in an array arr[]&"
url: "https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1"
```

```cpp
// MCM Recursive 
int solve(int arr[], int i, int j){
	if(i>=j) return 0;
	int ans = INT_MAX;
	for(int k = i;k<=j-1;k++){
		int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		if(temp < ans) ans = temp;
	}
	return ans;
}
int matrixMultiplication(int N, int arr[])
{
	int i = 1;
	int j = N-1;
	return solve(arr,i,j);
}
// the recursive code gives TLE
```

```cpp
// MCM memoization 
int t[101][101];
int solve(int arr[], int i, int j){
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	int ans = INT_MAX;
	for(int k = i;k<=j-1;k++){
		int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		if(temp < ans) ans = temp;
	}
	return t[i][j] = ans;
}
int matrixMultiplication(int N, int arr[])
{
	int i = 1;
	int j = N-1;
	memset(t,-1,sizeof(t));
	return solve(arr,i,j);
}
```

### MCM Further Reading 
```embed
title: "Matrix Chain Multiplication | DP-8 - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/uploads/matrixchainmultiplication.png"
description: "A Computer Science portal for geeks. It contains well written, well thought and well explained computer science and programming articles, quizzes and practice/competitive programming/company interview Questions."
url: "https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/"
```

## MCM based Problems 

### Palindrome Partitioning 

#### Palindrome Partitioning Recursive

```embed
title: "36 Palindrome Partitioning Recursive"
image: "https://img.youtube.com/vi/szKVpQtBHh8/maxresdefault.jpg"
description: "Palindrome Partitioning using RecursionGiven a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a pal…"
url: "https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35"
```
- values of i and j, `i==0` and `j==s.size()-1`. 
- when `i==j` then it is a palindrome itself, also we have to check if the given string is palindrome or not and if it is a palindrome then return 0. 
```cpp 
bool isPalindrome(string s, int i, int j){
	string p = s;
	reverse(p.begin()+i,p.end()-j);
	return s==p;
}
```
- so, the base condition is
```cpp 
if(i>=j) return 0;
if(isPalindrome(s,i,j)) return 0;
```
- find the valid k loop scheme: 
	- `k = i to k = j-1` and divide `i to k and k+1 to j`
- find the main ans from the temp ans: 
	- `temp = solve(s,i,k) + solve(s,k+1,j) + 1` 
	- one partition for division at k. 
	- take min of all temp ans to get the main ans.
```cpp 
// code from video 
int solve(string s, int i, int j){
	if(i>=j) return 0;
	if(isPalindrome(s,i,j)) return 0;
	int mn = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
		if(temp < mn) mn = temp;
	}
	return mn;
}
```

#### Palindrome Partitioning Memoization 

```embed
title: "watch?v=fOUlNlawdAU"
image: "https://img.youtube.com/vi/fOUlNlawdAU/maxresdefault.jpg"
description: "Palindrome Partitioning using Memoization(Dynamic Programming) Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. Example: “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/palindr... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=2&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=fOUlNlawdAU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=36"
```

- make the table based on the constraints. 
- store the min value in the table and if particular value in the table is not -1 then return that value from the table.

```cpp 
// code from video 
int t[1001][1001]; // based on length constraint 
int solve(string s, int i, int j){
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	if(isPalindrome(s,i,j)) return 0;
	int mn = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
		if(temp < mn) mn = temp;
	}
	return t[i][j] = mn;
}
```
#### Palindrome Partitioning optimized 
```embed
title: "watch?v=9h10fqkI7Nk"
image: "https://img.youtube.com/vi/9h10fqkI7Nk/maxresdefault.jpg"
description: "Palindrome Partitioning Memoized Optimization Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. Example: “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/palindr... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=9h10fqkI7Nk&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37"
```

- before calling `solve(s,i,k)` we will see if it has been solved before or not, if it has been solved then store in `t[i][k]` and same for `solve(s,k+1,j)`.
```cpp 
int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
// changes to ...

if(t[i][k]!=-1) left = t[i][k];
else {
	left = solve(s,i,k);
	t[i][k] = left;
}

if(t[k+1][j]!=-1) right = t[k+1][j];
else{
	right = solve(s,k+1,j);
	t[k+1][j] = right;
}

int temp = left + right + 1;
```
#### Palindrome Partitioning ques 
#companies  `Amazon, Microsoft, Google` 

```embed
title: "Palindromic Partitioning | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a string str,&nbsp;a partitioning of the string is a&nbsp;palindrome partitioning&nbsp;if every sub-string of the partition is a palindrome.&nbsp;Determine the fewest cuts needed for palindrome partitioning of the given string. Example 1:"
url: "https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1"
```


```cpp
// recursive code - give TLE
bool isPalindrome(string s, int i, int j){
	while(i<j){
		if(s[i++]!=s[j--]) return false;
	}
	return true;
}

int solve(string s, int i, int j){
	if(i>=j) return 0;
	if(isPalindrome(s,i,j)) return 0;
	int mn = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
		if(temp < mn) mn = temp;
	}
	return mn;
}
int palindromicPartition(string str){
	int i = 0;
	int j = str.length()-1;
	return solve(str,i,j);
}
```

```cpp
// memoized code TLE at TC 5
int t[501][501];
bool isPalindrome(string s, int i, int j){
	while(i<j){
		if(s[i++]!=s[j--]) return false;
	}
	return true;
}

int solve(string s, int i, int j){
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	if(isPalindrome(s,i,j)) return 0;
	int mn = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
		if(temp < mn) mn = temp;
	}
	return t[i][j] = mn;
}
int palindromicPartition(string str){
	int i = 0;
	int j = str.length()-1;
	memset(t,-1,sizeof(t));
	return solve(str,i,j);
}
```

```cpp 
// memoized code optimization 
    int t[501][501];
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    int solve(string s, int i, int j){
    	if(i>=j) return 0;
    	if(t[i][j]!=-1) return t[i][j];
    	if(isPalindrome(s,i,j)) return 0;
    	int mn = INT_MAX;
    	for(int k = i;k<j;k++){
    	    int left,right;
    		if(t[i][k]!=-1) left = t[i][k];
            else {
            	left = solve(s,i,k);
            	t[i][k] = left;
            }
            
            if(t[k+1][j]!=-1) right = t[k+1][j];
            else{
            	right = solve(s,k+1,j);
            	t[k+1][j] = right;
            }

            int temp = left + right + 1;

    		if(temp < mn) mn = temp;
    	}
    	return t[i][j] = mn;
    }
    
    int palindromicPartition(string str){
        int i = 0;
        int j = str.length()-1;
        memset(t,-1,sizeof(t));
        return solve(str,i,j);
    }
```

### Evaluate Expression to True ( difficult )

#### Evaluate Expression to True Recursive 
```embed
title: "39 Evaluate Expression to True Boolean Parenthesization Recursive"
image: "https://img.youtube.com/vi/pGVguAcWX4g/maxresdefault.jpg"
description: "Evaluate Expression To True-Boolean Parenthesization RecursionGiven a boolean expression with following symbols.Symbols ‘T’ --- true ‘F’ --- false And…"
url: "https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38"
```

NOTE: Watch video once...
![[603cadba5b132468caf140e3b0a00491_MD5.png]]
- In the solve function, we have to pass one more variable which tells what value that string should have from i to j. 

Follow the 4 steps of MCM format: 
- Step 1: Find i and j: 
	- `i=0 and j = s.size()-1`
- Step 2: Base Condition
	- First invalid input will be `i>j` in this case we will return 0.
	- when `i==j` then we have to consider the [single element](https://youtu.be/pGVguAcWX4g?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&t=1341). 
```cpp
// base condition 
if(i>j) return False;
if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
}
```

- Step 3: Find k-loop scheme
	- k always remains on the operator, therefore k moves two steps and start from `i+1` and goes till `j-1`.
	- `for(int k = i+1; k<=j-1;k+=2)`
- Calculate all the values for each partition made by k
```cpp 
for(int k = i+1;k<=j-1;k+=2){
// all these are temp ans
	int lt = solve(s,i,k-1,True);
	int lf = solve(s,i,k-1,False);
	int rt = solve(s,k+1,j,True);
	int rf = solve(s,k+1,j,False);
}
```

- Step 4: Find the main ans from temp ans
	- the ans depends on the operator type
	- we have to calculate all the values for each subproblem

```cpp 
// this is all inside the for loop 
if(s[k]=='&'){
	if(isTrue) ans += lt*rt;
	else ans += lf*rt+lt*rf+lf*rf;
}else if(s[k]=='|'){
	if(isTrue) ans += lf*rt+lt*rf+lt*rt;
	else ans += lf*rf;
}else if(s[k]=='^'){
	if(isTrue) ans += lf*rt + lt*rf;
	else ans += lt*rt + lf*rf;
}
```

```cpp 
// complete code from video
int solve(string s, int i, int j, bool isTrue){
	// base condition 
	if(i>j) return false;
	if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}

	int ans = 0;
	// k-loop scheme
	for(int k = i+1;k<=j-1;k+=2){
		// all these are temp ans
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);
		// get main ans from temp ans...
		if(s[k]=='&'){
			if(isTrue) ans += lt*rt;
			else ans += lf*rt+lt*rf+lf*rf;
		}else if(s[k]=='|'){
			if(isTrue) ans += lf*rt+lt*rf+lt*rt;
			else ans += lf*rf;
		}else if(s[k]=='^'){
			if(isTrue) ans += lf*rt + lt*rf;
			else ans += lt*rt + lf*rf;
		}
	}
	return ans;
}
```

#### Evaluate Expression to True Memoization 
```embed
title: "watch?v=bzXM1Zond9U"
image: "https://img.youtube.com/vi/bzXM1Zond9U/maxresdefault.jpg"
description: "Evaluate Expression To True-Boolean Parenthesization Memoized Given a boolean expression with following symbols. Symbols ‘T’ --- true ‘F’ --- false And following operators filled between symbols Operators & --- boolean AND | --- boolean OR ^ --- boolean XOR Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. Example: Input: symbol[] = {T, F, T} operator[] = {^, &} Output: 2 The given expression is “T ^ F & T”, it evaluates true in two ways ”((T ^ F) & T)” and ”(T ^ (F & T))” PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40"
```

- The dimensions of the table depends on the parameters that are changing in the function call. 
- Either we can create a 3D matrix or create a map where we store a string of` i, j and isTrue` as key and the count as value 
	- `unordered_map<string,int> mp;`
```cpp 
// complete code from video
unordered_map<string,int> mp;
int solve(string s, int i, int j, bool isTrue){
	// base condition 
	if(i>j) return false;
	if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}
	string temp = "";
	temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
	// temp becomes our key 
	// if temp is there then return mp[temp]
	if(mp.find(temp)!=mp.end()) return mp[temp];
	int ans = 0;
	// k-loop scheme
	for(int k = i+1;k<=j-1;k+=2){
		// all these are temp ans
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);
		// get main ans from temp ans...
		if(s[k]=='&'){
			if(isTrue) ans += lt*rt;
			else ans += lf*rt+lt*rf+lf*rf;
		}else if(s[k]=='|'){
			if(isTrue) ans += lf*rt+lt*rf+lt*rt;
			else ans += lf*rf;
		}else if(s[k]=='^'){
			if(isTrue) ans += lf*rt + lt*rf;
			else ans += lt*rt + lf*rf;
		}
	}
	return mp[temp] = ans;
}


```
#### Evaluate Expression to True ques 

```embed
title: "Boolean Parenthesization | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a boolean expression s of length n with following symbols.Symbols&nbsp;&nbsp;&nbsp; ‘T’ ---&gt; true&nbsp;&nbsp;&nbsp; ‘F’ ---&gt; falseand following operators filled between symbolsOperators&nbsp;&nbsp;&nbsp; &amp;&nbsp;&nbsp; ---&gt; boolean"
url: "https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1"
```

```cpp 
// recursive code
int solve(string s, int i, int j, bool isTrue){
	// base condition 
	if(i>j) return 0;
	if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}

	int ans = 0;
	// k-loop scheme
	for(int k = i+1;k<=j-1;k+=2){
		// all these are temp ans
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);

		// get main ans from temp ans...
		if(s[k]=='&'){
			if(isTrue) ans += lt*rt;
			else ans += lf*rt+lt*rf+lf*rf;
		}else if(s[k]=='|'){
			if(isTrue) ans += lf*rt+lt*rf+lt*rt;
			else ans += lf*rf;
		}else if(s[k]=='^'){
			if(isTrue) ans += lf*rt + lt*rf;
			else ans += lt*rt + lf*rf;
		}
	}
	return ans % 1003;
}
    int countWays(int n, string s){
        return solve(s,0,n-1,true);
    }
// gives TLE
```

```cpp 
unordered_map<string,int> mp;
// recursive code
int solve(string& s, int i, int j, bool isTrue){
	// base condition 
	if(i>j) return 0;
	if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}
	string temp = "";
	temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
	// temp becomes our key 
	// if temp is there then return mp[temp]
	if(mp.find(temp)!=mp.end()) return mp[temp];

	int ans = 0;
	// k-loop scheme
	for(int k = i+1;k<=j-1;k+=2){
		// all these are temp ans
		int lt, lf, rt, rf;
		
		string lt_str = to_string(i) + " " + to_string(k-1) + " " + to_string(true);
		if(mp.find(lt_str)!=mp.end()) lt = mp[lt_str] %1003;
		else lt = solve(s,i,k-1,true)%1003;
		
		string lf_str = to_string(i) + " " + to_string(k-1) + " " + to_string(false);
		if(mp.find(lf_str)!=mp.end()) lf = mp[lf_str] %1003;
		else lf = solve(s,i,k-1,false)%1003;
		
		string rt_str = to_string(k+1) + " " + to_string(j)+ " " + to_string(true);
		if(mp.find(rt_str) != mp.end()) rt = mp[rt_str] %1003;
		else rt = solve(s,k+1,j,true);
	
	    string rf_str = to_string(k+1) + " " + to_string(j) + "  " + to_string(false);
	    if(mp.find(rf_str) != mp.end()) rf = mp[rf_str] %1003;
	    else rf = solve(s,k+1,j,false)%1003;

		// get main ans from temp ans...
		if(s[k]=='&'){
			if(isTrue) ans += (lt*rt)% 1003;
			else ans += (lf*rt+lt*rf+lf*rf)% 1003;
		}else if(s[k]=='|'){
			if(isTrue) ans += (lf*rt+lt*rf+lt*rt)% 1003;
			else ans += (lf*rf)% 1003;
		}else if(s[k]=='^'){
			if(isTrue) ans += (lf*rt + lt*rf)% 1003;
			else ans += (lt*rt + lf*rf)% 1003;
		}
	}
	return mp[temp]  = ans % 1003;
}
    int countWays(int n, string s){
        mp.clear();
        return solve(s,0,n-1,true);
    }

// the find operation in map takes time therefore tle, for faster access use 3d array... 
```

```cpp 
int t[101][101][2]; // ( i * j * isTrue)

// function to check and solve for each partition lt,lf, rt, rf..
int solve_partition( string&s, int i , int j , bool isTrue){
    int res;
    if(t[i][j][isTrue] != -1) res = t[i][j][isTrue];
    else res = solve(s,i,j,isTrue);
    return res;
}

int solve(string& s, int i, int j, bool isTrue){
	// base condition 
	if(i>j) return 0;
	if(i==j){
		if(isTrue) return s[i] == 'T';
		else return s[i] == 'F';
	}
	
	if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];

	int ans = 0;
	// k-loop scheme
	for(int k = i+1;k<=j-1;k+=2){
		// all these are temp ans
		int lt, lf, rt, rf;
		
		// l --> i to k-1 
		lt = solve_partition(s,i,k-1,true);
		lf = solve_partition(s,i,k-1,false);
		// r --> k+1 to j
		rt = solve_partition(s,k+1,j,true);
		rf = solve_partition(s,k+1,j,false);
	
		// get main ans from temp ans...
		if(s[k]=='&'){
			if(isTrue) ans += (lt*rt);
			else ans += (lf*rt+lt*rf+lf*rf);
		}else if(s[k]=='|'){
			if(isTrue) ans += (lf*rt+lt*rf+lt*rt);
			else ans += (lf*rf);
		}else if(s[k]=='^'){
			if(isTrue) ans += (lf*rt + lt*rf);
			else ans += (lt*rt + lf*rf);
		}
	}
	return t[i][j][isTrue] = ans % 1003;
}
int countWays(int n, string s){
    memset(t, -1, sizeof(t));
    return solve(s,0,n-1,true);
}

// all test cases passed 
```

### Scrambled String ( Chod ques 🔥)

#### Scrambled String Recursive 

```embed
title: "watch?v=SqA0o-DGmEw"
image: "https://img.youtube.com/vi/SqA0o-DGmEw/maxresdefault.jpg"
description: "Scramble String using Recursion Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. Below is one possible representation of A = “great”: great / \\ gr eat / \\ / \\ g r e at / \\ a t To scramble the string, we may choose any non-leaf node and swap its two children. For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”. rgeat / \\ rg eat / \\ / \\ r g e at / \\ a t We say that “rgeat” is a scrambled string of “great”. Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”. rgtae / \\ rg tae / \\ / \\ r g ta e / \\ t a We say that “rgtae” is a scrambled string of “great”. PROBLEM STATEMENT LINK:https://www.interviewbit.com/problems/scramble-string/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40"
```

![[704197e5f2d519bddd5176349f8ee6fa_MD5.jpg]]

- We have two cases, one in which swapping is done and other where swapping is not done. 
- For case 1, when swapping is done: 
```cpp 
// check if a.first and b.last && a.last and b.first are scrambled...
if(solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i), sb.substr(0,n-i)))
	
```
- For case 2, when no swapping is done: 
```cpp 
// check if a.first and b.first && a.last and b.first are scrambled 
if(solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)))
```
- If any of the above case is true, then we have scrambled strings. 

- Base Condition: 
```cpp 
// addn conditions -- call in the main itself 
if(a.length()!=b.length()) return false;
if(a==b) return true; 

// base condition -- stop when the string comparsion is equal 
if(a.compare(b)==0) // a and b are equal length
	return true;

// empty str is not allowed as per constraints 
if(a.length()<=1 || b.length()<=1) return false;
// since length of both a and b is same in the solve function --> 
if(a.length() <= 1) return false;
```

- code from video
```cpp 

bool solve (string a, string b){
	if(a.compare(b)==0) return true;
	if(a.length()<=1) return false;
	int n = a.length();
	bool flag = false;

	for(int i = 1; i<n; i++){
		if((solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i))) or 
		   (solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)))){
			   flag = true; 
			   break;
		}   
	}
	return flag;
}

int main(){
	if(a.length()!=b.length()) return false;
	if(a==b) return true;
	solve(a,b);
}
```

#### Scrambled String Memoized 

```embed
title: "watch?v=VyHEglhbm-A?si=1is2KkWOQT_6LB-t"
image: "https://img.youtube.com/vi/VyHEglhbm-A/maxresdefault.jpg"
description: "Scramble String using Memoization(Dynamic Programming) Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. Below is one possible representation of A = “great”: great / \\ gr eat / \\ / \\ g r e at / \\ a t To scramble the string, we may choose any non-leaf node and swap its two children. For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”. rgeat / \\ rg eat / \\ / \\ r g e at / \\ a t We say that “rgeat” is a scrambled string of “great”. Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”. rgtae / \\ rg tae / \\ / \\ r g ta e / \\ t a We say that “rgtae” is a scrambled string of “great”. PROBLEM STATEMENT LINK:https://www.interviewbit.com/problems/scramble-string/ Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://youtu.be/VyHEglhbm-A?si=1is2KkWOQT_6LB-t"
```


- the changing variables here are string a and string b itself. 
- we will make a key `a_b` and store the corresponding value in the map. 
```cpp
// code from video 
unordered_map<string,bool> mp;
bool solve (string a, string b){
	if(a.compare(b)==0) return true;
	if(a.length()<=1) return false;
	int n = a.length();
	
	string key = a + " " + b;
	if(mp.find(key)!=mp.end()) return mp[key];
	bool flag = false;

	for(int i = 1; i<n; i++){
		if((solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i))) or 
		   (solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)))){
			   flag = true; 
			   break;
		}   
	}
	return mp[key] = flag;
}

int main(){
	if(a.length()!=b.length()) return false;
	if(a==b) return true;
	solve(a,b);
}
```
#### Scrambled String ques 

```embed
title: "Scrambled String | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two strings&nbsp;S1&nbsp;and&nbsp;S2&nbsp;of equal length, the task is to determine if S2 is a scrambled form of S1. Scrambled string:&nbsp;Given string&nbsp;str, we can represent it as a binary tree&nbsp;by partitioning it into two non-empty s"
url: "https://www.geeksforgeeks.org/problems/scrambled-string/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp 
// recursive code
  bool solve (string a, string b){ 	
    	if(a.compare(b)==0) return true;
    	if(a.length()<=1) return false;
    	int n = a.length();
        
    	for(int i = 1; i<n; i++){
    		if((solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i))) or 
    		   (solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)))){
    			  return true;
    		}   
    	}
    	return false;
    }
    
    bool isScramble(string a, string b){
        if(a.length()!=b.length()) return false;
	    if(a==b) return true;
	    return solve(a,b);
    }    

// gives tle
```

```cpp 
// optimized 
unordered_map<string,bool> mp;
bool solve (string a, string b){
	if(a.compare(b)==0) return true;
	if(a.length()<=1) return false;
	int n = a.length();
	
	string key = a + " " + b;
	if(mp.find(key)!=mp.end()) return mp[key];
	bool flag = false;

	for(int i = 1; i<n; i++){
		if((solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i), b.substr(0,n-i))) or 
		   (solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i), b.substr(i,n-i)))){
			   flag = true; 
			   break;
		}   
	}
	return mp[key] = flag;
}
bool isScramble(string a, string b){
	if(a.length()!=b.length()) return false;
	if(a==b) return true;
	return solve(a,b);
}    
```

### Egg Dropping Problem 

#### Egg Dropping Problem Recursive
```embed
title: "YouTube"
image: "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAeAAAAFoCAYAAACPNyggAAAOn0lEQVR4Xu3VsQnDQBBFwd3AakTuv8UTOHQuXjJXwC0MH97OzBmPAAECBAgQeFVgd+ecM/f9nev6zArwq94+J0CAAAECPwEBNgQCBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBAQYBsgQIAAAQKBgAAH6E4SIECAAAEBtgECBAgQIBAICHCA7iQBAgQIEBBgGyBAgAABAoGAAAfoThIgQIAAAQG2AQIECBAgEAgIcIDuJAECBAgQEGAbIECAAAECgYAAB+hOEiBAgAABAbYBAgQIECAQCAhwgO4kAQIECBD4D/ADV99NUy08rgcAAAAASUVORK5CYII="
description: "Share your videos with friends, family, and the world"
url: "https://youtu.be/S49zeUjeUL0?si=yxxpWUA5Dj4GejFx"
```
- k loop `for ( k = 1 to f)`
- Base Condition -- smallest valid input
```cpp 
if(egg == 1 || floor == 0 || floor = 1) return f;
```

![[3c37080e12e0da699258fae552a8effd_MD5.jpg]]

```cpp 
// code from video 
// recursive 
int solve (int e, int f){
	// base condition 
	if(f==0||f==1) return f;
	if(e==1) return f;

	int m_atmpt = INT_MAX;

	for(int k = 1; k<=f;k++){
		int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
		m_atmpt = min(m_atmpt, atmpt);
	}
		return min;
}
```
- the critical floor can be the last floor , which is the worst case, we have to find the min numbers of attempts in that case also, therefore we take the max of the two calls.
#### Egg Dropping Problem Memoization 

```embed
title: "YouTube"
image: "https://img.youtube.com/vi/gr2NtY-2QUY/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=gr2NtY-2QUY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=43"
```

- the dimensions of the matrix depend on the number of changing variables.

```cpp 
// code from video 
int static t[201][201];
int solve (int e, int f){
	// base condition 
	if(f==0||f==1) return f;
	if(e==1) return f;

	if(t[e][f]!=-1) return t[e][f];
	int m_atmpt = INT_MAX;

	for(int k = 1; k<=f;k++){
		int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
		m_atmpt = min(m_atmpt, atmpt);
	}
	return t[e][f] = m_atmpt;
}

int main(){
	memset(t,-1,sizeof(t));
	solve(e,f);
}
```

#### Egg Dropping Problem Optimization 
```embed
title: "YouTube"
image: "https://img.youtube.com/vi/jkygQmOiCCI/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=jkygQmOiCCI&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=44"
```

- check for each function call 

```cpp 
// code from video 
int t[201][201];
int solve (int e, int f){
	// base condition 
	if(f==0||f==1) return f;
	if(e==1) return f;

	if(t[e][f]!=-1) return t[e][f];
	int m_atmpt = INT_MAX;

	for(int k = 1; k<=f;k++){
		//int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
		int low, high;
		
		if(t[e-1][k-1]!=-1){
			low = t[e-1][k-1];
		}else{
			low = solve(e-1,k-1);
			t[e-1][k-1] = low;
		} 
		if(t[e][f-k]!=-1){
			high = t[e][f-k];
		}else{
			high = solve(e,f-k);
			t[e][f-k] = high;
		}
		
		int atmpt = 1 + max(low, high);// because we have to find worst case scenario 
		m_atmpt = min(m_atmpt, atmpt);
	}
	return t[e][f] = m_atmpt;
}

int main(){
	memset(t,-1,sizeof(t));
	solve(e,f);
}
```
#### Egg Dropping Problem Ques

```embed
title: "Egg Dropping Puzzle | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given N identical eggs and you have access to a K-floored building from&nbsp;1&nbsp;to&nbsp;K. There exists a floor f&nbsp;where 0 &lt;= f &lt;= K&nbsp;such that any egg dropped from a floor higher than f&nbsp;will break, and any egg dropped"
url: "https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1"
```

```cpp 
// recursive 
 int solve (int e, int f){
    	// base condition 
    	if(f==0||f==1) return f;
    	if(e==1) return f;
    
    	int mAtmpt = INT_MAX;
    
    	for(int k = 1; k<=f;k++){
    		int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
    		mAtmpt = min(mAtmpt, atmpt);
    	}
    		return mAtmpt;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        return solve(n,k);
    }
// gives TLE 
// find the TC later 
```

```cpp
// memoized 
int t[201][201];
int solve (int e, int f){
	// base condition 
	if(f==0||f==1) return f;
	if(e==1) return f;

	if(t[e][f]!=-1) return t[e][f];
	int m_atmpt = INT_MAX;

	for(int k = 1; k<=f;k++){
		int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
		m_atmpt = min(m_atmpt, atmpt);
	}
	return t[e][f] = m_atmpt;
}

int eggDrop(int n, int k) 
{
	// your code here
	memset(t,-1,sizeof(t));
	return solve(n,k);
}
```

```cpp 
// memoized optimized code 
//Function to find minimum number of attempts needed in 
//order to find the critical floor.
int  t[201][201];
int solve (int e, int f){
	// base condition 
	if(f==0||f==1) return f;
	if(e==1) return f;

	if(t[e][f]!=-1) return t[e][f];
	int m_atmpt = INT_MAX;

	for(int k = 1; k<=f;k++){
		//int atmpt = 1 + max(solve(e-1,k-1), solve(e,f-k));
		int low, high;
		
		if(t[e-1][k-1]!=-1){
			low = t[e-1][k-1];
		}else{
			low = solve(e-1,k-1);
			t[e-1][k-1] = low;
		} 
		if(t[e][f-k]!=-1){
			high = t[e][f-k];
		}else{
			high = solve(e,f-k);
			t[e][f-k] = high;
		}
		
		int atmpt = 1 + max(low, high);// because we have to find worst case scenario 
		m_atmpt = min(m_atmpt, atmpt);
	}
	return t[e][f] = m_atmpt;
}

int eggDrop(int n, int k) 
{
	// your code here
	memset(t,-1,sizeof(t));
	return solve(n,k);
}
```


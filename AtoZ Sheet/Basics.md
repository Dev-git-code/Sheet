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
## Basic Math

### 1. Count Digits

```embed
title: "Count Digits | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a natural number n. You have to find the number of digits in it and return it. Examples: Input: n = 12 Output: 2 Explanation: 12 has 2 digits Input: n = 456Output: 3Explanation: 456 has 3 digits Constraints:1 &lt;= n &lt;= 105 "
url: "https://www.geeksforgeeks.org/problems/count-digits-1606889545/1"
favicon: ""
aspectRatio: "100"
```

**3 approaches:** 
1. while loop 
2. recursion 
3. convert to string

```cpp 
string str = to_string(n)
```

---

### 2. Reverse Integer

```embed
title: "Reverse Integer - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Reverse Integer - Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).     Example 1:   Input: x = 123 Output: 321   Example 2:   Input: x = -123 Output: -321   Example 3:   Input: x = 120 Output: 21      Constraints:   * -231 <= x <= 231 - 1"
url: "https://leetcode.com/problems/reverse-integer/"
favicon: ""
aspectRatio: "52"
```

#### ✅ Function Purpose
Reverse digits of a 32-bit signed integer `x`. If the reversed number overflows, return `0`.

#### 🧠 Key Logic Summary
```cpp
while (x != 0):
    - Get last digit using x % 10
    - Check if ans will overflow after *10 and +digit
    - Update ans = ans * 10 + digit
    - Remove last digit from x using x / 10
```

#### 🔐 Overflow Check
```cpp
if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
```
- Prevents overflow **before** multiplying by 10
- Covers both positive and negative bounds

#### ✅ What You Learned
- **How to reverse an integer digit by digit**
- **How to detect integer overflow before it happens**
- **Why using `string` or `stoi()` is less safe for this problem**
- Efficient use of **math instead of strings**

#### ⚠️ What to Remember
- Always **check overflow before math operations** (not after)
- `INT_MAX = 2,147,483,647`, `INT_MIN = -2,147,483,648`
- Don't use `stoi()` or string-based reversal if precision and range safety is required

```cpp 
int reverse(int x) {
    int ans = 0; //-123
    while(x!=0){
        int digit = x%10; 
        if(ans<INT_MIN/10 || ans>INT_MAX/10) return 0;
        ans = ans*10 + digit;
        x = x/10;
    }
    return ans;
}
```

---

### 3. Palindrome Number

```embed
title: "Palindrome Number - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Palindrome Number - Given an integer x, return true if x is a palindrome, and false otherwise.     Example 1:   Input: x = 121 Output: true Explanation: 121 reads as 121 from left to right and from right to left.   Example 2:   Input: x = -121 Output: false Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.   Example 3:   Input: x = 10 Output: false Explanation: Reads 01 from right to left. Therefore it is not a palindrome.      Constraints:   * -231 <= x <= 231 - 1     Follow up: Could you solve it without converting the integer to a string?"
url: "https://leetcode.com/problems/palindrome-number/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
bool isPalindrome(int x) {
    int org_x = x;
    if(x<0) return false;

    long long ans = 0; 
    while(x!=0){
        ans = ans*10 + x%10;
        x = x/10;
    }

    if(ans == org_x) return true;
    return false;
}
```

#### ⚠️ What to Remember
- When reversing a int use long long as datatype as the reverse value can surpass int.

**TO DO:** Half reversal technique

---

### 4. GCD of Two Numbers

```embed
title: "GCD of two numbers | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given two positive integers a and b, find GCD of a and b. Note: Don't use the inbuilt gcd function Examples: Input: a = 20, b = 28 Output: 4 Explanation: GCD of 20 and 28 is 4 Input: a = 60, b = 36 Output: 12 Explanation: GCD of 60 and 36 is 12 Const"
url: "https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1"
favicon: ""
aspectRatio: "100"
```

#### 📌 Recursive GCD Using Subtraction
```cpp
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}
```

#### 🧠 Key Concepts
* **Base cases**:
  * `gcd(a, 0) = a`
  * `gcd(0, b) = b`
  * `gcd(a, a) = a`

* **Math property used (inductive step)**:
  * `gcd(a, b) = gcd(a - b, b)` if `a > b`
  * `gcd(a, b) = gcd(a, b - a)` if `b > a`

* **Hypothesis-based recursion**:
  Assume `gcd(x, y)` works for smaller values → use that to solve bigger ones.

#### ✅ What to Remember
* Subtract smaller from larger → problem size reduces each step
* Recursion stops at base case
* Math property = your inductive rule

---

### 5. Armstrong Numbers

```embed
title: "Armstrong Numbers | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given a 3-digit number n, Find whether it is an Armstrong number or not. An&nbsp;Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself.&nbsp;371 is an&nbsp;Armstrong number&nbs"
url: "https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
bool armstrongNumber(int n) {
    int x = n;
    long long ans = 0;
    while(x!=0){
        ans +=  pow(x%10, 3);
        x = x/10;
    }
   
    if(ans == n) return true;
    return false;
}
```

#### ✅ What to Remember
- Use `pow(base, exponent)` for power and not `^`.

### 6. All divisors of a Number

```embed
title: "All divisors of a Number | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given an integer n,&nbsp;print all the divisors of N in the&nbsp;ascending order.&nbsp;Examples: Input : n = 20 Output: 1 2 4 5 10 20 Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.  Input: n = 21191 Output: 1 21191 Explanation: As "
url: "https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
// if unable to understand solution read article from gfg
// this can also find if a number is prime (if lenght of ans is 2)
void print_divisors(int n) {
       vector<int> ans;
       for(int i = 1;i<=sqrt(n);i++){
           if(n%i ==0){
               if(n/i==i) ans.push_back(i);
               else{
                   ans.push_back(i);
                   ans.push_back(n/i);
               }
           }
           
       }
       
       sort(ans.begin(),ans.end());
       for(int i = 0;i<ans.size();i++){
           cout << ans[i] << " ";
       }
```

## Basic Recursion 

### 1. Reverse Array using Recursion

```embed
title: "Reverse an Array | Practice | GeeksforGeeks "
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "You are given an array of integers&nbsp;arr[]. Your task is to&nbsp;reverse the given array. Note:&nbsp;Modify the array in place. Examples: Input: arr = [1, 4, 3, 2, 6, 5] Output: [5, 6, 2, 3, 4, 1]Explanation: The elements of the array are 1 4 3 2 "
url: "https://www.geeksforgeeks.org/problems/reverse-an-array/1"
favicon: ""
aspectRatio: "100"
```

```cpp 
void rec_rev_arr(int b_idx, vector<int> &arr){
        int size = arr.size();
        if(b_idx < size/2) return;
       
        int tmp = arr[b_idx];
        arr[b_idx] = arr[size-b_idx-1];
        arr[size - b_idx-1] = tmp;
        
        rec_rev_arr(b_idx-1, arr);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        rec_rev_arr(arr.size()-1, arr);
    }
```


## Hashing 

```embed
title: "Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course"
image: "https://i.ytimg.com/vi/KEs5UyBJ39g/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://youtu.be/KEs5UyBJ39g?si=xWPN6-ylTDWruLI4"
favicon: ""
aspectRatio: "56.25"
```

### 1. Frequency of the Most Frequent Element

```embed
title: "Frequency of the Most Frequent Element - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Frequency of the Most Frequent Element - The frequency of an element is the number of times it occurs in an array.  You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.  Return the maximum possible frequency of an element after performing at most k operations.     Example 1:   Input: nums = [1,2,4], k = 5 Output: 3 Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4]. 4 has a frequency of 3.  Example 2:   Input: nums = [1,4,8,13], k = 5 Output: 2 Explanation: There are multiple optimal solutions: - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2. - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2. - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.   Example 3:   Input: nums = [3,9,6], k = 2 Output: 1      Constraints:   * 1 <= nums.length <= 105  * 1 <= nums[i] <= 105  * 1 <= k <= 105"
url: "https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/"
favicon: ""
aspectRatio: "52"
```

#### Brute Force using hashing
```cpp 
 int maxFrequency(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max_freq = 0;
        for(const auto& pair:mp){
            map<int,int> temp = mp;
            int check_key = pair.first;
            int rem_k = k;
			
            for(auto it=temp.rbegin(); it!=temp.rend();it++){
                int key = it->first;
                if(key<check_key){
                    int ops_needed = check_key -key;
                    while(temp[key]>0 && rem_k >= ops_needed){
                        temp[key]--;
                        temp[check_key]++;
                        rem_k -= ops_needed;
                    }
                }
            }

            max_freq = max(max_freq, temp[check_key]);
        }
        return max_freq;
    }
```

NOTE : Better approach is sliding window, include it in the sliding window section with approach.








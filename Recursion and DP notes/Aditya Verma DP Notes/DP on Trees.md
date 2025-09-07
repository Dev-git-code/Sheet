```table-of-contents
title: 
style: nestedList # TOC style (nestedList|inlineFirstLevel)
minLevel: 0 # Include headings from the specified level
maxLevel: 0 # Include headings up to the specified level
includeLinks: true # Make headings clickable
debugInConsole: false # Print debug info in Obsidian console
```
## General Syntax 
```embed
title: "watch?v=d1u2t018Kjg"
image: "https://img.youtube.com/vi/d1u2t018Kjg/maxresdefault.jpg"
description: "General Syntax of Dp on Tree In this video we will learn about syntax of DP on Tree PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/dynamic... Playlist Link: https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=1&t=0s&ab_channel=AdityaVerma . ------------------------------------------------------------------------------------------ Here are some of the gears that I use almost everyday: 🖊️ : My Pen (Used in videos too): https://amzn.to/38fKSM1 👨🏻‍💻 : My Apple Macbook pro: https://amzn.to/3w8iZh6 💻 : My gaming laptop: https://amzn.to/3yjcn23 📱 : My Ipad: https://amzn.to/39yEMGS ✏️ : My Apple Pencil: https://amzn.to/3kMnKYf 🎧 : My Headphones: https://amzn.to/3kMOzM7 💺 : My Chair: https://amzn.to/385weqR 🛋 : My Table: https://amzn.to/3kMohtd ⏰ : My Clock: https://amzn.to/3slFUV3 🙋🏻‍♀️ : My girlfriend: https://amzn.to/3M6zLDK ¯\\_(ツ)_/¯ PS: While having good gears help you perform efficiently, don’t get under the impression that they will make you successful without any hard work."
url: "https://www.youtube.com/watch?v=d1u2t018Kjg"
```

```cpp 
int solve(Node* root, int& res){

	// base condition 
	if(root == nullptr) return 0;

	// hypothesis
	int l = solve(root -> left, res);
	int r = solve(root -> right, res);

	// Induction 
	int temp = calculate temp ans ( using l and r );
	int ans = max(temp, relation);
	// relation --> decides if temp is passed further or not to get ans 
	res = max (res, ans);
	return temp;
}

int main(){ 
	int res = INT_MIN;
	solve(root, res);
	return res;
}
```
## Diameter of the Binary Tree 
```embed
title: "48 Diameter of a Binary Tree"
image: "https://img.youtube.com/vi/zmPj_Ee3B8c/maxresdefault.jpg"
description: "Diameter of TreeGiven a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest p…"
url: "https://www.youtube.com/watch?v=zmPj_Ee3B8c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=47"
```

![[726c44317f5eae1d0cbadba3f857a731_MD5.jpg]]
- Each node has two choices here, either it can become part of the larger diameter or  it can become the main node for the diameter.
- From the above general syntax, the base condition and hypothesis never change, we only have to think about the induction and change the induction step. 
```cpp 
int solve(Node* root, int& res){

	// base condition 
	if(root == nullptr) return 0;

	// hypothesis
	int l = solve(root -> left, res);
	int r = solve(root -> right, res);

	// Induction 
	// when the current node becomes part of greater diameteer 
	int temp = 1 + max(l,r); 
	// when the current node becomes the main node of the diameter
	int ans = max(temp, 1 + l + r);
	// relation --> decides if temp is passed further or not to get ans 
	res = max (res, ans);
	// return temp as solve function gives the condition when current node becomes part of the greater diameter
	return temp;
}

int main(){ 
	int res = INT_MIN;
	solve(root, res);
	return res;
}
```

### Diameter of Binary Tree ques 
```embed
title: "Diameter of a Binary Tree | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that t"
url: "https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1"
```

```cpp 
// Function to return the diameter of a Binary Tree.
int solve(Node* root, int& res){
	if (root == nullptr) return 0;
	
	int l = solve(root->left, res);
	int r = solve(root->right, res);
	
	int temp = 1 + max(l,r);
	int ans = max(temp, 1+l+r);
	res = max(ans, res);
	return temp;
}
int diameter(Node* root) {
	// Your code here
	int res = INT_MIN;
	solve(root, res);
	return res;
}
```
- read articles to further learn more about this...

## Maximum Path Sum to any Node 
```embed
title: "49 Maximum Path Sum | From any node to any node"
image: "https://img.youtube.com/vi/Osz-Vwer6rw/maxresdefault.jpg"
description: "Given a non-empty binary tree, find the maximum path sum.For this problem, a path is defined as any sequence of nodes from some starting node to any node in…"
url: "https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=48"
```

![[ccd232ff6e818ec9b3c7dca3200814a6_MD5.jpg]]

```cpp 
// code from video 
int solve(Node* root, int& res){

	// base condition 
	if(root == nullptr) return 0;

	// hypothesis
	int l = solve(root -> left, res);
	int r = solve(root -> right, res);

	// Induction 
	int temp = max(max(l,r) + root -> value , root -> value)
	int ans = max(temp, l + r + root->value);
	// relation --> decides if temp is passed further or not to get ans 
	res = max (res, ans);
	return temp;
}

int main(){ 
	int res = INT_MIN;
	solve(root, res);
	return res;
}
```

### Maximum Path Sum to any Node ques 
```embed
title: "Maximum path sum from any node | Practice | GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Given a binary tree,&nbsp;the task is to find the maximum path sum. The path may start and end at any node in the tree. Example 1: Input: 10 &nbsp; / \\ &nbsp; 2 -25 &nbsp; / \\ / \\ &nbsp;20 1 3 4 Output: 32 Explanation: Path in the give"
url: "https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
```

```cpp 
//Function to return maximum path sum from any node in a tree.
int solve(Node* root, int& res){
	if(root == nullptr) return 0;
	
	int l = solve(root->left, res);
	int r = solve(root-> right, res);
	
	int temp = max(max(l,r)+root->data, root->data);
	int ans = max(temp , l+r+root->data);
	res = max(ans, res);
	return temp;
}
int findMaxSum(Node* root)
{
	int res = INT_MIN;
	solve(root,res);
	return res;	
}
```

## Maximum Path Sum to leaf Node 
```embed
title: "YouTube"
image: "https://img.youtube.com/vi/ArNyupe-XH0/maxresdefault.jpg"
description: "Share your videos with friends, family, and the world"
url: "https://www.youtube.com/watch?v=ArNyupe-XH0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=49"
```

```cpp 
// code from video 
int solve(Node* root, int& res){

	// base condition 
	if(root == nullptr) return 0;

	// hypothesis
	int l = solve(root -> left, res);
	int r = solve(root -> right, res);

	// Induction 
	int temp = max(l,r) + root-> value;
	if(root->left == nullptr && root->right == nullptr) 
		temp = max(temp, root->value);
	int ans = max(temp, relation);
	res = max (res, ans);
	return temp;
}

int main(){ 
	int res = INT_MIN;
	solve(root, res);
	return res;
}
```



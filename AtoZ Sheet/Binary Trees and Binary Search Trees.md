## Traversals ( Basic )
### 1. DFS Traversal

#### 1.1. Preorder Traversal

```embed
title: "L5. Preorder Traversal of Binary Tree | C++ | Java | Code Explanation"
image: "https://i.ytimg.com/vi/RlUu72JrOCQ/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=RlUu72JrOCQ"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Binary Tree Preorder Traversal - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Binary Tree Preorder Traversal - Given the root of a binary tree, return the preorder traversal of its nodes' values.     Example 1:  Input: root = [1,null,2,3]  Output: [1,2,3]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png]  Example 2:  Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]  Output: [1,2,4,5,6,7,3,8,9]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/tree_2.png]  Example 3:  Input: root = []  Output: []  Example 4:  Input: root = [1]  Output: [1]     Constraints:   * The number of nodes in the tree is in the range [0, 100].  * -100 <= Node.val <= 100     Follow up: Recursive solution is trivial, could you do it iteratively?"
url: "https://leetcode.com/problems/binary-tree-preorder-traversal/"
favicon: ""
aspectRatio: "52"
```

```cpp 
void preorder(TreeNode* root, vector<int>& res) {
	if (root == nullptr) return;

	// Root
	res.push_back(root->val);

	// Left
	preorder(root->left, res);

	// Right
	preorder(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	preorder(root, res);
	return res;
}
```

#### 1.2. Inorder Traversal

```embed
title: "L6. Inorder Traversal of Binary Tree | C++ | Java | Code Explanation"
image: "https://i.ytimg.com/vi/Z_NEgBgbRVI/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=Z_NEgBgbRVI"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Binary Tree Inorder Traversal - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Binary Tree Inorder Traversal - Given the root of a binary tree, return the inorder traversal of its nodes' values.     Example 1:  Input: root = [1,null,2,3]  Output: [1,3,2]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png]  Example 2:  Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]  Output: [4,2,6,5,7,1,3,9,8]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/tree_2.png]  Example 3:  Input: root = []  Output: []  Example 4:  Input: root = [1]  Output: [1]     Constraints:   * The number of nodes in the tree is in the range [0, 100].  * -100 <= Node.val <= 100     Follow up: Recursive solution is trivial, could you do it iteratively?"
url: "https://leetcode.com/problems/binary-tree-inorder-traversal/"
favicon: ""
aspectRatio: "52"
```

```cpp
void inorder(TreeNode* root, vector<int>& res){

	if(root == nullptr) return;

	inorder(root->left,res);
	res.push_back(root->val);
	inorder(root->right,res);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	inorder(root, res);
	return res;
}
```

#### 1.3. Postorder Traversal

```embed
title: "L7. Postorder Traversal of Binary Tree | C++ | Java | Code Explanation"
image: "https://i.ytimg.com/vi/COQOU6klsBg/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=COQOU6klsBg"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Binary Tree Postorder Traversal - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Binary Tree Postorder Traversal - Given the root of a binary tree, return the postorder traversal of its nodes' values.     Example 1:  Input: root = [1,null,2,3]  Output: [3,2,1]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png]  Example 2:  Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]  Output: [4,6,7,5,2,9,8,3,1]  Explanation:  [https://assets.leetcode.com/uploads/2024/08/29/tree_2.png]  Example 3:  Input: root = []  Output: []  Example 4:  Input: root = [1]  Output: [1]     Constraints:   * The number of the nodes in the tree is in the range [0, 100].  * -100 <= Node.val <= 100     Follow up: Recursive solution is trivial, could you do it iteratively?"
url: "https://leetcode.com/problems/binary-tree-postorder-traversal/"
favicon: ""
aspectRatio: "52"
```

```cpp 
void postorder(TreeNode* root, vector<int>& res){
	if(root == nullptr) return;
	postorder(root->left,res);
	postorder(root->right,res);
	res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	postorder(root,res);
	return res;
}
```

### 2. Level Order Traversal

```embed
title: "L8. Level Order Traversal of Binary Tree | BFS | C++ | Java"
image: "https://i.ytimg.com/vi/EoAsWbO7sqg/maxresdefault.jpg"
description: "Check out TUF+:https://takeuforward.org/plus?source=youtubeFind DSA, LLD, OOPs, Core Subjects, 1000+ Premium Questions company wise, Aptitude, SQL, AI doubt ..."
url: "https://www.youtube.com/watch?v=EoAsWbO7sqg"
favicon: ""
aspectRatio: "56.25"
```

```embed
title: "Binary Tree Level Order Traversal - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Binary Tree Level Order Traversal - Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).     Example 1:  [https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg]   Input: root = [3,9,20,null,null,15,7] Output: [[3],[9,20],[15,7]]   Example 2:   Input: root = [1] Output: [[1]]   Example 3:   Input: root = [] Output: []      Constraints:   * The number of nodes in the tree is in the range [0, 2000].  * -1000 <= Node.val <= 1000"
url: "https://leetcode.com/problems/binary-tree-level-order-traversal/"
favicon: ""
aspectRatio: "52"
```

```cpp 
vector<vector<int>> levelOrder(TreeNode* root) {

	vector<vector<int>> ans;
	if(root == NULL) return ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int s = q.size();
		vector<int> level;

		for(int i = 0;i<s;i++){
			TreeNode* node = q.front();
			q.pop();
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
			level.push_back(node->val);
		}
		ans.push_back(level);
	}

	return ans;
}
```

- Rest of the iteration will be done at last, they are just the complex solution of the same problem.

## Medium

### 1. Maximum Depth in Binary Tree

```embed
title: "Fetching"
image: "data:image/svg+xml;base64,PHN2ZyBjbGFzcz0ibGRzLW1pY3Jvc29mdCIgd2lkdGg9IjgwcHgiICBoZWlnaHQ9IjgwcHgiICB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAxMDAgMTAwIiBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJ4TWlkWU1pZCI+PGcgdHJhbnNmb3JtPSJyb3RhdGUoMCkiPjxjaXJjbGUgY3g9IjgxLjczNDEzMzYxMTY0OTQxIiBjeT0iNzQuMzUwNDU3MTYwMzQ4ODIiIGZpbGw9IiNlMTViNjQiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM0MC4wMDEgNDkuOTk5OSA1MCkiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49IjBzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9Ijc0LjM1MDQ1NzE2MDM0ODgyIiBjeT0iODEuNzM0MTMzNjExNjQ5NDEiIGZpbGw9IiNmNDdlNjAiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM0OC4zNTIgNTAuMDAwMSA1MC4wMDAxKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMDYyNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iNjUuMzA3MzM3Mjk0NjAzNiIgY3k9Ijg2Ljk1NTE4MTMwMDQ1MTQ3IiBmaWxsPSIjZjhiMjZhIiByPSI1IiB0cmFuc2Zvcm09InJvdGF0ZSgzNTQuMjM2IDUwIDUwKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMTI1cyI+PC9hbmltYXRlVHJhbnNmb3JtPgo8L2NpcmNsZT48Y2lyY2xlIGN4PSI1NS4yMjEwNDc2ODg4MDIwNyIgY3k9Ijg5LjY1Nzc5NDQ1NDk1MjQxIiBmaWxsPSIjYWJiZDgxIiByPSI1IiB0cmFuc2Zvcm09InJvdGF0ZSgzNTcuOTU4IDUwLjAwMDIgNTAuMDAwMikiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49Ii0wLjE4NzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9IjQ0Ljc3ODk1MjMxMTE5NzkzIiBjeT0iODkuNjU3Nzk0NDU0OTUyNDEiIGZpbGw9IiM4NDliODciIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDM1OS43NiA1MC4wMDY0IDUwLjAwNjQpIj4KICA8YW5pbWF0ZVRyYW5zZm9ybSBhdHRyaWJ1dGVOYW1lPSJ0cmFuc2Zvcm0iIHR5cGU9InJvdGF0ZSIgY2FsY01vZGU9InNwbGluZSIgdmFsdWVzPSIwIDUwIDUwOzM2MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiIGJlZ2luPSItMC4yNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iMzQuNjkyNjYyNzA1Mzk2NDE1IiBjeT0iODYuOTU1MTgxMzAwNDUxNDciIGZpbGw9IiNlMTViNjQiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDAuMTgzNTUyIDUwIDUwKSI+CiAgPGFuaW1hdGVUcmFuc2Zvcm0gYXR0cmlidXRlTmFtZT0idHJhbnNmb3JtIiB0eXBlPSJyb3RhdGUiIGNhbGNNb2RlPSJzcGxpbmUiIHZhbHVlcz0iMCA1MCA1MDszNjAgNTAgNTAiIHRpbWVzPSIwOzEiIGtleVNwbGluZXM9IjAuNSAwIDAuNSAxIiByZXBlYXRDb3VudD0iaW5kZWZpbml0ZSIgZHVyPSIxLjVzIiBiZWdpbj0iLTAuMzEyNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT4KPC9jaXJjbGU+PGNpcmNsZSBjeD0iMjUuNjQ5NTQyODM5NjUxMTc2IiBjeT0iODEuNzM0MTMzNjExNjQ5NDEiIGZpbGw9IiNmNDdlNjAiIHI9IjUiIHRyYW5zZm9ybT0icm90YXRlKDEuODY0NTcgNTAgNTApIj4KICA8YW5pbWF0ZVRyYW5zZm9ybSBhdHRyaWJ1dGVOYW1lPSJ0cmFuc2Zvcm0iIHR5cGU9InJvdGF0ZSIgY2FsY01vZGU9InNwbGluZSIgdmFsdWVzPSIwIDUwIDUwOzM2MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiIGJlZ2luPSItMC4zNzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxjaXJjbGUgY3g9IjE4LjI2NTg2NjM4ODM1MDYiIGN5PSI3NC4zNTA0NTcxNjAzNDg4NCIgZmlsbD0iI2Y4YjI2YSIgcj0iNSIgdHJhbnNmb3JtPSJyb3RhdGUoNS40NTEyNiA1MCA1MCkiPgogIDxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MzYwIDUwIDUwIiB0aW1lcz0iMDsxIiBrZXlTcGxpbmVzPSIwLjUgMCAwLjUgMSIgcmVwZWF0Q291bnQ9ImluZGVmaW5pdGUiIGR1cj0iMS41cyIgYmVnaW49Ii0wLjQzNzVzIj48L2FuaW1hdGVUcmFuc2Zvcm0+CjwvY2lyY2xlPjxhbmltYXRlVHJhbnNmb3JtIGF0dHJpYnV0ZU5hbWU9InRyYW5zZm9ybSIgdHlwZT0icm90YXRlIiBjYWxjTW9kZT0ic3BsaW5lIiB2YWx1ZXM9IjAgNTAgNTA7MCA1MCA1MCIgdGltZXM9IjA7MSIga2V5U3BsaW5lcz0iMC41IDAgMC41IDEiIHJlcGVhdENvdW50PSJpbmRlZmluaXRlIiBkdXI9IjEuNXMiPjwvYW5pbWF0ZVRyYW5zZm9ybT48L2c+PC9zdmc+"
description: "Fetching https://www.youtube.com/watch?v=eD3tmO66aBA"
url: "https://www.youtube.com/watch?v=eD3tmO66aBA"
favicon: ""
```

```embed
title: "Maximum Depth of Binary Tree - LeetCode"
image: "https://leetcode.com/static/images/LeetCode_Sharing.png"
description: "Can you solve this real interview question? Maximum Depth of Binary Tree - Given the root of a binary tree, return its maximum depth.  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.     Example 1:  [https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg]   Input: root = [3,9,20,null,null,15,7] Output: 3   Example 2:   Input: root = [1,null,2] Output: 2      Constraints:   * The number of nodes in the tree is in the range [0, 104].  * -100 <= Node.val <= 100"
url: "https://leetcode.com/problems/maximum-depth-of-binary-tree/description/"
favicon: ""
aspectRatio: "52"
```

```cpp 
int maxDepth(TreeNode* root) {
	if(root == NULL) return 0;

	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);

	return 1+max(lh, rh);
}
```
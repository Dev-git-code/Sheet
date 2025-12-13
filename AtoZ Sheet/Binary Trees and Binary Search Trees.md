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



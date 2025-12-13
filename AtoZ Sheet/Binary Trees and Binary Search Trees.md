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


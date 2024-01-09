#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Pre-order Traversal (Iterative)
void preOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        std::cout << node->val << " ";

        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }
}

// In-order Traversal (Iterative)
void inOrderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* curr = root;

    while (curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();

        std::cout << curr->val << " ";
        curr = curr->right;
    }
}

// Post-order Traversal (Iterative)
void postOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        stack1.pop();
        stack2.push(node);

        if (node->left) stack1.push(node->left);
        if (node->right) stack1.push(node->right);
    }

    while (!stack2.empty()) {
        std::cout << stack2.top()->val << " ";
        stack2.pop();
    }
}

// Level-order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        std::cout << node->val << " ";

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
    }
}

// Helper function to build a tree from pre-order and in-order traversal
TreeNode* buildTreePreIn(std::vector<int>& preorder, std::vector<int>& inorder, int& preIndex, int inStart, int inEnd, std::unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(preorder[preIndex++]);

    if (inStart == inEnd) return root;

    int inIndex = inMap[root->val];

    root->left = buildTreePreIn(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildTreePreIn(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

// Function to construct binary tree from given preorder and inorder traversal
TreeNode* buildTreeFromPreIn(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    return buildTreePreIn(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
}

// Helper function to build a tree from post-order and in-order traversal
TreeNode* buildTreePostIn(std::vector<int>& postorder, std::vector<int>& inorder, int& postIndex, int inStart, int inEnd, std::unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(postorder[postIndex--]);

    if (inStart == inEnd) return root;

    int inIndex = inMap[root->val];

    root->right = buildTreePostIn(postorder, inorder, postIndex, inIndex + 1, inEnd, inMap);
    root->left = buildTreePostIn(postorder, inorder, postIndex, inStart, inIndex - 1, inMap);

    return root;
}

// Function to construct binary tree from given postorder and inorder traversal
TreeNode* buildTreeFromPostIn(std::vector<int>& postorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    int postIndex = postorder.size() - 1;
    return buildTreePostIn(postorder, inorder, postIndex, 0, inorder.size() - 1, inMap);
}

// Count the number of all nodes in a tree
int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count the number of leaf nodes in a tree
// Leaf nodes are nodes with no children
int countLeafNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Count the number of nodes with degree 2 in a tree
// Nodes with degree 2 are those with both left and right children
int countDegreeTwoNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = (root->left != nullptr && root->right != nullptr) ? 1 : 0;
    return count + countDegreeTwoNodes(root->left) + countDegreeTwoNodes(root->right);
}

// Calculate the height (depth) of a tree
// Height of a tree is the length of the longest path from the root to a leaf
int calculateHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int main() {
    // Sample traversals for testing
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    // Build trees from given traversals
    TreeNode* treeFromPreIn = buildTreeFromPreIn(preorder, inorder);
    TreeNode* treeFromPostIn = buildTreeFromPostIn(postorder, inorder);

    // Testing traversal methods
    std::cout << "Pre-order Traversal (Tree from Pre and In order): ";
    preOrderTraversal(treeFromPreIn);
    std::cout << "\nIn-order Traversal (Tree from Pre and In order): ";
    inOrderTraversal(treeFromPreIn);
    std::cout << "\nPost-order Traversal (Tree from Pre and In order): ";
    postOrderTraversal(treeFromPreIn);
    std::cout << "\nLevel-order Traversal (Tree from Pre and In order): ";
    levelOrderTraversal(treeFromPreIn);
    std::cout << "\n";

    std::cout << "Pre-order Traversal (Tree from Post and In order): ";
    preOrderTraversal(treeFromPostIn);
    std::cout << "\nIn-order Traversal (Tree from Post and In order): ";
    inOrderTraversal(treeFromPostIn);
    std::cout << "\nPost-order Traversal (Tree from Post and In order): ";
    postOrderTraversal(treeFromPostIn);
    std::cout << "\nLevel-order Traversal (Tree from Post and In order): ";
    levelOrderTraversal(treeFromPostIn);
    std::cout << "\n";

    return 0;
}


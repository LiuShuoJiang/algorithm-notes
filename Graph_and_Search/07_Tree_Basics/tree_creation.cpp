#include <iostream>
#include <queue>

// Define the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Insert a node in the binary tree
    /*
    insert a new node with a given value into the binary tree 
    following a level-order approach, 
    meaning the node is added
    at the first available position from left to right
    */
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                break;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Pre-order Traversal
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // In-order Traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Post-order Traversal
    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }

    // Level-order Traversal
    void levelOrderTraversal() {
        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            std::cout << temp->data << " ";

            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }

    // Height of the tree
    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    // Perform traversals
    std::cout << "Pre-order Traversal: ";
    tree.preOrderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "In-order Traversal: ";
    tree.inOrderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    tree.postOrderTraversal(tree.root);
    std::cout << std::endl;

    std::cout << "Level-order Traversal: ";
    tree.levelOrderTraversal();
    std::cout << std::endl;

    // Display the height of the tree
    std::cout << "Height of the tree: " << tree.height(tree.root) << std::endl;

    return 0;
}

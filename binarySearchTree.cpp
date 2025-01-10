#include<iostream>
#include<string>

using namespace std;


class TreeNode{
    
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int v): value(v), left(nullptr), right(nullptr) {}
    
};

class BinarySearchTree{
    
    public:
        TreeNode* root;
        
        BinarySearchTree(): root(nullptr) {}
        
        void insert(int value){
            
            root = insertNode(root, value);
        }
        
        TreeNode* insertNode(TreeNode* node, int value){
            
            if(node == nullptr){
                
                return new TreeNode(value);
            }
            
            if(value > node -> value){
                
                // Move towards the right of the tree.
                node -> right = insertNode(node -> right, value);
            }
            else{
                
                // Move towards the left of the tree.
                node -> left = insertNode(node -> left, value);
            }
            
            return node;
        }
        
        void remove(int value){
            
            root = removeNode(root, value);
        }
        
        TreeNode* removeNode(TreeNode* node, int value){
            
            if(node == nullptr){
                return nullptr; // value is not found in the tree
            }
            
            if(value > node -> value){
                
                // check the right side of the TreeNode
                node -> right = removeNode(node -> right, value);
            }
            else if(value < node -> value){
                
                // Check the left side of the TreeNode
                node -> left = removeNode(node -> left, value);
            }
            else{
                
                // Found the node to be deleted
                
                // Case 1: Node with only one child or no child.
                if(node -> left == nullptr){
                    
                    TreeNode* tempNode = node -> right;
                    delete node;
                    return tempNode;
                }
                else if(node -> right = nullptr){
                    TreeNode* tempNode = node -> left;
                    delete node;
                    return tempNode;
                }
                
                // Case 2: Node has two children.
                // Get the inorder successor: Smallest in the right subtree
                TreeNode* minValueNode = findMin(node -> right);
                
                // Copy the inorder successor's content to this node.
                node -> value = minValueNode -> value;
                
                // Delete the inorder successor
                node -> right = removeNode(node -> right, minValueNode -> value);
                
            }
            
            return node; // return the unchanged node.
            
        }
        
        TreeNode* findMin(TreeNode* node){
            if(node == nullptr){
                
                return nullptr; // If the subtree is empty, then return nullptr
            }
            
            while(node -> left != nullptr){
                
                // keep moving to the left
                node = node -> left;
            }
            return node; // return the leftmost node, which should be the min node.
            
            
        }
        
        void inorderTraversal() {
            
            inorderHelper(root);
            std::cout << std::endl;
            
        }
        
        void inorderHelper(TreeNode* node) {
            
            if (node != nullptr) {
                
                inorderHelper(node->left);
                std::cout << node->value << " ";
                inorderHelper(node->right);
                
            }
            
        }
    
};

int main()
{
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    
    std::cout << "Initial BST (Inorder): ";
    bst.inorderTraversal();
    
    bst.remove(10);  // Remove node with one child
    std::cout << "BST after removing 10: ";
    bst.inorderTraversal();
    
    bst.remove(3);   // Remove node with two children
    std::cout << "BST after removing 3: ";
    bst.inorderTraversal();
    
    bst.remove(1);   // Remove leaf node
    std::cout << "BST after removing 1: ";
    bst.inorderTraversal();
    
    return 0;
}

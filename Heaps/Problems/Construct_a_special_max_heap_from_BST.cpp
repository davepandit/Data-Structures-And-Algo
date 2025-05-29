// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void inorderTraversal(Node* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    void fillInPostOrderFashion(Node* root, vector<int>& inorder, int& i){
        if(root == NULL){
            return;
        }
        
        fillInPostOrderFashion(root->left, inorder, i);
        fillInPostOrderFashion(root->right, inorder, i);
        
        root->data = i < inorder.size() ? inorder[i] : root->data;
        // increase the count of i
        i++;
    }
    void convertToMaxHeapUtil(Node* root) {
        // We need to find the inorder traversal of the BST 
        // and then fill the inoorder traversal in the post order fashion
        
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        // now we can fill the data in the post order fashion 
        int index = 0;
        fillInPostOrderFashion(root, inorder, index);
    }
};

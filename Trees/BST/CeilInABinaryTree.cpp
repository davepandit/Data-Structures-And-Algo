// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;
    
    Node* node = root;
    int ans = -1;
    while(node != NULL){
        if(node->data >= input){
            // that can be a possible answer 
            ans = node->data;
            // eliminate the right search space 
            node = node->left;
        }
        else if(node->data < input){
            // eliminate the left search space 
            node = node->right;
        }
    }
    
    return ans;
    
}
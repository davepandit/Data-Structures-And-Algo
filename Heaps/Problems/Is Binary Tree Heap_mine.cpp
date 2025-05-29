// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool checkCompleteBinaryTree(Node* root){
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current == NULL) {
                nullSeen = true;
            } else {
                if (nullSeen) return false; // If we saw NULL before, this is not CBT
                q.push(current->left);
                q.push(current->right);
            }
        }
        return true;
    }
    bool checkHeapCondition(Node* root, int min, int max){
        if(root == NULL){
            return true;
        }
        
        if(root->data < min || root->data > max){
            return false;
        }
        
        // solve for the left part 
        bool lp = checkHeapCondition(root->left, INT_MIN, root->data);
        // solve for the right part
        bool rp = checkHeapCondition(root->right, INT_MIN, root->data);
        
        return lp && rp;
    }
    bool isHeap(Node* root) {
        // here we can use the same method that we used to check whether a binary 
        // tree is a bst or not 
        
        if(root == NULL){
            return true;
        }
        
        bool res = checkCompleteBinaryTree(root);
        bool ans = checkHeapCondition(root, INT_MIN, INT_MAX);
        
        return ans && res;
        
    }
};
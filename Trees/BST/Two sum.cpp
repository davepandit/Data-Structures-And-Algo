/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* node, vector<int>& inorder){
        if(node == NULL){
            return;
        }

        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        // we will first do the inorder traversal
        // and then use the two pointer approach 

        vector<int> inorder;
        inorderTraversal(root, inorder); 

        int low = 0, high = inorder.size() - 1;
        while(low < high){
            if(inorder[low] + inorder[high] == k){
                return true;
            }
            else if(inorder[low] + inorder[high] < k){
                // move the low right wards
                low = low + 1;
            }
            else if(inorder[low] + inorder[high] > k){
                // move the high left wards
                high = high - 1;
            }
        }

        return false;
    }
};
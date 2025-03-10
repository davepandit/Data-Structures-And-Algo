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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            // Algorithm 
            // 1. There can be multiple trees as the soln for this problem 
            // But we will try to add the target val to the node that has either the left node 
            // as null or the right node as null(basically kind of ekdum niche of the tree)
            // such that uske niche wala tree is not disturbed at all
            // 2. Loop till the node is valid
            // Rest of the algo is simple and requires some sort of  hit and trial to arrive
    
            TreeNode* node = root;
            // making one temp node, because baad me jake ise Node ke right me ya to left me we 
            // need to add the target node
            TreeNode* tempNode = root;
            while(node){
                if(node->val < val){
                    tempNode = node;
                    // move to the right 
                    node = node->right;
                }
                else if(node->val > val){
                    tempNode = node;
                    // move to the left 
                    node = node->left;
                }
            }
    
            // now we have the tempNode jiske ya to fir left me ya to fir right me 
            // we have to add the target Node
            TreeNode* tNode = new TreeNode(val);
            if(root == NULL){
                return tNode;
            }
            if(tempNode->val < val){
                tempNode->right = tNode;
            }
            else{
                tempNode->left = tNode;
            }
    
            // now return the root
            return root;
        }
    };
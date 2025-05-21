/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        // in order to find the max we need to go to the absolute right of the tree 
        Node* node = root;
        while(true){
            if(node->right == NULL){
                break;
            }
            // move the node 
            node = node->right;
        }
        // now we are at the correct position 
        // at the right most ele 
        return node->data;
    }

    int findMin(Node *root) {
        // here we need to return the absolute left most ele 
        Node* node = root;
        while(true){
            if(node->right == NULL){
                break;
            }
            // move the node 
            node = node->right;
        }
        // now we are at the absolute left of an ele 
        return node->data;
    }
};
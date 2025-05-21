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
        Node* node = root;
        int max = INT_MIN;
        // we will do a level order traversal and compare every ele and check for the mac
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            // take out the top ele 
            Node* node = q.front();
            q.pop();
            
            max = node->data > max ? node->data : max;
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        return max;
    }

    int findMin(Node *root) {
        // here also we will be doing a level order traverasl to find out the min ele
        Node* node = root;
        int min = INT_MAX;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            // take out the top most ele
            Node* node = q.front();
            q.pop();
            
            min = node->data < min ? node->data : min;
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        return min;
    }
};
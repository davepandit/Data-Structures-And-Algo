#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    // check whether the root is null or not
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    
    // push the root node to the queue
    q.push(root);

    // stop when the queue becomes empty
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            // pop out the front ele 
            Node* node = q.front();
            q.pop();

            // check whether the node has some left child or right child
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            // push the node ka value to the level vector 
            level.push_back(node->data);
        }
        // now we have the one level vector ready to be pushed into the ans vector
        ans.push_back(level);
    }


    return ans;

}

int main(){
    Node* root = new Node(1);
    vector<vector<int>> ans = levelOrderTraversal(root);
    return 0;
}
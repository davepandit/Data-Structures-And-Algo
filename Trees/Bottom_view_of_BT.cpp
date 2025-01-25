#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

vector<int> bottom_view(Node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    map<int, int> mpp;
    // the key is the vertical index and the value is the node ka value 
    queue<pair<Node*, int>> q;
    // the first one is the node itself and the second one is the vertical index of the node
    q.push({root, 0});

    while (!q.empty())
    {
        // take out the first one
        auto node = q.front();
        q.pop();

        mpp[node.second] = node.first->data;

        // then we can move on to the left and the right 
        if(node.first->left){
            q.push({node.first->left, node.second - 1});
        }
        if(node.first->right){
            q.push({node.first->right, node.second + 1});
        }
    }

    // now the mpp is ready 
    for(auto i : mpp){
        res.push_back(i.second);
    }

    return res;
    
}

int main(){
    Node* root = new Node(1);
    vector<int> ans = bottom_view(root);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i];
    }
    return 0;
}
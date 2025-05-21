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

vector<int> top_view(Node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    map<int, int> mpp;
    // key in the mao is the x axis value that is the vertical order and then value is the node ka value
    queue<pair<Node*, int>> q;
    // the first one being the node itself and the second one is the vertical index
    q.push({root, 0});

    while (!q.empty())
    {
        // take out the first ele 
        // and check whether that is there in the map
        // if the key is there in the map then dont insert
        auto node = q.front();
        // pop the ele 
        q.pop();
        if(mpp.find(node.second) == mpp.end()){
            // then the ele is not there in the map and we need to push it to the map
            mpp.insert({node.second, node.first->data});
        }
        // then move to the left and the right ele 
        if(node.first->left){
            q.push({node.first->left, node.second - 1});
        }

        if(node.first->right){
            q.push({node.first->right, node.second + 1});
        }
    }
    // now the mpp has all the top view ele in it 
    for(auto i : mpp){
        res.push_back(i.second);
    }

    return res;

}

int main(){
    Node* root = new Node(1);
    vector<int> ans = top_view(root);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i];
    }
    return 0;
}
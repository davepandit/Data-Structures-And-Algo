#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
        }
};

int solve(Node* root, int& maxi){
    if(root == NULL){
        return 0;
    }
    // calculate the left part ka sum and the right part ka sum 
    int left_part_sum = max(0, solve(root->left, maxi));
    int right_part_sum = max(0, solve(root->right, maxi));

    // setting the max
    maxi = max(maxi, root->data + left_part_sum + right_part_sum);
    return (root->data + max(left_part_sum, right_part_sum));
}

int max_path_sum(Node* root){
    if(root == NULL){
        return 0;
    }

    // this function will solve the rest 
    int maxi = 0;
    solve(root, maxi);

    return maxi;
}

int main(){
    Node* root = new Node(1);
    int ans = max_path_sum(root);
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BSTReverseIterator {
private:
    stack<Node*> st;

    // Push all rightmost nodes (similar to how we pushed leftmost for next())
    void pushRight(Node* node) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

public:
    // Constructor initializes the stack with rightmost nodes
    BSTReverseIterator(Node* root) {
        pushRight(root);
    }

    // Returns the previous largest element (inorder predecessor)
    int prev() {
        if (st.empty()) return -1; // Edge case: No more elements

        Node* node = st.top();
        st.pop();

        // If this node has a left subtree, push all its rightmost nodes
        if (node->left) {
            pushRight(node->left);
        }

        return node->data;
    }

    // Checks if there are more elements to process
    bool hasPrev() {
        return !st.empty();
    }
};

int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTReverseIterator it(root);

    while (it.hasPrev()) {
        cout << it.prev() << " ";
    }
    return 0;
}

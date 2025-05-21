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

class BSTIterator {
private:
    stack<Node*> st;

    // Helper function to push all left nodes onto the stack
    void pushLeft(Node* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor: Initialize stack with leftmost nodes
    BSTIterator(Node* root) {
        pushLeft(root);
    }

    // Returns next smallest element in BST
    int next() {
        if (st.empty()) return -1; // Edge case: No more elements

        Node* node = st.top();
        st.pop();

        // If this node has a right subtree, push all its left children
        if (node->right) {
            pushLeft(node->right);
        }

        return node->data;
    }

    // Checks if there are more elements to process
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator it(root);

    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    return 0;
}

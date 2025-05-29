class Solution {
  public:
    // Check if the tree is complete using level order traversal
    bool isCompleteTree(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current == NULL) {
                nullSeen = true;
            } else {
                if (nullSeen) return false; // If we saw NULL before, this is not CBT
                q.push(current->left);
                q.push(current->right);
            }
        }
        return true;
    }

    // Check max-heap property (parent >= children)
    bool isHeapUtil(Node* root) {
        if (!root) return true;

        if (root->left && root->data < root->left->data) return false;
        if (root->right && root->data < root->right->data) return false;

        return isHeapUtil(root->left) && isHeapUtil(root->right);
    }

    bool isHeap(Node* root) {
        return isCompleteTree(root) && isHeapUtil(root);
    }
};

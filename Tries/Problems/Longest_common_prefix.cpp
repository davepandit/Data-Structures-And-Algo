struct Node {
     // Array to store
     // links to child nodes
    Node* links[26];
     // Counter for number of
     // words that end at this node
    int cntEndWith = 0;
    // Counter for number of words
    // that have this node as a prefix
    int cntPrefix = 0; 

    Node(){
        for(int i = 0; i < 26; ++i){
            links[i] = nullptr; 
        }
    }
    // Function to check if the
    // node contains a specific key
    bool containsKey(char ch) {
        // Check if the link corresponding
        // to the character exists
        return (links[ch - 'a'] != NULL); 
    }

    // Function to get the child
    // node corresponding to a key
    Node* get(char ch) {
        // Return the link
        // corresponding to the character
        return links[ch - 'a']; 
    }

    // Function to insert a child
    // node with a specific key
    void put(char ch, Node* node) {
         // Set the link corresponding to
         // the character to the provided node
        links[ch - 'a'] = node;
    }

    // Function to increment the
    // count of words that end at this node
    void increaseEnd() {
        // Increment the counter
        cntEndWith++; 
    }

    // Function to increment the count of
    // words that have this node as a prefix
    void increasePrefix() {
         // Increment the counter
        cntPrefix++;
    }

    // Function to decrement the count
    // of words that end at this node
    void deleteEnd() {
        // Decrement the counter
        cntEndWith--; 
    }

    // Function to decrement the count of
    // words that have this node as a prefix
    void reducePrefix() {
        // Decrement the counter
        cntPrefix--; 
    }
};

// Define a class for the
// trie data structure
class Trie {
private:
    // Pointer to the
    // root node of the trie
    Node* root; 

public:
    // Constructor to initialize
    // the trie with an empty root node
    Trie() {
        // Create a new root node
        root = new Node(); 
    }

    // Function to insert
    // a word into the trie
    void insert(string word) {
        // Start from the root node
        Node* node = root; 
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
             // If the character is
             // not already in the trie
            if (!node->containsKey(word[i])) {
                // Create a new node
                // for the character
                node->put(word[i], new Node()); 
            }
             // Move to the child node
             // corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix
            // count for the node
            node->increasePrefix(); 
        }
        // Increment the end count
        // for the last node of the word
        node->increaseEnd(); 
    }

    // Function to count the number
    // of words equal to a given word
    int countWordsEqualTo(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                 // Return 0 if the
                 // character is not found
                return 0;
            }
        }
        // Return the count of
        // words ending at the node
        return node->cntEndWith; 
    }

    // Function to count the number of
    // words starting with a given prefix
    int countWordsStartingWith(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                // Return 0 if the
                // character is not found
                return 0; 
            }
        }
        // Return the count of
        // words with the prefix
        return node->cntPrefix; 
    }

    // Function to erase a
    // word from the trie
    void erase(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is
            // found in the trie
            if (node->containsKey(word[i])) { 
                 // Move to the child node
                 // corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix
                // count for the node
                node->reducePrefix(); 
            } else {
                // Return if the
                // character is not found
                return; 
            }
        }
        // Decrement the end count
        // for the last node of the word
        node->deleteEnd(); 
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // create an instance/object of the class Trie 
        Trie trie;
        int n = strs.size();

        // insert all the array ele into the trie 
        for(int i = 0; i < n; ++i){
            trie.insert(strs[i]);
        }

        // now we will iterate on the prefixes of the first word 
        // and check whether the count of the prefixes == the number of ele in the array 
        string prefix = "";
        string ans = "";
        for(int i = 0; i < strs[0].size(); ++i){
            prefix += strs[0][i];

            // find the count of this prefix in the trie using the count prefix function 
            if(trie.countWordsStartingWith(prefix) == n){
                // this can be a possible answer right 
                ans = prefix;
            };
        }

        // now we can return ans
        return ans;
    }
};
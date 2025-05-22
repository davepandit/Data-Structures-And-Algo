#include <bits/stdc++.h>
using namespace std;

struct Node
{
    // here every node has an array which is holding references to other nodes 
    Node* links[26];
    // flag variable 
    bool flag = false;

    Node(){
        for(int i = 0; i < 26; ++i){
            links[i] = nullptr; 
        }
    }
    
    // check if the node contians the specific key 
    bool containsKey(char ch){
        // just see if the pointer to that char in the links is pointing to null or what 
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    Node* get(char ch){
        return links[ch - 'a'];
    }

    // Set the current node
    // as the end of a word
    void setEnd(){
        flag = true;
    }

    // Check if the current node
    // marks the end of a word
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node* root;
    public:
        // Constructor to initialize the
        // Trie with an empty root node
        Trie(){
            root = new Node();
        }

        // Inserts a word into the Trie
        // Time Complexity O(len), where len
        // is the length of the word
        void insert(string word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                if(!node->containsKey(word[i])){
                    // if we reach here then links[word[i]] is pointing to null
                    // and we can add a reference node to this 
                    node->put(word[i], new Node);
                }
                // Move to the next node
                node = node->get(word[i]);
            }
            // mark the end of the word 
            node->setEnd();
        }

        // Returns if the word
        // is in the trie
        // search a word 
        bool search(string word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                if(!node->containsKey(word[i])){
                    // the first letter itself is not found 
                    return false;
                }

                // move to the next node 
                node = node->get(word[i]);
            }

            // for the word to exist the last reference's node flag should be true
            return node->isEnd();
        }

        // Returns if there is any word in the
        // trie that starts with the given prefix
        bool startsWith(string prefix) {
            Node* node = root;
            for (int i = 0; i < prefix.length(); i++) {
                if (!node->containsKey(prefix[i])) {
                    // If a letter is not found, there is
                    // no word with the given prefix
                    return false;
                }
                // Move to the next node
                node = node->get(prefix[i]);
            }
            // The prefix is found in the Trie
            return true;
        }
};

int main(){
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



struct Node{
    Node* links[26];
    bool flag;

    // contains key 
    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    // put
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    // get 
    Node* get(char ch){
        return links[ch - 'a'];
    }

    // set end 
    void setEnd(){
        flag = true;
    }

    // isEnd
    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
    public:
        Trie(){
            root = new Node();
            // mark all the links as false
            for(int i = 0; i < 26; ++i){
                root->links[i] = nullptr;
            }

            // mark the flag as false 
            root->flag = false;
        }
        // insert 
        void insert(string word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                // check of the character exists
                if(!node->containsKey(word[i])){
                    // if we reach here then the character doesnot exist 
                    node->put(word[i], new Node);
                }
                // move to the next node
                node = node->get(word[i]);
            }
            // if the word is inserted mark flag = true
            node->setEnd();
        }

        // check if the prefix exists 
        bool checkIfPrefixExists(string word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                node = node->get(word[i]);
                if(node->flag == false){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
};
class Solution {
public:
    string completeString(vector<string>& nums) {
        // algorithm 
        // make a trie from all the words that are given in the nums array 
        Trie trie; // instance of the class 
        for(int i = 0; i < nums.size(); ++i){
            trie.insert(nums[i]);
        }

        // so now we have made the trie
        // and now we need to check whether the prefixes exist or not
        string longest = "";

        for(auto it : nums){
            if(trie.checkIfPrefixExists(it)){
                if(it.length() > longest.length()){
                    longest = it;
                }
                else if(it.length() == longest.length() && it < longest){
                    longest = it;
                }
            }
        }

        if(longest == ""){
            return "None";
        }
    }
};

int main(){
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    // constructor
    Node(){
        for(int i = 0; i < 26; ++i){
            links[i] = nullptr;
        }
    }

    // we need to implement 5 functions 
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string& word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                if(!node->containsKey(word[i])){
                    // then we need to put the word 
                    node->put(word[i], new Node);
                }
                // move to the reference node 
                node = node->get(word[i]);
            }

            // once all the letters are processed then we can mark the flag as false 
            node->setEnd();
        }

        // search a word 
        // because the prefix of the word should exist as a word 
        bool search(string& word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                if(node->containsKey(word[i])){
                    // if the letter exists then move to the reference node 
                    node = node->get(word[i]);
                }else{
                    return false;
                }
            }
            // if we have processed all the nodes then we can just check for the flag 
            return node->flag;
        }
};

string longestWordWithAllPrefixes(vector<string>& strings){
    int n = strings.size();
    Trie trie;

    // insert all the ele of the array to the trie
    for(int i = 0; i < n; ++i){
        trie.insert(strings[i]);
    }

    // now we need to check every prefix of every string that whether it exists in the trie or not
    string ans = "";
    
    for(int i = 0; i < n; ++i){
        string prefix = "";
        for(int j = 0; j < strings[i].size(); ++j){
            prefix += strings[i][j];
            // now check whether this prefix exists or not 
            if(trie.search(prefix)){
                // then this can be one of the possible answers
                // because we need to find the longest 
                if(prefix.length() > ans.length()){
                    ans = prefix;
                }
                else if(prefix.length() == ans.length() && prefix < ans){
                    // if we do prefix < ans 
                    // then we are checking the lexicographical order 
                    ans = prefix;
                }
            }
            else {
                return "";
            }
        }

        // here we have the longest word 
        return ans;
    }
}

int main(){
    vector<string> strings = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    string ans = longestWordWithAllPrefixes(strings);
    cout << ans;
    return 0;
}
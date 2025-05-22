struct Node{
    Node* links[26];
    
    // we need to implement 5 functions here 
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    
    // put the ele 
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    // get the reference node 
    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
        Node* root;
        int count = 0;
    public:
        // constructor
        Trie(){
            root = new Node();
        }
        
        // insert an word 
        void insert(string& word){
            Node* node = root;
            for(int i = 0; i < word.length(); ++i){
                if(!node->containsKey(word[i])){
                    // then we need to put the word 
                    node->put(word[i], new Node());
                    // also increase the count
                    count = count + 1;
                }
                // get the reference node 
                node = node->get(word[i]);
            }
        }
        
        // return count 
        int getCount(){
            return count + 1;
        }
};
int countDistinctSubstring(string s) {
    // all the time we were given the array of substrings
    // which we are inserting into the trie 
    // but this time we need to insert the substrings if the string into the trie
    
    Trie trie;
    int n = s.size();
    
    // put all the substrings into the trie
    for(int i = 0; i < n; ++i){
        string prefix = "";
        for(int j = i; j < n; ++j){
            prefix += s[j];
            // insert into the trie 
            trie.insert(prefix);
        }
    }
    
    
    return trie.getCount();
}
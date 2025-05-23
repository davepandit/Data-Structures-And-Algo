struct Node{
    Node* links[2];

    // we need to implement 3 functions 

    // contains a bit or not 
    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    // put the bit 
    void put(int bit, Node* node){
        links[bit] = node;
    }

    // get the reference node 
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
        Node* root;
    public:

        // constructor
        Trie(){
            root = new Node();
        }

        // insert the num into the trie, but rememeber if we insert 9
        // then the binary representation of 9 which is 32 bit long will be stored

        void insert(int num){
            Node* node = root;
            // we know how to check whether a bit is a set bit or not
            // (num >> i) & 1
            // the same logic can be used to get the bit at some position i from the right

            for(int i = 31; i >= 0; --i){
                int bit = (num >> i) & 1;

                // check whether this bit is there ot not
                if(!node->containsKey(bit)){
                    // then we need to put that 
                    node->put(bit, new Node());
                }

                // move to the reference node 
                node = node->get(bit);
            }
        }

        // get max 
        int getMax(int num){
            int maxi = 0;
            Node* node = root;
            for(int i = 31; i >= 0; --i){
                int bit = (num >> i) & 1;

                // in order to maximise the result the xor operation we need to get !bit 
                if(node->containsKey(!bit)){
                    // if we can find the !bit 
                    // then we can turn that bit 
                    maxi = maxi | (1 << i);
                    node = node->get(!bit);
                }else{
                    node = node->get(bit);
                }
            }

            return maxi;
        }
};

class Solution {
public:
    int findMaximumXOR_with_x(vector<int>& nums, int x) {
        Trie trie;
        // insert all the ele of the array into the trie 
        for(auto it : nums){
            trie.insert(it);
        }

        // now we need to call the get max which will do the rest 
        int maxi = trie.getMax(x);

        cout << maxi;
    }
};
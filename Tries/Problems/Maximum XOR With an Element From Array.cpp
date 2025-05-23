struct Node{
    Node* links[2];

    // we will implement 3 functions 

    // contains key
    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    // get the reference node 
    Node* get(int bit){
        return links[bit];
    }

    // put into the trie
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
    private:
        Node* root;
    
    public:
        Trie(){
            root = new Node();
        }

        // insert into the trie
        void insert(int num){
            Node* node = root;
            for(int i = 31; i >=0; --i){
                // we can get the bit using the same logic that we use to check whether a bit is set or not
                int bit = (num >> i) & 1;

                // check if the bit exists 
                if(!node->containsKey(bit)){
                    // then we can put this into the trie
                    node->put(bit, new Node());
                }
                // move to the next reference node 
                node = node->get(bit);
            }
        }

        // get the max XOR 
        int getMax(int num){
            Node* node = root;
            int maxi = 0;

            for(int i = 31; i >= 0; --i){
                // get the bit of num
                int bit = (num >> i) & 1;

                // we need to check whether !bit exists or not 
                if(node->containsKey(!bit)){
                    // then we can set the bit of maxi
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // approach 
        // sort the array nums
        // make a vector<pair<int, pair<int, int>>> called as offline queries (oQ)
        // offline query ka structure means -> queries[i][1], queries[i][0], i
        // we need to make something as offline query because 
        // we want to sort the queries based on mi


        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;

        for(int i = 0; i < queries.size(); ++i){
            oQ.push_back({queries[i][1], {queries[i][0], i}});\
        }

        // now we can sort oQ based on mi
        sort(oQ.begin(), oQ.end());


        int n = nums.size();
        int q = oQ.size();
        Trie trie;
        int p = 0;
        vector<int> ans(q, -1);
        // now we can traverse over oQ and can make the trie
        bool inserted = false;
        for(int i = 0; i < q; ++i){
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qIndex = oQ[i].second.second;

            // insert into the trie
            while(p < n && nums[p] <= mi){
                // then only we can insert into the trie
                trie.insert(nums[p]);
                // move the p pointer 
                p++;
                inserted = true;
            }

            if(inserted){
                int max = trie.getMax(xi);
                ans[qIndex] = max;
            }else{
                ans[qIndex] = -1;
            }

        }


        return ans;
    }
};
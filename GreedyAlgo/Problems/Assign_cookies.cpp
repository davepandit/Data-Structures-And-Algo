class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // here we will be using the greedy method

        // sort the two arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // now we can use the two pointer approach 
        int first = 0; // this is to iterate on the array s
        int second = 0; // this is to iterate on the array g


        int childrenSatisfied = 0;
        while(first < s.size() && second < g.size()){
            if(s[first] >= g[second]){
                // then the children at the index second can be satisfied
                childrenSatisfied++;
                // move the first and the second pointer both 
                first++;
                second++;
            }
            else{
                // move the first pointer 
                first++;
            }
        }

        return childrenSatisfied;
    }
};
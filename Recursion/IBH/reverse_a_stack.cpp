// User function Template for C++

class Solution {
  public:
    void removeRemainingAndPutTop(stack<int>& st, int topEle){
        if(st.size() == 0){
            // simply we can put the top ele 
            st.push(topEle);
            return;
        }
        
        // remove the top
        int anotherTop = st.top();
        st.pop();
        
        removeRemainingAndPutTop(st, topEle);
        
        // push the anotherTop into the st
        st.push(anotherTop);
        
    }
    void solve(stack<int>& st){
        if(st.size() == 0){
            return;
        }
        
        // take out the top ele 
        int topEle = st.top();
        st.pop();
        
        solve(st);
        // take out the rest of the ele and put the topEle first and then again
        // put the ele jinko ki na humne nikala hai 
        removeRemainingAndPutTop(st, topEle);
        
    }
    void Reverse(stack<int> &st) {
        int n = st.size();
        
        solve(st);
    }
};
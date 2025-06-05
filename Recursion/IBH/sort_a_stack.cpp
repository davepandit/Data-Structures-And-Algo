#include <bits/stdc++.h>
using namespace std;


class SortedStack{
public:
    stack<int> s;
    // push into stack 
    void insertIntoStack(int ele){
        s.push(ele);
    }

    void print(){
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
    void insert(int);
    void solve();
    void sort();
    
};


/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack :: insert(int ele){
    if(s.size() == 0 || s.top() <= ele){
        // then we can insert the ele 
        s.push(ele);
        return;
    }
    
    // take out the last ele 
    int last = s.top();
    s.pop();
    
    // call again
    insert(ele);
    
    // now we can insert the last 
    s.push(last);
}
void SortedStack :: solve(){
    if(s.size() == 1){
        // then no need to sort because one ele is always sorted 
        return;
    }
    
    // take out the top ele 
    int ele = s.top();
    s.pop();
    
    // sort the rest of the stack 
    solve();
    
    // insert the ele into the correct position 
    insert(ele);
}
void SortedStack ::sort() {
    // using the IBH method 
    
    int n = s.size();
    
    solve();
    
}


int main(){
    SortedStack sortStack;

    sortStack.insertIntoStack(10);
    sortStack.insertIntoStack(34);
    sortStack.insertIntoStack(1);
    sortStack.insertIntoStack(3);
    sortStack.insertIntoStack(15);
    sortStack.sort();

    sortStack.print();
    return 0;

}
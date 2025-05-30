/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // brute force: using a map
        map<ListNode*, int> mpp;

        // traverse over the first linked list and insrt the node and 1 into the mpp
        // 1 signifies that the ele has been seen 

        ListNode* node = headA;
        while(node){
            mpp[node] = 1;
            // move the node 
            node = node->next;
        }

        // traverse over the other node and check if there is common node 
        node = headB;
        while(node){
            if(mpp.find(node) != mpp.end()){
                return node;
            }

            // move to the next
            node = node->next;
        }

        return NULL;
    }
};
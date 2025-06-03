/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // this will be used extensively to solve other problems 

        if(list1 == NULL && list2 == NULL){
            return NULL;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                // move the list1 pointer 
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                // move the list2 pointer 
                list2 = list2->next;
            }

            // move the temp pointer 
            temp = temp->next;
        }

        // lets say that dono me se kisi ek ka size zyada tha and uske ele abhi bhi hai 
        if(list1 != NULL){
            temp->next = list1;
        }
        else if(list2 != NULL){
            temp->next = list2;
        }

        return dummyNode->next;
    }
};
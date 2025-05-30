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
        // during the traversal only we will compare the two nodes if they are same or not

        ListNode* nodeA = headA;
        int countA = 0;

        while(nodeA){
            countA++;

            // move to the next 
            nodeA = nodeA->next;
        }


        ListNode* nodeB = headB;
        int countB = 0;

        while(nodeB){
            countB++;

            // move to the next 
            nodeB = nodeB->next;
        }


        nodeA = headA;
        nodeB = headB;
        if(countA > countB){
            // then we need to move nodeA by (countA - countB) places 
            while(countA != countB){
                nodeA = nodeA->next;
                countA--;
            }
        }
        else if(countB > countA){
            // then we need to move nodeB by (countB - countA) places 
            while(countA != countB){
                nodeB = nodeB->next;
                countB--;
            }
        }


        // now we are at the same positions and now we can check for the common nodes

        while(nodeA && nodeB){
            if(nodeA == nodeB){
                return nodeA;
            }

            // move the nodes 
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return NULL;
    }
};
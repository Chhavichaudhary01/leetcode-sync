/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         for(ListNode* a = headA; a != NULL; a = a->next){
//             for(ListNode* b = headB; b != NULL; b = b->next){
//                 if(a == b){
//                 return a;
//                 }
//             }
//         }
//         return NULL;


        
//     }
// };




////////more optimal approach


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};

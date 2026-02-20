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
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* temp = head;
//         if(head == NULL || head->next==NULL){
//             return NULL;
//         }
//         int pos = 0,len =0;
//         while(temp != NULL){
//             len++;
//             temp = temp->next;
//         }
//         pos = len/2;
//         temp = head;
//         for(int i = 1;i<pos;i++){
//             temp = temp->next;

//         }
//         temp->next = temp->next->next;
//         return head;
        

        




        
//     }
// };

// best approach

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle
        prev->next = slow->next;

        return head;
    }
};

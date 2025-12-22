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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        ListNode*dummy = new ListNode(0);
        ListNode*temp= dummy;

        while(List1!=NULL && List2!=NULL){
            if(List1->val<=List2->val){
                temp->next=List1;
                List1= List1->next;

            }
            else{
                temp->next = List2;
                List2=List2->next;
            }
            temp = temp->next;
        }
        if(List1!=NULL){
            temp->next = List1;
        }
        else{
            temp->next = List2;
        }
        return dummy->next;
    }
};

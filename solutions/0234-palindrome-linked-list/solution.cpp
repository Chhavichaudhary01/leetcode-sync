class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        
        ListNode* temp = head;
        while(slow != NULL){
            if(temp->val != slow->val)
                return false;
            
            temp = temp->next;
            slow = slow->next;
        }
        
        return true;
    }
};


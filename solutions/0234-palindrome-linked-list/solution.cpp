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
        
        // 1️⃣ Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2️⃣ Reverse second half
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        // 3️⃣ Compare both halves
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


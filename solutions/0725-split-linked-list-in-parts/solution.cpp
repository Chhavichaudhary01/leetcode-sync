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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         // Count total nodes
        int n = 0;
        ListNode* temp = head;

        while(temp) {
            n++;
            temp = temp->next;
        }

        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans;

        ListNode* curr = head;

        for(int i = 0; i < k; i++) {

            // Size of current part
            int partSize = size;

            if(extra > 0) {
                partSize++;
                extra--;
            }

            // Starting node of this part
            ListNode* partHead = curr;

            // Move curr to end of current part
            for(int j = 1; j < partSize && curr != NULL; j++) {
                curr = curr->next;
            }

            // Break the current part
            if(curr != NULL) {
                ListNode* nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }

            ans.push_back(partHead);
        }

        return ans;

        
    }
};

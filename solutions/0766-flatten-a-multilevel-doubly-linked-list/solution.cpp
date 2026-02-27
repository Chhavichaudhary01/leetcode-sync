/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        if(head == NULL) return head;

        while(curr != NULL){

            Node* next = NULL;   // <-- moved outside (scope fix)

            // flatten child
            if(curr->child != NULL){
                next = curr->next;   // save next

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
            }

            // finding tail (only if child was present)
            if(next != NULL){
                while(curr->next != NULL){
                    curr = curr->next;
                }

                // attach tail with next ptr
                curr->next = next;
                next->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;

        while (curr) {
            Node dummy(0);
            Node* prev = &dummy;

            // Traverse the current level and link children
            while (curr) {
                if (curr->left) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next;
            }

            // Move to the next level's start
            curr = dummy.next;
        }

        return root;
        
    }
};

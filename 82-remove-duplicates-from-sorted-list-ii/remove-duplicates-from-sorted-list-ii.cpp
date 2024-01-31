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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) return head;

        if(head -> next == NULL) return head;
        
        ListNode *h = NULL;
        ListNode *start = head;

        ListNode *ans = NULL;

        bool f = false;
        
        while(start -> next != NULL) {
            if(start -> val == start -> next -> val) {
                int v = start -> val;
                while(start -> next -> val == v) {
                    start = start -> next;
                    if(start -> next == NULL) break;
                }

                if(start -> next == NULL) {
                    f = true;
                    break;
                }
            }
            else{
                if(h == NULL) {
                    ListNode *new_node = new ListNode(start -> val);
                    new_node -> next = NULL;
                    h = new_node;
                    ans = h;
                }
                else{
                    ListNode *node = new ListNode(start -> val);
                    node -> next = NULL;
                    h -> next = node;
                    h = h -> next;
                }
            }
            start = start -> next;
        }

        if(!f) {
            if(h == NULL) {
                ans = start;
            }
            else{
                h -> next = start;
            }
        }

        h = ans;

        return h;
    }
};
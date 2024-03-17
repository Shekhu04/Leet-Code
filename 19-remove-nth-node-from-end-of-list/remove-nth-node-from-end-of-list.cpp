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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         //BFA
    if(head == NULL) return NULL;

    int cnt = 0;
    ListNode*temp = head;

    //Count number of nodes
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    if(cnt == n){
        ListNode*newHead = head -> next;
        delete(head);
        return newHead;
    }

    //Calculate the position of the node to delete (res)
    int res = cnt - n;
    ListNode* curr = head;

    //Traverse to the node just before the one to delete
    while(curr != NULL) {
        res--;

        if(res == 0) break;
            
        curr = curr -> next;
    }

    //Delete the Nth node from the end
    ListNode* delNode = curr->next;
    curr->next = curr->next->next;
    delete(delNode);
    return head;
    }
};
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
    
    int length(ListNode *&head)
    {
        ListNode *temp = head;
        int count = 0;
        while(temp != 0)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* &head, int k) {
        
        // Base Case : Empty or Single Node
        if(head == 0 or head->next == 0)
            return head;
        
        int len = length(head);
        if(k > len)
            return head;
        
        // Step 1 : Reverse first k Nodes
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        int count = 0;
        
        while(count < k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        // Step 2 : Recursive Call for remaining Nodes
        if(curr != 0)
        {
            head->next = reverseKGroup(curr,k);
        }
        
        // Step 3 : Return head of modified linked list
        return prev;
    }
};
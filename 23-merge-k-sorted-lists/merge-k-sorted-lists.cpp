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
    ListNode* mergeTwoList(ListNode* head1, ListNode* head2) 
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode* ans = new ListNode(-1);
        ListNode* ptr = ans;
        while (head1 && head2) 
        {
            if (head1->val < head2->val) 
            {
                ptr->next = head1;
                ptr = ptr->next;
                head1 = head1->next;
            } 
            else 
            {
                ptr->next = head2;
                ptr = ptr->next;
                head2 = head2->next;
            }
        }
        while (head1) 
        {
            ptr->next = head1;
            ptr = ptr->next;
            head1 = head1->next;
        }
        while (head2) 
        {
            ptr->next = head2;
            ptr = ptr->next;
            head2 = head2->next;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.size() == 0)
            return NULL;
        ListNode* head1 = lists[0];
        for (int i = 1; i < lists.size(); i++) 
            head1 = mergeTwoList(head1, lists[i]);
        return head1;
    }
};
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
    ListNode* middleNode(ListNode* head) {
        ios::sync_with_stdio(0);
        ListNode* sl = head;
        ListNode* fs= head;
        while (fs && fs->next)
        {
            sl = sl->next;
            fs = fs->next->next;
        }
        
        return sl;
    }
};

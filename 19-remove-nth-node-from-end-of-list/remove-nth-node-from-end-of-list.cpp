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
    //Optimal Approach
    //Create two pointers
    ListNode* fastp = head;
    ListNode* slowp = head;

    //Move the fastp N nodes ahead
    for(int i = 0; i<n;i++) fastp = fastp -> next;

    //if fastp becomes NULL then the Nth node from the end is head
    if(fastp == NULL) return head->next;

    //Move both pointers until fastp reaches the end
    while(fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }
    //Delete the Nth node from the end
    ListNode* delNode = slowp->next;
    slowp->next = slowp ->next->next;
    delete delNode;
    return head;
    }
};
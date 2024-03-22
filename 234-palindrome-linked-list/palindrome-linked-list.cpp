

class Solution {
public:

ListNode * reverse(ListNode*head){
    if(head == NULL || head ->next == NULL) return head;
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

    bool isPalindrome(ListNode* head) {
         if(head == NULL || head->next == NULL){
            return true;
        }
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
       }
       ListNode* newHead = reverse(slow->next);
       ListNode * first = head;
       ListNode* second = newHead;

       while(second != NULL) {
        if(first -> val != second -> val){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second -> next;
       }
       reverse(newHead);
       return true;
    }
};
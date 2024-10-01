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
    ListNode* reverseList(ListNode* head) {
    //BFA using stack
    //    ListNode * temp = head;
    //    stack<int> st;

    //    while(temp){
    //     st.push(temp -> val);
    //     temp = temp -> next;
    //    } 
    //    temp = head;

    //    while(temp){
    //     temp -> val = st.top();
    //     st.pop();
    //     temp = temp -> next;
    //    }

    //    return head;

    //OA (Iterative)
    // ListNode* temp = head;
    // ListNode * prev = NULL;

    // while(temp){
    //     ListNode* front = temp -> next;
    //     temp -> next = prev;
    //     prev = temp;
    //     temp = front;
    // }
    // return prev;

    //OA (Recursive)

    if(head == NULL || head -> next == NULL){
        return head;
    }
    ListNode * newHead = reverseList(head -> next);
    ListNode * front = head -> next;
    front -> next = head;
    head -> next = NULL;

    return newHead;
    }
};
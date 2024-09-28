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
    // Function to merge two sorted linked lists (list1 and list2)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node 'temp' to use as the head of the merged list
        ListNode *temp = new ListNode(0);
        
        // 'merge' is a pointer that will traverse and build the merged list
        ListNode *merge = temp;

        // Traverse both lists until one of them becomes empty (null)
        while (list1 && list2) {
            // Compare the current values of list1 and list2
            if (list1->val > list2->val) {
                // If the value of list2 is smaller or equal, add it to the merged list
                merge->next = new ListNode(list2->val);
                
                // Move the pointer in list2 forward
                list2 = list2->next;
            } else {
                // If the value of list1 is smaller or equal, add it to the merged list
                merge->next = new ListNode(list1->val);
                
                // Move the pointer in list1 forward
                list1 = list1->next;
            }
            // Move the 'merge' pointer to the next node in the merged list
            merge = merge->next;
        }

        // If list1 still has remaining elements, append them to the merged list
        if (list1) merge->next = list1;

        // If list2 still has remaining elements, append them to the merged list
        if (list2) merge->next = list2;
        
        // Return the merged list starting from temp->next (skip the dummy node)
        return temp->next;
    }
};

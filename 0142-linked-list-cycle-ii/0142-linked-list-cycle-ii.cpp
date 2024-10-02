/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    // Function to detect the starting point of the cycle in a linked list.
    ListNode *detectCycle(ListNode *head) {
    
        // Initialize two pointers, slow and fast, both starting at the head of the list.
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse the list with slow moving one step and fast moving two steps.
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Slow pointer moves one step.
            fast = fast->next->next;     // Fast pointer moves two steps.

            // If slow and fast meet, it indicates a cycle in the list.
            if(slow == fast) {

                // Reset the slow pointer to the head to find the start of the cycle.
                slow = head;

                // Move both slow and fast one step at a time until they meet again.
                // When they meet, it's the start of the cycle.
                while(slow != fast) {
                    slow = slow->next;  // Move slow one step.
                    fast = fast->next;  // Move fast one step.
                }

                // Return the node where the cycle starts.
                return slow;
            }
        }

        // If no cycle is detected, return NULL.
        return NULL;  
    }
};

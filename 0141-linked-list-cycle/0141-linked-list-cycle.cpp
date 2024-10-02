/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // //BFA
        // ListNode * temp = head;

        // unordered_map<ListNode*, int> nodeMap;

        // while(temp){
        //     if(nodeMap.find(temp) != nodeMap.end()){  //nodeMap.end() => not present
        //         return true;
        //     }
        //     nodeMap[temp] = 1;
        //     temp = temp -> next;
        // }
        // return false;


       //OA
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
	
            if(fast == slow)
                return true;
        }
        return false;
    }
};
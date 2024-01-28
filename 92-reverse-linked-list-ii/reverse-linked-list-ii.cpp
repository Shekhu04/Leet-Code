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
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(head==NULL) return head;
        cout<<"done"<<endl;
        if(head->next==NULL) return head;
        cout<<"done2"<<endl;
        int l=left;
        ListNode *prev=NULL;
        ListNode* ans=head;
       

        while(l>1)
        {
            prev=head;
            head=head->next;
            l--;
        }


        cout<<head->val;
        int loop=right-left+1;
        ListNode* pre=NULL;
        ListNode* nex;
        ListNode* last;
        ListNode* prev2=head;


        while(loop)
        {
            if(head)
           { 
               nex=head->next;
            head->next=pre;
            pre=head;
            head=nex;
            }

            loop--;
        }
        if(prev!=nullptr)
        {if(pre!=nullptr)
        {
            prev->next=pre;
        }


        else prev->next=NULL;}
        else ans=pre;
        prev2->next=head;

        return ans;
    }
};
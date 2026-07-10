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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode*  temp1=list1;
      ListNode* temp2=list2;
      ListNode* head;
      if(!list1) return list2;
      if(!list2) return list1;
      if(temp1->val<=temp2->val){
        head=new ListNode(temp1->val);
        temp1=temp1->next;
      }
      else{
        head=new ListNode(temp2->val);
        temp2=temp2->next;
      }
       ListNode* temp=head;
       while(temp1 and temp2){
        if(temp1->val<=temp2->val){
        ListNode* temp3=new ListNode(temp1->val);
        temp->next=temp3;
        temp=temp->next;
        temp1=temp1->next;
      }
      else{
        ListNode* temp3=new ListNode(temp2->val);
        temp->next=temp3;
        temp=temp->next;
        temp2=temp2->next;
      }
      
       }
       if(temp1) temp->next=temp1;
       if(temp2) temp->next=temp2;
       return head;
    }
};
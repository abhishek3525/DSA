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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int total=l1->val+l2->val;
        int sum=total%10;
        total/=10;
        carry=total%10;
        ListNode* head=new ListNode(sum);
        ListNode* temp=head;
        ListNode* temp1=l1->next;
        ListNode* temp2=l2->next;
        while(temp1 and temp2){
            total=temp1->val+temp2->val+carry;
            sum=total%10;
            total/=10;
            carry=total%10;
            ListNode* temp3=new ListNode(sum);
            temp->next=temp3;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            total=temp1->val+carry;
            sum=total%10;
            total/=10;
            carry=total%10;
            ListNode* temp3=new ListNode(sum);
            temp->next=temp3;
            temp=temp->next;
            temp1=temp1->next;

        }
        while(temp2){
            total=temp2->val+carry;
            sum=total%10;
            total/=10;
            carry=total%10;
            ListNode* temp3=new ListNode(sum);
            temp->next=temp3;
            temp=temp->next;
            temp2=temp2->next;
        }
        if(carry){
            ListNode* temp3=new ListNode(carry);
            temp->next=temp3;
        }
        return head;
    }
};
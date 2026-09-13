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
        ListNode*temp=head ;
        int count =0 ;
        while(temp!=NULL){
            temp=temp->next ;
            count ++;
        }// no of count nikala 
        // count minus n 
        count-=n ;
        // if count =0
        if(count==0){
            ListNode*temp=head ;
            head=head->next ;
            delete temp ;
            return head ;

        }
        ListNode*curr=head,*prev=NULL ;
        while(count--){
            prev=curr;
            curr=curr->next ;
        }
            prev->next=curr->next ;
            delete curr ;
            return head ;
        

        
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or only one node
      ListNode* dummy = new ListNode(0);
     dummy->next = head;

        // Find length and last node
        int l = 0;
        ListNode* temp = dummy;

        while (temp->next != NULL) {
            temp = temp->next;
            l++;
        }

          if (l == 0) {
            return head;
        }

        // k can be greater than length
        k = k % l;

        // No rotation needed
        if (k == 0) {
            return head;
        }

        // Make the list circular
        temp->next = dummy->next;

        // Find the new tail
        ListNode* newTail = head;

        for (int i = 0; i < l - k - 1; i++) {
            newTail = newTail->next;
        }

        // Node after newTail becomes new head
        ListNode* newHead = newTail->next;
        dummy->next=newHead;

        // Break the circle
        newTail->next = NULL;

        return dummy->next;
    }
};
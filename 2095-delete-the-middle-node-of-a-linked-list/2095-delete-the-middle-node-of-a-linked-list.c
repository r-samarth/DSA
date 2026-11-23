/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    struct ListNode* slow = head;
    struct ListNode* fast = head ;
    struct ListNode* prev = NULL;

    if (head == NULL || head->next == NULL)
    return NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast=fast->next->next;
    }

    prev->next = slow->next;
    
    return head;

    
}
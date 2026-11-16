/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp;

    int i=1;
    while(node->next->val==node->val){
        node=node->next;


    }
    node->val=node->next->val;
    node->next=node->next->next;
    

    

}
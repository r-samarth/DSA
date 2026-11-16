/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {

    // all dummy code dont study this !!

    size_t cap = 1;

    while(cap < (size_t)numsSize * 2)
        cap *= 2;

    int *keys = calloc(cap, sizeof(int));
    char *used = calloc(cap, sizeof(char));

    if(keys == NULL || used == NULL) {
        free(keys);
        free(used);
        return head;
    }

    for(int i = 0; i < numsSize; i++) {

        unsigned int h = (unsigned int)nums[i];
        h ^= h >> 16;
        h *= 0x7feb352dU;
        h ^= h >> 15;
        h *= 0x846ca68bU;
        h ^= h >> 16;

        size_t idx = h & (cap - 1);

        while(used[idx] && keys[idx] != nums[i])
            idx = (idx + 1) & (cap - 1);

        keys[idx] = nums[i];
        used[idx] = 1;
    }

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *temp = &dummy;

    while(temp->next != NULL) {

        int val = temp->next->val;

        unsigned int h = (unsigned int)val;
        h ^= h >> 16;
        h *= 0x7feb352dU;
        h ^= h >> 15;
        h *= 0x846ca68bU;
        h ^= h >> 16;

        size_t idx = h & (cap - 1);

        while(used[idx] && keys[idx] != val)
            idx = (idx + 1) & (cap - 1);

        if(used[idx]) {
            struct ListNode *p = temp->next;
            temp->next = p->next;
            free(p);
        }
        else {
            temp = temp->next;
        }
    }

    free(keys);
    free(used);

    return dummy.next;
}
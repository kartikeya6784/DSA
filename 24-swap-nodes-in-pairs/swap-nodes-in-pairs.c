/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val=0;
    dummy.next=head;
    struct ListNode* current=&dummy;
    while(current->next!=NULL && current->next->next!=NULL){
        struct ListNode* first=current->next;
        struct ListNode* second=current->next->next;
        first->next=second->next;
        second->next=first;
        current->next=second;
        current=first;

    }
    return dummy.next;
}
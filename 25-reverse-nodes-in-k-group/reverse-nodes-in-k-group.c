/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Base case: if the current segment has less than k nodes, return head
    struct ListNode* current = head;
    int count = 0;
    while (count < k && current) {
        current = current->next;
        count++;
    }
    if (count < k) {
        return head;
    }
    
    // Reverse the current segment
    struct ListNode* prev = NULL;
    struct ListNode* next_node = NULL;
    current = head;
    for (int i = 0; i < k; i++) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    
    // Recursively reverse the next segment
    head->next = reverseKGroup(current, k);
    
    return prev;
}
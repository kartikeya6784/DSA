/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* mergetwoLists(struct ListNode* l1,struct ListNode* l2){
    struct ListNode result;
    struct ListNode* p = &result;

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            p->next = l1;
            l1 = l1->next;
        }
        else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1 != NULL){
        p->next = l1;
    }
    if(l2 != NULL){
        p->next = l2;
    }
    return result.next;
 }

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){
        return NULL;
    }
    struct ListNode* result = lists[0];
    
    for(int i = 1;i < listsSize;i++){
        result = mergetwoLists(result,lists[i]);
    }
    return result;
}
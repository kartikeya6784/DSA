
typedef struct node {

    int data;
    struct node *next;
    struct node *prevMin;

} Node;

typedef struct {

    struct node *top1;
    struct node *top2;  /// to maintain min values in order
    
} MinStack;


MinStack* minStackCreate() {

    MinStack *stack = (MinStack *) malloc(sizeof(MinStack));

    stack->top1 = NULL;
    stack->top2 = NULL;

    return stack;
    
}

void minStackPush(MinStack* obj, int val) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = obj->top1;
    newNode->prevMin = NULL;
    obj->top1 = newNode;

    if(obj->top2 == NULL || obj->top2->data > val)
    {
        newNode->prevMin = obj->top2;
        obj->top2 = newNode;
    }
    
}

void minStackPop(MinStack* obj) {

    Node *deletedNode = obj->top1;

    if(obj->top1 == obj->top2)
        obj->top2 = obj->top2->prevMin;

    obj->top1 = obj->top1->next;
    free(deletedNode);
    
}

int minStackTop(MinStack* obj) {

    return obj->top1->data;
    
}

int minStackGetMin(MinStack* obj) {

    return obj->top2->data;
    
}

void minStackFree(MinStack* obj) {

    Node *deletedNode;

    while(obj->top1)
    {
        deletedNode = obj->top1;
        obj->top1 = obj->top1->next;
        free(deletedNode);
    }
    
    obj->top2 = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
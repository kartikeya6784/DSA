#define Maxnum 10001

int Peep ( int *Stack, int top ) {
    return Stack[top];
}

int Pop ( int *Stack, int *top ) {
    return Stack[(*top)--];
}

void Push ( int *Stack, int *top, int input ) {
    Stack[++(*top)]=input;
    return;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *output=( int *)malloc(sizeof(int)*nums1Size);
    * returnSize=nums1Size;
    int Stack[nums2Size], top=-1, NG[Maxnum]; // next greater element
    for ( int i=0; i<nums2Size; ++i) {
        while (  top!=-1 && Peep( Stack, top )<nums2[i] )
            NG[ Pop( Stack, &top)]=nums2[i];
        Push( Stack, &top, nums2[i]);
    }
    while ( top!=-1 )
        NG[ Pop( Stack, &top)]=-1;
    for ( int i=0; i<nums1Size; ++i)
        output[i]=NG[ nums1[i]];
    return output;
}
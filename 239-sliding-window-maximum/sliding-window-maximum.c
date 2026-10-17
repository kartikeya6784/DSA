
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc(numsSize * sizeof(int));
    int *deque = (int*)malloc(numsSize * sizeof(int));

    int front = 0, rear = 0;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front < rear && deque[front] <= i - k) {
            front++;
        }
        while (front < rear &&
               nums[deque[rear - 1]] <= nums[i]) {
            rear--;
        }
        deque[rear++] = i;
        if (i >= k - 1) {
            result[(*returnSize)++] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}
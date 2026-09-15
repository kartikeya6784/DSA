/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* result = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Calculate the product of everything to the LEFT
    int leftProduct = 1;

    for (int i = 0; i < numsSize; i++) {

        // Store the product of everything before nums[i]
        result[i] = leftProduct;

        // Add nums[i] to the running left product
        leftProduct = leftProduct * nums[i];
    }

    // Calculate the product of everything to the RIGHT
    int rightProduct = 1;

    for (int i = numsSize - 1; i >= 0; i--) {

        // Multiply the left product by the right product
        result[i] = result[i] * rightProduct;

        // Add nums[i] to the running right product
        rightProduct = rightProduct * nums[i];
    }

    return result;
}
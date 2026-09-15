int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* a = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    a[0] = -1;
    a[1] = -1;

    if (numsSize == 0) {
        return a;
    }
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] != target) {
                a[0] = mid;
                break;
            } else {
                right = mid - 1;
            }
        }
    }
    left = 0;
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == numsSize - 1 || nums[mid + 1] != target) {
                a[1] = mid;
                break;
            } else {
                left = mid + 1;
            }
        }
    }
    return a;
}
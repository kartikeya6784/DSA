/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int *nums, int *index, int *count, int *temp, int *tempIndex,
           int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;
    int smaller = 0;

    while(i <= mid && j <= right) {

        if(nums[index[j]] < nums[index[i]]) {
            tempIndex[k] = index[j];
            smaller++;
            j++;
        }
        else {
            count[index[i]] += smaller;
            tempIndex[k] = index[i];
            i++;
        }

        k++;
    }

    while(i <= mid) {
        count[index[i]] += smaller;
        tempIndex[k] = index[i];
        i++;
        k++;
    }

    while(j <= right) {
        tempIndex[k] = index[j];
        j++;
        k++;
    }

    for(i = left; i <= right; i++) {
        index[i] = tempIndex[i];
    }
}

void mergeSort(int *nums, int *index, int *count, int *temp,
               int *tempIndex, int left, int right) {

    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, index, count, temp, tempIndex, left, mid);
    mergeSort(nums, index, count, temp, tempIndex, mid + 1, right);

    merge(nums, index, count, temp, tempIndex, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int *count = calloc(numsSize, sizeof(int));

    if(numsSize == 0)
        return count;

    int *index = malloc(numsSize * sizeof(int));
    int *temp = malloc(numsSize * sizeof(int));
    int *tempIndex = malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        index[i] = i;
    }

    mergeSort(nums, index, count, temp, tempIndex, 0, numsSize - 1);

    free(index);
    free(temp);
    free(tempIndex);

    return count;
}
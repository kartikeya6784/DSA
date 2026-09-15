int firstMissingPositive(int* nums, int numsSize) {
    int i =0;
    while(i<numsSize){
        if(nums[i]>0 && nums[i]<=numsSize && nums[i]!=nums[nums[i]-1]){
            int temp=nums[i];
            nums[i]=nums[temp-1];
            nums[temp-1]=temp;
        }
        else{
            i++;
        }
    }
    for(int j=0;j<numsSize;j++){
        if (nums[j]!=j+1){
            return j+1;
        }
    }
    return numsSize+1;
}
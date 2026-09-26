void sortColors(int* nums, int numsSize) {
    int zered=0;
    int onewhite=0;
    int twoblue=0;
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]==0)
         zered++;
        else if (nums[i]==1)
         onewhite++;
        else
         twoblue++;
    }
    for(i=0;i<zered;i++)
      nums[i]=0;
    for(;i<zered+onewhite;i++)
      nums[i]=1;
    for(;i<numsSize;i++)
      nums[i]=2;
}
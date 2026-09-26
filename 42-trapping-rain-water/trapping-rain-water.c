int trap(int* height, int heightSize) {
    int lefth[heightSize];
    int lmax=height[0],rmax=height[heightSize-1];
    int righth[heightSize];
    int water=0;
    for(int i=0;i<heightSize;i++){
        if(height[i]>lmax){
            lefth[i]=height[i];
            lmax=height[i];
        }else{
            lefth[i]=lmax;
        }
    }
    for(int j = heightSize-1;j>=0;j--){
        if(height[j]>rmax){
            righth[j]=height[j];
            rmax = height[j];
        }else{
            righth[j]=rmax;
        }
    }
    int num;
    for(int k=0;k<heightSize-1;k++){
        if(lefth[k]<=righth[k]){
            num=lefth[k]-height[k];
        }else{
            num=righth[k]-height[k];
        }
        water=water+num;
    }
    return water;
}
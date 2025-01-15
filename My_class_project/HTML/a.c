#include <stdio.h>
#include<stdlib.h>
int* finduplicates(int* nums,int numsize,int* returnsize){
    int count=0;
    for(int i=0;i<numsize;i++){
        for(int j=1+i;j<numsize;j++){
            if(nums[i] == nums[j]){
            returnsize[i]=nums[i];
            }
            
        }
    }
    printf("duplicate numbers :\n");
     for(int i=0;i<numsize;i++){
      if(returnsize[i]!=0){
         printf("%d\t",returnsize[i]);
      }
     }
     printf("\n");
    
    
}
int main() {
    int numsize;
    printf("enter the number size :\n");
    scanf("%d",&numsize);
    int* nums = (int*)malloc(numsize * sizeof(int));
     int* returnsize=(int*)malloc(numsize*sizeof(int));
     printf("the array numbers are :\n");
    for(int i=0;i<numsize;i++){
       
        scanf("%d",&nums[i]);
       returnsize[i]=0;
    }
  
    finduplicates(nums,numsize,returnsize);
    return 0;
}
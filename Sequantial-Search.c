#include <stdio.h>
int sequential(int arr[],int key,int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int main(){
    int key;
    int arr[]={7,3,5,9,8,1};
    int size= sizeof(arr)/ sizeof(arr[0]);
    printf("Enter the number that you want to find: \n");
    scanf("%d",&key);
    int index= sequential(arr,key,size);

    if(index!=1){
        printf("%d found at location: %d\n",key,index);
    }
    else{
        printf("%d not found in the array\n",key);
    }



    return 0;
}
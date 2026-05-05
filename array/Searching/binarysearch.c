#include <stdio.h>

int main(){
    int arr[100],n,key,mid,low,high;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:");
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched:");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    
    while(low <= high){
        mid = (low + high) /2;

        if(arr[mid] == key){
        printf("Element found at position %d ", mid);
        return 0;

        }else if(arr[mid] < key){
        low = mid + 1;
        
        }else{
            high = mid - 1;
        }
    }
    return 0;
}
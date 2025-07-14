#include<iostream>
using namespace std;

//Basic code for binary search, linear search, bubble sort, insertion sort, selection sort 

int binarySearch(int arr[],int n,int target,int low,int high){

    if(high>=low){

        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
        return binarySearch(arr,n,target,mid+1,high);
        }
        else{
        return binarySearch(arr,n,target,low,mid-1);
        }
    }
    return -1;
}



int linearSearch(int arr[], int n,int target){

    for(int i=0;i<n;i++){
        if(arr[i]==target){
        return i;
        }
    }
    return -1;
}


void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    cout<<"\nBubble Sorted array-";
    for(int i=0;i<n;i++){
        cout<<" "<< arr[i];
    }

}

void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout<<"\nInsertion Sorted array-";
    for(int i=0;i<n;i++){
        cout<<" "<< arr[i];
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j= i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;

            }
            swap(arr[i],arr[min]);
        }
    }
    cout<<"\nSelection Sorted array-";
    for(int i=0;i<n;i++){
        cout<<" "<< arr[i];
    }
    
}
int main(){
    int arr[] = {15, 22, 34, 36, 51, 63, 75};
    int n = 7;
    
    cout<<"\nLinear Search result:";
    int result = linearSearch(arr, n, 22);

        if (result == -1){
            cout << "Element not found";
            }
        else{
            cout << "Index: " << result;
            }
    
    bubbleSort(arr,n);
    insertionSort(arr,n);
    selectionSort(arr,n);

    cout<<"\nBinary Search result: ";
    result = binarySearch(arr, n, 51,0,6);

        if (result == -1){
            cout << "Element not found";
            }
        else{
            cout << "Index: " << result;
            }
}
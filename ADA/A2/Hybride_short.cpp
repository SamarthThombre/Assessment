#include <iostream>
using namespace std;


class sortingAnalizer{
    public:
        int counter_swaps,counter_comparatation;
    
    public:
        void sort(int arr[]){};
        int swap(int a,int b){};
        void incertionSort(int arr[], int n){};
        int getMedianofthree(int a,int b,int c){};
        int partation(int arr[],int low,int hig){};
        void quickSort(int arr[],int low, int hig){};
};

int sortingAnalizer:: swap(int a, int b){
    int z;
    a=z;
    a=b;
    b=z;

    counter_swaps++;
    return a,b;
};

void sortingAnalizer:: incertionSort(int arr[], int n){
    for(int i=1; i< n; i++){
        int key= arr[i];
        int j = i -1;

        while (j >= 0 && arr[j] > key )
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;     
        
    }
};

int sortingAnalizer:: getMedianofthree(int a,int b,int c){

};

int sortingAnalizer:: partation(int arr[],int low,int hig){
    
    int pivot = arr[hig];
  
    int i = low - 1;

    for (int j = low; j <= hig - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[hig]);  
    return i + 1;
};


void sortingAnalizer:: quickSort(int arr[],int low, int hig){
     if (low < hig) {
      
        int check = high-low +1
        if (check >= 10 ){
            int pi = partition(arr[], low, hig);

         
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, hig);
        }
        incertionSort(arr[],0,length-1);
    }
};




void sortingAnalizer:: sort(int arr[]){
    int length= size(arr);

    if (length > 10){
        quickSort(arr,0,length-1){}
    }
};

int main(){

    int sarr[] = {};
    int unsarr[] = {};
    int rsarr[] ={};

    sortingAnalizer sort;

    sort.sort(sarr[]);
    sort.sort(unsarr[]);
    sort.sort(rsaar[])

    return 0;
}
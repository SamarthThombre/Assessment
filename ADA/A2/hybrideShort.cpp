#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


class sortingAnalizer {
public:
    int counter_swaps;
    int counter_comparisons;

    sortingAnalizer() {
        counter_swaps = 0;
        counter_comparisons = 0;
    }

    void sort(int arr[], int size);
    void swap(int &a, int &b); // Added '&' to pass by reference
    void insertionSort(int arr[], int low, int high);
    void getMedianOfThree(int arr[], int low, int high); 
    int partition(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high);
    void printArray(int arr[], int size); 
    void normalQuickSort(int arr[], int low, int high);
    void sortNormal(int arr[], int size); // A new caller just for the normal sort
};

// 1. Swap Logic
void sortingAnalizer::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    counter_swaps++;
}

// 2. Insertion Sort to handle sub-arrays (low to high)
void sortingAnalizer::insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= low) {
            counter_comparisons++; 
            if (arr[j] > key) {
                arr[j + 1] = arr[j]; 
                counter_swaps++;     
                j = j - 1;
            } else {
                break; }
        }
        arr[j + 1] = key;
    }
}

// 3. Implemented Median-of-Three
void sortingAnalizer::getMedianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    counter_comparisons++;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    
    counter_comparisons++;
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    
    counter_comparisons++;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);

    swap(arr[mid], arr[high]);
}

// 4. Partition Counters
int sortingAnalizer::partition(int arr[], int low, int high) {
    
    getMedianOfThree(arr, low, high);
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        counter_comparisons++; 
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 5.  Hybrid Logic
void sortingAnalizer::quickSort(int arr[], int low, int high) {
    if (low < high) {
        int check_size = high - low + 1;

        
        if (check_size <= 10) { 
            insertionSort(arr, low, high);
        } else {
        
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

// 6. The main sorting caller
void sortingAnalizer::sort(int arr[], int size) {
    counter_swaps = 0;
    counter_comparisons = 0;
    
    quickSort(arr, 0, size - 1);
}

// 7.Helper function to print the array
void sortingAnalizer::printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 8. The normal Quick Sort 
void sortingAnalizer::normalQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Standard divide and conquer
        int pi = partition(arr, low, high);
        
        normalQuickSort(arr, low, pi - 1);
        normalQuickSort(arr, pi + 1, high);
    }
}

// 9. The caller to reset the counters and start the normal sort
void sortingAnalizer::sortNormal(int arr[], int size) {
    counter_swaps = 0;
    counter_comparisons = 0;
    
    normalQuickSort(arr, 0, size - 1);
}

// Array Initialization and Sizes in Main
int main() {
    int sarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    int unsarr[] = {8, 3, 1, 5, 9, 2, 14, 10, 15, 6, 4, 11, 13, 12, 7};
    int rsarr[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 

    int size_sarr = sizeof(sarr) / sizeof(sarr[0]);
    int size_unsarr = sizeof(unsarr) / sizeof(unsarr[0]);
    int size_rsarr = sizeof(rsarr) / sizeof(rsarr[0]);

    sortingAnalizer analyzer;
    
    cout << "--- Sorting sorted Array ---" << endl;
    auto start = high_resolution_clock::now();
    analyzer.sort(sarr, size_sarr);
    auto stop = high_resolution_clock::now();
    analyzer.printArray(sarr, size_sarr);
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl << endl;


    cout << "--- Sorting Random Array ---" << endl;
    auto start1 = high_resolution_clock::now();
    analyzer.sort(unsarr, size_unsarr);
    auto stop1 = high_resolution_clock::now();
    analyzer.printArray(unsarr, size_unsarr);
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time taken by function: " << duration1.count() << " microseconds" << endl << endl;


    cout << "--- Sorting Reverse Array ---" << endl;
    auto start2 = high_resolution_clock::now();
    analyzer.sort(rsarr, size_rsarr);
    auto stop2 = high_resolution_clock::now();
    analyzer.printArray(rsarr, size_rsarr);
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by function: " << duration2.count() << " microseconds" << endl << endl;

    cout << "--- Standard Quick Sort (For Comparison) ---" << endl;
    auto start_norm = high_resolution_clock::now();
    analyzer.sortNormal(unsarr, size_unsarr);
    auto stop_norm = high_resolution_clock::now();
    analyzer.printArray(unsarr, size_unsarr);
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration_norm = duration_cast<microseconds>(stop_norm - start_norm);
    cout << "Execution time: " << duration_norm.count() << " microseconds\n\n"<< endl << endl;
    
    return 0;   
}
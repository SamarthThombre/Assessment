#include <iostream>
#include <chrono>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;
using namespace std::chrono;

class sortingAnalizer {
public:
    long long counter_swaps;        // Changed to long long for massive arrays
    long long counter_comparisons;  // Changed to long long for massive arrays

    sortingAnalizer() {
        counter_swaps = 0;
        counter_comparisons = 0;
    }

    void sort(int arr[], int size);
    void sortNormal(int arr[], int size); 
    void swap(int &a, int &b); 
    void insertionSort(int arr[], int low, int high);
    void getMedianOfThree(int arr[], int low, int high); 
    int partition(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high);
    void normalQuickSort(int arr[], int low, int high);
};

// --- CORE SORTING UTILITIES ---

void sortingAnalizer::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    counter_swaps++;
}

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
                break; 
            }
        }
        arr[j + 1] = key;
    }
}

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

// --- ALGORITHM 1: HYBRID QUICK SORT ---

void sortingAnalizer::quickSort(int arr[], int low, int high) {
    if (low < high) {
        int check_size = high - low + 1;
        
        // The Hybrid Switch: Sub-arrays of 10 or less use Insertion Sort
        if (check_size <= 10) { 
            insertionSort(arr, low, high);
        } else {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

void sortingAnalizer::sort(int arr[], int size) {
    counter_swaps = 0;
    counter_comparisons = 0;
    quickSort(arr, 0, size - 1);
}

// --- ALGORITHM 2: NORMAL QUICK SORT ---

void sortingAnalizer::normalQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // No hybrid switch, just standard divide and conquer all the way down
        int pi = partition(arr, low, high);
        normalQuickSort(arr, low, pi - 1);
        normalQuickSort(arr, pi + 1, high);
    }
}

void sortingAnalizer::sortNormal(int arr[], int size) {
    counter_swaps = 0;
    counter_comparisons = 0;
    normalQuickSort(arr, 0, size - 1);
}

// --- MAIN EXECUTION ---

int main() {
    cout << "========================================\n";
    cout << "        THE BIG ARRAY CHALLENGE         \n";
    cout << "========================================\n\n";

    int massive_size = 10000;
    
    // Using 'new' to allocate large memory so the stack doesn't overflow
    int* massive_hybrid = new int[massive_size];
    int* massive_normal = new int[massive_size];

    // Seed the random number generator
    srand(time(0)); 
    
    // Fill the arrays with 10,000 identical random numbers
    for(int i = 0; i < massive_size; i++) {
        int random_num = rand() % 100000;
        massive_hybrid[i] = random_num;
        massive_normal[i] = random_num;
    }

    sortingAnalizer analyzer;

    // --- RACE 1: HYBRID QUICK SORT ---
    cout << "--- Sorting 10,000 Numbers (Hybrid Quick Sort) ---" << endl;
    auto start_massive_h = high_resolution_clock::now();
    
    analyzer.sort(massive_hybrid, massive_size);
    
    auto stop_massive_h = high_resolution_clock::now();
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration_massive_h = duration_cast<microseconds>(stop_massive_h - start_massive_h);
    cout << "Execution time: " << duration_massive_h.count() << " microseconds\n\n";


    // --- RACE 2: NORMAL QUICK SORT ---
    cout << "--- Sorting 10,000 Numbers (Normal Quick Sort) ---" << endl;
    auto start_massive_n = high_resolution_clock::now();
    
    analyzer.sortNormal(massive_normal, massive_size);
    
    auto stop_massive_n = high_resolution_clock::now();
    cout << "Comparisons: " << analyzer.counter_comparisons << " | Swaps: " << analyzer.counter_swaps << endl;
    auto duration_massive_n = duration_cast<microseconds>(stop_massive_n - start_massive_n);
    cout << "Execution time: " << duration_massive_n.count() << " microseconds\n\n";


    // Clean up memory to prevent memory leaks
    delete[] massive_hybrid;
    delete[] massive_normal;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "\nSorted Array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    
    cout << "\n\nEnter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int mid;
    bool found = false;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            cout << "Element found at position " << mid;
            found = true;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(!found)
        cout << "Element not found";

    return 0;
}


#include <iostream>
#include <algorithm>

void show(int a[], int arraySize){
    for(int i = 0; i < arraySize; ++i){
        std::cout<< a[i] << " ";
    }
}

//quick sort code in C++
int partition(int arr[], int start, int end){
    int pivot = arr[start];

    int count = 0;
    for(int i= start + 1; i <= end; i++){
        if(arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int start, int end){
    //base case
    if(start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    //sorting the left part
    quickSort(arr, start, p - 1);

    //sorting the right part
    quickSort(arr, p + 1, end);
}


//C++ program of heap sort
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i){
    int largest = i; //initialize largest as root
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is larger than root
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    // If right child is larger than largest so far
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    // If largest is not root
    if(largest != i){
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n){
    // Build heap (rearrange array)
    for(int i = n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for(int i = n-1; i>=0; i--){
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


//C++ program of insertion sort
void insertionSort(int arr[], int n){
    int i, key, j;
    for(i = 1; i<n; i++){
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}



int main()
{
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    //size of the array
    int aSize = sizeof(a) / sizeof(a[0]);
    std::cout << "The array before sorting is :\n";

    //print the array
    show(a, aSize);

    //sort the array
    std::sort(a, a + aSize);
    std::cout << "\nThe array after sorting is :\n";

    // print the array after sorting
    show(a, aSize);


    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = 10;

    quickSort(arr, 0, n - 1);
    std::cout<<"\nArray after using quick sort: " << std::endl;

    for(int i = 0; i < n; i++){
        std::cout<< arr[i] << " ";
    }

    int arr2[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    std::cout << "\nHEAP SORT: The array before sorting is :\n";
    printArray(arr2, n);

    heapSort(arr2, n);
    std::cout << "\nHEAP SORT: The array after sorting is :\n";
    printArray(arr2, n);


    int arr3[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    std::cout << "\nINSERTION SORT: The array before sorting is :\n";
    printArray(arr3, n);

    insertionSort(arr2, n);
    std::cout << "\nINSERTION SORT: The array after sorting is :\n";
    printArray(arr3, n);

    return 0;
}

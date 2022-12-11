#include <iostream>
#include <algorithm>

void show(int a[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
        std::cout << a[i] << ", ";
}

int binarySearch(int array[], int size, int searchValue){
    int low = 0;
    int high = size - 1;

    int mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(searchValue == array[mid]){
            return mid;
        }
        else if(searchValue > array[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    // CPP program to implement
    // Binary Search in
    // Standard Template Library (STL)

    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int aSize = sizeof(a) / sizeof(a[0]);

    std::cout << "\nThe array is : \n";
    show(a, aSize);

    std::cout << "\n\nLet's say we want to search for ";
    std::cout << "\n2 in the array So, we first sort the array";

    std::sort(a, a + aSize);

    std::cout << "\n\nThe array after sorting is : \n";
    show(a, aSize);
    std::cout << "\n\nNow, we do the binary search";

    if(std::binary_search(a, a + 10, 2)){
        std::cout<<"\nElement found in the array";
    }
    else{
        std::cout<<"\nElement not found in the array";
    }

    std::cout << "\n\nNow, say we want to search for 10";
    if (std::binary_search(a, a + 10, 10))
        std::cout << "\nElement found in the array";
    else
        std::cout << "\nElement not found in the array";


    //sorted array
    int b[] = {12, 22, 34, 47, 55, 67, 82, 98};

    int userValue;
    std::cout<<"\nEnter an integer: " << std::endl;
    std::cin>> userValue;

    // Binary search without STL
    int result = binarySearch(b, 8, userValue);

    if(result > 0){
        std::cout<<"The number "<<b[result] <<" was found at the element with index " << result << std::endl;
    }
    else{
        std::cout<<"The number "<< userValue << " was not found." << std::endl;
    }

    return 0;
}

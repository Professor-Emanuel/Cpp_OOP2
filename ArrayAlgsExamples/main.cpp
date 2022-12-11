#include <iostream>
#include<algorithm> // for all_of()
#include<numeric> //for iota()
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, -6};

    //check if all elements are positive
    std::all_of(arr, arr + 6, [](int x){return x>0;}) ? std::cout<<"All elements are positive\n" : std::cout<<"Not all elements are positive\n";

    //Check if any element is negative
    std::any_of(arr, arr + 6, [](int x){return x<0;}) ? std::cout<<"There is a negative element\n" : std::cout<<"All elements are positive\n";

    int brr[6] = {1, 2, 3, 4, 5, 6};
    std::none_of(brr, brr+6, [](int x){return x<0;}) ? std::cout<<"No negative elements\n" : std::cout<<"There are negative elements\n";

    int copyArray[6];
    std::copy_n(brr, 6, copyArray);
    // Displaying the copied array
    std::cout << "The new array after copying is :\n";
    for (int i=0; i<6 ; i++)
       std::cout << copyArray[i] << " ";

    std::cout<<std::endl;

    int crr[6] = {0}; // Initializing array with 0 values
    std::iota(crr, crr + 6, 20);

    // Displaying the new array
    std::cout << "The new array after assigning values is :\n";
    for (int i=0; i<6 ; i++)
       std::cout << crr[i] << " ";

    return 0;
}

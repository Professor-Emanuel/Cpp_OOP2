#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> //For accumulate operation

void print(std::vector<int> vect, int n){
    for(int i=0; i<n; i++){
        std::cout<<vect[i] <<" ";
    }
}


int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::vector<int> vect(arr, arr + n);

    std::cout<<"Vector is: ";
    print(vect, n);

    // Sorting the Vector in Ascending order
    std::sort(vect.begin(), vect.end());

    std::cout << "\nVector after sorting is: ";
    print(vect, n);

    // Sorting the Vector in Descending order
    std::sort(vect.begin(), vect.end(), std::greater<int>());
    std::cout << "\nVector after sorting in descending order is: ";
    print(vect, n);

    // Reversing the Vector (descending to ascending , ascending to descending)
    std::reverse(vect.begin(), vect.end());
    std::cout << "\nVector after reversing is: ";
    print(vect, n);

    std::cout << "\nMaximum element of vector is: ";
    std::cout << *max_element(vect.begin(), vect.end());

    std::cout << "\nMinimum element of vector is: ";
    std::cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    std::cout << "\nThe summation of vector elements is: ";
    std::cout << accumulate(vect.begin(), vect.end(), 0);

    std::cout << "\nOccurences of 20 in vector: ";

    // Counts the occurrences of 20 from 1st to
    // last element
    std::cout<< std::count(vect.begin(), vect.end(), 20);

    // find() returns iterator to last address if
    // element not present
    std::find(vect.begin(), vect.end(), 115) != vect.end() ? std::cout<<"\nElement found" : std::cout<<"\nElement not found";


    // Returns the first occurrence of 20
    auto q = std::lower_bound(vect.begin(), vect.end(), 20);

    // Returns the last occurrence of 20
    auto p = std::upper_bound(vect.begin(), vect.end(), 20);

    std::cout<< "The lower bound is at position: ";
    std::cout<< q - vect.begin() << std::endl;

    std::cout<< "The upper bound is at position: ";
    std::cout<< p - vect.begin() << std::endl;

    vect.erase(std::find(vect.begin(), vect.end(), 10));
    std::cout << "\nVector after erasing element:\n";
    print(vect, vect.size());

    vect.erase(std::unique(vect.begin(), vect.end()), vect.end());
    std::cout << "\nVector after removing duplicates:\n";
    print(vect, vect.size());


    std::next_permutation(vect.begin(), vect.end());
    std::cout << "\nVector after performing next permutation:\n";
    print(vect, vect.size());

    std::prev_permutation(vect.begin(), vect.end());
    std::cout << "\nVector after performing prev permutation:\n";
    print(vect, vect.size());

    std::cout << "\nDistance between first to max element: ";
    std::cout << std::distance(vect.begin(), max_element(vect.begin(), vect.end()));

    return 0;
}

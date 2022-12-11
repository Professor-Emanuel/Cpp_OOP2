#include <iostream>
#include<algorithm> // for partition algorithm
#include<vector> // for vector



int main()
{
    // Initializing vector
    std::vector<int> vect = {2, 1, 5, 6, 8, 7};

    // Checking if vector is partitioned
    // using is_partitioned()
    is_partitioned(vect.begin(), vect.end(), [](int x){
                        return x%2 == 0;
                   }) ? std::cout<<"Vector is partitioned\n" : std::cout<<"Vector is not partitioned\n";

    std::cout << std::endl;

    // partitioning vector using partition()
    partition(vect.begin(), vect.end(), [](int x){ return x%2 == 0;});

    // Checking if vector is partitioned
    // using is_partitioned()
    is_partitioned(vect.begin(), vect.end(), [](int x)
    {
        return x%2==0;

    }) ? std::cout << "Now, vector is partitioned after partition operation" :
        std::cout << "Vector is still not partitioned after partition operation";

    std::cout << std::endl;

    // Displaying partitioned Vector
    std::cout << "The partitioned vector is : ";

    for(int &x : vect){
        std::cout << x << " ";
    }
    std::cout << std::endl;


    std::vector<int> vect2 = {2, 1, 5, 6, 8, 7};
    // partitioning vector using stable_partition()
    // in sorted order
    stable_partition(vect2.begin(), vect2.end(), [](int x){ return x%2 == 0;});

    // Displaying partitioned Vector
    std::cout << "The partitioned vector is : ";

    for(int &x : vect2){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Declaring iterator
    std::vector<int>::iterator it1;

    // using partition_point() to get ending position of partition
    auto it = partition_point(vect2.begin(), vect2.end(), [](int x){ return x%2 == 0;});

    // Displaying partitioned Vector
    std::cout << "The vector elements returning true for condition are :\n";
    for(it1 = vect2.begin(); it1 != it; it1++){
        std::cout << *it1 << " ";
    }
    std::cout << std::endl;

    std::vector<int> vect3 = { 2, 1, 5, 6, 8, 7 };
    std::vector<int> vect4;
    std::vector<int> vect5;

    // Resizing vectors to suitable size using count_if() and resize()
    int n = count_if(vect3.begin(), vect3.end(), [](int x){ return x%2 == 0;});
    vect4.resize(n);
    vect5.resize(vect3.size() - n);

    // Using partition_copy() to copy partitions
    partition_copy(vect3.begin(), vect3.end(), vect4.begin(), vect5.begin(), [](int x){ return x%2 ==0;});

     // Displaying partitioned Vector
    std::cout << "The elements that return true for condition are : ";
    for (int &x : vect4)
            std::cout << x << " ";
    std::cout << std::endl;

    // Displaying partitioned Vector
    std::cout << "The elements that return false for condition are : ";
    for (int &x : vect5)
            std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}

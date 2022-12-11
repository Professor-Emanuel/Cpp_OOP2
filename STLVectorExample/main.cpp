#include <iostream>
#include <vector>


int main()
{
    //create a vector to store integers
    std::vector<int> vec;
    int i;

    //display the original size of vec
    std::cout << "Vector size = " << vec.size() << std::endl;

    //push 5 values into the vector
    for(i = 0; i<5; i++){
        vec.push_back(i);
    }

    //display extended size of vec
    std::cout << "Extended vector size = " << vec.size() << std::endl;

    //access 5 values from the vector
    for(i = 0; i < 5; i++){
        std::cout<< "Value of vec [" <<i <<"] = " << vec[i] <<std::endl;
    }

    //use iterator to access the values
    std::vector<int>::iterator v = vec.begin();
    while(v != vec.end()){
        std::cout<< "Value of v = "<< *v << std::endl;
        v++;
    }


    return 0;
}

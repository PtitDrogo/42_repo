#include <iostream>
#include <vector>


//THE BINARY SEARCH PART WILL WORK CORRECTLY AS DESCRIBED HERE
//PRAISE THE LORD

int binarySearch(const std::vector<int> &arr, int target);

int main(int argc, char const *argv[])
{
    std::vector<int> vector = {2, 4, 6, 7, 10, 14, 18, 21};
    std::vector<int> vector_to_insert = {5, 10, 15, 1, 50};

    for (unsigned int i = 0; i < vector_to_insert.size(); i++)
    {
        int index_to_insert = binarySearch(vector, vector_to_insert[i]);
        vector.insert(vector.begin() + index_to_insert, vector_to_insert[i]);
    }

    //DEBUG PRINTING THE PROPER RESULT
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    //END DEBUG
    
    return 0;
}


int binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left); // We want to know where the number should be, so we are returning left instead of -1;
}
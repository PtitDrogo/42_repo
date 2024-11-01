#include <vector>
#include <iostream>
#include <iterator>
#include <utility>

// Helper function to get the max value in a pair
int pairMax(int a, int b)
{
    return a > b ? a : b;
}

// Helper function to get the min value in a pair
int pairMin(int a, int b)
{
    return a < b ? a : b;
}

// Merge two sorted ranges of pairs
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> merged;
    std::vector<int>::iterator leftIt = left.begin();
    std::vector<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        // Compare max values of the current pairs
        int leftPairMax = pairMax(*leftIt, *(leftIt + 1));
        int rightPairMax = pairMax(*rightIt, *(rightIt + 1)); //this works in vector AND list

        if (leftPairMax <= rightPairMax)
        {
            merged.push_back(*leftIt);
            merged.push_back(*(leftIt + 1));
            leftIt += 2;
        }
        else
        {
            merged.push_back(*rightIt);
            merged.push_back(*(rightIt + 1));
            rightIt += 2;
        }
    }

    // Copy remaining pairs from left vector
    while (leftIt != left.end())
    {
        merged.push_back(*leftIt);
        merged.push_back(*(leftIt + 1));
        leftIt += 2;
    }

    // Copy remaining pairs from right vector
    while (rightIt != right.end())
    {
        merged.push_back(*rightIt);
        merged.push_back(*(rightIt + 1));
        rightIt += 2;
    }

    return (merged);
}

// Recursive merge sort implementation for pairs
std::vector<int> mergeSort(std::vector<int> &arr)
{
    if (arr.size() == 1)
        return arr;
    if (arr.size() == 2)
    {
       if (arr[0] > arr[1])
        std::swap(arr[0], arr[1]);
        return arr;
    }
    
    std::vector<int>::size_type middle = arr.size() / 2;
    middle = (middle / 2) * 2;


    std::vector<int> left(arr.begin(), arr.begin() + middle);
    std::vector<int> right(arr.begin() + middle, arr.end());


    left = mergeSort(left);
    right = mergeSort(right);

    return (merge(left, right));
}

// Utility function to print vector
void printVector(const std::vector<int> &arr)
{
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Example usage
int main()
{
    std::vector<int> arr;
    arr.push_back(0);
    arr.push_back(14);
    arr.push_back(6);
    arr.push_back(13);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(42);
    std::cout << "Original array: ";
    printVector(arr);

    // Create a new sorted vector
    bool is_odd = arr.size() % 2 != 0;
    int last_elem;
    
    if (is_odd)
    {
        last_elem = arr.back();
        arr.pop_back();
    }
    std::vector<int> sortedArr = mergeSort(arr);
    if (is_odd)
        sortedArr.push_back(last_elem);

    std::cout << "Sorted array: ";
    printVector(sortedArr);

    return 0;
}
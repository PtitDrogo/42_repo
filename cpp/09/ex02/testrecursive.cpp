#include <vector>
#include <iostream>
#include <iterator>

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right)
{
    std::vector<int> merged;
    std::vector<int>::const_iterator leftIt = left.begin();
    std::vector<int>::const_iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
            merged.push_back(*leftIt++);
        else
            merged.push_back(*rightIt++);
    }
    while (leftIt != left.end())
        merged.push_back(*leftIt++);
    while (rightIt != right.end())
        merged.push_back(*rightIt++);

    return merged;
}

std::vector<int> mergeSort(const std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    std::vector<int>::size_type middle = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + middle);
    std::vector<int> right(arr.begin() + middle, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

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
    arr.push_back(64);
    arr.push_back(34);
    arr.push_back(34);
    arr.push_back(200);
    arr.push_back(5);
    arr.push_back(124);
    arr.push_back(55);
    arr.push_back(25);
    arr.push_back(12);
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(90);

    std::cout << "Original array: ";
    printVector(arr);

    // Create a new sorted vector
    std::vector<int> sortedArr = mergeSort(arr);

    std::cout << "Sorted array: ";
    printVector(sortedArr);

    return 0;
}
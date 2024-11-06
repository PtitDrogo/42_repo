#ifndef P_MERGE_ME_TPP
# define P_MERGE_ME_TPP

#include "PmergeMe.h"

template<typename Container>
PmergeMe<Container>::PmergeMe() {}
template<typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> &other) : _container(other._container) {}
template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
void printContainer(const Container &arr)
{
    for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
size_t PmergeMe<Container>::size() const
{
    return (_container.size());
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _container = other._container;
    }
    return (*this);
}

template<typename Container>
const Container &PmergeMe<Container>::getContainer() const
{
    return (_container);
}

template<typename Container>
void PmergeMe<Container>::fillContainer(const int *array, int size)
{
    _container.insert(_container.end(), array, array + size);
}

template<typename Container>
void PmergeMe<Container>::epicSortWrapper()
{
    std::cout << "Before :"; printContainer(_container);
    
    bool is_odd = _container.size() % 2 != 0;
    int last_elem;
    if (is_odd)
    {
        last_elem = _container.back();
        _container.pop_back();
    }
    Container preSortedArr = epicSort(_container);
    Container largeElements = moveLargeElements(preSortedArr);
    if (is_odd)
        preSortedArr.push_back(last_elem);
    binaryInsert(preSortedArr, largeElements);
    
    std::cout << "After : "; printContainer(largeElements);
}

template<typename Container>
Container PmergeMe<Container>::moveLargeElements(Container& container)
{
    Container largeElements;
    typename Container::iterator it = container.begin();
    it++;
    for (; it != container.end(); it += 1)
    {
        largeElements.push_back(*it);
        it = container.erase(it);
        if (it == container.end() || it + 1 == container.end())
            break;
    }
    return (largeElements);
}

template<typename Container>
Container PmergeMe<Container>::epicSort(Container &container)
{
    if (container.size() == 1)
        return container;
    if (container.size() == 2)
    {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return container;
    }
    
    typename Container::size_type middle = container.size() / 2;
    middle = (middle / 2) * 2;


    Container left(container.begin(), container.begin() + middle);
    Container right(container.begin() + middle, container.end());


    left = epicSort(left);
    right = epicSort(right);

    return (merge(left, right));
}

template<typename Container>
Container PmergeMe<Container>::merge(Container &left, Container &right)
{
    Container merged;
    typename Container::iterator leftIt = left.begin();
    typename Container::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        int leftPairMax = pairMax(*leftIt, *(leftIt + 1));
        int rightPairMax = pairMax(*rightIt, *(rightIt + 1));

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
    while (leftIt != left.end())
    {
        merged.push_back(*leftIt);
        merged.push_back(*(leftIt + 1));
        leftIt += 2;
    }
    while (rightIt != right.end())
    {
        merged.push_back(*rightIt);
        merged.push_back(*(rightIt + 1));
        rightIt += 2;
    }

    return (merged);
}

template<typename Container>
void PmergeMe<Container>::binaryInsert(Container& small_container, Container& big_container)
{
    typename Container::iterator it = small_container.begin();
    typename Container::iterator index;

    while (it != small_container.end())
    {
        index = big_container.begin() + binarySearch(big_container, *it);
        big_container.insert(index, *it);
        it++;
    }
}


template<typename Container>
int PmergeMe<Container>::binarySearch(const Container &arr, int target)
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
    return (left);
}

#endif

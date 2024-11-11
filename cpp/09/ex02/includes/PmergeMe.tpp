#ifndef P_MERGE_ME_TPP
#define P_MERGE_ME_TPP

#include "PmergeMe.h"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> &other) : _container(other._container) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void printContainer(const Container &arr)
{
    for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
size_t PmergeMe<Container>::size() const
{
    return (_container.size());
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _container = other._container;
    }
    return (*this);
}

template <typename Container>
const Container &PmergeMe<Container>::getContainer() const
{
    return (_container);
}

template <typename Container>
void PmergeMe<Container>::fillContainer(const int *array, int size)
{
    _container.insert(_container.end(), array, array + size);
}

template <typename Container>
void PmergeMe<Container>::epicSortWrapper()
{
    if (_container.size() == 1)
        return;
    bool is_odd = _container.size() % 2 != 0;
    int last_elem;
    if (is_odd)
    {
        last_elem = _container.back();
        _container.pop_back();
    }

    Container preSortedArr = epicSort(_container);
    _container = moveLargeElements(preSortedArr);
    if (is_odd)
        preSortedArr.push_back(last_elem);
    binaryInsert(preSortedArr);
}

template <typename Container>
Container PmergeMe<Container>::moveLargeElements(Container &container)
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

template <typename Container>
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

template <typename Container>
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

template <typename Container>
void PmergeMe<Container>::binaryInsert(Container &small_container)
{
    typename Container::iterator index_big;
    typename Container::iterator index_small_start;
    typename Container::iterator index_small_end;
    const size_t jacobsthal[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525}; //got rid of one 1s.
    int js_len = sizeof(jacobsthal) / sizeof(size_t);
    
    //I do a sliding window.
    // I go from End to start each time, then reset start to be End + 1 AND end to be jacobstal[i++];

    std::cout << "big container : ";
    printContainer(_container); std::cout << std::endl;
    std::cout << "small container : ";
    printContainer(small_container); std::cout << std::endl; 
   
    
    //I do it once for the index 0; This is hacky i guess;
    index_big = _container.begin() + binarySearch(_container, small_container[0]);
    _container.insert(index_big, small_container[0]);
   for (int i = 0; i < js_len; i++)
   {
        if (jacobsthal[i] > small_container.size())
            break ;

        //Inserting everything before the index of jacobsthal;
        std::cout << "the value of i now is " << i << ", so that means fucking jacobsthal[i] is :" << jacobsthal[i] << std::endl;
        index_small_start = small_container.begin() + jacobsthal[i];
        index_small_end = small_container.begin() + jacobsthal[i + 1]; //THIS WILL CRASH EVENTUALLY;
        std::cout << "Start index (aka the value i will end my loop at) is " << *index_small_start << std::endl;
        std::cout << "end index (aka the value i will start my loop at) is " << *index_small_end << std::endl;
        
        while (index_small_end != index_small_start)
        {
            //We insert into the big array;
            index_big = _container.begin() + binarySearch(_container, *index_small_end);
            _container.insert(index_big, *index_small_end);
            std::cout << "Inserting : " << *index_small_end << std::endl;
            //After doing the fucking jacob insert, we insert the one before until we go to the start;
            index_small_end--;
        }
   }
    // std::cout << "size of container is : " << small_container.size() << std::endl;

    //We then insert the rest
    // typename Container::iterator it = small_container.begin();
    // it = small_container.begin();
    // while (it != small_container.end())
    // {
    //     index_big = _container.begin() + binarySearch(_container, *it);
    //     _container.insert(index_big, *it);
    //     it++;
    // }
}

template <typename Container>
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

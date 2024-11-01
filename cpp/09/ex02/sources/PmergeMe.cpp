#include "PmergeMe.h"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) : _vector(other._vector)
{
}
PmergeMe::~PmergeMe() {}


void printVector(const std::vector<int> &arr)
{
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
    }
    return (*this);
}
const std::vector<int> &PmergeMe::getVector() const
{
    return (_vector);
}

std::ostream &operator<<(std::ostream &out, PmergeMe const &fixed)
{
    std::vector<int> vec = fixed.getVector();
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return (out);
}

void PmergeMe::fillVector(const int *array, int size)
{
    // std::cout << size << std::endl;
    _vector.insert(_vector.end(), array, array + size);
    // _vector.insert(_vector.end(), &array[0], &array[size]);
}

/*
l y a 5 étapes je vais essayer de t'expliquer et de les illustrer avec un exemple :
Tu as cette entrée : 33 2 15 8 99 4
faire des paires avec le plus grand d'un coté et le plus petit de l'autre  : 33 2 15 8 99 4 = >  2 33 8 15 4 99
trier les paires par leur plus grand nombre par récursion : 2 33 8 15 4 99 = > 8 15 2 33 4 99   
//RECURSION ENDS HERE I GUESS
Mettre les plus petits dans un tableau et les plus grands dans un autre : 8 2 4 | 15 33 99
Vu que les paires étaient triés le tableau des grands est trié, tu ajoutes le petit de la première paire 8 au premier index du tableau des grands : 2 4 | 8 15 33 99
Tu ajoutes les petits dans la tableau des grands avec un binary search (recherche dichotomique)
Pour optimiser la dernière étape tu utilises la suite de Jacobsthal (https://fr.wikipedia.org/wiki/Suite_de_Jacobsthal)
*/

void PmergeMe::epicSortWrapper()
{
    std::cout << "Before :" << *this << std::endl;
    bool is_odd = _vector.size() % 2 != 0;
    int last_elem;
    if (is_odd)
    {
        last_elem = _vector.back();
        _vector.pop_back();
    }
    std::vector<int> preSortedArr = epicSort(_vector);
    std::vector<int> largeElements = moveLargeElements(preSortedArr);
    if (is_odd)
        preSortedArr.push_back(last_elem);
    binaryInsert(preSortedArr, largeElements);
    std::cout << "After : "; printVector(largeElements);
}

std::vector<int> PmergeMe::moveLargeElements(std::vector<int>& vector)
{
    std::vector<int> largeElements;
    std::vector<int>::iterator it = vector.begin();
    it++;
    for (; it != vector.end(); it += 1)
    {
        largeElements.push_back(*it);
        it = vector.erase(it);
        //Erase returns the iterator AFTER the one it just deleted; ence why this entire thing works;
        if (it == vector.end() || it + 1 == vector.end())
            break;
    }
    return (largeElements);
}

std::vector<int> PmergeMe::epicSort(std::vector<int> &vector)
{
    if (vector.size() == 1)
        return vector;
    if (vector.size() == 2)
    {
        if (vector[0] > vector[1])
            std::swap(vector[0], vector[1]);
        return vector;
    }
    
    std::vector<int>::size_type middle = vector.size() / 2;
    middle = (middle / 2) * 2;
    std::vector<int> left(vector.begin(), vector.begin() + middle);
    std::vector<int> right(vector.begin() + middle, vector.end());
    left = epicSort(left);
    right = epicSort(right);
    return (merge(left, right));
}

std::vector<int> PmergeMe::merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> merged;
    std::vector<int>::iterator leftIt = left.begin();
    std::vector<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        int leftPairMax = std::max(*leftIt, *(leftIt + 1));
        int rightPairMax = std::max(*rightIt, *(rightIt + 1)); //this works in vector AND list

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

void PmergeMe::binaryInsert(std::vector<int>& small_vector, std::vector<int>& big_vector)
{
    std::vector<int>::iterator it = small_vector.begin();
    std::vector<int>::iterator index;

    //We can insert the first number its always correct;
    big_vector.insert(big_vector.begin(), *it);
    it++;
    while (it != small_vector.end())
    {
        index = big_vector.begin() + binarySearch(big_vector, *it);
        big_vector.insert(index, *it);
        it++;
    }
}



int PmergeMe::binarySearch(const std::vector<int> &arr, int target)
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
    return (left); //We want to know where the number should be, so we are returning left instead of -1;
}

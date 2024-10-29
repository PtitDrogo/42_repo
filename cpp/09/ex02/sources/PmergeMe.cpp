#include "PmergeMe.h"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) : _vector(other._vector)
{
}
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
    }
    return (*this);
}
const std::vector<int>&PmergeMe::getVector() const
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
Mettre les plus petits dans un tableau et les plus grands dans un autre : 8 2 4 | 15 33 99
Vu que les paires étaient triés le tableau des grands est trié, tu ajoutes le petit de la première paire 8 au premier index du tableau des grands : 2 4 | 8 15 33 99
Tu ajoutes les petits dans la tableau des grands avec un binary search (recherche dichotomique)
Pour optimiser la dernière étape tu utilises la suite de Jacobsthal (https://fr.wikipedia.org/wiki/Suite_de_Jacobsthal) 
*/


void PmergeMe::epicSort()
{
    //hi
    std::cout << "Before :" << *this << std::endl;
    size_t size = _vector.size();
    if (size < 2)
        return ;
    bool has_stray = (size % 2 != 0);
    if (has_stray) //If we have an odd numbers of numbers, I want to ignore the last one in the pair sorting business
        size--;
    size--;
    for (unsigned int i = 0; i < size; i++)
    {
        if (_vector[i] < _vector[i + 1])
            std::swap(_vector[i], _vector[i + 1]);
    }
    // Step 2: Perform comparisons to determine the larger element in each pair
    std::vector<int> larger_elements;
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].second == -1) {
            larger_elements.push_back(pairs[i].first);
        } else {
            larger_elements.push_back(std::max(pairs[i].first, pairs[i].second));
        }
    }
    std::cout << "Post pair sort : " << *this << std::endl;
}


int PmergeMe::binarySearch(const std::vector<int>& arr, int target) 
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
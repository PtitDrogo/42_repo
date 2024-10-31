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
Mettre les plus petits dans un tableau et les plus grands dans un autre : 8 2 4 | 15 33 99
Vu que les paires étaient triés le tableau des grands est trié, tu ajoutes le petit de la première paire 8 au premier index du tableau des grands : 2 4 | 8 15 33 99
Tu ajoutes les petits dans la tableau des grands avec un binary search (recherche dichotomique)
Pour optimiser la dernière étape tu utilises la suite de Jacobsthal (https://fr.wikipedia.org/wiki/Suite_de_Jacobsthal)
*/

void PmergeMe::epicSortWrapper()
{
    std::cout << "Before :" << *this << std::endl;
    _vector = epicSort(_vector);
    std::cout << "After : " << *this << std::endl;
}

std::vector<int> PmergeMe::epicSort(std::vector<int> &vector)
{
    // hi

    int n = vector.size();

    if (n <= 1)
    {
        return vector;
    }
    if (n == 2)
    {
        if (vector[0] < vector[1])
            std::swap(vector[0], vector[1]);
        return vector;
    }

    // Step 1: Group the elements into pairs
    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
        }
        else
        {
            continue;
            // pairs.push_back(std::make_pair(vector[i], -1)); //-1 method doesnt actually work.
        }
    }

    // std::cout << "Printing content of my vector of pairs" << std::endl;
    // for (unsigned int i = 0; i < pairs.size(); i++)
    // {
    //     std::cout << pairs[i].first << " "<< pairs[i].second << " "; 
    // }
    // std::cout << std::endl;

    // Step 2: Perform comparisons to determine the larger element in each pair
    std::vector<int> larger_elements;
    for (unsigned int i = 0; i < pairs.size(); i++)
    {
        // if (pairs[i].second == -1)
        //     continue;// larger_elements.push_back(pairs[i].first);
            //I wanna swap I think;
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
        larger_elements.push_back(pairs[i].second);
    }


    std::cout << "Printing content of my vector of pairs after swap" << std::endl;
    for (unsigned int i = 0; i < pairs.size(); i++)
    {
        std::cout << pairs[i].first << " "<< pairs[i].second << " "; 
    }
    std::cout << std::endl;

    //Recursion Time
    std::vector<int> S = epicSort(larger_elements);
    std::cout << "Printing content of my big vector" << std::endl;
    for (unsigned int i = 0; i < S.size(); i++)
    {
        std::cout << S[i] << " "; 
    }
    return S;


    // // Step 4: Insert the smaller element from each pair at the start of S
    //Technically this isnt even needed for this shit to Work

    // // Step 5: Insert the remaining elements into S using binary search
    // for (int i = 0; i < n; i++)
    // {
    //     if (std::find(S.begin(), S.end(), vector[i]) == S.end())
    //     {
    //         S.insert(S.begin() + binarySearch(S, vector[i]), vector[i]);
    //     }
    // }
    // for (unsigned int i = 0; i < vector_to_insert.size(); i++)
    // {
    //     int index_to_insert = binarySearch(vector, vector_to_insert[i]);
    //     vector.insert(vector.begin() + index_to_insert, vector_to_insert[i]);
    // }

    // return S;
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
    return (left); // We want to know where the number should be, so we are returning left instead of -1;
}
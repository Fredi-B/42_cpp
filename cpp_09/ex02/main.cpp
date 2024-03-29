#include "PmergeMe.hpp"
#include <sstream>
#include <iomanip>

bool    isInputCorrect(int argc, char** argv);
bool    isNumber(std::string arg);
void    fillSequence(std::vector<int> *sequence, int argc, char **argv);
void    printResults(PmergeMe<std::multiset<int> > &mergeSet, PmergeMe<std::priority_queue<int> > &mergeQueue);

int main(int argc, char** argv)
{
    std::vector<int>    sequence;

    if (!isInputCorrect(argc, argv))
        return (1);
    fillSequence(&sequence, argc, argv);

    PmergeMe<std::multiset<int> >        mergeSet(sequence);
    PmergeMe<std::priority_queue<int> >  mergeQueue(sequence);

    mergeSet.sort_sequence();
    mergeQueue.sort_sequence();
    printResults(mergeSet, mergeQueue);
    return (0);
}

void    printResults(PmergeMe<std::multiset<int> > &mergeSet, PmergeMe<std::priority_queue<int> > &mergeQueue)
{
    std::multiset<int>::const_iterator  it_set;

    std::cout << "Before:";
    for (std::vector<int>::const_iterator it = mergeSet.getSequence().begin(); \
            it != mergeSet.getSequence().end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::multiset<int>::const_iterator it = mergeSet.begin(mergeSet); \
            it != mergeSet.end(mergeSet); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::cout << std::setprecision(7) << std::fixed;
    std::cout << "Time to process a range of " <<  mergeSet.getSize() << " elements "\
                << "with std::multiset:       " << mergeSet.getSortingTime() << " us" << std::endl;
    std::cout << "Time to process a range of " <<  mergeQueue.getSize() << " elements "\
                <<"with std::priority_queue: " << mergeQueue.getSortingTime() << " us" << std::endl;
}

void    fillSequence(std::vector<int> *sequence, int argc, char **argv)
{
    std::stringstream   magical_converter_stream;
    unsigned int        next_int;

    for (int i = 1; i < argc; i++)
    {
        magical_converter_stream << argv[i];
        magical_converter_stream >> next_int;
        magical_converter_stream.clear();
        sequence->push_back(next_int);
    }
    return ;
}

bool    isInputCorrect(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return (false);
    }
    if (argc > 3010)
    {
        std::cout << "Too many arguments" << std::endl;
        return (false);
    }
    for (int i = 1; i < argc; i++)
    {
        if (!isNumber(argv[i]))
            return (false);
    }
    return (true);
}

bool    isNumber(std::string arg)
{
    for (unsigned long i = 0; i < arg.length(); i++)
    {
        if (!std::isdigit(arg.at(i)))
        {
            std::cout << "Error: wrong input" << std::endl;
            return (false);
        }
    }
    return (true);
}

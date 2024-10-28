#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <iomanip> // For controlling floating-point precision
#include <sstream>
#include <sys/time.h>


class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		float _vectorSortTime;
		float _dequeSortTime;
		
		void _mergeInsertSortVector();
		void _mergeInsertSortDeque();
	    template <typename Container>
		bool _isValidNumber(const Container &input);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &other);

		bool setVector(const std::vector<int> &inputVec);
		void sortVector();
		void printVector() const; 
		float getVectorSortTime() const;

		bool setDeque(const std::deque<int> &inputDeq);
		void sortDeque();
		void printDeque() const;
		float getDequeSortTime() const;

};


template <typename Container>
bool PmergeMe::_isValidNumber(const Container &input)
{
	typename Container::const_iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        std::stringstream ss;
        ss << *it;  // Convert the element to a string
        
        int number;
        // Try converting the string back to an integer
        if (!(ss >> number)) 
        {
            std::cerr << "Error: Not a valid number.\n";
            return false;
        }
        // Check if there's still something left in the stream
        if (ss.fail() || !ss.eof()) 
        {
            std::cerr << "Error: Not a valid number.\n";
            return false;
        }
    }
    return true;
}

#endif

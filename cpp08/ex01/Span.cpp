#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span& Span::operator=(const Span &obj)
{
	if (this != &obj) {
        this->_maxSize = obj._maxSize;
        this->_numbers = obj._numbers;
    }
    return *this;
}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}


void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();
    
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = sorted[1] - sorted[0];
    for (unsigned int i = 1; i < sorted.size() - 1; ++i)
	{
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is already full!\n";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate a span!\n";
}

const std::vector<int>& Span::getNumbers() const {
        return this->_numbers;
}

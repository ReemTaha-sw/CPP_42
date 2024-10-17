#include "Span.hpp"

template <typename T>
void Span::addNumbers(T begin, T end)
{
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
        throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end);
}
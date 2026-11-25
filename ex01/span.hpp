#pragma once

#include <vector>
#include <stdexcept>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int     _maxSize;

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;
};


/*
 * Longest span is just the max - min
 *
 * Shortest span: 
 * - sort the array (in a copy)
 * - check the smallest difference between all steps
 *
 * Pitfalls
 * 	MaxSize reached
 * 	Not enough numbers for Span (<2)
*/

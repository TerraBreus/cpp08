#include "span.hpp"
#include <iostream>
#include <algorithm>

void	Span::addNumber(int n) {
	if (_numbers.size() == _maxSize)
		throw (std::overflow_error("Maximum size reached."));
	_numbers.push_back(n);
}

int		Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw (std::logic_error("Cannot have span if size is smaller than 2 (two)."));
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());

	int min_span = -1;
	std::vector<int>::const_iterator it;
	for (it = copy.begin() + 1; it != copy.end(); it++) {
		int step = *it - *(it - 1);
		if (step < min_span || min_span == -1)
			min_span = step;
	}

	return (min_span);
}

int		Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw (std::logic_error("Cannot have span if size is smaller than 2 (two)."));
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

Span::Span(unsigned int n) : _maxSize(n) {};

Span&	Span::operator=(const Span& other) {
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_maxSize = other._maxSize;
	}
	return (*this);
};

Span::Span(const Span& other){
	*this = other;
}

Span::~Span() {};

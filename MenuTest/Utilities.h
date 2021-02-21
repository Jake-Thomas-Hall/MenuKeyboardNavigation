#include <iostream>
#include <algorithm>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

#ifndef H_UTILITIES
#define H_UTILITIES
namespace util {
	template <typename IteratorT, typename FunctionT>
	FunctionT for_each_iterator(IteratorT first, IteratorT last, int initial, FunctionT func) {
		for (; first != last; ++first, ++initial)
			func(initial, *first);
		return func;
	}

	void Pause();
}

#endif // !H_UTILITIES


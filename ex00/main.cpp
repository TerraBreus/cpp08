#include "easyfind.hpp"
#include <vector>
#include <iostream>

/*
 * Associative containers do not need to be handled!
 *
 * Associative: meaning entries are associated with something. (key, value)
 * Most common examples are std::pair, std::map, std::unorder_map
*/

int main(void)
{
	{
		std::vector<int> victor;

		victor.push_back(12);
		victor.push_back(59);
		victor.push_back(99);

		try
		{
			std::vector<int>::iterator it = easyfind(victor, 12);
			std::cout << *it << std::endl;
			it = easyfind(victor, 12200);
		}
		catch (const easyfind_exception<int>& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "additional data: " << e.what_data() << std::endl;
		}
	}

}

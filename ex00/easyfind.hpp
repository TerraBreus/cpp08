#include <exception>
#include <string>

template <typename T>
class easyfind_exception : public std::exception
{
		std::string		message;
		T				data;
	public :
		explicit easyfind_exception(std::string m, T d) : message(m), data(d) {};

		const char* what() const noexcept override {
			return (message.c_str());}
		T what_data() const noexcept {
			return (data);}
};

template <typename T>
typename T::iterator easyfind(T& ref, int to_find)
{
	typename T::iterator it = ref.begin();
	while (it != ref.end())
	{
		if (*it == to_find)
			break ;
		it++;
	}
	if (it == ref.end())
		throw (easyfind_exception<int>("not found", to_find));
	else 
		return it;
}

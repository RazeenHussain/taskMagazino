#include <iostream>
#include <list>
#include <string>
#include <locale>         // std::locale, std::tolower

class Node
{
public:
	Node(std::string name, std::list<Node> children = {})
	{
		name_ = name;
		children_ = children;
	};

	static int cToLower(int c) {
		return tolower(c);
	}

	int count_nodes_containing_string(std::string needle)
	{
		int count = 0;
		for (std::string::size_type i = 0; i<needle.length(); ++i)
			needle[i] = cToLower(needle[i]);
		for (std::string::size_type i = 0; i<name_.length(); ++i)
			name_[i] = cToLower(name_[i]);
		std::size_t found = name_.find(needle);
		if (found != std::string::npos)
			count++;
		for (std::list<Node>::iterator i = children_.begin(); i != children_.end(); i++)
		{
			count += i->count_nodes_containing_string(needle);
		}
		return count;
	}
private:
	std::string name_;
	std::list<Node> children_;
};

#ifndef RunTests
int main()
{
	//Create an example tree
	Node n("roOT", {
		{ "MagaZino",{
			{ "I" },
			{ "Love" },
			{ "magazino" }
		} },
		{ "Hello",{
			{ "Hello",{
				{ "Hello",{
					{ "World" }
				} }
			} }
		} }
	});
	//Cout the solution
	std::cout << n.count_nodes_containing_string("test") << std::endl;
}
#endif
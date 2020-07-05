#include "SortedVector.hpp"

#include <fmt/format.hpp>
#include <fmt/ranges.hpp>

int main()
{
	fmt::print("Wooooo\n");
	{
		const OK::SortedVector<int> sv;
		fmt::print("Default       : {}\n", sv.vector());
	}
	{
		const OK::SortedVector<int> sv {1, 2, 3, 4, -5, 0, 69, -420};
		fmt::print("Initializer   : {}\n", sv.vector());
	}
	{
		const OK::SortedVector<int> sv(4ULL);
		fmt::print("Count         : {}\n", sv.vector());
	}
	{
		const OK::SortedVector<int> sv(6ULL, 3);
		fmt::print("Count & Value : {}\n", sv.vector());
	}
	{
		OK::SortedVector<int> _ {1, 2, 3, 4, 5, -42};
		fmt::print("Orig. before  : {}\n", _.vector());
		const OK::SortedVector<int> sv {std::move(_)};
		fmt::print("MoveConst     : {}\n", sv.vector());
		fmt::print("Orig. after   : {}\n", _.vector());
	}
	{
		OK::SortedVector<int> sv {-2, 4, 2, 3, -2, 5, 69, 0, 1, -99};
		fmt::print("push()        : {}\n", sv.vector());
		sv.push(420);
		sv.push(-420);
		sv.push(69);
		sv.push(-7);
		sv.push(-69);
		sv.push(7);
		fmt::print("Pushing [420, -420, 69, -7, -69, 7]\n");
		fmt::print("push()        : {}\n", sv.vector());
	}
	{
		OK::SortedVector<int> sv {-2, 4, 2, 3, -2, 5, 69, 0, 1, -99, 923};
		sv.push(420);
		sv.push(-420);
		sv.push(69);
		sv.push(-7);
		sv.push(-69);
		sv.push(7);
		fmt::print("push & pop    : {}\n", sv.vector());
		sv.pop();
		fmt::print("push & pop    : {}\n", sv.vector());
		sv.pop();
		fmt::print("push & pop    : {}\n", sv.vector());
	}

	return 0;
}

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

	return 0;
}

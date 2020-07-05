#pragma once

#include <algorithm>
#include <initializer_list>
#include <numeric>
#include <utility>
#include <vector>

namespace OK
{
// TODO: Do some concept shit, check for equality and less than
template<typename T>
class SortedVector final
{
public:
	constexpr SortedVector() noexcept = default;
	constexpr SortedVector(std::size_t count) noexcept : m_vector(count) {}
	constexpr SortedVector(std::size_t count, const T& value) noexcept : m_vector(count, value) {}

	template<typename Iter>
	constexpr SortedVector(Iter first, Iter last) noexcept : m_vector {first, last}
	{
		sort();
	}

	constexpr SortedVector(const SortedVector& other) noexcept : m_vector {other} { sort(); }

	constexpr SortedVector(SortedVector&& other) noexcept : m_vector {std::move(other.m_vector)}
	{
		sort();
	}

	constexpr SortedVector(std::initializer_list<T> init) noexcept : m_vector {init} { sort(); }

	constexpr std::size_t size() const noexcept { return m_vector.size(); }
	constexpr std::size_t capacity() const noexcept { return m_vector.capacity(); }
	constexpr std::vector<T>& vector() noexcept { return m_vector; }
	constexpr const std::vector<T>& vector() const noexcept { return m_vector; }

private:
	std::vector<T> m_vector {};

	constexpr void sort() noexcept { std::sort(m_vector.begin(), m_vector.end()); }
};
}	 // namespace OK

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
	// Constructors
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

	// Getters
	[[nodiscard]] constexpr std::size_t size() const noexcept { return m_vector.size(); }
	[[nodiscard]] constexpr std::size_t capacity() const noexcept { return m_vector.capacity(); }
	[[nodiscard]] constexpr std::vector<T>& vector() noexcept { return m_vector; }
	[[nodiscard]] constexpr const std::vector<T>& vector() const noexcept { return m_vector; }

	constexpr typename std::vector<T>::iterator begin() noexcept { return m_vector.begin(); }
	constexpr typename std::vector<T>::const_iterator cbegin() const noexcept
	{
		return m_vector.cbegin();
	}
	constexpr typename std::vector<T>::iterator end() noexcept { return m_vector.end(); }
	constexpr typename std::vector<T>::const_iterator cend() const noexcept
	{
		return m_vector.cend();
	}

	// Modifiers
	void push(const T& val) noexcept { m_vector.insert(push_iter(val), val); }

private:
	std::vector<T> m_vector {};

	constexpr void sort() noexcept { std::sort(m_vector.begin(), m_vector.end()); }
	constexpr typename std::vector<T>::const_iterator push_iter(const T& val) const noexcept
	{
		auto pivot = std::next(m_vector.cbegin(), m_vector.size() / 2ULL);
		// How to make this loop?
		while(val < *pivot)
		{
			const auto dist = std::distance(m_vector.cbegin(), pivot);
			if(dist == 1)
				break;
			pivot = std::next(m_vector.cbegin(), dist);
		}

		while(*pivot < val)
		{
			const auto dist = std::distance(pivot, m_vector.cend());
			if(dist == 1)
				break;
			pivot = std::next(pivot, dist);
		}

		return pivot;
	}
};
}	 // namespace OK

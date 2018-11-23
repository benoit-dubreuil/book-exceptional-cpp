#pragma once

#include <array>
#include <iostream>

template <typename T, std::size_t Size>
class FixedVector
{
	using ArrayType = std::array<T, Size>;
	ArrayType m_data;

public:
	using iterator = typename ArrayType::iterator;
	using const_iterator = typename ArrayType::const_iterator;

	FixedVector() = default;

	FixedVector(const FixedVector<T, Size>& other)
	{
		copy(other.begin(), other.end(), begin());
		std::cout << "Copy constructor" << std::endl;
	}

	FixedVector<T, Size>& operator=(const FixedVector<T, Size>& other)
	{
		copy(other.begin(), other.end(), begin());
		std::cout << "Copy assignment" << std::endl;

		return *this;
	}

	template <typename O, size_t OSize>
	FixedVector(const FixedVector<O, OSize>& other)
	{
		copy(other.begin(), other.begin() + std::min(Size, OSize), begin());
		std::cout << "Conversion constructor" << std::endl;
	}

	template <typename O, size_t OSize>
	FixedVector<T, Size>& operator=(const FixedVector<O, OSize>& other)
	{
		copy(other.begin(), other.begin() + std::min(Size, OSize), begin());
		std::cout << "Conversion assignment" << std::endl;

		return *this;
	}

	iterator begin()
	{
		return m_data.begin();
	}

	const_iterator begin() const
	{
		return m_data.cbegin();
	}

	const_iterator cbegin() const
	{
		return m_data.cbegin();
	}

	iterator end()
	{
		return m_data.end();
	}

	const_iterator end() const
	{
		return m_data.cend();
	}

	const_iterator cend() const
	{
		return m_data.cend();
	}

	static constexpr std::size_t size()
	{
		return Size;
	}
};


#pragma once

#include "../MemoryUtils.h"

// For learning purposes, the global operators new and delete are used. Ideally, the std::allocator class should be used.
template <typename T>
class StackArrayImpl
{
public:

	size_t size;
	size_t usedOffset;
	T* data;

	explicit StackArrayImpl(size_t size = 0) noexcept : size(size), usedOffset(), data(size ? MemoryUtils::allocate<T>(size) : nullptr)
	{
	}

	// Does not actually copy the data, only reserve enough memory and set the properties.
	explicit StackArrayImpl(const StackArrayImpl& other) noexcept : StackArrayImpl(other.size)
	{
	}

	StackArrayImpl(StackArrayImpl&& other) noexcept : StackArrayImpl()
	{
		swap(*this, other);
	}

	~StackArrayImpl() noexcept
	{
		MemoryUtils::placementDestruct(data, data + usedOffset);
		MemoryUtils::deallocate(data);
	}

	friend void swap(StackArrayImpl& lhs, StackArrayImpl& rhs) noexcept
	{
		using std::swap;

		swap(lhs.size, rhs.size);
		swap(lhs.usedOffset, rhs.usedOffset);
		swap(lhs.data, rhs.data);
	}

private:
	StackArrayImpl& operator=(const StackArrayImpl&) = delete;
};
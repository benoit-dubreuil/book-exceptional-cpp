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

	explicit StackArrayImpl(size_t size = 0) : size(size), usedOffset(), data(size ? static_cast<T*>(operator new(sizeof(T) * size)) : nullptr)
	{
	}

	// Does not actually copy the data, only reserve enough memory and set the properties.
	explicit StackArrayImpl(const StackArrayImpl& other) : StackArrayImpl(other.size)
	{
	}

	~StackArrayImpl()
	{
		MemoryUtils::placementDestruct(data, data + usedOffset);
		operator delete(data);
	}

private:
	StackArrayImpl& operator=(const StackArrayImpl&) = delete;
};
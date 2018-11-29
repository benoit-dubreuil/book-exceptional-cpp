#pragma once

#include "../MemoryUtils.h"

// For learning purposes, the global operators new and delete are used. Ideally, the std::allocator class should be used.
template <typename T>
class StackArrayImpl
{
	size_t m_size;
	size_t m_usedOffset;
	T* m_data;

public:
	explicit StackArrayImpl(size_t size = 0) : m_size(size), m_usedOffset(), m_data(size ? operator new(sizeof(T) * size) : nullptr)
	{
	}

	~StackArrayImpl()
	{
		MemoryUtils::placementDestruct(m_data, m_data + m_usedOffset);
		operator delete(m_data);
	}
};
#pragma once

#include "../MemoryUtils.h"

template <typename T, typename Impl>
class StackContainer
{
	Impl m_impl;

public :
	explicit StackContainer() = default;

	template <typename... TImplArgs>
	explicit StackContainer(TImplArgs... implArgs) : m_impl(implArgs...)
	{
	}

	StackContainer(const StackContainer& other) : m_impl(other.m_impl)
	{
		while (m_impl.usedOffset < other.m_impl.usedOffset)
		{
			MemoryUtils::placementNew(m_impl.data + m_impl.usedOffset, other.m_impl.data[m_impl.usedOffset]);
			++m_impl.usedOffset;
		}
	}

	StackContainer(StackContainer&& other) : StackContainer()
	{
		swap(*this, other);
	}

	StackContainer& operator=(StackContainer other)
	{
		swap(*this, other);

		return *this;
	}

	friend void swap(StackContainer& lhs, StackContainer& rhs) noexcept
	{
		using std::swap;

		swap(lhs.m_impl, rhs.m_impl);
	}

	size_t getReservedSize() const
	{
		return m_impl.size;
	}

	size_t getUsedSize() const
	{
		return m_impl.usedOffset;
	}
};
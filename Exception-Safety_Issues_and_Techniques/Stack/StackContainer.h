#pragma once

#include "../MemoryUtils.h"

template <typename T, typename Impl>
class StackContainer
{
	Impl m_impl;

public:
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

	void push(const T& element)
	{
		if (m_impl.usedOffset == m_impl.size)
		{
			StackContainer tmp(increaseSize(m_impl.size));

			while (tmp.count() < m_impl.usedOffset)
			{
				tmp.push(m_impl.data[tmp.count()]);
			}

			tmp.push(element);

			using std::swap;
			swap(m_impl, tmp.m_impl);
		}
		else
		{
			MemoryUtils::placementNew(m_impl.data + m_impl.usedOffset, element);
			++m_impl.usedOffset;
		}
	}

	T& top()
	{
		if (m_impl.usedOffset == 0)
		{
			throw "Empty stack";
		}

		return m_impl.data[m_impl.usedOffset - 1];
	}

	void pop()
	{
		if (m_impl.usedOffset == 0)
		{
			throw "Pop from empty stack";
		}
		else
		{
			--m_impl.usedOffset;
			MemoryUtils::placementDestruct(m_impl.data + m_impl.usedOffset);
		}
	}

	// The reserved memory
	size_t size() const
	{
		return m_impl.size;
	}

	// The actual element count
	size_t count() const
	{
		return m_impl.usedOffset;
	}

private:
	static size_t increaseSize(size_t size)
	{
		return size * 2 + 1;
	}
};
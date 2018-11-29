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
};
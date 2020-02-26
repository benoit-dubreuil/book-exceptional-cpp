#pragma once

#include <utility>

class MemoryUtils final
{
	MemoryUtils() = delete;

public:
	
	template <typename T, typename... TArgs>
	static void placementNew(T* const ptr, TArgs&&... args)
	{
		new (ptr) T(std::forward<TArgs>(args)...);
	}

	template <typename T>
	static void placementDestruct(T* const ptr)
	{
		ptr->~T();
	}

	template <typename ForwardIterator>
	static void placementDestruct(ForwardIterator first, ForwardIterator last)
	{
		while (first != last)
		{
			placementDestruct(&*first);
			++first;
		}
	}
};
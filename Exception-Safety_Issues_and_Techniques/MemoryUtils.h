#pragma once

class MemoryUtils final
{
	MemoryUtils() = delete;

public:
	
	template <typename T, typename... TArgs>
	static void placementNew(T* const ptr, const TArgs&... args)
	{
		new (ptr) T(args...);
	}

	template <typename T>
	static void placementDestruct(T* const ptr)
	{
		ptr->~T();
	}

	template <class ForwardIterator>
	static void placementDestruct(ForwardIterator first, ForwardIterator last)
	{
		while (first != last)
		{
			placementDestruct(&*first);
			++first;
		}
	}
};
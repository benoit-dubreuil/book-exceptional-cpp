#pragma once

#include <utility>

class MemoryUtils final
{
	MemoryUtils() = delete;

public:
	
	template<typename T>
	static T* allocate()
	{
		return static_cast<T*>(operator new(sizeof(T)));
	}

	template<typename T, typename size_t = std::size_t>
	static T* allocate(size_t size)
	{
		return static_cast<T*>(operator new(sizeof(T) * size));
	}

	template<typename T>
	static void deallocate(T* ptr)
	{
		operator delete(ptr);
	}

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
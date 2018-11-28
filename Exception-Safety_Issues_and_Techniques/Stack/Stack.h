#pragma once

#include "StackContainer.h"
#include "StackArrayImpl.h"
#include "StackLinkedImpl.h"

template <typename T>
using Stack = StackContainer<T, StackArrayImpl>;

template <typename T>
using StackArray = StackContainer<T, StackArrayImpl>;

template <typename T>
using StackLinked = StackContainer<T, StackLinkedImpl>;
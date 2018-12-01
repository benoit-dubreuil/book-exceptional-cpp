#pragma once

#include <memory>

#include "StackContainer.h"
#include "StackArrayImpl.h"

template <typename T>
using Stack = StackContainer<T, StackArrayImpl<T>>;

template <typename T>
using StackArray = StackContainer<T, StackArrayImpl<T>>;
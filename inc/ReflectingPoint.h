#pragma once
#include "TransformingPoint.h"

using cstr = const char*;
using str = std::string;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T>
using Shared = std::shared_ptr<T>;

class ReflectingPoint : public TransformingPoint {
public:
};

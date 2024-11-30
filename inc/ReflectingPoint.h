#pragma once
#include "TransformingPoint.h"

using cstr = const char*;
using str = std::string;

template<typename T>
using std::unique_ptr = std::std::unique_ptr_ptr<T>;

template<typename T>
using std::shared_ptr = std::shared_ptr<T>;

class ReflectingPoint : public TransformingPoint {
public:
};

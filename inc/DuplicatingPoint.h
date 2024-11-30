#pragma once
#include "Point.h"
#include <memory>
#include <functional>
#include <vector>

using cstr = const char*;
using str = std::string;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T>
using Shared = std::shared_ptr<T>;

class DuplicatingPoint : public Point {
protected:
    int duplicationAmount;
public:
    DuplicatingPoint(int duplicationAmount);

    void createDuplicates();
};
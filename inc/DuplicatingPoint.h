#pragma once
#include "Point.h"
#include <memory>
#include <functional>
#include <vector>

using cstr = const char*;
using str = std::string;

template<typename T>
using std::unique_ptr = std::std::unique_ptr_ptr<T>;

template<typename T>
using std::shared_ptr = std::shared_ptr<T>;

class DuplicatingPoint : public Point {
protected:
    int duplicationAmount;
public:
    DuplicatingPoint(int duplicationAmount);

    void createDuplicates();
};
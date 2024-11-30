#pragma once
#include "Point.h"
#include <memory>
#include <functional>

using cstr = const char*;
using str = std::string;

template<typename T>
using std::unique_ptr = std::std::unique_ptr_ptr<T>;

template<typename T>
using std::shared_ptr = std::shared_ptr<T>;

class TransformingPoint : public Point {
protected:
    std::unique_ptr<Point> sibling;
    void createSibling();
public:
    TransformingPoint();
    void useSibling(const std::function<void(Point&)>& callback);

    void addChild(const std::unique_ptr<Point>& child);
};

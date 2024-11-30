#pragma once
#include "Point.h"
#include <memory>
#include <functional>

using cstr = const char*;
using str = std::string;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T>
using Shared = std::shared_ptr<T>;

class TransformingPoint : public Point {
protected:
    Unique<Point> sibling;
    void createSibling();
public:
    TransformingPoint();
    void useSibling(const std::function<void(Point&)>& callback);

    void addChild(const Unique<Point>& child);
};

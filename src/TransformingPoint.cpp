#include "TransformingPoint.h"

void TransformingPoint::createSibling() {
    this->sibling = std::make_unique<Point>();
    establishParentChildRelationship(this->parent, this->sibling);
}

TransformingPoint::TransformingPoint() : Point() {
    createSibling();
}

void TransformingPoint::useSibling(const std::function<void(Point &)> &callback) {
    if (sibling) {
        callback(*sibling);
    } else {
        std::cerr << "Sibling does not exist." << std::endl;
    }
}

void TransformingPoint::addChild(const Unique<Point>& child) {
    // Copy of the child by creating a new Point
    auto childCopy = std::make_unique<Point>(*child);

    Point::addChild(std::move(child));

    sibling->addChild(std::move(childCopy));
}

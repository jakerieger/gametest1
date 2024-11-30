#include "DuplicatingPoint.h"

DuplicatingPoint::DuplicatingPoint(int duplicationAmount) 
: duplicationAmount(duplicationAmount), Point() {
    createDuplicates();
}

void DuplicatingPoint::createDuplicates() {
    // Holds the position of the current duplicated point's parent
    Shared<Point> currentParent = sharedFromThis();

    // Holds the original children owned by this point (as in, before duplication)
    auto originalChildren = std::vector<Unique<Point>>();
    for (const auto& child : children) {
        originalChildren.push_back(child->clone());
    }

    for (int i = 0; i < this->duplicationAmount; i++) {
        // The i'th added duplicate point
        Unique<Point> newPoint = std::make_unique<Point>();
        
        // Set currentParent as the parent of the new Point
        newPoint->setParent(currentParent);

        // Copy children
        for (const auto& childFromThis : originalChildren) {
            newPoint->addChild(childFromThis->clone());
        }

        // Change currentParent to the newly created point 
        currentParent = std::move(newPoint);
    }
}

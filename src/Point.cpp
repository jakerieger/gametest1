#include "Point.h"
#include <algorithm>
#include <sstream>
#include <numeric>

int Point::latestPointId = 0;

// Constructor
Point::Point() : id(latestPointId++), parent(nullptr) {}

// Destructor
Point::~Point() {
    children.clear();
}

Point::Point(const Point& other) : id(other.id), parent(other.parent) {
    for (const auto& child : other.children) {
        if (child) {
            children.push_back(child->clone());
        }
    }
}

Point &Point::operator=(const Point &other)
{
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Copy id
    id = other.id;

    // Copy parent (shared ownership)
    parent = other.parent;

    // Deep copy children
    children.clear(); // Clear existing children to avoid memory leaks
    for (const auto& child : other.children) {
        if (child) {
            children.push_back(child->clone()); // Clone each child
        }
    }

    return *this;

}

// Move Constructor
Point::Point(Point&& other) noexcept :
    id(other.id),
    parent(std::move(other.parent)),
    children(std::move(other.children)) 
    {
        other.id = -1;
    }

// Move Assignment Operator
Point& Point::operator=(Point&& other) noexcept {
    if (this != &other) {
        id = other.id;
        parent = std::move(other.parent);
        children = std::move(other.children);

        other.id = -1;
    }
    return *this;
}

std::unique_ptr<Point> Point::clone() const
{
    return std::make_unique<Point>(*this);
}

int Point::getId() const {
    return id;
}

void Point::setParent(const std::shared_ptr<Point>& parent) {
    this->parent = parent;
}

std::shared_ptr<Point> Point::getParent() const {
	return parent;
}

void Point::addChild(const std::unique_ptr<Point>& child) {
    children.push_back(std::move(child));
}

void Point::removeChild(std::unique_ptr<Point>& child) {
    // Find and remove the child
    auto it = std::remove_if(children.begin(), children.end(),
        [&child](const std::unique_ptr<Point>& ptr) { return ptr.get() == child.get(); });

    if (it != children.end()) {
        children.erase(it, children.end());  // Remove the child from the vector
    }
}

const std::vector<std::unique_ptr<Point>>& Point::getChildren() const {
    return children;
}

void Point::establishParentChildRelationship(std::shared_ptr<Point> parent, std::unique_ptr<Point>& child) {
    child->setParent(parent);
    parent->addChild(child);
}

std::string Point::toString() const {
    std::ostringstream oss;
    oss << "ID: " << id << std::endl;

    // Check if the parent exists
    if (parent) {
        oss << "Parent ID: " << parent->getId() << std::endl;
    } else {
        oss << "Parent ID: None" << std::endl;
    }

    // List children IDs
    if (!children.empty()) {
        oss << "Children IDs: [";
        for (const auto& child : children) {
            oss << child->getId() << ", ";
        }
        // Safely remove the trailing comma and space
        oss.seekp(-2, std::ios_base::end);
        oss << "]";
    } else {
        oss << "Children IDs: []";
    }

    return oss.str();
}


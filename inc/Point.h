#pragma once
#include <iostream>
#include <vector>
#include <memory>

using cstr = const char*;
using str = std::string;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T>
using Vec = std::vector<T>;

class Point : std::enable_shared_from_this<Point> {
protected:
	int id;
	Shared<Point> parent;
	Vec<Unique<Point>> children;

public:
	/** Used as a counter for point ID incrementing */
	static int latestPointId;

	Point();  // Constructor
	virtual ~Point(); // Destructor
	Point(const Point& other); // Copy constructor
	Point& operator=(const Point& other); // Copy assignment operator
	Point(Point&&) noexcept; // Move constructor
	Point& operator=(Point&&) noexcept;   // Move assignment operator

	// Virtual clone method for polymorphic behavior
	virtual Unique<Point> clone() const;

	// Exposes shared_from_this
	std::shared_ptr<Point> sharedFromThis() {
        return shared_from_this();
    }

	// Gets the ID for the point
	int getId() const;

	/**
	 * Sets the parent for a point
	 * @param parent a shared pointer to the parent node 
	 */
	void setParent(const Shared<Point>& parent);

	Shared<Point> getParent() const;

	/**
	 * Adds a child point to the point.
	 * @param child a unique pointer to the child node 
	 */
	void addChild(const Unique<Point>& child);

	/**
	 * Removes a child from the point, if it exists.
	 * Deletes the child and all of its children.
	 * @param child a unique pointer to the child node 
	 */
	void removeChild(Unique<Point> child);

	/**
	 * Returns a vector of unique pointers to all children of this point.
	 */
	const Vec<Unique<Point>>& getChildren() const;

	static void establishParentChildRelationship(Shared<Point> parent, Unique<Point>& child);

	str toString() const;
};
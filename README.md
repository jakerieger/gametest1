# Data Structure
intro text

## The Long-Term Goal
Make a data structure that can be used to quickly generate procedural maps with some amount of translational and reflectional symmetry, with hopes of making more architecturally convincing maps.

The goal is to use this as an abstraction layer for organizing the space in the most conceptual way possible. 
Down the line there will be goals to integrate this with another layer that solves a valid space for each point to occupy, and what the distances between each point will be.

Certain features like ```ReflectionPoint``` and ```DuplicationPoint``` will require implementations that realize their sibling's location as a transformation of the original point's location, as specified in the respective class's definition.

## Key Features of the Idea:
- Data is organized into points
- Points can have many children (may be limited later)
- Points can only have one parent (may change also)
- Certain specialized points have "siblings" which are meant to mock the structure of the point that creates it. In rendering phases, this will be used to create "wings" and other mirrored layouts.
- Certain other points have the ability to duplicate themselves, attaching a number of duplicates to themselves to create segmented repeating structures, like hallways with multiple exits.
- Directionality isn't meant to be implemented in this layer, but in general, each point will have a direction defined by the vector created between itself and its parent.
- Any duplications will append along these vectors, and any reflected objects will place themselves orthogonal to this vector.

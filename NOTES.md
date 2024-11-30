# Notes

So I deleted some files to get it to compile, and it still wouldn't so I re-wrote the Point class.

These are some of the big things I'd focus on:

1. Don't mix unique and shared pointers of the same pointer. Both the parent and children pointers
   need to be shared in this implementation.
2. Prioritize interfaces over class inheritance. Define contracts and let individual classes sort
   out the details.
3. Utilize templates more, you can avoid a lot of redundancy.
4. Don't use `std::endl` more than once per scope. It does a lot more than just print a newline and
   it's notoriously expensive.
5. I removed the copy and assignment constructors, they're unnecessary.
6. Utilize `nodiscard` for functions that return member values.
7. Mark classes that implement interfaces as `final`, this lets the compiler do some optimizing.

Some of the details you list out in the readme I'm not sure if I understand, but the implementation
I
wrote should serve as a solid foundation for anything you want to do.

### Considerations

I don't know how you plan on utilizing this data structure, but I think creating a "generator" class
that produces these trees would make the most sense. You could even define them in XML/whatever
files
and parse those into the structure. Just some ideas, I have no idea what you're doing with this
outside
of what you said.
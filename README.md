# ZCM

A WIP vector math library compatible with GLM.

The main focus of the library is compilation speed, so we don't use any templates and even #includes in public library headers.

As a consequence, the runtime performance will be worse than GLM (LTO might help though).

For building the library you need c++11 compatible compiler.

# Planned Features
* SIMD implementation
* Fast (to compile) swizzling
* Integer and double vectors
* Optional header-only mode for release builds.
* Higher-level primitives (bbox, rays, intersections, etc.)

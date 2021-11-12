# GL++

A thin wrapper around OpenGL for C++11.
This library was inspired by [Vulkan.hpp](https://github.com/KhronosGroup/Vulkan-Hpp), the C++ wrapper for Vulkan.

## Unique resources

All OpenGL object handles (or ids) are wrapped in a `UniqueXxx` type that handles automatic destruction. These types are similar to a `std::unique_ptr` ; they can't be copied but can be moved.
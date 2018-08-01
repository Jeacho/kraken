
add_subdirectory(filesystem)

file(GLOB Sources "*.cpp")
add_library(root_dir STATIC ${Sources})

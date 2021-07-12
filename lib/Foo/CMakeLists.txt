add_library(foo INTERFACE)

target_include_directories(foo
    INTERFACE
    .
)

target_sources(foo
    INTERFACE
    Foo.cpp
)
add_subdirectory(node_application)

add_example_executable(app
    app.cpp
    builders.h
    builders.cpp
    drawing.h
    drawing.cpp
    widgets.h
    widgets.cpp
)

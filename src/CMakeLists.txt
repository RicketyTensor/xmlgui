add_subdirectory(node_application)

add_example_executable(app
    node.h
    node.cpp
    app.cpp
    builders.h
    builders.cpp
    drawing.h
    drawing.cpp
    widgets.h
    widgets.cpp
    xml/xml_reader.h
    xml/xml_reader.cpp
)

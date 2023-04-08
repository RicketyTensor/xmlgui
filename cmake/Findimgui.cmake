if (TARGET imgui)
    return()
endif()

set(_imgui_SourceDir ${CMAKE_SOURCE_DIR}/external/imgui)
set(_imgui_BinaryDir ${CMAKE_BINARY_DIR}/external/imgui)

project(imgui VERSION 1.76)

set(_imgui_Sources
    ${IMGUI_DIR}/imconfig.h
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui.h
    ${IMGUI_DIR}/misc/debuggers/imgui.natvis
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_internal.h
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imstb_rectpack.h
    ${IMGUI_DIR}/imstb_textedit.h
    ${IMGUI_DIR}/imstb_truetype.h
    ${IMGUI_DIR}/LICENSE.txt
)

add_library(${PROJECT_NAME} STATIC ${_imgui_Sources})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_compile_definitions(${PROJECT_NAME} PUBLIC "ImDrawIdx=unsigned int")
target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_DISABLE_OBSOLETE_FUNCTIONS)
target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_DISABLE_OBSOLETE_KEYIO)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${_imgui_Sources})

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "external")



include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)

find_package_handle_standard_args(
    imgui
    REQUIRED_VARS
        _imgui_SourceDir
)


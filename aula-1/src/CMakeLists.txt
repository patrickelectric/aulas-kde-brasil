# Populate a CMake variable with the sources
set(SRCS
    main.cpp
)

qt5_add_resources(RESOURCES ../resources.qrc)

# Tell CMake to create the aula-1 executable
add_executable(aula-1 ${SRCS} ${RESOURCES})
# Use the Widgets module from Qt 5
target_link_libraries(aula-1
    Qt5::Core
    Qt5::Qml
    Qt5::QuickControls2
    Qt5::Quick
    Qt5::Widgets
)

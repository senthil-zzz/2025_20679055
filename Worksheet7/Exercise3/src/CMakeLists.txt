cmake_minimum_required(VERSION 3.16)

project(ProjectQt_App)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(VTK REQUIRED)

qt_add_executable(ProjectQt
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    optiondialog.cpp    # Added
    optiondialog.h      # Added
    optiondialog.ui     # Added
    ModelPart.cpp       # Added
    ModelPart.h         # Added
    ModelPartList.cpp   # Added
    ModelPartList.h     # Added
    icons.qrc           # Added
    settings.qrc
)

target_link_libraries(ProjectQt PRIVATE
    Qt6::Widgets
    ${VTK_LIBRARIES}
)

vtk_module_autoinit(
  TARGETS ProjectQt
  MODULES VTK::RenderingOpenGL2
          VTK::RenderingOpenVR
          VTK::InteractionStyle
)

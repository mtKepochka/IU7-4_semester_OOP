cmake_minimum_required(VERSION 3.5)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


function(add_include_directories_recursive dir)
    include_directories("${dir}")
    get_filename_component(abs_dir "${dir}" ABSOLUTE)
    file(GLOB subdirs RELATIVE "${abs_dir}" "${abs_dir}/*")
    foreach(subdir ${subdirs})
        if(IS_DIRECTORY "${abs_dir}/${subdir}")
            include_directories("${abs_dir}/${subdir}")
            add_include_directories_recursive("${abs_dir}/${subdir}")
        endif()
    endforeach()
endfunction()

# Вызываем функцию для добавления всех подпапок в качестве корневых директорий
# add_include_directories_recursive("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/qt_ui")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/commands")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/managers")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/drawer")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/objects")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/objects_data")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/visitor")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/scene")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/load")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/exeption")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/math")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/transform")
add_include_directories_recursive("${CMAKE_CURRENT_LIST_DIR}/history")


set(PROJECT_SOURCES
        main.cpp
        qt_ui/mainwindow.cpp
        qt_ui/mainwindow.h
        qt_ui/mainwindow.ui
        qt_ui/logic/Logic.h qt_ui/logic/Logic.cpp
        qt_ui/logic/MetaData.h qt_ui/logic/MetaData.cpp

        commands/Facade.h
        commands/Command.h
        commands/Camera/CameraCommand.h commands/Camera/CameraCommand.cpp
        commands/Scene/SceneCommand.h commands/Scene/SceneCommand.cpp
        commands/Object/ObjectCommand.h commands/Object/ObjectCommand.cpp
        commands/Load/LoadCommand.h commands/Load/LoadCommand.cpp
        commands/History/HistoryCommand.h commands/History/HistoryCommand.cpp

        managers/ManagerSolution.h managers/ManagerSolution.cpp
        managers/BaseManager.h
        managers/draw/DrawManager.h managers/draw/DrawManager.cpp
        managers/draw/DrawManagerCreator.h managers/draw/DrawManagerCreator.cpp
        managers/scene/SceneManager.h managers/scene/SceneManager.cpp
        managers/scene/SceneManagerCreator.h managers/scene/SceneManagerCreator.cpp
        managers/camera/CameraManager.h managers/camera/CameraManager.cpp
        managers/camera/CameraManagerCreator.h managers/camera/CameraManagerCreator.cpp
        managers/transform/TransformManager.h managers/transform/TransformManager.cpp
        managers/transform/TransformManagerCreator.h managers/transform/TransformManagerCreator.cpp
        managers/load/LoadManager.h managers/load/LoadManager.cpp
        managers/load/LoadManagerCreator.h managers/load/LoadManagerCreator.cpp
        managers/history/HistoryManager.h managers/history/HistoryManager.cpp
        managers/history/HistoryManagerCreator.h managers/history/HistoryManagerCreator.cpp

        objects/BaseObject.h objects/BaseObject.cpp
        objects/ObjectComposite.h objects/ObjectComposite.cpp
        objects/VisibleObjects/VisibleObject.h
        objects/InvisibleObjects/InVisibleObject.h
        objects/VisibleObjects/model/BaseModel.h
        objects/VisibleObjects/model/SceletonModel/SceletonModel.h objects/VisibleObjects/model/SceletonModel/SceletonModel.cpp

        objects/InvisibleObjects/camera/BaseCamera.h
        objects/InvisibleObjects/camera/FPSCamera.h objects/InvisibleObjects/camera/FPSCamera.cpp
        objects/InvisibleObjects/camera/CameraFactory.h objects/InvisibleObjects/camera/CameraFactory.cpp

        objects_data/SceletonModelData/SceletonModelData.h
        objects_data/SceletonModelData/VertexEdgeData.h objects_data/SceletonModelData/VertexEdgeData.cpp
        objects_data/SceletonModelData/AdjacencyListData.h objects_data/SceletonModelData/AdjacencyListData.cpp
        objects_data/SceletonModelData/Vertex.h objects_data/SceletonModelData/Vertex.cpp
        objects_data/SceletonModelData/Edge.h objects_data/SceletonModelData/Edge.cpp
        objects_data/SceletonModelData/AdjacencyList.h objects_data/SceletonModelData/AdjacencyList.cpp

        drawer/DrawerSolution.h
        drawer/AbstractFactory.h
        drawer/BaseDrawer.h
        drawer/Qt/QtFactory.h drawer/Qt/QtFactory.cpp
        drawer/Qt/QtDrawer.h drawer/Qt/QtDrawer.cpp


        visitor/BaseVisitor.h
        visitor/draw/DrawVisitor.h visitor/draw/DrawVisitor.cpp

        scene/Scene.h scene/Scene.cpp

        load/directors/SceletonModelDirector.h load/directors/SceletonModelDirector.cpp
        load/builders/ModelBuilder.h
        load/builders/BuilderSolution.h load/builders/BuilderSolution.cpp
        load/builders/SceletonModel/SceletonModelBuilder.h
        load/builders/SceletonModel/SceletonModelBuilderFactory.h
        load/builders/SceletonModel/VertexEdgeSceletonModelBuilder.h load/builders/SceletonModel/VertexEdgeSceletonModelBuilder.cpp
        load/builders/SceletonModel/AdjacencyListSceletonModelBuilder.h load/builders/SceletonModel/AdjacencyListSceletonModelBuilder.cpp
        load/sources/SourceSolution.h load/sources/SourceSolution.cpp
        load/sources/ModelSourceFactory.h
        load/sources/ModelSource.h
        load/sources/VertexEdgeSource.h load/sources/VertexEdgeSource.cpp
        load/sources/AdjacencyListSource.h load/sources/AdjacencyListSource.cpp

        load/sources/VertexEdgeSourceFactory.h load/sources/VertexEdgeSourceFactory.cpp
        load/sources/AdjacencyListSourceFactory.h load/sources/AdjacencyListSourceFactory.cpp
        load/builders/SceletonModel/VertexEdgeSceletonModelBuilderFactory.h load/builders/SceletonModel/VertexEdgeSceletonModelBuilderFactory.cpp
        load/builders/SceletonModel/AdjacencyListSceletonModelBuilderFactory.h load/builders/SceletonModel/AdjacencyListSceletonModelBuilderFactory.cpp

        load/directors/ModelDirector.h
        load/directors/ModelDirectorSolution.h load/directors/ModelDirectorSolution.cpp
        load/directors/ModelDirectorFactory.h
        load/directors/SceletonModelDirectorFactory.h load/directors/SceletonModelDirectorFactory.cpp

        exeption/BaseException.h
        exeption/LoadException.h
        exeption/ArrayException.h
        exeption/CastException.h

        math/glm_wrapper.h math/glm_wrapper.cpp
        math/Matrix4.h math/Matrix4.cpp
        math/Vector3.h math/Vector3.cpp

        transform/Transformation.h transform/Transformation.cpp
        transform/TransformationData.h transform/TransformationData.cpp

        history/CareTaker.h history/CareTaker.cpp
        history/Memento.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab_03
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET lab_03 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(lab_03 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(lab_03
            ${PROJECT_SOURCES}

        )
    endif()
endif()

target_link_libraries(lab_03 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab_03)
endif()
set_target_properties(lab_03 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab_03
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_03)
endif()

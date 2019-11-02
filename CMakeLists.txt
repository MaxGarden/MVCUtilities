CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(MVCUtilities)

SET(MVC_UTILITIES_SOURCES
    Include/MVC/MVCUtilities.h
    
    Include/MVC/DataModel.h
    Include/MVC/Controller.h
    Include/MVC/ControllerBase.h
    Include/MVC/ControllerBase.inl
    Include/MVC/Listener.h
    Include/MVC/ListenableBase.h
    Include/MVC/ListenableBase.inl
    Include/MVC/View.h
    Include/MVC/ViewBase.h
    Include/MVC/ViewBase.inl
    Include/MVC/Utilities.h
)

ADD_LIBRARY(MVCUtilities STATIC ${MVC_UTILITIES_SOURCES})

TARGET_INCLUDE_DIRECTORIES(MVCUtilities PUBLIC Include)
SET_TARGET_PROPERTIES(MVCUtilities PROPERTIES LINKER_LANGUAGE CXX)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
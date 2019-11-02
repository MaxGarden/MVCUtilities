CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(MVCUtilities)

SET(MVC_UTILITIES_SOURCES
    Include/MVCUtilities/MVCUtilities.h
    Include/MVCUtilities/Pointers.h
    
    Include/MVCUtilities/DataModel.h
    Include/MVCUtilities/Controller.h
    Include/MVCUtilities/ControllerBase.h
    Include/MVCUtilities/ControllerBase.inl
    Include/MVCUtilities/Listener.h
    Include/MVCUtilities/ListenableBase.h
    Include/MVCUtilities/ListenableBase.inl
    Include/MVCUtilities/View.h
    Include/MVCUtilities/ViewBase.h
    Include/MVCUtilities/ViewBase.inl
    Include/MVCUtilities/Utilities.h
)

ADD_LIBRARY(MVCUtilities STATIC ${MVC_UTILITIES_SOURCES})

TARGET_INCLUDE_DIRECTORIES(MVCUtilities PUBLIC Include)
SET_TARGET_PROPERTIES(MVCUtilities PROPERTIES LINKER_LANGUAGE CXX)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
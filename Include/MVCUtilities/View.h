#pragma once

#include "DataModel.h"
#include "Controller.h"

class IView
{
public:
    virtual ~IView() = default;

    virtual bool SetController(const IControllerSharedPtr& controller) = 0;
};

class IViewFactory
{
public:
    virtual ~IViewFactory() = default;
    virtual std::unique_ptr<IView> Create() = 0;
};
#pragma once

#include "Listener.h"

namespace MVC
{
    class IController : public IListenable
    {
    public:
        virtual ~IController() = default;

        virtual bool SetDataModel(const IDataModelSharedPtr& dataModel) = 0;
    };
}
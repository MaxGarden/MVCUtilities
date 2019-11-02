#pragma once

#include "Listener.h"

namespace MVC
{
    class IDataModel : public IListenable
    {
    public:
        virtual ~IDataModel() = default;
    };
}
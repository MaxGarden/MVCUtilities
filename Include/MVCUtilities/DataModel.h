#pragma once

#include "Listener.h"

class IDataModel : public IListenable
{
public:
    virtual ~IDataModel() = default;
};
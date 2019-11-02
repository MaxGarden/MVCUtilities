#pragma once
#include "MVCUtilities.h"

namespace MVC
{
    using ListenerHandle = size_t;
    const ListenerHandle InvalidListenerHandle = 0;

    class IListener
    {
    public:
        virtual ~IListener() = default;
    };

    class IListenable
    {
    public:
        virtual ~IListenable() = default;

        virtual std::optional<ListenerHandle> RegisterListener(IListenerUniquePtr&& listener) = 0;
        virtual bool UnregisterListener(const ListenerHandle& handle) = 0;
    };
}
#pragma once

#include "Listener.h"

namespace MVC
{
    template<typename SuperClass, typename ListenerType>
    class ListenableBase : public SuperClass
    {
    public:
        ListenableBase() = default;
        virtual ~ListenableBase() override = default;

        virtual std::optional<ListenerHandle> RegisterListener(IListenerUniquePtr&& listener) override;
        virtual bool UnregisterListener(const ListenerHandle& handle) override;

    protected:
        template<typename ListenerMethod, typename... Arguments>
        void NotifyListeners(ListenerMethod method, Arguments&&... arguments);

    private:
        std::vector<std::unique_ptr<ListenerType>> m_listeners;
    };

    #include "ListenableBase.inl"
}
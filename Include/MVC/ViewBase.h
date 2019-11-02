#pragma once

#include "View.h"

namespace MVC
{
    template<typename SuperClass, typename ControllerType>
    class ViewBase : public SuperClass
    {
    public:
        ViewBase() = default;
        virtual ~ViewBase() override = default;

        virtual bool SetController(const IControllerSharedPtr& controller) override;

    protected:
        virtual void OnControllerChanged();
        virtual IListenerUniquePtr CreateListener();

        const std::shared_ptr<ControllerType>& GetController() const noexcept;

        using Super = ViewBase<SuperClass, ControllerType>;

    private:
        std::shared_ptr<ControllerType> m_Controller;
        ListenerHandle m_ListenerHandle;
    };

    #include "ViewBase.inl"
}
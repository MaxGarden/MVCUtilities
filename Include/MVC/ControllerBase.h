#pragma once

#include "ListenableBase.h"

namespace MVC
{
    template<typename SuperClass, typename DataModelType, typename ListenerType>
    class ControllerBase : public CListenableBase<SuperClass, ListenerType>
    {
    public:
        ControllerBase() = default;
        virtual ~ControllerBase() override;

        virtual bool SetDataModel(const IDataModelSharedPtr& dataModel) override;

    protected:
        virtual void OnDataModelChanged();
        virtual IListenerUniquePtr CreateListener();

        const std::shared_ptr<DataModelType>& GetDataModel() const noexcept;

        using Super = ControllerBase<SuperClass, DataModelType, ListenerType>;

    private:
        std::shared_ptr<DataModelType> m_DataModel;
        ListenerHandle m_ListenerHandle;
    };

    #include "ControllerBase.inl"
}
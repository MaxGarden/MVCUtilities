template<typename SuperClass, typename DataModelType, typename ListenerType>
ControllerBase<SuperClass, DataModelType, ListenerType>::~ControllerBase()
{
    SetDataModel(nullptr);
}

template<typename SuperClass, typename DataModelType, typename ListenerType>
bool ControllerBase<SuperClass, DataModelType, ListenerType>::SetDataModel(const IDataModelSharedPtr& dataModel)
{
    const auto resetListener = [this]()
    {
        if (m_dataModel)
            m_dataModel->UnregisterListener(m_listenerHandle);

        m_listenerHandle = InvalidListenerHandle;
    };

    if (!dataModel)
    {
        resetListener();
        m_dataModel.reset();
        OnDataModelChanged();
        return true;
    }

    const auto castedDataModel = std::dynamic_pointer_cast<DataModelType>(dataModel);
    if (!castedDataModel)
        return false;

    resetListener();
    m_dataModel = std::move(castedDataModel);

    if (auto listener = CreateListener())
    {
        const auto listenerHandle = m_dataModel->RegisterListener(std::move(listener));
        DEBUG_ASSERT(listenerHandle);
        m_listenerHandle = listenerHandle.value_or(m_listenerHandle);
    }

    OnDataModelChanged();

    return true;
}

template<typename SuperClass, typename DataModelType, typename ListenerType>
void ControllerBase<SuperClass, DataModelType, ListenerType>::OnDataModelChanged()
{
    //to override
}

template<typename SuperClass, typename DataModelType, typename ListenerType>
IListenerUniquePtr ControllerBase<SuperClass, DataModelType, ListenerType>::CreateListener()
{
    //to override
    return nullptr;
}

template<typename SuperClass, typename DataModelType, typename ListenerType>
const std::shared_ptr<DataModelType>& ControllerBase<SuperClass, DataModelType, ListenerType>::GetDataModel() const noexcept
{
    return m_dataModel;
}
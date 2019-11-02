template<typename SuperClass, typename ControllerType>
void ViewBase<SuperClass, ControllerType>::OnControllerChanged()
{
    //to override
}

template<typename SuperClass, typename ControllerType>
IListenerUniquePtr ViewBase<SuperClass, ControllerType>::CreateListener()
{
    //to override
    return nullptr;
}

template<typename SuperClass, typename ControllerType>
const std::shared_ptr<ControllerType>& ViewBase<SuperClass, ControllerType>::GetController() const noexcept
{
    return m_controller;
}

template<typename SuperClass, typename ControllerType>
bool ViewBase<SuperClass, ControllerType>::SetController(const IControllerSharedPtr& controller)
{
    const auto resetListener = [this]()
    {
        if (m_controller)
            m_controller->UnregisterListener(m_listenerHandle);

        m_listenerHandle = InvalidListenerHandle;
    };

    if (!controller)
    {
        resetListener();
        m_controller.reset();
        OnControllerChanged();
        return true;
    }

    const auto castedController = std::dynamic_pointer_cast<ControllerType>(controller);
    if (!castedController)
        return false;

    resetListener();
    m_controller = std::move(castedController);

    if (auto listener = CreateListener())
    {
        const auto listenerHandle = m_controller->RegisterListener(std::move(listener));
        DEBUG_ASSERT(listenerHandle);
        m_listenerHandle = listenerHandle.value_or(m_listenerHandle);
    }

    OnControllerChanged();

    return true;
}
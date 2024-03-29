template<typename SuperClass, typename ListenerType>
std::optional<ListenerHandle> ListenableBase<SuperClass, ListenerType>::RegisterListener(IListenerUniquePtr&& listener)
{
    const auto castedListener = dynamic_cast<ListenerType*>(listener.get());
    if (!castedListener)
        return std::nullopt;

    m_listeners.emplace_back(std::unique_ptr<ListenerType>(castedListener));
    return reinterpret_cast<ListenerHandle>(listener.release());
}

template<typename SuperClass, typename ListenerType>
bool ListenableBase<SuperClass, ListenerType>::UnregisterListener(const ListenerHandle& handle)
{
    const auto iterator = std::find_if(m_listeners.begin(), m_listeners.end(), [&handle](const auto& listener)
    {
        return reinterpret_cast<ListenerHandle>(listener.get()) == handle;
    });

    if (iterator == m_listeners.end())
        return false;

    iterator->reset();
    return true;
}

template<typename SuperClass, typename ListenerType>
template<typename ListenerMethod, typename... Arguments>
void ListenableBase<SuperClass, ListenerType>::NotifyListeners(ListenerMethod method, Arguments&&... arguments)
{
    for (const auto& listener : m_listeners)
    {
        if (listener)
            (listener.get()->*method)(std::forward<Arguments>(arguments)...);
    }

    RemoveFromContainer(m_listeners, nullptr);
}
package seiot.coffeemanager.utils;

/**
 * An interface modeling a source of events, generating events 
 * listened by {@link EventSubscriber}.
 */
public interface EventPublisher {

    /**
     * Posts a new event.
     * @param event the event occurred.
     */
    void post(Event event);

    /**
     * Registers a new {@link EventSubscriber} to the actual listeners
     * @param subscriber the {@link EventSubscriber} to register
     */
    void register(EventSubscriber subscriber);

    /**
     * Unregisters a new {@link EventSubscriber} from the actual listeners.
     * @param subcriber the {@link EventSubscriber} to unregister.
     */
    void unregister(EventSubscriber subcriber);

}

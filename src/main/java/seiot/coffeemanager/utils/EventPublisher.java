package seiot.coffeemanager.utils;

public interface EventPublisher {

    void post(Event event);

    void register(EventSubscriber subscriber);

    void unregister(EventSubscriber subcriber);

}

package seiot.coffeemanager.utils;

import com.google.common.eventbus.EventBus;

public abstract class AbstractEventPublisher implements EventPublisher {

    private final EventBus eventBus = new EventBus();

    public void post(final Event event) {
        eventBus.post(event);
    }

    public void register(final EventSubscriber subscriber) {
        eventBus.register(subscriber);
    }

    public void unregister(final EventSubscriber subscriber) {
        eventBus.unregister(subscriber);
    }

}

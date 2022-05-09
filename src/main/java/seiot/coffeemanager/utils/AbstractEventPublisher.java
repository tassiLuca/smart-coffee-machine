package seiot.coffeemanager.utils;

import com.google.common.eventbus.EventBus;

public abstract class AbstractEventPublisher implements EventPublisher {

    private final EventBus eventBus = new EventBus();

    @Override
    public void post(final Event event) {
        eventBus.post(event);
    }

    @Override
    public void register(final EventSubscriber subscriber) {
        eventBus.register(subscriber);
    }

    @Override
    public void unregister(final EventSubscriber subscriber) {
        eventBus.unregister(subscriber);
    }

}

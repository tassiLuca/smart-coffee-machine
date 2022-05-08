package seiot.coffeemanager.utils;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public abstract class AbstractEventPublisher implements EventPublisher {

    private final Set<EventSubscriber> subscribers = new HashSet<>();

    public void post(final Event event) {
        subscribers.forEach(EventSubscriber::notifyEvent);
    }

    public void register(final EventSubscriber subscriber) {
        subscribers.add(Objects.requireNonNull(subscriber));
    }

    public void unregister(final EventSubscriber subscriber) {
        subscribers.remove(subscriber);
    }

}

#pragma once
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <vector>
#include "events.hpp"

using EventCallback = std::function<void(const Event&)>; // Обертка. Чтобы хранить все обработчики в одном контейнере, так как работаем с разными типами событий

class EventDispatcher {
public:
    static EventDispatcher& instance(); // Паттерн синглтон! У нас один такой объект на всю программу, делаем его глобальным. 

    template <typename EventT>
    void subscribe(std::function<void(const EventT&)> callback) {
        auto& vector = subscribers_[std::type_index(typeid(EventT))]; // берем событие Event, превращаем тип в ключ для словаря,
        vector.push_back(
            [cb = std::move(callback)](const Event& e) {
                cb(static_cast<const EventT&>(e));
            }
        );
    }
    template <typename EventT>
    void notify(const EventT& event) {
        auto it = subscribers_.find(std::type_index(typeid(EventT)));
        if (it == subscribers_.end()) return;
        for (auto& callback : it->second) {
            callback(event);
        }
    }

private:
    EventDispatcher() = default;
    std::unordered_map<std::type_index, std::vector<EventCallback>> subscribers_;
};

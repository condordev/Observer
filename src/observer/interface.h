#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include <memory>
#include <set>

namespace ObserverProject {

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &messageFromPublisher) = 0;
};

class IPublisher {
public:
    virtual ~IPublisher(){};
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify() = 0;
};

}

#endif // INTERFACE_H

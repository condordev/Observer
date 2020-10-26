#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "interface.h"
#include <iostream>
#include <list>

namespace ObserverProject {

class Observer;

class Publisher : public IPublisher
{
public:
    explicit Publisher();
    ~Publisher();

    void attach(IObserver *observer) override;
    void detach(IObserver *observer) override;
    void notify() override;
    void createMessage(std::string message = "Empty");
    void howManyObserver();
    void someBusinessLogic();

private:
    std::list<IObserver *> listObserver_;
    std::string message_;
};

}

#endif // PUBLISHER_H

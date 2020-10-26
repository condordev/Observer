#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <string>
#include "publisher.h"
//#include "interface.h"

namespace ObserverProject {

/*
 * Observer are the subscriber object which want to be informed from Publisher via Update()
 * Observer HAVE to implement the Update() method so the Publisher can call this callback in his notify() method
 */
class Observer : public IObserver
{
public:
    explicit Observer(Publisher& publisher);
    ~Observer();
    void Update(const std::string &messageFromPublisher) override;
    void removeMeFromTheList();
    void printInfo();
private:
    static int staticNumber_;
    std::string messageFromPublisher_;
    Publisher &publisher_;
    int number_;
};

int Observer::staticNumber_ = 0;

}

#endif // OBSERVER_H

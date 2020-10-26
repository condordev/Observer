#include "publisher.h"

namespace ObserverProject {

Publisher::Publisher(){}

Publisher::~Publisher()
{
  std::cout << "Goodbye, I was the Subject." << std::endl;
}

void Publisher::attach(IObserver *observer)
{
    listObserver_.push_back(observer);
}

void Publisher::detach(IObserver *observer)
{
    listObserver_.remove(observer);
}

void Publisher::notify()
{
    std::list<IObserver *>::iterator iterator = listObserver_.begin();
    howManyObserver();
    while (iterator != listObserver_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}
void Publisher::createMessage(std::string message)
{
    this->message_ = message;
    notify();
}

void Publisher::howManyObserver()
{
  std::cout << "There are " << listObserver_.size() << " observers in the list." << std::endl;
}

void Publisher::someBusinessLogic()
{
    this->message_ = "Publisher says: I'm about to do some thing important";
    notify();
    std::cout << "I'm about to do some thing important" << std::endl;
}


}

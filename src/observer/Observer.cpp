#include "observer.h"
#include <iostream>

namespace ObserverProject{

Observer::Observer(Publisher& publisher) : publisher_(publisher)
{
    this->publisher_.attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::staticNumber_ << "\"." << std::endl;
    this->number_ = Observer::staticNumber_;
}

Observer::~Observer() {
  std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\"." << std::endl;
}

void Observer::Update(const std::string &messageFromPublisher)
{
    messageFromPublisher_ = messageFromPublisher;
    printInfo();
}

void Observer::removeMeFromTheList()
{
    publisher_.detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list." << std::endl;
}

void Observer::printInfo()
{
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->messageFromPublisher_ << std::endl;
}

}


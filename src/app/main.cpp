#include <QCoreApplication>
#include <QDebug>
#include "observer/observer.h"
#include "observer/publisher.h"
#include <memory>

class Test{
public:
    Test(const int c) : counter_(c) {
        std::cout << "created " << this << std::endl;
        counter_++;
    }
    ~Test() {std::cout << "deleted" << this << std::endl;}
    void sayHello() const {std::cout << "Say Hello from " << this << " Number: " << counter_ << std::endl;}
    void sayNumber() const {std::cout << "My number is " << counter_ << std::endl;}

private:
    std::unique_ptr<Test> this_ = nullptr;
    int counter_ = 0;
};


void usePtr(const std::unique_ptr<Test>& t){
    t->sayHello();
}
void usePtr(const Test* t){
    if(t) t->sayHello();
}
void usePtr(const Test& t){
    t.sayHello();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* unique ptr stuff begin */

    std::vector<std::unique_ptr<Test>> vec;
    // emplace_back: perfect forwarding, constructed directly into vector, no temporary needed
    vec.emplace_back(std::make_unique<Test>(0));
    vec.emplace_back(std::make_unique<Test>(1));
    vec.emplace_back(std::make_unique<Test>(2));

    /////// ACCESSING THE POINTER
    // auto will give the value ie copy so it does not compile
    // auto& -> reference to the unique pointer itself
    // get prints the pointer value
    for(auto& i : vec){
        std::cout << "Found: " << i.get() << std::endl;
    }

    const Test& last = *vec.back();
    last.sayNumber();

    // If you don't want to take ownership of the pointer away from the vector, simply access the managed pointer directly:
    Test* ptrLast = vec.at(vec.size() - 1).get();
    ptrLast->sayNumber();

    // unique_ptr cannot be copied or assigned. It needs to be move copied or move assigned. You can achieve this by use of std::move
    // the last element is now not a valid Test object
    std::unique_ptr<Test> lastUnique = std::move(vec.back());
    lastUnique->sayNumber();

    // remove last garbage element
    vec.pop_back();

    // move the unique_ptr back into vector
    vec.emplace_back(std::move(lastUnique));

    std::cout << "Vecor size: " << vec.size() << std::endl;

    // check what happened to lastUnique after move
    if(lastUnique.get() != nullptr)
        lastUnique->sayNumber();
    else
        std::cout << "lastUnique is now " << lastUnique.get() << std::endl;

    /////// USING THE POINTER
    for(auto& i : vec){
        // worst: only to change ownership
        usePtr(i);

        // better: pass the encapsulated pointer but must be checked if valid
        usePtr(i.get());

        // best: pass the object itself and avoid passing the unique_ptr since the vector remains the owner
        usePtr(*i);
    }

    /////// MOVING THE POINTER TO ANOTHER VECTOR
    std::vector<std::unique_ptr<Test>> vecTo;
    std::move(vec.begin(), vec.end(), std::back_inserter(vecTo));
    vec.erase(vec.begin(), vec.end());
    std::cout << "Vecor size: " << vec.size() << std::endl;

    /* unique ptr stuff end */

    qDebug() << "App started ";

    ObserverProject::Publisher *subject = new ObserverProject::Publisher;
    ObserverProject::Observer *observer1 = new ObserverProject::Observer(*subject);
    ObserverProject::Observer *observer2 = new ObserverProject::Observer(*subject);
    ObserverProject::Observer *observer3 = new ObserverProject::Observer(*subject);
    ObserverProject::Observer *observer4;
    ObserverProject::Observer *observer5;

    subject->createMessage("Hello World! :D");
    observer3->removeMeFromTheList();

    subject->createMessage("The weather is hot today! :p");
    observer4 = new ObserverProject::Observer(*subject);

    observer2->removeMeFromTheList();
    observer5 = new ObserverProject::Observer(*subject);

    subject->createMessage("My new car is great! ;)");
    subject->someBusinessLogic();

    observer5->removeMeFromTheList();
    observer4->removeMeFromTheList();
    observer1->removeMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    // event loop is running
    return a.exec();
}

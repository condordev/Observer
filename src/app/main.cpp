#include <QCoreApplication>
#include <QDebug>
#include "observer/observer.h"
#include "observer/publisher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

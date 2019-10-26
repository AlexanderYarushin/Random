#include <QCoreApplication>
#include <iostream>

#define rand_max 32767
#define rand_max2 32767.0

static unsigned long int next = 1;

double random()
{
    next = next * 1103515245 + 12345;
    return (next % (rand_max + 1)) / rand_max2;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    for(int i = 0; i < 100; ++i){
        std::cout << random() << std::endl;
    }
    return a.exec();
}


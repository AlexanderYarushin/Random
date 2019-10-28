#include <QCoreApplication>
#include <iostream>
#include <cmath>

#define rand_max 1500000

static unsigned long long next = 1;
static unsigned long long a = 5634345;
static unsigned long long c = 31345;

unsigned random()
{
    next = next * a + c;
    return (next % (rand_max));
    //return (next % (rand_max)) / (rand_max * 1.0);
}


static const int N = 100000;

int notRepeat(){
    unsigned rnd = random();
    unsigned count = 0;
    while(random() != rnd){
        count++;
    }
    return count;
}


double mathExp(){
    double mas[N];
    double sum = 0;
    for(int i = 0; i < N; ++i){
        mas[i] =  random() / (rand_max * 1.0);
    }
    for(int i = 0; i < N; ++i){
        sum+=mas[i];
    }
    return sum / N;
}

double dispersion(){
    double mas[N];
    double sum = 0;
    double exp = mathExp();
    for(int i = 0; i < N; ++i){
        mas[i] = random() / (rand_max * 1.0);
    }
    for(int i = 0; i < N; ++i){
        sum+=pow(mas[i] - exp,2);
    }
    return sum / N;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::cout << "Mathematical expectation: " << mathExp() << std::endl;
    std::cout << "Dispersion: " << dispersion() << std::endl;
    std::cout << "Without repetition: " << notRepeat() << std::endl;

    return app.exec();
}


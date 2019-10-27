#include <QCoreApplication>
#include <iostream>
#include <cmath>

#define rand_max 32767

static unsigned long int next = 1;
static unsigned long int a = 1; //1103515245
static unsigned long int c = 1; //12345

double random()
{
    next = next * a + c;
    return (next % (rand_max)) / (rand_max * 1.0);
}


static const int N = 100000;


double mathExp(){
    double mas[N];
    double sum = 0;
    for(int i = 0; i < N; ++i){
        mas[i] = random();
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
        mas[i] = random();
    }
    for(int i = 0; i < N; ++i){
        sum+=pow(mas[i] - exp,2);
    }
    return sum / N;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Mathematical expectation: " << mathExp() << std::endl;
    std::cout << "Dispersion: " << dispersion() << std::endl;

    return a.exec();
}


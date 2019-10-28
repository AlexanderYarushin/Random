#include <QCoreApplication>
#include <iostream>
#include <cmath>

#define rand_max 2147483647

static long long next = 1;

int random()
{
    long long a = 564;
    long long c = 3;
    next = (next * a + c) % rand_max;
    return static_cast<int>(next);
}


static const int N = 100000;

int notRepeat(int (*f)()){
    int rnd = f();
    int count = 0;
    while(f() != rnd){
        count++;
    }
    return count;
}


double mathExp(int (*f)()){
    next = 1;
    double mas[N];
    double sum = 0;
    for(int i = 0; i < N; ++i){
       if(f == random) mas[i] =  f() / (rand_max * 1.0);
       if(f == rand) mas[i] =  f() / (RAND_MAX * 1.0);
    }
    for(int i = 0; i < N; ++i){
        sum+=mas[i];
    }
    return sum / N;
}

double dispersion(int (*f)()){
    double mas[N];
    double sum = 0;
    double exp = mathExp(random);
    for(int i = 0; i < N; ++i){
       if(f == random) mas[i] = f() / (rand_max * 1.0);
       if(f == rand) mas[i] = f() / (RAND_MAX * 1.0);
    }
    for(int i = 0; i < N; ++i){
        sum+=pow(mas[i] - exp,2);
    }
    return sum / N;
}

double standardDeviation(int (*f)()){
    return sqrt(dispersion(f));
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    std::cout << "Mathematical expectation: " << mathExp(random) << std::endl;
    std::cout << "Dispersion: " << dispersion(random) << std::endl;
    std::cout << "Without repetition: " << notRepeat(random) << std::endl;
    std::cout << "Standard deviation: " << standardDeviation(random) << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Mathematical expectation: " << mathExp(rand) << std::endl;
    std::cout << "Dispersion: " << dispersion(rand) << std::endl;
    std::cout << "Without repetition: " << notRepeat(rand) << std::endl;
    std::cout << "Standard deviation: " << standardDeviation(rand) << std::endl;
    return app.exec();
}


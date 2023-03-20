#include <iostream>

using namespace std;

struct Car{
char make[256];
int year;
int wheels;
bool isRunning;
};

int main()
{


   Car myBMW;

   myBMW.year=2001;
   myBMW.isRunning= true;

   printf("My BMW YEAR %d", myBMW.year);

   printf("My BMW Is Running %d", myBMW.isRunning);
   system("pause");
    return 0;
}

#include <iostream>
#include <cmath>
#include <time.h>


int main() {
    int n,m,size, average=0;
    srand(time(NULL));

    std::cout<<"n,m: ";
    std::cin>>n>>m;

    int* arr1 = new int [n];

    for(int i=0; i<n; ++i)
    {
        arr1[i] = rand()%m+1;
        average += arr1[i];
    }
    average=average/n;
    if(n<10)
    {
        size=n;
    } else{ size = 10;}
    std::cout<<"[ ";
    for(int j= 0; j<size; ++j)
    {
        std::cout << arr1[j]<<" ";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"Average = "<<average<<std::endl;



    delete[] arr1;

    return 0;
}

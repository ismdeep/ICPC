#include <iostream>

#include <stdio.h>

#include <cmath>

using namespace std;



int main(){

    float x1,y1;

    float x2,y2;

    while(cin>>x1>>y1>>x2>>y2){

        float result=0;

        result=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        printf("%.2f\n",result);

    }

    return 0;

}

//end

//ism

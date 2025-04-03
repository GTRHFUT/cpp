#pragma once 
int fibonacci(int months){
    if(months == 1 || months == 2)return 1;
    return fibonacci(months - 1) + fibonacci(months - 2);
}
#include <iostream>
#include "../header/item.h"
#include "../header/task.h"

int main(){
    Task math;
    math.setName("Math");
    math.setLocation("Pierce Hall");
    math.setDescription("Math 10a Multivariable Calc Section 004");
    math.edit();
}
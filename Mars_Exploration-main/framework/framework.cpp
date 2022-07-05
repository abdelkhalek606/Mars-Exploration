// framework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"MARSSTATION.h"
using namespace std;
int main()
{
   
   
    MARSSTATION App;
   MODE m;

    App.redinputfile();
    m=App.selectmode();
    App.trsh();
    if (m == interactivem)
    {
        while (!App.iscomplet())
       
        {

            App.completedmission();
            App.getroverincheck();
            App.getmaintence();
            App.makeevent();
            App.assgin();
            App.updetinterface();
            App.day();
           
        
        }
    }
    else if (m == stepbystepm)
    {
        while (!App.iscomplet())
        {
            App.completedmission();
            App.getroverincheck();
            App.getmaintence();

            App.makeevent();
            App.assgin();
            App.updetinterface();
            App.day();
           
      
        }
    }
    else {
        App.updetinterface();
        while (!App.iscomplet())
        {
            App.makeevent();
            App.assgin();
            App.day();
            App.completedmission();
            App.getroverincheck();
            App.getmaintence();
        }
        App.updetinterface();

    }
    App.makeoutputfile();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

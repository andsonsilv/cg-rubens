#include <iostream>

using namespace std;

#include <gui.h>

void desenhar(){
    GUI::displayInit();

    GUI::setLight(0,0,2,0,true,false);
    GUI::drawOrigin(1);
    GUI::setColor(0.0,0.8,0.0);
    GUI::drawFloor();

    GUI::setColor(0.8,0.0,0.8);
    GUI::drawSphere(2,2,0,0.25);

    GUI::displayEnd();
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenhar);
}




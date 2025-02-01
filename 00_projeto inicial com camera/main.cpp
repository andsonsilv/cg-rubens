#include <iostream>

using namespace std;

#include <gui.h>

void desenhar(){
    GUI::displayInit();
    GUI::setColor(0.8,0.0,0.0);
    GUI::drawFloor();
    GUI::displayEnd();
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenhar);
}




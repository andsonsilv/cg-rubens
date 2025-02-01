#include <iostream>

using namespace std;

#include <gui.h>

void desenhar(){
    GUI::displayInit();
    GUI::displayEnd();
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenhar);
}




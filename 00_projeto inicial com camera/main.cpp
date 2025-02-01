#include <iostream>

using namespace std;

#include <gui.h>

Vetor3D posicaoEsfera = Vetor3D(2,2,0);
float raioEspera = 0.25;

void desenhar(){
    GUI::displayInit();

    GUI::setLight(0,0,2,0,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(0.0,0.8,0.0);
    GUI::drawFloor();

    GUI::setColor(0.8,0.0,0.8);
    GUI::drawSphere(posicaoEsfera.x,posicaoEsfera.y,posicaoEsfera.z,raioEspera);

    posicaoEsfera.x += glutGUI::drx;
    posicaoEsfera.y += glutGUI::dry;
    posicaoEsfera.z += glutGUI::dlrx;
    raioEspera += 0.01*glutGUI::dlx;

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y){
    GUI::keyInit(tecla,x,y);
    switch (tecla) {
    case 'a':
        posicaoEsfera.x -= 0.2;
        break;
    case 'd':
        posicaoEsfera.x += 0.2;
        break;
    case 's':
        posicaoEsfera.y -= 0.2;
        break;
    case 'w':
        posicaoEsfera.y += 0.2;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'o':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenhar,teclado);
}




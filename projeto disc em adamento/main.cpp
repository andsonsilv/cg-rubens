#include <iostream>

using namespace std;

#include <gui.h>

Vetor3D posicaoEsfera = Vetor3D(0,0,0);
float raioEspera = 0.25;

Vetor3D posicaoLuz = Vetor3D(0,2,2);
int idLuz[8] = {0,1,2,3,4,5,6,7};

void casa()
{
    glBegin(GL_QUADS); //frente
    glNormal3b(0,0,1);
    glVertex3f(0,0,1);
    glVertex3f(1,0,1);
    glVertex3f(1,1,1);
    glVertex3f(0,1,1);
    glEnd();

    glBegin(GL_QUADS); //tras
    glNormal3b(0,0,-1);
    glVertex3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glVertex3f(1,1,0);
    glEnd();

    glBegin(GL_QUADS); //direita
    glNormal3b(1,0,0);
    glVertex3f(1,1,1);
    glVertex3f(1,0,1);
    glVertex3f(1,0,0);
    glVertex3f(1,1,0);
    glEnd();

    glBegin(GL_QUADS); //esquerda
    glNormal3b(-1,0,0);
    glVertex3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glVertex3f(0,1,1);
    glEnd();

    glBegin(GL_QUADS); //cima
    glNormal3b(0,1,0);
    glVertex3f(0,1,0);
    glVertex3f(0,1,1);
    glVertex3f(1,1,1);
    glVertex3f(1,1,0);
    glEnd();

    glBegin(GL_QUADS); //baixo
    glNormal3b(0,-1,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(1,0,1);
    glVertex3f(0,0,1);
    glEnd();

    glBegin(GL_POLYGON); //telhadoesquerdo
    glNormal3b(-1,1,0);
    glVertex3f(0.5,1.5,0.5);
    glVertex3f(0,1,0);
    glVertex3f(0,1,1);
    glEnd();

    glBegin(GL_POLYGON); //telhadodireito
    glNormal3b(1,1,0);
    glVertex3f(1,1,0);
    glVertex3f(0.5,1.5,0.5);
    glVertex3f(1,1,1);
    glEnd();

    glBegin(GL_POLYGON); //telhadofrente
    glNormal3b(0,1,1);
    glVertex3f(0,1,1);
    glVertex3f(1,1,1);
    glVertex3f(0.5,1.5,0.5);
    glEnd();

    glBegin(GL_POLYGON); //telhadotras
    glNormal3b(0,1,-1);
    glVertex3f(0,1,0);
    glVertex3f(0.5,1.5,0.5);
    glVertex3f(1,1,0);
    glEnd();
}

void desenhar(){
    GUI::displayInit();

    GUI::setLight(idLuz[0],posicaoLuz.x,posicaoLuz.y,posicaoLuz.z,true,false);

    GUI::drawOrigin(1.0);

    GUI::setColor(0.0,0.8,0.0);
    GUI::drawFloor();





    posicaoEsfera.x += glutGUI::drx;
    posicaoEsfera.y += glutGUI::dry;
    posicaoEsfera.z += glutGUI::dlrx;
    raioEspera += 0.01*glutGUI::dlx;

    GLdouble plane[4] = {0,0,1,-0.1};
    glClipPlane(GL_CLIP_PLANE0,plane);
    glEnable(GL_CLIP_PLANE0);

    GUI::setColor(0.8,0.0,0.8);
    GUI::drawSphere(posicaoEsfera.x,posicaoEsfera.y,posicaoEsfera.z,raioEspera);

    glDisable(GL_CLIP_PLANE0);


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
    case '-':
        posicaoLuz.z -= 0.2;
        break;
    case '+':
        posicaoLuz.z += 0.2;
        break;
    case '4':
        posicaoLuz.x -= 0.2;
        break;
    case '6':
        posicaoLuz.x += 0.2;
        break;
    case '5':
        posicaoLuz.y -= 0.2;
        break;
    case '8':
        posicaoLuz.y += 0.2;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenhar,teclado);
}




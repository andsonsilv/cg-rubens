#include <iostream>

using namespace std;

#include <gui.h>

Vetor3D posEsfera = Vetor3D(0.5,1,0);
float raioEsfera = 0.2;

Model3DS carro = Model3DS("../3ds/cartest.3DS");

void casa()
{
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    //frontal
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glTexCoord2f(0,0); glVertex3f(0,0,1);
        glTexCoord2f(0.25,0); glVertex3f(1,0,1);
        glTexCoord2f(0.25,1); glVertex3f(1,1,1);
        glTexCoord2f(0,1); glVertex3f(0,1,1);
    glEnd();
    //direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glTexCoord2f(0.25,0); glVertex3f(1,0,1);
        glTexCoord2f(0.5,0); glVertex3f(1,0,0);
        glTexCoord2f(0.5,1); glVertex3f(1,1,0);
        glTexCoord2f(0.25,1); glVertex3f(1,1,1);
    glEnd();
    //traseira
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glTexCoord2f(0.5,0); glVertex3f(1,0,0);
        glTexCoord2f(0.75,0); glVertex3f(0,0,0);
        glTexCoord2f(0.75,1); glVertex3f(0,1,0);
        glTexCoord2f(0.5,1); glVertex3f(1,1,0);
    glEnd();
    //esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glTexCoord2f(0.75,0); glVertex3f(0,0,0);
        glTexCoord2f(1,0); glVertex3f(0,0,1);
        glTexCoord2f(1,1); glVertex3f(0,1,1);
        glTexCoord2f(0.75,1); glVertex3f(0,1,0);
    glEnd();
    //superior
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(1,1,1);
        glVertex3f(1,1,0);
    glEnd();
    //inferior
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(1,0,1);
        glVertex3f(0,0,1);
    glEnd();
    //teto esquerdo
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,1);
        glVertex3f(0.5,1.5,0.5);
    glEnd();
}

void objetoCortado() {
    //GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    //GUI::drawHalfSphere(0,0,0, raioEsfera);
    //GUI::drawSphereInsideBox222(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    //GUI::drawSphereInsideBox222(0,0,0, raioEsfera);

    //    //clipping
    //    //GLdouble plane[4] = { 0.0, 1.0, 0.0, 1}; //deixa a parte acima (y) do plano aparecendo (plano posicionado no y=-1, d desloca o plano no sentido oposto à normal) (corta o y<-1)
    //    //GLdouble plane[4] = { 0.0, -1.0, 0.0, 1}; //deixa a parte abaixo (y) do plano aparecendo (plano posicionado no y=1, d desloca o plano no sentido oposto à normal) (corta o y>1)
    //    GLdouble plane[4] = { 1.0, 1.0, 0.0, -1.0 }; //deixa a parte à frente do plano (z) do plano aparecendo (plano posicionado no z=0, d desloca o plano no sentido oposto à normal) (corta o z<0)
    //    glClipPlane(GL_CLIP_PLANE0, plane);
    //    glEnable(GL_CLIP_PLANE0);



    //    //objeto a ser cortado
    //    //GUI::drawSphere(0,0,0,raioEsfera);
    //    casa();

    //    //clipping
    //    glDisable(GL_CLIP_PLANE0);
}

int idTexture = 3;

void objetoComTextura() {
    //Usando texturas

    GUI::habilitaTextura(true,false,0);
    GUI::selecionaTextura(idTexture);

    //objeto a ser texturizado
    //GUI::setColor(0.5,0.5,0.5);
    //GUI::drawBox(-1,-1,-1, 1,1,1);
    //GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);

    GUI::setColor(1,1,1,0.5);
    //glBegin(GL_POLYGON);
    //    glNormal3f(0,0,1);
    //    glTexCoord2f(0,0); glVertex3d(0,0,0);
    //    glTexCoord2f(0.5,0); glVertex3d(1,0,0);
    //    glTexCoord2f(0.5,1); glVertex3d(1,1,0);
    //    glTexCoord2f(0,1); glVertex3d(0,1,0);
    //glEnd();
    //glBegin(GL_POLYGON);
    //    glNormal3f(0,0,1);
    //    glTexCoord2f(0,0); glVertex3d(0,0,0);
    //    glTexCoord2f(0.5,0); glVertex3d(1,0,0);
    //    glTexCoord2f(0.25,1); glVertex3d(0.5,1,0);
    //    //glTexCoord2f(0.5*posEsfera.x,1); glVertex3d(posEsfera.x,1,0);
    //    //glTexCoord2f(-0.5*glutGUI::cam->e.x,1); glVertex3d(posEsfera.x,1,0);
    //glEnd();

    //casa();

    glRotatef(-90,1,0,0);
    GLUquadricObj *quad = gluNewQuadric();
    Desenha::gluClosedCylinder(quad,0.5,0,1,30,30);
    gluDeleteQuadric( quad );

    GUI::desabilitaTextura(true,false);
}

Vetor3D rotacaoZ( Vetor3D v, float theta ) {
    Vetor3D vt;
    float thetaRad = theta*PI/180;
    vt.x = cos(thetaRad)*v.x - sin(thetaRad)*v.y;
    vt.y = sin(thetaRad)*v.x + cos(thetaRad)*v.y;
    vt.z = v.z;
    return vt;
}

Vetor3D translacao( Vetor3D v, Vetor3D desl ) {
    Vetor3D vt;
    vt.x = v.x + desl.x;
    vt.y = v.y + desl.y;
    vt.z = v.z + desl.z;
    return vt;
}

Vetor3D t(0,0,0);
Vetor3D r(0,0,0);
Vetor3D s(1,1,1);

void transformacoesSemMatriz() {
    //testando transformar um objeto (um simples triangulo, por exemplo)

    //aplicando funcoes de transformacao nos vertices do objeto

    //exemplo de um triangulo 2D
    //Vetor3D v1 = Vetor3D(0,0,0);
    //Vetor3D v2 = Vetor3D(1,0,0);
    //Vetor3D v3 = Vetor3D(0,1,0);

    //exemplo de um objeto afastado da origem
    //Vetor3D v1 = Vetor3D(1,0,0);
    //Vetor3D v2 = Vetor3D(2,0,0);
    //Vetor3D v3 = Vetor3D(1.5,1,0);

    //exemplo guardando tbm o vetor normal do triangulo
    //Vetor3D vN = Vetor3D(0,0,1);
    //Vetor3D v1 = Vetor3D(0,0,0);
    //Vetor3D v2 = Vetor3D(1,0,0);
    //Vetor3D v3 = Vetor3D(0,1,0);

    //exemplo da face frontal da nossa piramide
    Vetor3D vN = Vetor3D(0,1,1);
    Vetor3D v1 = Vetor3D(1,0,1);
    Vetor3D v2 = Vetor3D(0,1,0);
    Vetor3D v3 = Vetor3D(-1,0,1);

    //glRotatef();
    //glTranslatef();

    Vetor3D desl = Vetor3D( t.x,t.y,0 ); //          R.(T.vi)
    v1 = translacao(v1,desl);
    v2 = translacao(v2,desl);
    v3 = translacao(v3,desl);

    float theta = r.z;
    vN = rotacaoZ(vN,theta);
    v1 = rotacaoZ(v1,theta);
    v2 = rotacaoZ(v2,theta);
    v3 = rotacaoZ(v3,theta);

    glBegin(GL_POLYGON);
        glNormal3f( vN.x, vN.y, vN.z );
        glVertex3f( v1.x, v1.y, v1.z );
        glVertex3f( v2.x, v2.y, v2.z );
        glVertex3f( v3.x, v3.y, v3.z );
    glEnd();
}

void desenha() {
    GUI::displayInit();


    GUI::drawOrigin(2.5);
    GUI::setLight(0,1,1,1, false, false);



    //GUI::drawOriginAL(5,0.5);
    //GUI::setColor(5.0,0.0,0.0, 1,false);
    GUI::drawFloor(5,5);

    GUI::setColor(0.0,0.8,0.0, 1,true);
    //GUI::drawSphere(posEsfera.x,posEsfera.y,posEsfera.z, raioEsfera);
    //posEsfera.x -= 0.001;
    //raioEsfera += 0.001;

    //GUI::drawBox(-1,-1,-1, 1,1,1);

    glPushMatrix();
        //GUI::glReflectPlaneXZf();
        //GUI::glReflectPlaneYZf();

        // vf = I.T.R.vi
        //      <---- interpretacao global
        //      ----> interpretacao local (ordem usada pelo OpenGl)
        glTranslatef(t.x,t.y,t.z);
        glRotatef(r.x, 1,0,0);
        glRotatef(r.y, 0,1,0);
        glRotatef(r.z, 0,0,1);
        glScalef(s.x,s.y,s.z);

        //GUI::glShearXYf(t.x,t.y);

        GUI::drawOrigin(0.5);


        //glTranslatef(1,1,0);
        GUI::setColor(0.0,0.8,0.0, 1,true);
        //objetoComTextura();
        //glDisable(GL_CULL_FACE);
            GUI::drawBox(0,0,0, 1,1,1);
        //glEnable(GL_CULL_FACE);
        //casa();
        //objetoCortado();
        //GUI::setColor(0.0,0.8,0.0, 0.5,true);
        //transformacoesSemMatriz();

        //GUI::drawHalfSphere(0,0,0, 0.5, true);
        //GUI::drawHalfSphere(0,0,0, 0.5, false);

        //GUI::setColor(0,0,0.8);
        //GUI::draw3ds(carro);
    glPopMatrix();

    //glPushMatrix();
    //    //original
    //    glTranslatef(t.x,t.y,t.z);
    //    glRotatef(r.z, 0,0,1);
    //    glScalef(s.x,s.y,s.z);
    //    GUI::drawOrigin(0.5);
    //    //glTranslatef(1,1,0);
    //    GUI::setColor(0.0,0.8,0.0, 1,true);
    //    //objetoComTextura();
    //    GUI::drawBox(0,0,0, 1,1,1);
    //glPopMatrix();

    //interacao com o mouse
    //posEsfera.x += glutGUI::drx;
    //posEsfera.y += glutGUI::dry;
    //posEsfera.z += -0.1*glutGUI::dlx;
    //raioEsfera += 0.01*glutGUI::dlrx;
    t.x += glutGUI::drx;
    t.y += glutGUI::dry;
    t.z += glutGUI::dlry;
    r.x += glutGUI::dly;
    r.y += glutGUI::dlx;
    r.z += glutGUI::dlrx;
    s.x += glutGUI::dmx;
    s.y += glutGUI::dmy;
    s.z += glutGUI::dlmy;

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'p':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'a':
        posEsfera.x -= 0.1;
        break;
    case 'd':
        posEsfera.x += 0.1;
        break;
    case 's':
        posEsfera.y -= 0.1;
        break;
    case 'w':
        posEsfera.y += 0.1;
        break;
    case 't':
        idTexture ++;
        idTexture = idTexture%7;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}




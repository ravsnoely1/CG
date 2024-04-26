#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>

// listas de exibição
GLuint casaList, chaoList, arvoreList, solList, nuvemList;

void init() {
    glClearColor(0.6, 0.8, 1.0, 1.0); // azul claro

    // Criação das lista
    casaList = glGenLists(5);
    chaoList = casaList + 1;
    arvoreList = casaList + 2;
    solList = casaList + 3;
    nuvemList = casaList + 4;

    // Lista para a casa
    glNewList(casaList, GL_COMPILE);
        //telhado
        glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.0, 0.0); //vermelho
            glVertex3f(-70, 50, 0); 
            glVertex3f(70, 50, 0);  
            glVertex3f(0, 100, 0);  
        glEnd();
        //parede
        glBegin(GL_QUADS);
            glColor3f(0.72, 0.25, 0.05); // Cor de tijolo
            glVertex3f(-50,-50,0);
            glVertex3f(50,-50,0);
            glVertex3f(50,50,0);
            glVertex3f(-50,50,0);
        glEnd(); 
        // Porta da casa
        glBegin(GL_QUADS);
            glColor3f(0.25, 0.25, 0.25); // Cinza escuro
            glVertex3f(10, -50, 0); 
            glVertex3f(30, -50, 0); 
            glVertex3f(30, 10, 0); 
            glVertex3f(10, 10, 0); 
        glEnd();
        // Janela da casa
        glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 1.0f); //  azul
            glVertex3f(-30, 0, 0); 
            glVertex3f(0, 0, 0); 
            glVertex3f(0, 30, 0); 
            glVertex3f(-30, 30, 0); 
        glEnd();
    glEndList();

    // Lista para o chão
    glNewList(chaoList, GL_COMPILE);
        glColor3f(0.0, 1.0, 0.0); // chão verde
        glBegin(GL_QUADS);
            glVertex3f(-200.0, -120.0, 0);
            glVertex3f(200.0, -120.0, 0);
            glVertex3f(200.0, -90.0, 0);
            glVertex3f(-200.0, -90.0, 0);
        glEnd();
    glEndList();

    // Lista para a árvore
    glNewList(arvoreList, GL_COMPILE);
        glColor3f(0.4, 0.3, 0.1); // marrom
        //tronco
        glBegin(GL_QUADS);
            glVertex3f(100.0, -50.0, 0);
            glVertex3f(110.0, -50.0, 0);
            glVertex3f(110.0, 0.0, 0);
            glVertex3f(100.0, 0.0, 0);
        glEnd();
        glColor3f(0.0, 0.5, 0.0); // verde escuro
        //copa da arvore
        glBegin(GL_TRIANGLES);
            glVertex2f(80.0, 0.0);
            glVertex2f(130.0, 0.0);
            glVertex2f(105.0, 50.0);
        glEnd();
    glEndList();

    // Lista para o sol
    glNewList(solList, GL_COMPILE);
        glColor3f(1.0, 1.0, 0.0); // sol amarelo
        glBegin(GL_POLYGON);
            for(int i = 0; i < 360; i += 20) {
                float rad = i * 3.14159 / 180.0;
                glVertex2f(cos(rad) * 20.0 + 150.0, sin(rad) * 20.0 + 80.0);
            }
        glEnd();
    glEndList();

    // Lista para as nuvens
    glNewList(nuvemList, GL_COMPILE);
        glColor3f(1.0, 1.0, 1.0); // branco
        glBegin(GL_POLYGON);
            glVertex2f(-150.0, 70.0);
            glVertex2f(-130.0, 85.0);
            glVertex2f(-110.0, 70.0);
            glVertex2f(-130.0, 55.0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-120.0, 60.0);
            glVertex2f(-100.0, 75.0);
            glVertex2f(-80.0, 60.0);
            glVertex2f(-100.0, 45.0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-90.0, 50.0);
            glVertex2f(-70.0, 65.0);
            glVertex2f(-50.0, 50.0);
            glVertex2f(-70.0, 35.0);
        glEnd();
    glEndList();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    gluLookAt(0.0, 0.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Desenha as listas de exibição
    glCallList(chaoList);
    glCallList(casaList);
    glCallList(arvoreList);
    glCallList(solList);
    glCallList(nuvemList);

    glutSwapBuffers();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cena OpenGL com Display List");
    glewInit();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
    glutMainLoop();
    return 0;
}

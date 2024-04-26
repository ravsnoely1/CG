#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void desenhaTelhado() {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Cor vermelha para o telhado
        glVertex3f(-60, 50, 0);
        glVertex3f(60, 50, 0);
        glVertex3f(0, 100, 0);
    glEnd();
}

void desenhaParede() {
    glBegin(GL_QUADS);
        glColor3f(0.72, 0.25, 0.05); // Cor de tijolo para as paredes
        glVertex3f(-50, -50, 0);
        glVertex3f(50, -50, 0);
        glVertex3f(50, 50, 0);
        glVertex3f(-50, 50, 0);
    glEnd();
}

void desenhaPorta() {
    glBegin(GL_QUADS);
        glColor3f(0.25, 0.25, 0.25); // Cor cinza escuro para a porta
        glVertex3f(10, -50, 0);
        glVertex3f(30, -50, 0);
        glVertex3f(30, 10, 0);
        glVertex3f(10, 10, 0);
    glEnd();
}

void desenhaJanela() {
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // Cor azul para a janela
        glVertex3f(-30, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 30, 0);
        glVertex3f(-30, 30, 0);
    glEnd();
}

void desenhaCasa() {
    desenhaTelhado();
    desenhaParede();
    desenhaPorta();
    desenhaJanela();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaCasa();
    glFlush();
}

void inicializa() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fundo branco
}

void redimensionada(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casa OpenGL");
    glewInit();
    inicializa();
    glutDisplayFunc(display);
    glutReshapeFunc(redimensionada);
    glutMainLoop();
    return 0;
}

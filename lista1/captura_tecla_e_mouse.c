#include <GL/freeglut.h>
#include <stdio.h>

// Variáveis globais para armazenar informações do teclado e mouse
int larguraJanela, alturaJanela;
char ultimaTecla;
int posXMouse, posYMouse;

// Funcao para desenhar texto na tela
void desenhaTexto(const char* texto, int comprimento, int x, int y) {
    glMatrixMode(GL_PROJECTION);
    double matriz[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matriz);
    glLoadIdentity();
    glOrtho(0, larguraJanela, 0, alturaJanela, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for(int i = 0; i < comprimento; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)texto[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matriz);
    glMatrixMode(GL_MODELVIEW);
}

// Callback para redimensionamento da tela
void redimensiona(int largura, int altura) {
    larguraJanela = largura;
    alturaJanela = altura;
    printf("Nova largura: %d, Nova altura: %d\n", largura, altura);
    glViewport(0, 0, largura, altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, largura, 0, altura);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Callback para pressionamento de tecla
void teclaPressionada(unsigned char tecla, int x, int y) {
    ultimaTecla = tecla;
    posXMouse = x;
    posYMouse = y;
    printf("Tecla pressionada: %c, Posicao do mouse: (%d, %d)\n", tecla, x, y);
}

// Callback para despressionamento de tecla
void teclaSolta(unsigned char tecla, int x, int y) {
    printf("Tecla solta: %c, Posicao do mouse: (%d, %d)\n", tecla, x, y);
}

// Callback para clique do mouse
void cliqueMouse(int botao, int estado, int x, int y) {
    printf("Botao do mouse: %d, Estado: %d, Posicao: (%d, %d)\n", botao, estado, x, y);
}

// Callback para movimento do mouse
void movimentoMouse(int x, int y) {
    printf("Posicao do mouse: (%d, %d)\n", x, y);
}

// Funcao principal de desenho
void exibe() {
    glClear(GL_COLOR_BUFFER_BIT);
    char info[128];

    sprintf(info, "Largura: %d, Altura: %d", larguraJanela, alturaJanela);
    desenhaTexto(info, strlen(info), 10, alturaJanela - 20);
    sprintf(info, "Ultima tecla: %c", ultimaTecla);
    desenhaTexto(info, strlen(info), 10, alturaJanela - 60);
    sprintf(info, "Clique do mouse: (%d, %d)",  posXMouse, posYMouse);
    desenhaTexto(info, strlen(info), 10, alturaJanela - 80);
    
                              
    glutSwapBuffers();
}

// Funcao principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Eventos OpenGL e freeglut");
    glutDisplayFunc(exibe);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);
    glutKeyboardUpFunc(teclaSolta);
    glutMouseFunc(cliqueMouse);
    glutPassiveMotionFunc(movimentoMouse);
    glutIgnoreKeyRepeat(1); // Desabilita o disparo contínuo de teclas
    glutMainLoop();
    return 0;
}

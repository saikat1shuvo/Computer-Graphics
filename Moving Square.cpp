#include <GL/glut.h>
float pos1 = -0.8f;
float pos2 = 0.8f;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(pos1, 0.0f, 0.0f);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
    glEnd();
    glLoadIdentity();
    glTranslatef(pos2, 0.0f, 0.0f);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
    glEnd();

    glutSwapBuffers();
}
void update(int value) {
    pos1 += 0.01f;
    pos2 -= 0.01f;

    if (pos1 > 1.0f) pos1 = -1.0f;
    if (pos2 < -1.0f) pos2 = 1.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Opposite Moving Boxes");
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}



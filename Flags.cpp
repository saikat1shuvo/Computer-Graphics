#include <windows.h>
#include <GL/glut.h>

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
    glClear(GL_COLOR_BUFFER_BIT);

    float size = 0.4f;   // size of each square
    float startX = -0.8f;
    float startY = 0.8f;

    for(int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++) {

            // Alternate color logic
            if((row + col) % 2 == 0)
                glColor3f(0.0f, 0.0f, 0.0f);  // Black
            else
                glColor3f(1.0f, 1.0f, 1.0f);  // White

            float x1 = startX + col * size;
            float y1 = startY - row * size;

            glBegin(GL_QUADS);
            glVertex2f(x1, y1);
            glVertex2f(x1 + size, y1);
            glVertex2f(x1 + size, y1 - size);
            glVertex2f(x1, y1 - size);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("4x4 Chess Board - Lab Task");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


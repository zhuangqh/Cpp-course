#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <typeinfo>
#include <GL/glut.h>

// coordinates of frame
float array[3][7] = {
    {0.0, 50.0,  0.0, 45.0, 45.0, -5.0,  5.0},
    {0.0,  0.0, 50.0, -5.0,  5.0, 45.0, 45.0},
    {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0}
};

// translation matrix
float matrix_trans[3][3] = {
    {1.0, 0.0, 50.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}
};

// rotation matrix
float matrix_rotat[3][3] = {
    {0.0, -1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0}
};

Matrix<float> frame(array);
Matrix<float> trans(matrix_trans);
Matrix<float> rotat(matrix_rotat);

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
}

void draw_axis(void) {
    // draw coordinate axis
        glBegin(GL_LINES);
                glColor3f(1.0, 1.0, 1.0);  // x axis
                glVertex2f(-400.0, 0.0);
        glVertex2f(400.0, 0.0);

        glColor3f(1.0, 1.0, 1.0);  // y axis
                glVertex2f(0.0, 200.0);
        glVertex2f(0.0, -200.0);
        glEnd();

    // draw scale
    glBegin(GL_LINES);
        for (int i = -40; i <= 40; i++) {  // x axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(10.0*i, 0.0);
            glVertex2f(10.0*i, 3.0);
        }

        for (int i = -20; i <= 20; i++) {  // y axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(0.0, 10.0*i);
            glVertex2f(3.0, 10.0*i);
        }
    glEnd();
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);

    draw_axis();

    glLoadIdentity();

    glFlush ();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    if (w <= h)
        gluOrtho2D (-200.0, 250.0, -100.0*(GLfloat)h/(GLfloat)w,
                    200.0*(GLfloat)h/(GLfloat)w);
    else
        gluOrtho2D (-200.0*(GLfloat)w/(GLfloat)h,
                    250.0*(GLfloat)w/(GLfloat)h, -50.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutMainLoop();

  return 0;
}

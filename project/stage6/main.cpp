#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <GL/glut.h>
#include <map>
#include <cmath>

// coordinates of frame
float array[3][7] = {
    {0.0, 0.125,  0.0, 0.1125, 0.1125, -0.0125,  0.0125},
    {0.0,  0.0, 0.125, -0.0125,  0.0125, 0.1125, 0.1125},
    {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0}
};

// translation matrix
float matrix_trans[3][3] = {
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}
};

// rotation matrix
float matrix_rotat[3][3] = {
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 1.0}
};

//necessary varibles
const float pi = 2 * asin(1);
Matrix<float> primary_frame(array);
Matrix<float> frame(array);
Matrix<float> trans(matrix_trans);
Matrix<float> rotat(matrix_rotat);
std::map<std::string, Vector<float> >pose_list;

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
}

void draw_axis(void) {
    // draw coordinate axis
        glBegin(GL_LINES);
                glColor3f(1.0, 1.0, 1.0);  // x axis
                glVertex2f(-1.0, 0.0);
                glVertex2f(1.0, 0.0);

        glColor3f(1.0, 1.0, 1.0);  // y axis
                glVertex2f(0.0, 1.0);
                glVertex2f(0.0, -1.0);
        glEnd();

    // draw scale
    glBegin(GL_LINES);
        for (int i = -8; i <= 8; i++) {  // x axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(0.125*i, 0.0);
            glVertex2f(0.125*i, 0.0075);
        }

        for (int i = -8; i <= 8; i++) {  // y axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(0.0, 0.125*i);
            glVertex2f(0.0075, 0.125*i);
        }
    glEnd();
}

void draw_frame(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
          frame(i, j) /= frame(2, j);
        }
    }

    glShadeModel(GL_SMOOTH);
    glBegin (GL_LINES);//draw frame
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame(0, 0), frame(1, 0));
        glVertex2f(frame(0, 1), frame(1, 1));

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame(0, 1), frame(1, 1));
        glVertex2f(frame(0, 3), frame(1, 3));

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame(0, 1), frame(1, 1));
        glVertex2f(frame(0, 4), frame(1, 4));


        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame(0, 0), frame(1, 0));
        glVertex2f(frame(0, 2), frame(1, 2));

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame(0, 2), frame(1, 2));
        glVertex2f(frame(0, 5), frame(1, 5));

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame(0, 2), frame(1, 2));
        glVertex2f(frame(0, 6), frame(1, 6));
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

void draw_pose(const std::string mode) {
  glClear (GL_COLOR_BUFFER_BIT);
  draw_axis();

  frame = primary_frame;
  draw_frame();
  for (int i = 0; i < 3; ++i) {
    Matrix<float> now = frame;

    //translate the frame to the origin
    trans(0, 2) = -1 * frame(0, 0);
    trans(1, 2) = -1 * frame(1, 0);
    now = trans * frame;

    //rotate
    float rotate_deg = pose_list[mode](i) * pi * -1 / 180.0;
    rotat(0, 0) = cos(rotate_deg);
    rotat(0, 1) = sin(rotate_deg);
    rotat(1, 0) = -1 * sin(rotate_deg);
    rotat(1, 1) = cos(rotate_deg);

    now = rotat * now;

    //translate back after rotation
    trans(0, 2) = frame(0, 0);
    trans(1, 2) = frame(1, 0);
    now = trans * now;

    //translation
    float tran_deg;
    if (now(0, 1) - now(0, 0) > 1e-6)
      tran_deg = atan((now(1, 1) - now(1, 0))
                      / (now(0, 1) - now(0, 0)));
    else
      tran_deg = now(1, 1) - now(1, 0) > 0 ? (pi / 2) : (pi / -2);

    trans(0, 2) = 0.125 * cos(tran_deg);
    trans(1, 2) = 0.125 * sin(tran_deg);
    now = trans * now;

    //draw arm
    glBegin (GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(frame(0, 0), frame(1, 0));
        glVertex2f(now(0, 0), now(1, 0));
    glEnd();

    frame = now;
    glLoadIdentity();
    draw_frame();
  }
  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 'q': break;
  case 'z': draw_pose("qz"); break;
  case 'r': draw_pose("qr"); break;
  case 'n': draw_pose("qn"); break;
  case 'd': draw_pose("qd"); break;
  }
}


int main(int argc, char** argv) {
  //create a list of poses
  float parameters[4][1][3] = {0, 0, 0,
                           90, 0, 0,
                           45, -45, 45,
                           -90, 0, 0};
  pose_list["qz"] = Vector<float>(parameters[0]);
  pose_list["qr"] = Vector<float>(parameters[1]);
  pose_list["qn"] = Vector<float>(parameters[2]);
  pose_list["qd"] = Vector<float>(parameters[3]);

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("The robot arm");

  init();

  glutDisplayFunc(display);

  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

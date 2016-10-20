#include<GL/glut.h>

GLdouble CoordinateVertex[][3] = {
    {0.0, 0.0, 0.0},
    {3.0, 0.0, 0.0},
    {0.0, 3.0, 0.0},
    {0.0, 0.0, 3.0}
};

int CoordinateEdge[][2] = {
    {0, 1},
    {0, 2},
    {0, 3}
};

void display(void)
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    /* 図形の描画 */
    glBegin(GL_LINES);

    glColor3d(1.0, 0.0, 0.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[0][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[0][1]]);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[1][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[1][1]]);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3dv(CoordinateVertex[CoordinateEdge[2][0]]);
    glVertex3dv(CoordinateVertex[CoordinateEdge[2][1]]);

    glEnd();

    glFlush();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);

    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
    glTranslated(0.0, 0.0, -5.0);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("arm_simulator");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

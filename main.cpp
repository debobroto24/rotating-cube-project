#include<windows.h>
#include<GL/glut.h>
// PERUBAHAN

// inITIALIZES 3d rendering
void initRendering(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

//called when the window is resized
void handleResize(int w , int h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w/(double)h,1.0,200.0);
}

float _angle = -70.0f;
void drawScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f , 0.0f, -14.0f);

    glRotatef(10, 1.0f , 0.0f , 0.0f);
    glRotatef(-10 , 0.0f , 0.0f , 1.0f);
    glRotatef(_angle, 0.0f , 1.0f , 0.0f);
    //glRotatef(10,1.0f , 0.0f , 0.0f,0.0f);
    //glRotatef(-10 , 0.0f , 0.0f 1.0f);
    //glRotatef(_angle , 0.0f , 1.0f , 0.0f);
//    glColor3f(1.0f,1.0f,0.5f);

    glBegin(GL_QUADS);

  //front
//    glColor3f(1.0,0.0,0.0);
glColor3f(1.0f, 1.0f, 1.0f);//white
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    //back
//    glColor3f(0.0,1.0,0.0);
glColor3f(1.0f, 0.5f, 0.0f);//Orange
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    //left
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    //top
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    //bottom
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glEnd();
    glutSwapBuffers();
}

void update (int value){
    _angle += 1.5f;
    if(_angle > 360){
        _angle -=360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update , 0);
}

int main(int argc, char** argv){
    //Innitailize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);

    //create the window
    glutCreateWindow("lighthing");
    initRendering();

    //set hanler functionsw
    glutDisplayFunc(drawScene);

    glutReshapeFunc(handleResize);

    update(0);

    glutMainLoop();
    return 0;
}

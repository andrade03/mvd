//GERSON ALEXANDER SANDOVAL GUERRERO
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

static int girox = 0;
static int giroy = 0;
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;


GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
GLfloat scale2=1.0f;
void init(void)
{
	GLfloat light_position[] = { -1.0, 1.0, 5.0, 0.0 };
// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT, GL_FILL);

}
//funcion que controla los matariales 
void color(float q, float w, float e, float r, float t, float y, float u, float i, float o, float p)
{
	
GLfloat mat_ambient[] = { q, w, e, p };
GLfloat mat_diffuse[] = { r, t, y, p };
GLfloat mat_specular[] = { u, i, o, p };
GLfloat shine[] = {27.8974f};

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);

}
void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-500, 500, -500, 500, -500, 500);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

void cuboinit(){
	
    /* Dibujamos una tetera */
glBegin(GL_POLYGON);

    //glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.3, -0.3 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3,  0.3, -0.3 );      // V2 Amarillo
   // glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.3,  0.3, -0.3 );      // V3 es azul
   // glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.3, -0.3, -0.3 );      // V4 rojo

    glEnd();

    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    //glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f( 0.3, -0.3, 0.3 );
    glVertex3f( 0.3,  0.3, 0.3 );
    glVertex3f(-0.3,  0.3, 0.3 );
    glVertex3f(-0.3, -0.3, 0.3 );
    glEnd();

    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
//    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3,  0.3, -0.3 );
    glVertex3f(0.3,  0.3,  0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glEnd();

    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    //glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3,  0.3,  0.3 );
    glVertex3f(-0.3,  0.3, -0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();

    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    //glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3,  0.3,  0.3 );
    glVertex3f(0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3, -0.3 );
    glVertex3f(-0.3,  0.3,  0.3 );
    glEnd();
/*
    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.3, -0.3, -0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glVertex3f(-0.3, -0.3, -0.3 );
    glEnd();
*/
    glFlush();
glutSwapBuffers();
	}

void display(void)
{
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
	 //glShadeModel(GL_SMOOTH);
    glClearColor(0,1,1,0.5);
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
    
// Rotacion de 25 grados en torno al eje x
    glRotated(30.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();    
   
  // glLightfv (GL_LIGHT0, GL_POSITION, position);
   glTranslatef(X, Y, Z);
   //glLightfv (GL_LIGHT0, GL_POSITION, position);
   //glTranslated (0.0, 0.0, 1.5);
   //glDisable (GL_LIGHTING);
  
   glTranslatef(-160.0,-180.0,30.0);
    color(0.05f, 0.05, 0.05f,0.5f, 0.5f, 0.5f,0.7f, 0.7f, 0.7f,0.078125f);
    //glutSolidCube (70.0);
   cuboinit();
   //glEnable (GL_LIGHTING);
   glPopMatrix ();
     

   //BASE
   glPushMatrix();
     //
    glTranslatef(17.5,-220.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.9, 0.8, 0.9);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();
     //BASE
     
     //MASTIL
   glPushMatrix();
     //
    glTranslatef(17.5,20.0,30.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
        color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 3.0, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();     
//MASTIL
//LATERAL

   glPushMatrix();
     //
      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(18.0,240.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.7, 0.7, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();
     
     
   glPushMatrix();
     //
      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(240.0,240.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(3.0, 0.7, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();     

//MASTIL PEQUEÑO
   glPushMatrix();
     //
           glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,140.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 1.0, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  

//MASTIL PEQUEÑO FIN


//MASTIL MAS PEQUEÑO
   glPushMatrix();
     //
           glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,10.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.2, scale2, 0.2);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();
//MASTIL MAS PEQUEÑO FIN



//PRIMER CUBO BAJO LA POLEA

if(scale2>=3.5 && (((GLdouble) giroy))==0.0){
//if(scale2>=3.5 && (((GLdouble) giroy))==0.0){
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,-220.0,30.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.55, 0.55, 0.55);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     
 }
 else{
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,-220.0,30.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
        color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.35, 0.35, 0.35);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     	 
	 }
//PRIMER CUBO BAJO LA POLEA FIN

//CUBO GRADOS NEGATIVOS

if(scale2>=2.3 && (((GLdouble) giroy))==15.0){
//if(scale2>=3.5 && (((GLdouble) giroy))==0.0){
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,-160.0,-60.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.55, 0.55, 0.55);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     
 }
 else{
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,-160.0,-60.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
        color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.35, 0.35, 0.35);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     	 
	 }
//CUBO GRADOS NEGATIVOS FIN


//SEGUNDO NEGATIVOS
if(scale2>=2.3 && (((GLdouble) giroy))==85.0){
//if(scale2>=3.5 && (((GLdouble) giroy))==0.0){
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(80.0,-160.0,-380.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.7, 0.7, 0.7);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     
 }
 else{
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(80.0,-160.0,-380.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
        color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 0.5, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     	 
	 }
//SEGUNDO NEGATIVOS FIN
     
     
     //NEGATIVOS PRIMERO
     //SEGUNDO NEGATIVOS
if(scale2>=2.8 && (((GLdouble) giroy))==-55.0){
//if(scale2>=3.5 && (((GLdouble) giroy))==0.0){
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(180.0,-220.0,320.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.7, 0.7, 0.7);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     
 }
 else{
   glPushMatrix();
     //
     //      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   //glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(180.0,-220.0,320.0);
    /*color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);*/
        color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 0.5, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();  
     	 
	 }
     //NEGATIVOS PRIMERO FIN
     
     /*glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(17.5,250.0,30.0);
    glTranslatef(X, Y, Z);
    color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
      glColor3f(1.0,1.0,0.0);
    //glutSolidSphere (90,50,60);
    //glutSolidCube (120.0);
    glutSolidCube (45.0);
     glPopMatrix();
     *//*
   glPushMatrix();
     //
      glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(-50.0,120.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(3.5, 0.7, 0.5);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();
     */
     //LATERAL
     /*
   glPushMatrix();
     //
    glTranslatef(20.0,-40.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    glScalef(1.3, 1.5, 1.0);
    //glutSolidSphere (90,50,60);
    glutSolidCube (120.0);
    //glutSolidCube (50.0);
     glPopMatrix();
*/
//PUNTO NEGRO QUE AHI APARECE
    /* glPushMatrix();
 glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
   glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(271.0,-90.0,50.0);
 color(0.0f, 0.05, 0.0f,0.4f, 0.5f, 0.4f,0.7f, 0.04f, 0.7f,0.078125f);
      glColor3f(1.0,1.0,0.0);
    //glutSolidSphere (90,50,60);
    //glutSolidCube (120.0);
    glutSolidCube (25.0);
     glPopMatrix();

     */
     

     //////////////////////////////////
     //fin para los de arriba
     
     
     
     

   glFlush();
}

void specialKeys( int key, int x, int y )
{

    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT){
		
		if(giroy>=85){
			giroy=90;
			}
		else{
          giroy = (giroy + 5) % 90;
           }//X += 20.0 / 180;
}
   //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT){
        //X -= 20.0;
		if(giroy<=-85){
			giroy=-90;
			}
		else{        
        giroy = (giroy - 5)  % 180;
	}}
    else if (key == GLUT_KEY_UP){
		

        if(scale2<=1.0){
			scale2=1.0;
			
			}
			else{
				        scale2 -= 0.1;
				}
			}
    else if (key == GLUT_KEY_DOWN){
		if(scale2>=4.0){
			scale2=4.0;
			}
		else{
		scale2 += 0.1;
	}}
	
	
    
    //  Solicitar actualización de visualización
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels	
    glutInitWindowSize (1000, 800);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (10, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Fifuras");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}


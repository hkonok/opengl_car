#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define WHITE 0, 0, 0

#define BLACK 1, 1, 1

#define LIGHT_GREEN 0.125, 0.698, 0.667
#define DARK_GREEN 0.000, 0.502, 0.502

#define LIGHT_WHITE 0.961, 0.961, 0.961
#define DARK_WHITE 0.502, 0.502, 0.502

//make a global variable -- for tracking the anglular position of camera
double cameraAngle;			//in radian
double cameraAngleDelta;

double cameraHeight;
double cameraRadius;

double rectAngle;	//in degree

bool canDrawGrid;

void car_top(){
    //car top
    glBegin(GL_QUADS);{
		    glColor3f(LIGHT_GREEN);
			glVertex3f(0,0,30);
			glVertex3f(15,0,30);//right low
			glColor3f(DARK_GREEN);
			glVertex3f(15,30,30);//right top
			glVertex3f(0,30,30);
		}glEnd();

     // between top and front glass
		glBegin(GL_QUADS);{
            glColor3f(LIGHT_GREEN);
			glVertex3f(0,30,30);
			glVertex3f(15,30,30);//right low
			glVertex3f(15,32,28);//right top
			glVertex3f(0,32,28);
		}glEnd();

    // between front and back glass
		glBegin(GL_QUADS);{
            glColor3f(LIGHT_GREEN);
			glVertex3f(0,0,30);
			glVertex3f(0,-3,27);

            glColor3f(DARK_GREEN);
            glVertex3f(7.5,-3,27);//rihgt low
            glVertex3f(7.5,0,30);//right top
		}glEnd();

		glBegin(GL_QUADS);{
            glColor3f(LIGHT_GREEN);
			glVertex3f(15,-3,27);//rihgt low
			glVertex3f(15,0,30);//right top

            glColor3f(DARK_GREEN);
            glVertex3f(7.5,0,30);//right top
            glVertex3f(7.5,-3,27);//rihgt low

        }glEnd();
}

void front_n_back_glass(){
    // front glass

		glBegin(GL_QUADS);{
            glColor3f(DARK_WHITE);
			glVertex3f(0,32,28);
			glVertex3f(15,32,28);//right low
			glColor3f(LIGHT_WHITE);
			glVertex3f(19,40,20);//right top
			glVertex3f(-4,40,20);
		}glEnd();

        // back glass
		glBegin(GL_QUADS);{
            glColor3f(DARK_WHITE);
			glVertex3f(0,-3,27);
			glVertex3f(15,-3,27);//right top
			glColor3f(LIGHT_WHITE);
			glVertex3f(18,-9,20);//right low
			glVertex3f(-3,-9,20);
		}glEnd();
}

void top_left_frame(){
    glBegin(GL_POLYGON);{
            /* Set the vertices */
            glColor3f(LIGHT_GREEN);
            //front glass
            glVertex3f(-4,40,20);//front right top
            glVertex3f(0,32,28);//front right low
            glVertex3f(0,30,30);//between right low
            //middhel of front glass nad top base
            glColor3f(DARK_GREEN);
            glVertex3f(-0.5,30,28);//right low
            glVertex3f(-6,40,20);
        }glEnd();

        //base line
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                //front glass

                glVertex3f(0,30,30);//between right low
                glVertex3f(0,0,30);//base right low

                glColor3f(DARK_GREEN);
                //middhel of front glass nad top base
                glVertex3f(-.5,0,28);//base right low
                glVertex3f(-.5,30,28);//right low
            }glEnd();

         // back glass side
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                glVertex3f(0,0,30);//base right low
                glVertex3f(0,-3,27);//rihgt low
                glVertex3f(-3,-9,20);//right low

                glColor3f(DARK_GREEN);
                glVertex3f(-6,-9,20);//right low
                glVertex3f(-0.5,0,28);//base right low
                glVertex3f(0,0,30);//base right low

            }glEnd();


            //horizontal border back glass to front glass
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                glVertex3f(-6,-9,20);//right low
                glVertex3f(-7,-9,18);//right low

                glColor3f(DARK_GREEN);
                glVertex3f(-7,40,18);
                glVertex3f(-6,40,20);//
                //front right top

            }glEnd();
}

void top_right_frame(){
    glBegin(GL_POLYGON);{
            /* Set the vertices */
            glColor3f(LIGHT_GREEN);
            //front glass
            glVertex3f(19,40,20);//front right top
            glVertex3f(15,32,28);//front right low
            glVertex3f(15,30,30);//between right low
            //middhel of front glass nad top base
            glColor3f(DARK_GREEN);
            glVertex3f(15.5,30,28);//right low
            glVertex3f(21,40,20);
        }glEnd();

        //base line
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                //front glass

                glVertex3f(15,30,30);//between right low
                glVertex3f(15,0,30);//base right low

                glColor3f(DARK_GREEN);
                //middhel of front glass nad top base
                glVertex3f(15.5,0,28);//base right low
                glVertex3f(15.5,30,28);//right low
            }glEnd();

         // back glass side
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                glVertex3f(15,0,30);//base right low
                glVertex3f(15,-3,27);//rihgt low
                glVertex3f(18,-9,20);//right low

                glColor3f(DARK_GREEN);
                glVertex3f(21,-9,20);//right low
                glVertex3f(15.5,0,28);//base right low
                glVertex3f(15,0,30);//base right low

            }glEnd();


            //horizontal border back glass to front glass
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(LIGHT_GREEN);
                glVertex3f(21,-9,20);//right low
                glVertex3f(22,-9,18);//right low

                glColor3f(DARK_GREEN);
                glVertex3f(22,40,18);
                glVertex3f(21,40,20);//
                //front right top

            }glEnd();
}


void right_side_window(){
    //right side front galass window/////////////////////////////////////////////////////////////////////////////////
            glBegin(GL_POLYGON);{
                glColor3f(DARK_WHITE);
                glVertex3f(21,40,20);//

                glColor3f(LIGHT_WHITE);
                glVertex3f(15.5,30,28);//right low
                glVertex3f(21,30,20);//
                //front right top
            }glEnd();
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_WHITE);
                glVertex3f(15.5,30,28);
                glVertex3f(21,30,20);//

                glColor3f(DARK_WHITE);
                glVertex3f(21,18,20);//
                glVertex3f(15.5,17.5,28);//right low
            }glEnd();

            //right side middle window
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(DARK_WHITE);

                glVertex3f(15.5, 16.5  , 28);//right low
                glVertex3f(21  , 16.5  , 20);//

                glColor3f(LIGHT_WHITE);
                glVertex3f(21,1,20);//
                glVertex3f(15.5,1.5,28);//right low
            }glEnd();

            //right side back window
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_WHITE);
                glVertex3f(21,0,20);//
                glVertex3f(15.5,0.9,28);
                glVertex3f(15.5,0,28);

                glColor3f(DARK_WHITE);
                glVertex3f(21,-9,20);//right low
            }glEnd();
}


void left_side_window(){
    //right side front galass window/////////////////////////////////////////////////////////////////////////////////
            glBegin(GL_POLYGON);{
                glColor3f(DARK_WHITE);
                glVertex3f(-6,40,20);//

                glColor3f(LIGHT_WHITE);
                glVertex3f(-0.5,30,28);//right low
                glVertex3f(-6,30,20);//
                //front right top
            }glEnd();
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_WHITE);
                glVertex3f(-0.5,30,28);
                glVertex3f(-6,30,20);//

                glColor3f(DARK_WHITE);
                glVertex3f(-6,18,20);//
                glVertex3f(-0.5,17.5,28);//right low
            }glEnd();

            //right side middle window
            glBegin(GL_POLYGON);{
                /* Set the vertices */
                glColor3f(DARK_WHITE);

                glVertex3f(-0.5, 16.5  , 28);//right low
                glVertex3f(-6  , 16.5  , 20);//

                glColor3f(LIGHT_WHITE);
                glVertex3f(-6,1,20);//
                glVertex3f(-0.5,1.5,28);//right low
            }glEnd();

            //right side back window
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_WHITE);
                glVertex3f(-6,0,20);//
                glVertex3f(-0.5,0.9,28);
                glVertex3f(-0.5,0,28);

                glColor3f(DARK_WHITE);
                glVertex3f(-6,-9,20);//right low
            }glEnd();
}


void right_side_window_divider(){
             //glass devider one
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_GREEN);
                glVertex3f(15.5,17.5,28);
                glVertex3f(15.5, 16.5  , 28);

                glColor3f(DARK_GREEN);
                glVertex3f(21  , 16.5  , 20);
                glVertex3f(21,18,20);
                //right low
            }glEnd();

            //glass devider two
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_GREEN);
                glVertex3f(15.5,0.9,28);
                glVertex3f(15.5,1.5,28);

                glColor3f(DARK_GREEN);
                glVertex3f(21,1,20);
                 glVertex3f(21,0,20);
            }glEnd();
}

void left_side_window_divider(){
             //glass devider one
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_GREEN);
                glVertex3f(-0.5,17.5,28);
                glVertex3f(-0.5, 16.5  , 28);

                glColor3f(DARK_GREEN);
                glVertex3f(-6  , 16.5  , 20);
                glVertex3f(-6,18,20);
                //right low
            }glEnd();

            //glass devider two
            glBegin(GL_POLYGON);{
                glColor3f(LIGHT_GREEN);
                glVertex3f(-0.5,0.9,28);
                glVertex3f(-0.5,1.5,28);

                glColor3f(DARK_GREEN);
                glVertex3f(-6,1,20);
                 glVertex3f(-6,0,20);
            }glEnd();
}


void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(WHITE, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
//	gluLookAt(-30,-30,50,	0,0,0,	0,0,1);

	gluLookAt(cameraRadius*cos(cameraAngle), cameraRadius*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
	//rotate this rectangle around the Z axis

	glPushMatrix();{
	    //drawing car
        car_top();
        front_n_back_glass();

		top_right_frame();
		right_side_window();
		right_side_window_divider();

		top_left_frame();
		left_side_window();
		left_side_window_divider();

	}glPopMatrix();		//the effect of rotation is not there now.

	//some gridlines along the field
	int i;

	//WILL draw grid IF the "canDrawGrid" is true:

	if(canDrawGrid == true){
		glColor3f(0.3, 0.3, 0.3);	//grey
		glBegin(GL_LINES);{
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		}glEnd();
	}

	// draw the two AXES
	glColor3f(BLACK);	//100% white
	glBegin(GL_LINES);{
		//Y axis
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);

		//X axis
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
	}glEnd();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

	cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!

	//codes for any changes in Models

	rectAngle -= 1;

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':	//reverse the rotation of camera
			cameraAngleDelta = -cameraAngleDelta;
			break;

		case '2':	//increase rotation of camera by 10%
			cameraAngleDelta *= 1.1;
			break;

		case '3':	//decrease rotation
			cameraAngleDelta /= 1.1;
			break;

		case '8':	//toggle grids
			canDrawGrid = 1 - canDrawGrid;
			break;

		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraRadius += 10;
			break;
		case GLUT_KEY_UP:		// up arrow key
			if(cameraRadius > 10)
				cameraRadius -= 10;
			break;

		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_LEFT:
			break;

		case GLUT_KEY_PAGE_UP:
			cameraHeight += 10;
			break;
		case GLUT_KEY_PAGE_DOWN:
			cameraHeight -= 10;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				cameraAngleDelta = -cameraAngleDelta;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}


void init(){
	//codes for initialization
	cameraAngle = 0;	//// init the cameraAngle
	cameraAngleDelta = 0.002;
	rectAngle = 0;
	canDrawGrid = true;
	cameraHeight = 150;
	cameraRadius = 150;

	//clear the screen
	glClearColor(WHITE, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

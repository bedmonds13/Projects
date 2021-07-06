//mesh.cpp
#include "Mesh.h"
#include "GL/Glut.h"
#include <iostream>
#include <fstream>

/*******Point constructor and functions*******/
Point3::Point3():x(0), y(0), z(0) {}
Point3::Point3(float xx, float yy, float zz): x(xx), y(yy), z(zz){}
void Point3::set(float dx, float dy, float dz)
{
    x = dx;
    y = dy;
    z = dz;
}
void Point3::set(Point3& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

/*******Face constructor and functions*******/
Face::Face():nVerts(0),vert(nullptr){
}
Face::~Face()
{
    delete[] vert;
}
/*******Mesh constructor and functions*******/
Mesh::Mesh()    //constructor
{
    numVerts = numFaces = numNormals = 0;
    pt = NULL;
    norm = NULL;
    face = NULL;
}

bool Mesh::isEmpty()
{
    return (numVerts == 0) || (numFaces == 0) || (numNormals == 0);
}

void Mesh::setColor(int n)
{
    if (n == 1)
        glColor3f(1, 0, 0);
    else if (n == 2)
        glColor3f(0, 1, 0);
    else if (n == 3)
        glColor3f(0, 0, 1);
    else if (n == 4)
        glColor3f(1, 1, 0);
    else if (n == 5)
        glColor3f(1, 0, 1);
    else if (n == 6)
        glColor3f(0, 1, 1);
    else
        glColor3f(0, 0, 0);
}

void Mesh::drawMesh()   // use OpenGL to draw this mesh
{
    // draw each face of this mesh using OpenGL: draw each polygon.
    if (isEmpty()) return; // mesh is empty

    for (int f = 0; f < numFaces; f++) // draw each face
    {
        
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glBegin(GL_POLYGON);
        std::cout << std::endl;
        setColor(f);
        for (int v = 0; v < face[f].nVerts; v++) // for each vertex
        {
            int in = face[f].vert[v].normIndex; // index of this normal
            int iv = face[f].vert[v].vertIndex; // index of this vertex
            glNormal3f(norm[in].x, norm[in].y, norm[in].z);
            std::cout << "[" << norm[in].x << "," << norm[in].y << "," <<
                norm[in].z << "]" << "    ";
            glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
            std::cout << "(" << pt[iv].x << "," << pt[iv].y << "," <<
                pt[iv].z << ")" << "    ";
        }
        glEnd();
        std::cout << std::endl;
    }
} //drawMesh

//read Mesh data from file
int Mesh::readFile(const char* fileName)
{
    std::fstream infile;
    infile.open(fileName, std::ios::in);
    std::cout << "opening file " << std::endl;
    if (infile.fail()) return -1; // error - can't open file
    if (infile.eof())  return -1; // error - empty file
    infile >> numVerts >> numNormals >> numFaces;
    pt = new Point3[numVerts];
    norm = new Vector3[numNormals];
    face = new Face[numFaces];
    //check that enough memory was found:
    if (!pt || !norm || !face)return -1; // out of memory
    std::cout << "file open O.K. " << std::endl;

    for (int p = 0; p < numVerts; p++) // read the vertices
        infile >> pt[p].x >> pt[p].y >> pt[p].z;
    for (int n = 0; n < numNormals; n++) // read the normals
        infile >> norm[n].x >> norm[n].y >> norm[n].z;
    std::cout << "numFaces = " << numFaces << std::endl;
    for (int f = 0; f < numFaces; f++)// read the faces
    {
        infile >> face[f].nVerts;
        std::cout << "counting" << std::endl;
        face[f].vert = new VertexID[face[f].nVerts];
        for (int i = 0; i < face[f].nVerts; i++)
            infile >> face[f].vert[i].vertIndex;
        for (int i = 0; i < face[f].nVerts; i++)
            infile >> face[f].vert[i].normIndex;
    }
    return 0; // success
} 
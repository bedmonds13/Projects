#include <string>

class Vector3
{
public:
    float x;
    float y;
    float z;
};
class Point3 {
public:
    float x, y, z;

    void set(float dx, float dy, float dz);
    void set(Point3& p);
    Point3(float xx, float yy, float zz);
    Point3();

};

class VertexID {
public:
    int vertIndex;	//index of this vertex in the vertex list
    int normIndex;	//index of this vertex's normal
};
//used to define a Mesh
class Face {
public:
    int nVerts;
    VertexID* vert; 	//array of vertex and normal indices

    Face();	   	//constructor
    ~Face();		//destructor
};

class Mesh {
private:
    int numVerts, numNormals, numFaces;
    Point3* pt; 		// array of points ( 3D vertices
    Vector3* norm; 	// array of normals
    Face* face; 		// array of faces
    int lastVertUsed;
    int lastNormUsed;
    int lastFaceUsed;

public:
    int readFile(const char* fileName);
    std::string meshFileName; 	// holds file name for this Mesh
    void setColor(int n);
    void readMesh(std::string fname);
    void writeMesh(char* fname);
    void printMesh();
    void drawMesh();
    void drawEdges();
    void freeMesh();
    bool isEmpty();
    void makeEmpty();
    Mesh();
    //virtual void drawOpenGL();
    Mesh(std::string fname);
    Vector3 newell4(int indx[]);
    //bool hit(Ray& r, Intersection& inter);
}; // end of Mesh class

    
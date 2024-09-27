#include <cmath>
#include <vector>
#include <iostream>

struct Vec3 {
    float x, y, z;

    // Default constructor
    Vec3() : x(0), y(0), z(0) {}

    // Constructor with parameters
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Copy constructor
    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}

    // Assignment operator
    Vec3& operator=(const Vec3& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // Addition
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    // Subtraction
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Dot product
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Magnitude
    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Normalize
    Vec3 normalize() const {
        float mag = magnitude();
        return mag > 0 ? Vec3(x / mag, y / mag, z / mag) : Vec3(0, 0, 0);
    }

    // Print
    void print() const {
        std::cout << "Vec3(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};


struct GameObject
{
    Vec3 pos; 

    GameObject() : pos(0.f, 0.f, 0.f) {} // Constructor for GameObject

    void display(int depth) {
        std::cout << std::string(depth, '-') << " GameObject at ";
        pos.print();
    }

    int tick(int deltaTime) {
        // Update logic goes here (for example, moving the object)
        // For now, just return a placeholder value
        return 0; 
    }
};

struct Entity : GameObject
{

};


void deCasteljau()
{
int d = 3;
    float a[5] = {0,4,3,1,2};
const float t = 0.5;
    a[0] = a[0] * (1-t) + a[1]*t;
    a[1] = a[1] * (1-t) + a[2]*t;

    for (int k = d; k>0;k--)
    {
        for (int i =0;i<k;i++)
        {
            a[i] = a[i] * (1 - t)+ a[i+ 1]*t;
            std::cout<< a[0]<<'\n';
        }
    }
    

}

int main(int argc, char* argv[])
{
    deCasteljau();
    return 0;
}

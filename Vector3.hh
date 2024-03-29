//
// Created by yanis on 16/05/2023.
//

#ifndef TP1_VECTOR3_HH
#define TP1_VECTOR3_HH

#include <cmath>
#include <vector>


class Vector3 {
public:
    float x=0;
    float y=0;
    float z=0;

    Vector3(){};
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    float* toFloatArray(){
        float* array = new float[3];
        array[0] = x;
        array[1] = y;
        array[2] = z;
        return array;
    }

    Vector3 fromFloatArray(float* array){
        Vector3 vector;
        vector.x = array[0];
        vector.y = array[1];
        vector.z = array[2];
        return vector;
    }

    Vector3 normalize(){
        float norm = sqrt(x*x+y*y+z*z);
        x/=norm;
        y/=norm;
        z/=norm;

        return  {x,y,z};
    }

    static void translateVerticesOnVector(std::vector<float>& vertices, Vector3 center){
        for (int i = 0; i < vertices.size(); i+=3){
            vertices[i] += center.x;
            vertices[i+1] += center.y;
            vertices[i+2] += center.z;
        }
    }

    std::vector<float> toArray(){
        return {x, y, z};
    }

    void operator+=(Vector3 v){
        x+=v.x;
        y+=v.y;
        z+=v.z;
    }

    void operator-=(Vector3 v){
        x-=v.x;
        y-=v.y;
        z-=v.z;
    }

    Vector3 operator*(float value){
        return {x *= value,y*=value,z*=value};
    }
};


#endif //TP1_VECTOR3_HH

#ifndef TP1_OBJLOADER_HH
#define TP1_OBJLOADER_HH

#include "Vector3.hh"
#include "Vector2.hh"
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

class ObjLoader {
public:
    std::vector<float> vertex_buffer;
    std::vector<float> normal_buffer;
    std::vector<float> uv_buffer;

    int nbObjects = 0;

    void load(const char* path){
        nbObjects++;

        //init buffers
        std::vector<unsigned int> vertexIndices;
        std::vector<unsigned int> normalIndices;
        std::vector<unsigned int> uvIndices;
        std::vector<Vector3> temp_vertex_buffer;
        std::vector<Vector3> temp_normal_buffer;
        std::vector<Vector2> temp_uv_buffer;

        //open the file
        FILE * file = std::fopen(path, "r");
        if( file == NULL ){
            throw std::invalid_argument("Impossible to open the file !\n");
        }

        //parse the file
        while( 1 ) {
            char lineHeader[128];
            // read the first word of the line
            int res = fscanf(file, "%s", lineHeader);
            if (res == EOF)
                break;
            if ( strcmp( lineHeader, "v" ) == 0 ){
                Vector3 vertex;
                fscanf(file, " %f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
                temp_vertex_buffer.push_back(vertex);
            }
            else if ( strcmp( lineHeader, "vt" ) == 0 ) {
                Vector2 uv;
                fscanf(file, "%f %f\n", &uv.x, &uv.y);
                temp_uv_buffer.push_back(uv);
            }else if ( strcmp( lineHeader, "vn" ) == 0 ) {
                Vector3 normal;
                fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
                temp_normal_buffer.push_back(normal);
            }else if ( strcmp( lineHeader, "f" ) == 0 ) {
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0],
                                     &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2],
                                     &uvIndex[2], &normalIndex[2]);
                if (matches != 9) {
                    throw std::invalid_argument(
                            "File can't be read by our simple parser : ( Try exporting with other options\n");
                }

                //fill indices buffer
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices.push_back(uvIndex[0]);
                uvIndices.push_back(uvIndex[1]);
                uvIndices.push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }
        }

        //fill buffers in the correct order
        for( unsigned int i=0; i<vertexIndices.size(); i++ ){
            //fill vertex_buffer
            unsigned int vertexIndex = vertexIndices[i];
            Vector3 vertex = temp_vertex_buffer[ vertexIndex-1 ];
            vertex_buffer.push_back(vertex.x);
            vertex_buffer.push_back(vertex.y);
            vertex_buffer.push_back(vertex.z);

            //fill uv buffer
            unsigned int uvIndex = uvIndices[i];
            Vector2 uv = temp_uv_buffer[uvIndex-1];
            uv_buffer.push_back(uv.x);
            uv_buffer.push_back(uv.y);

            //fill normal buffer
            unsigned int normalIndex = normalIndices[i];
            Vector3 normal = temp_normal_buffer[normalIndex-1];
            normal_buffer.push_back(normal.x);
            normal_buffer.push_back(normal.y);
            normal_buffer.push_back(normal.z);
        }
    }
};


#endif //TP1_OBJLOADER_HH

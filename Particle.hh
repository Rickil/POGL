#ifndef TP1_PARTICULE_HH
#define TP1_PARTICULE_HH

#include "Vector3.hh"
//#include <glm/glm.hpp>

class Particle {
public:
    Vector3 position;
    Vector3 velocity;
    float lifetime;

    Particle(){
        //set initial lifetime of the particle to 200 frames
        lifetime = 200;

        //set random initial position for particle between -1 and 1
        float x = -1 + rand()/RAND_MAX*10;
        float y = 0 + rand()/RAND_MAX*2;
        float z = -1 + rand()/RAND_MAX*10;
        position = Vector3((((float) rand() / (float) RAND_MAX) - 0.5)/3,-0.5,(((float) rand() / (float) RAND_MAX) - 0.5)/3);
    }

    void update(std::vector<Particle*> &_particlesInRange, unsigned int deltaTime){

        /*//create acceleration vector
        Vector3 acceleration;
        acceleration.y += 0.1;
        acceleration.x += (float)rand()/RAND_MAX;
        acceleration.y += (float)rand()/RAND_MAX;
        acceleration.z += (float)rand()/RAND_MAX;
        acceleration.normalize();
        acceleration *= 0.05;*/

        //lifetime of the particle decreased
        //lifetime--;

        //accelerate the particle
        //velocity += acceleration /** ((float)deltaTime / 1000.0f)*/;
        //move the particle
        //position += acceleration /** ((float)deltaTime / 1000.0f)*/;

        Vector3 acceleration;
        //upwards acceleration due to convection added
        acceleration.y += 0.6f;
        //lifetime of the particle decreased
        lifetime--;
        //for each particle in range move towards or away from it depending on density
        for (unsigned int i = 0; i < _particlesInRange.size(); i++)
        {
            if (_particlesInRange[i] != this)
            {
                if (_particlesInRange.size() > 20)
                {
                    acceleration += (position - _particlesInRange[i]->position) * 0.02f;
                }
                else
                {
                    acceleration += (position - _particlesInRange[i]->position) * -2.0f;
                }
            }
        }
        //accelerate the particle
        velocity += acceleration * ((float)deltaTime / 1000.0f);
        //move the particle
        position += velocity * ((float)deltaTime / 1000.0f)*100;
    }

};


#endif //TP1_PARTICULE_HH

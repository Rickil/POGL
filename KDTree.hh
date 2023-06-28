//
// Created by yanis on 16/06/2023.
//

#ifndef POGL_KDTREE_HH
#define POGL_KDTREE_HH

#include "Particle.hh"
#include <vector>

/*class Sphere {
public:
    static Sphere CalculateFromPoints(std::vector<Vector3>& points)
    {
        Sphere boundingSphere;

        // Calculate the center as the average of all points
        for (Vector3& point : points) {
            boundingSphere.center += point;
        }
        boundingSphere.center /= points.size();

        // Calculate the radius as the maximum distance from the center
        for (Vector3& point : points) {
            float distance = Vector3::Magnitude(point - boundingSphere.center);
            boundingSphere.radius = std::max(boundingSphere.radius, distance);
        }

        return boundingSphere;
    }

    Vector3 center;
    float radius;
};*/

class Node {
public:
    Vector3 center;
    float radius;
    int depth;
    Node* left;
    Node* right;
    std::vector<Vector3> vertices;
};

class KDTree {
public:

    int depth = 0;
    Node* root;
    Particle* center;
    KDTree* left;
    KDTree* right;
    KDTree(int depth, std::vector<Particle*> particles);
    KDTree(int maxVerticesPerSphere, const std::vector<float> vertices);
    void DestroyTree();
    void getNeighboursParticles(float range, Vector3 position, std::vector<Particle*> &neighbours, float* largestDistanceInRange);

    Node* BuildTree(std::vector<Vector3>& vertices, int maxVerticesPerSphere, int depth);
    void CalculateBoundingSphere(Node* node, std::vector<Vector3>& vertices);
    Node* CreateLeafNode(std::vector<Vector3>& vertices);
    Node* CreateInternalNode(std::vector<Vector3>& vertices, int axis);
    void DestroyTree(Node* node);
    void fillSmart(std::vector<float>& smart_vertex_buffer);
};


#endif //POGL_KDTREE_HH

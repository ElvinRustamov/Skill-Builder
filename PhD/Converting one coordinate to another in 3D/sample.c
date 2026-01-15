#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    double m[3][3];
} matrix;

Vector vector_add(Vector a, Vector b) {
    return (Vector){ a.x + b.x, a.y + b.y, a.z + b.z };
}

Vector matrix_vector_mul(matrix m, Vector v) {
    Vector r;
    r.x = m.m[0][0]*v.x + m.m[0][1]*v.y + m.m[0][2]*v.z;
    r.y = m.m[1][0]*v.x + m.m[1][1]*v.y + m.m[1][2]*v.z;
    r.z = m.m[2][0]*v.x + m.m[2][1]*v.y + m.m[2][2]*v.z;
    return r;
}

matrix matrix_mul(matrix a, matrix b) {
    matrix r = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                r.m[i][j] += a.m[i][k] * b.m[k][j];
    return r;
}


matrix rot_x(double angle) {
    return (matrix){{
        {1, 0, 0},
        {0, cos(angle), -sin(angle)},
        {0, sin(angle),  cos(angle)}
    }};
}

matrix rot_y(double angle) {
    return (matrix){{
        { cos(angle), 0, sin(angle)},
        {0, 1, 0},
        {-sin(angle), 0, cos(angle)}
    }};
}

matrix rot_z(double angle) {
    return (matrix){{
        {cos(angle), -sin(angle), 0},
        {sin(angle),  cos(angle), 0},
        {0, 0, 1}
    }};
}

Vector transform_point(
    Vector local,
    matrix rotation,
    Vector translation
) {
    Vector rotated = matrix_vector_mul(rotation, local);
    return vector_add(rotated, translation);
}

int main(void) {
    Vector p_local = {1.0, 2.0, 3.0};

    double rx = 0 * M_PI / 180.0;
    double ry = 0 * M_PI / 180.0;
    double rz = 90 * M_PI / 180.0;

    matrix R = matrix_mul(
            rot_z(rz),
            matrix_mul(rot_y(ry), rot_x(rx))
        );

    Vector T = {10.0, -5.0, 2.0};

    Vector p_world = transform_point(p_local, R, T);

    printf("World coordinates:\n");
    printf("X = %.4f\n", p_world.x);
    printf("Y = %.4f\n", p_world.y);
    printf("Z = %.4f\n", p_world.z);

    return 0;
}

#include <stdio.h>
#include <math.h>

struct point{
    float x;
    float y;
};

typedef struct point POINT;

void fractale(POINT A, POINT B, float r, float theta, int niveau);

int main(){
    int niveau = 2;
    float theta = M_PI/4;
    float r = 2/(1+sqrt(5));
    POINT A = {100, 0};
    POINT B = {100, 100};

    fractale(A, B, r, theta, niveau);

    return 0;
}

void fractale(POINT A, POINT B, float r, float theta, int niveau){
    if (niveau <= 0) return;
    POINT M1;
    POINT M2;
    M1.x = B.x + r * cos(theta) * (B.x - A.x) - r * sin(theta) * (B.y - A.y);
    M2.x = B.x + r * cos(theta) * (B.x - A.x) + r * sin(theta) * (B.y - A.y);
    M1.y = B.y + r * sin(theta) * (B.x - A.x) + r * cos(theta) * (B.y - A.y);
    M2.y = B.y - r * sin(theta) * (B.x - A.x) + r * cos(theta) * (B.y - A.y);

    printf("(%.0f, %.0f), (%.0f, %.0f)\n", M1.x, M1.y, M2.x, M2.y);
    fractale(B, M1, r, theta, niveau - 1);
    fractale(B, M2, r, theta, niveau - 1);
}
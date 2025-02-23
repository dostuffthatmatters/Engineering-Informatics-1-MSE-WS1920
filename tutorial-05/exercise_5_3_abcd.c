/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 05
************************************************************************************/


#include <stdio.h>
#include <math.h>

struct rectangle {
    double length;
    double width;
};

struct triangle {
    double hypothenuse;
    double height;
};

struct circle {
    double radius;
};


double rectangle_area(struct rectangle rectangle) {
    return rectangle.length * rectangle.width;
}

double triangle_area(struct triangle triangle) {
    return 0.5 * triangle.height * triangle.hypothenuse;
}

double circle_area(struct circle circle) {
    return M_PI * circle.radius * circle.radius;
}

int main() {

    struct rectangle rectangle_1 = {2, 4};
    double area_1 = rectangle_area(rectangle_1);
    printf("Rectangle: %f\n", area_1);

    struct triangle triangle_1 = {2, 4};
    printf("Triangle: %f\n", triangle_area(triangle_1));

    struct circle circle_1 = {2};
    printf("Circle: %f\n", circle_area(circle_1));

    return 0;
}

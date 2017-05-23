#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

double GetSurface(struct rectangular_cuboid temp);
double GetVolume(struct rectangular_cuboid temp);

int main()
{
    struct rectangular_cuboid kubo;
    kubo.a = 120.32;
    kubo.b = 66.66;
    kubo.c = 2.5;

    printf("Surface: %.02f\n", GetSurface(kubo));
    printf("Volume: %.02f\n", GetVolume(kubo));

    return 0;
}

double GetSurface(struct rectangular_cuboid temp)
{
    double surface;
    surface = 2 * (temp.a + temp.b + temp.c);
    return surface;
}

double GetVolume(struct rectangular_cuboid temp)
{
    double volume;
    volume = temp.a * temp.b * temp.c;
    return volume;
}







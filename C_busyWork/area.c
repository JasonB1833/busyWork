#include <stdio.h>
#include <stdlib.h>


struct Rectangle 
{
  double width;
  double height;
  double perimeter;
  double area;
};

int main(int argc, char *argv[])
{
  //init struct item
  struct Rectangle rectangle;
  //rectangle.width = 10.0;
  //rectangle.height = 20.0;
  
  // use cli argument to fill width and height
  rectangle.width = atoi(argv[1]);
  rectangle.height = atoi(argv[2]);

  rectangle.perimeter = (2.0 *(rectangle.width + rectangle.height));

  rectangle.area = rectangle.height * rectangle.width;

  // print items to cli
  printf("height is : %.2f\n", rectangle.height);
  printf("width is : %.2f\n", rectangle.width);
  printf("perimeter is : %.2f\n", rectangle.perimeter);
  printf("area is : %.2f\n", rectangle.area);
}

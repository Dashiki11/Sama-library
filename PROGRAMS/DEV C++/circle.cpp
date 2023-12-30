#include <iostream>
#include <cmath>
using namespace std;

struct point
{
  float x, y;
};

struct circle
{
  float r;
  struct point o;
};

int contains (struct circle vc, struct point vp)
{
  if ((pow (vc.o.x - vp.x, 2) + pow (vc.o.y - vp.y, 2)) > pow(vc.r,2)) 
    return 0; 
  else 
    return 1;
}

int main(void)
 {
 struct circle c = {2, (3, 2)};
 struct point p = {4, 2}; 
 int answer;

answer = contains(c, p);

if (answer == 1)

cout<<"Circle c contains point p"<<endl;

else

cout<<"Circle c NOT contains point p"<<endl;


system ("PAUSE");

return 0;
 }

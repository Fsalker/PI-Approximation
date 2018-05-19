///=////////////////////////////////////////////////////////////////////////=///
///                                                                          ///
///         Summary                                                          ///
///                                                                          ///
///     This is a somewhat simple program that figures out PI's value by     ///
/// throwing points inside a concentric circle and square whose diameter     ///
/// and side are equal.                                                      ///
///                                                                          ///
///     About PI/4 of the randomly generated points should be in the         ///
/// circle, but not in the square. (circle area / square area)               ///
///                                                                          ///
///                                                                          ///
///         Notes                                                            ///
///                                                                          ///
///     -Browser axis are employed (XOY, top-bottom, left-right              ///
///     -Randomly generated integer coordinates might make the               ///
/// approximation inaccurate. Maybe we should fix that...                    ///
///                            ("possible improvement")                      ///
///                                                                          ///
///                                                                          ///
///         Possible improvements                                            ///
///                                                                          ///
///     -Separating the current Classes into .h and .cpp (like               ///
/// actual C++ programmers would do).                                        ///
///     -Moving pointIsInside_shape() functions from Main to Point           ///
/// class.                                                                   ///
///                                                                          ///
///=////////////////////////////////////////////////////////////////////////=///

#include <iostream> // cout
#include <cassert> // assert()
#include <cmath> // sqrt()
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <cstring> // strcpy()
#include "point.h"
#include "square.h"
#include "circle.h"
using namespace std;

bool pointIsInside_square(const Point& P, const Square& S){
    return  S.top_left->x  <= P.x &&
            S.bot_right->x >= P.x &&
            S.top_left->y  <= P.y &&
            S.bot_right->y >= P.y;
}

bool pointIsInside_circle(const Point& P, const Circle& C){
    double dist_x = P.x - C.center->x;;
    double dist_y = P.y - C.center->y;
    double dist = sqrt(dist_x*dist_x + dist_y*dist_y);

    return dist <= C.radius;
}

int main()
{
    /// Test
    Point::unitTest();
    Square::unitTest();
    Circle::unitTest();

    /// Solve (find PI)
    const int NUM_POINTS = 10000000;
    const double X_CENTER = 0;
    const double Y_CENTER = 0;
    const double RADIUS = 32000;

    const int SIDE = RADIUS * 2;
    const double X_MIN = X_CENTER - RADIUS;
    const double X_MAX = X_CENTER + RADIUS;
    const double Y_MIN = Y_CENTER - RADIUS;
    const double Y_MAX = Y_CENTER + RADIUS;

    int points_inside_square = 0;
    int points_inside_circle = 0;

    Square S(X_MIN, Y_MIN, SIDE);
    Circle C(X_CENTER, Y_CENTER, RADIUS);

    cout<<S<<C;
    srand(time(NULL));
    for(int i=0; i<NUM_POINTS; ++i){
        double x = X_MIN + rand() % (SIDE+1);
        double y = Y_MIN + rand() % (SIDE+1);
        Point P(x, y);

        bool inside_square = pointIsInside_square(P, S);
        bool inside_circle = pointIsInside_circle(P, C);

        char msg_square[20];
        char msg_circle[20];
        if(inside_square) strcpy(msg_square, "TRUE");
        else strcpy(msg_square, "FALSE");
        if(inside_circle) strcpy(msg_circle, "TRUE");
        else strcpy(msg_circle, "FALSE");

        /*if(!inside_circle)
            cout<<"-------------------------------------------------------------\n";
        cout<<P;
        cout<<"Point is inside Square: "<<msg_square<<"\n";
        cout<<"Point is inside Circle: "<<msg_circle<<"\n";
        cout<<"\n";*/

        points_inside_square += inside_square;
        points_inside_circle += inside_circle;
    }

    cout<<"Points inside the square: "<<points_inside_square<<"\n";
    cout<<"Points inside the circle: "<<points_inside_circle<<"\n";

    double PI = 4.0 * points_inside_circle / points_inside_square ;
    cout<<"PI = "<<PI<<"\n";

    return 0;
}

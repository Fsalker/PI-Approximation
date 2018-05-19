#ifndef CIRCLE_H
    #define CIRCLE_H

    #include "Point.h"

    class Circle{
    private:

    public:
        Point *center;
        double radius;
        double diameter;

        Circle(double center_x, double center_y, double Radius){
            center = new Point(center_x, center_y);
            radius = Radius;
            diameter = Radius * 2;
        }

        Circle(double top_left_x, double top_left_y, double Radius, bool initiate_by_top_left_coordinates) : Circle(top_left_x + Radius, top_left_y + Radius, Radius){}

        ~Circle(){
            delete center;
        }

        bool operator ==(const Circle& other){
            return (*center) == *(other.center) && radius == other.radius;
        }

        friend ostream& operator<<(ostream& out, const Circle& C){
            out<<"Circle parameters:\n";
            out<<" -CENTER: "<<*C.center;
            out<<" -RADIUS: "<<C.radius<<"\n";
            out<<"\n";
            return out;
        }

        static void unitTest(){
            Circle A(200, 200, 50);
            Circle B(150, 150, 50, true);

            assert(A == B);
            assert(A.radius == 50);
            assert(A.diameter == 100);
        }
};
#endif // CIRCLE_H

#ifndef POINT_H
    #define POINT_H

    #include <iostream>
    using namespace std;

    class Square;
    class Circle;

    class Point{
        private:

        public:
            double x,y;

            Point(double X, double Y){
                x = X;
                y = Y;
            }

            Point(const Point& other){
                x = other.x;
                y = other.y;
            }

            Point (){
            }

            Point operator =(const Point& other){
                x = other.x;
                y = other.y;

                return *this;
            }

            Point operator +(double offset){
                Point res;
                res.x = x+offset;
                res.y = y+offset;
                return res;
            }

            Point operator -(double offset){
                return *this + (-offset);
            }

            Point operator +(const Point& other){
                Point res;
                res.x = x + other.x;
                res.y = y + other.y;
                return res;
            }

            bool operator ==(const Point& other){
                return x == other.x && y == other.y;
            }

            friend ostream& operator<<(ostream& out, const Point& p){
                out<<"Point's coordinates: x = "<<p.x<<", y = "<<p.y<<"\n";
                return out;
            }

            static void unitTest(){
                Point A(4, 7);
                Point B(A);
                Point C = A;
                Point D;
                Point E;
                Point F(5, 11); /// (A+A) - 3
                D = (E=A);

                assert(A == B);
                assert(A == C);
                assert(A == D);
                assert(A == E);
                assert(A+A == B+B);
                assert(A+A == F+3);
                assert(A+A-3 == F);
            }
    };
#endif

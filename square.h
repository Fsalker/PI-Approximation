#ifndef SQUARE_H
    #define SQUARE_H

    #include "Point.h"

    class Square{
    private:

    public:
        Point *top_left;
        Point *bot_right;
        double side;

        Square(double top_left_x, double top_left_y, double Side){
            top_left = new Point(top_left_x, top_left_y);
            bot_right = new Point(*top_left + Side);
            side = Side;
        }

        ~Square(){
            delete top_left;
            delete bot_right;
        }

        friend ostream& operator<<(ostream& out, const Square& S){
            out<<"Square parameters:\n";
            out<<" -TOP LEFT: "<<*S.top_left;
            out<<" -BOTTOM RIGHT: "<<*S.bot_right;
            out<<" -SIDE: "<<S.side<<"\n";
            out<<"\n";
            return out;
        }

        static void unitTest(){
            Square A(100, 100, 150);
            Point M(100, 100);
            Point N(250, 250);

            assert(*(A.top_left) == M);
            assert(*(A.bot_right) == N);
        }
};
#endif // SQUARE_H

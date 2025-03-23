#ifndef POINT_CLASS_H
#define POINT_CLASS_H


class Point
{
    private:
        double x = 0, y = 0;
    public:

        Point(); 
        Point(const double x, const double y);

        void input();
        void check_input() const;

        double getX() const;
        double getY() const;
};


#endif //POINT_CLASS_H//
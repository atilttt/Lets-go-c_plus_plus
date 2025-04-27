#ifndef POINT_CLASS_H
#define POINT_CLASS_H


class Point
{
    private:
        double x, y;
    public:

        Point(); 
        Point(const double x, const double y);

        double getX() const;
        double getY() const;
};


#endif //POINT_CLASS_H//
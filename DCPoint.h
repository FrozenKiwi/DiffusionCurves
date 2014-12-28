#ifndef DCPOINT_H
#define DCPOINT_H

    struct DCPoint
    {
    public:
        // x
        double x;

        // y
        double y;

        // Default constructor
        DCPoint()
        {
            this->x = -1;
            this->y = -1;
        }

        // Constructor
        DCPoint(double x, double y)
        {
            this->x = x;
            this->y = y;
        }

        // Scale a point
        DCPoint Resize(double val)
        {
            DCPoint newP;
            newP.x = this->x * val;
            newP.y = this->y * val;
            return newP;
        }

        // if a point is (-1, -1)
        bool Invalid()
        {
            if(((int)x) == -1 && ((int)y) == -1)
                { return true; }
            return false;
        }

        // Normalize
        DCPoint Norm()
        {
            double vlength = std::sqrt( x * x + y * y );
            return DCPoint(this->x / vlength, this->y / vlength);
        }

        // Euclidean distance
        double Distance(DCPoint other)
        {
            double xDist = x - other.x;
            double yDist = y - other.y;
            return sqrt(xDist * xDist + yDist * yDist);
        }

        // Euclidean distance
        double Distance(double otherX, double otherY)
        {
            double xDist = x - otherX;
            double yDist = y - otherY;
            return sqrt(xDist * xDist + yDist * yDist);
        }

        // squared euclidean distance
        double DistanceSquared(DCPoint other)
        {
            double xDist = x - other.x;
            double yDist = y - other.y;
            return (xDist * xDist + yDist * yDist);
        }

        // squared euclidean distance
        double DistanceSquared(double otherX, double otherY)
        {
            double xDist = x - otherX;
            double yDist = y - otherY;
            return (xDist * xDist + yDist * yDist);
        }

        // operator overloading
        DCPoint operator+ (const DCPoint& other) { return DCPoint(x + other.x, y + other.y); }

        // operator overloading
        DCPoint operator- (const DCPoint& other) { return DCPoint(x - other.x, y - other.y); }
        bool operator== (const DCPoint& other)
        { return (abs(this->x - other.x) < M_EPS && abs(this->y - other.y) < M_EPS); }

        // operator overloading
        bool operator!= (const DCPoint& other)
        { return (abs(this->x - other.x) >= M_EPS || abs(this->y - other.y) >= M_EPS); }

        // operator overloading
        DCPoint operator+= (const DCPoint& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        // operator overloading
        DCPoint operator-= (const DCPoint& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        // operator overloading
        DCPoint operator/ (const double& val) { return DCPoint(x / val, y / val); }

        // operator overloading
        DCPoint operator* (const double& val) { return DCPoint(x * val, y * val); }

        // operator overloading
        DCPoint operator*= (const double& val)
        {
            x *= val;
            y *= val;
            return *this;
        }

        // operator overloading
        DCPoint operator/= (const double& val)
        {
            x /= val;
            y /= val;
            return *this;
        }

        // length of a vector
        double Length() { return sqrt(x * x + y * y); }

        // squared length of a vector
        double LengthSquared() { return x * x + y * y; }

        // dot product
        double Dot(DCPoint otherPt) { return x * otherPt.x + y * otherPt.y; }

        // cross product
        DCPoint Cross(DCPoint otherPt)
        {
            //U x V = Ux*Vy-Uy*Vx
            return DCPoint(x * otherPt.y, y * otherPt.x);
        }

        // linear dependency test
        bool IsLinearDependent(DCPoint otherPoint)
        {
            double det = (this->x * otherPoint.y) - (this->y * otherPoint.x);
            if(det > -M_EPS && det < M_EPS) { return true; }
            return false;
        }

        // angle direction
        DCPoint DirectionTo(DCPoint otherPt)
        {
            return DCPoint(otherPt.x - this->x, otherPt.y - this->y);
        }
    };

#endif // DCPOINT_H

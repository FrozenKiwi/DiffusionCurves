#ifndef CURVESTORAGE_H
#define CURVESTORAGE_H


// forward declaration
//struct DCPoint;

#include "DCPoint.h"

class CurveStorage
{
public:
    CurveStorage();
    ~CurveStorage();


    std::vector<std::vector<DCPoint> > GetCurves() { return curves; }

    void StartCurve();
    void AddPoint(int x, int y);
    void EndCurve();


    void DrawCurve();

private:
    std::vector<std::vector<DCPoint> > curves;
    std::vector<DCPoint> tempCurve;


};

#endif // CURVESTORAGE_H

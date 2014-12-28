
#include "stdafx.h"
#include "CurveStorage.h"
#include "DCPoint.h"

CurveStorage::CurveStorage()
{
}


CurveStorage::~CurveStorage()
{
}


void CurveStorage::StartCurve()
{
    //tempCurve.clear();
}

void CurveStorage::AddPoint(int x, int y)
{
    tempCurve.push_back(DCPoint(x, y));
}


void CurveStorage::EndCurve()
{
    std::vector<DCPoint> cloneCurve;
    for(size_t a = 0; a < tempCurve.size(); a++)
    {
        cloneCurve.push_back(DCPoint(tempCurve[a].x, tempCurve[a].y));
    }
    curves.push_back(cloneCurve);

    tempCurve.clear();

}

void CurveStorage::DrawCurve()
{
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0, 0, 0, 1);
    glLineWidth(1.0);
    glBegin(GL_LINES);



    for(size_t a = 0; a < curves.size(); a++)
    {
        for(size_t b = 1; b < curves[a].size(); b++)
        {
            DCPoint p0 = curves[a][b - 1];
            DCPoint p1 = curves[a][b];

            glVertex3f(p0.x, p0.y, 0);
            glVertex3f(p1.x, p1.y, 0);

            //std::cout << p0.x << " " << p0.y << " " << p1.x << p1.y << std::endl;
        }
    }

    for(size_t b = 1; b < tempCurve.size(); b++)
    {
        DCPoint p0 = tempCurve[b - 1];
        DCPoint p1 = tempCurve[b];

        glVertex3f(p0.x, p0.y, 0);
        glVertex3f(p1.x, p1.y, 0);

        //std::cout << p0.x << " " << p0.y << " " << p1.x << p1.y << std::endl;
    }

    glEnd();


    //std::cout << curves.size() << std::endl;

    glFlush();
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

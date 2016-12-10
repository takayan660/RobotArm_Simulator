/*------------------------------------------------------*/
/* Biological Engineering: Problem Set 03               */
/* main program                                         */
/*                                                      */
/* file name    :   BiologicalEngineering_set3.cpp      */
/* compiler     :   gcc                                 */
/* Student ID   :   1526084                             */
/* author       :   Takaharu Nakajima                   */
/* date         :   2016.11.11                          */
/* memo         :   生体工学第三回目の1.1から1.3の      */
/*                  プログラムをまとめたものになります  */
/*                                                      */
/*                  一部変数の定義のため変更した部分    */
/*                  (例)                                */
/*                  RT0 -> RTa                          */
/*                  このように0, 1...Eをa, b...Eに      */
/*                  変更しました                        */
/*                                                      */
/*------------------------------------------------------*/

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define PI 3.1415926

double deg2rad(double degree)
{
    double radian = degree * PI / 180.0f;
    return radian;
}

int main()
{
    double deg1, deg2, deg3, deg4, deg5;
    double rad1, rad2, rad3, rad4, rad5;
    Matrix<double,4,4> RTa, aTb, bTc, cTd, dTe, eTf, fTg;
    Matrix<double,4,4> RTb, RTc, RTd, RTe, RTf, RTg;
    Vector3d RZa, RZb, RZc, RZd, RZe, RZf, RZg;
    Vector3d Rpa, Rpb, Rpc, Rpd, Rpe, Rpf, Rpg;
    Vector3d RpEa, RpEb, RpEc, RpEd, RpEe, RpEf, RpEg;

    /* Input */
    cout << "Angle input" << endl;
    cout << "deg1= ";
    cin >> deg1;
    cout << "deg2= ";
    cin >> deg2;
    cout << "deg3= ";
    cin >> deg3;
    cout << "deg4= ";
    cin >> deg4;
    cout << "deg5= ";
    cin >> deg5;

    /* Convert to radians */
    rad1 = deg2rad(deg1);
    rad2 = deg2rad(deg2);
    rad3 = deg2rad(deg3);
    rad4 = deg2rad(deg4);
    rad5 = deg2rad(deg5);

    /* Link parameters */
    RTa << 1, 0, 0, 0,
           0, 1, 0, 0, 
           0, 0, 1, 1, 
           0, 0, 0, 1;
    aTb << cos(rad1), -sin(rad1), 0, 0,
           sin(rad1),  cos(rad1), 0, 0,
                   0,          0, 1, 0,
                   0,          0, 0, 1;
    bTc << cos(rad2), -sin(rad2), 0, 0,
                   0,          0, -1, 0,
           sin(rad2),  cos(rad2), 0, 0, 
                   0,          0, 0, 1;
    cTd << cos(rad3), -sin(rad3), 0, 1,
           sin(rad3),  cos(rad3), 0, 0, 
                   0,          0, 1, 0, 
                   0,          0, 0, 1;
    dTe << cos(rad4), -sin(rad4), 0, 1,
           sin(rad4),  cos(rad4), 0, 0, 
                   0,          0, 1, 0, 
                   0,          0, 0, 1;
    eTf << cos(rad5), -sin(rad5), 0, 0,
                   0,          0, -1, 0,
           sin(rad5),  cos(rad5), 0, 0, 
                   0,          0, 0, 1;
    fTg << 1, 0, 0, 0, 
           0, 1, 0, 0, 
           0, 0, 1, 1, 
           0, 0, 0, 1; 

    /* Matrix calculation */
    RTb = RTa * aTb;
    RTc = RTb * bTc;
    RTd = RTc * cTd;
    RTe = RTd * dTe;
    RTf = RTe * eTf;
    RTg = RTf * fTg;

    RZa = RTa.block<3,1>(0,2);
    RZb = RTb.block<3,1>(0,2);
    RZc = RTc.block<3,1>(0,2);
    RZd = RTd.block<3,1>(0,2);
    RZe = RTe.block<3,1>(0,2);
    RZf = RTf.block<3,1>(0,2);
    RZg = RTg.block<3,1>(0,2);

    Rpa = RTa.block<3,1>(0,3);
    Rpb = RTb.block<3,1>(0,3);
    Rpc = RTc.block<3,1>(0,3);
    Rpd = RTd.block<3,1>(0,3);
    Rpe = RTe.block<3,1>(0,3);
    Rpf = RTf.block<3,1>(0,3);
    Rpg = RTg.block<3,1>(0,3);

    RpEa = Rpg - Rpa;
    RpEb = Rpg - Rpb;
    RpEc = Rpg - Rpc;
    RpEd = Rpg - Rpd;
    RpEe = Rpg - Rpe;
    RpEf = Rpg - Rpf;
    RpEg = Rpg - Rpg;
    
    /* Calculation result display */
    /* RT0 ~ 3TE */
    cout << "RT0=" << endl;
    cout << RTa << endl;
    cout << "0T1=" << endl;
    cout << aTb << endl;
    cout << "1T2=" << endl;
    cout << bTc << endl;
    cout << "2T3=" << endl;
    cout << cTd << endl;
    cout << "3T4=" << endl;
    cout << dTe << endl;
    cout << "4T5=" << endl;
    cout << eTf << endl;
    cout << "5T6=" << endl;
    cout << fTg << endl << endl;

    /* RZ0 ~ RZE */
    cout << "RZ0=" << endl;
    cout << RZa << endl;
    cout << "RZ1=" << endl;
    cout << RZb << endl;
    cout << "RZ2=" << endl;
    cout << RZc << endl;
    cout << "RZ3=" << endl;
    cout << RZd << endl;
    cout << "RZ4=" << endl;
    cout << RZe << endl;
    cout << "RZ5=" << endl;
    cout << RZf << endl;
    cout << "RZ6=" << endl;
    cout << RZg << endl;

    /* Rp0 ~ Rp1 */
    cout << "Rp0=" << endl;
    cout << Rpa << endl;
    cout << "Rp1=" << endl;
    cout << Rpb << endl;
    cout << "Rp2=" << endl;
    cout << Rpc << endl;
    cout << "Rp3=" << endl;
    cout << Rpd << endl;
    cout << "Rp4=" << endl;
    cout << Rpe << endl;
    cout << "Rp5=" << endl;
    cout << Rpf << endl;
    cout << "Rp6=" << endl;
    cout << Rpg << endl;

    /* RZ0 x RpE,0 ~ RZE x RpE,E */
    cout << "RZ0 x RpE,0=" << endl;
    cout << RZa.cross(RpEa) << endl;
    cout << "RZ1 x RpE,1=" << endl;
    cout << RZb.cross(RpEb) << endl;
    cout << "RZ2 x RpE,2=" << endl;
    cout << RZc.cross(RpEc) << endl;
    cout << "RZ3 x RpE,3=" << endl;
    cout << RZd.cross(RpEd) << endl;
    cout << "RZ4 x RpE,4=" << endl;
    cout << RZe.cross(RpEe) << endl;
    cout << "RZ5 x RpE,5=" << endl;
    cout << RZf.cross(RpEf) << endl;
    cout << "RZ6 x RpE,6=" << endl;
    cout << RZg.cross(RpEg) << endl;

    return 0;
}

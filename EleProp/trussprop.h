﻿#ifndef TRUSSPROP_H
#define TRUSSPROP_H

#include "Eigen/Eigen"
//#include "../MaterialProp/mat.h"
#include "../TopAbstractClass/abstractmaterial.h"
#include "../TopAbstractClass/abastractelementprop.h"



using namespace Eigen;
/*
 * 杆单元截面属性
 * 仅支持各向同性材料
 */

class TrussProp: public EProp
{
public:
    TrussProp(int id);
    virtual ~TrussProp();

	int SetValue(const std::map<std::string, double>& EPropNameAndValue);

    

protected:
    //杆单元属性
   



};

#endif // TRUSSPROP_H

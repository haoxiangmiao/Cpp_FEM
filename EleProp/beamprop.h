﻿#ifndef BEAMPROP_H
#define BEAMPROP_H

/*
 * 梁单元属性
 * 仅支持各向同性材料
 */

#include "Eigen/Eigen"
#include <assert.h>
#include "../TopAbstractClass/abstractmaterial.h"
#include "../TopAbstractClass/abastractelementprop.h"

class BeamProp:public EProp
{

public:
    BeamProp(int id);
    virtual ~BeamProp();

	int SetValue(const std::map<std::string, double>& EPropNameAndValue);
protected:
   
};

#endif // BEAMPROP_H

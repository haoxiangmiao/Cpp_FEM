﻿#ifndef LINEARSTRUMAT_H
#define LINEARSTRUMAT_H

#include "structuremat.h"

class LinearStruMat :public StructureMat
{
public:
    LinearStruMat(int dim);
    virtual ~LinearStruMat() = 0;
};

#endif // LINEARSTRUMAT_H

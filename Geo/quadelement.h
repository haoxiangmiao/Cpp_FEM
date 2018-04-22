﻿#ifndef QUADELEMENT_H
#define QUADELEMENT_H

/* 四边形单元
 * 包括4节点单元，8节点单元，9节点单元
 */

#include "../TopAbstractClass/abstractelement.h"

class QuadElement:public Element
{
public:
    QuadElement();
    QuadElement(int ElementId,
                int MaterialId,
                Element::ElementType eletype,
                const Eigen::MatrixXi& VertexIdArray);
    ~QuadElement();

    QuadElement(const QuadElement& that);
    QuadElement& operator =(const QuadElement& that);

    Element* Clone() const;

	int GetSpecificMatrix(SparseMatrixType SMT, Eigen::MatrixXd& ReturnMatrix);
};

#endif // QUADELEMENT_H

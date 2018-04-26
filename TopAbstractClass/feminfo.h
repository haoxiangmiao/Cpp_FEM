﻿#ifndef FEMINFO_H
#define FEMINFO_H

//#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class AbstractFileReader;
class Vertex;
class Element;
class Mat;
class EProp;
class Load;
class Constraint;
/*
 * 用于管理FEM的所有的输入信息
 * 包括
 * vector<Element>
 * vector<Point>
 * vector<Material>
 * vector<EProp>
 * ....
 */

class FEMinfo
{
public:
    enum FEMModelType
    {
        LinearStatic = 1,
        LinearDynamic,
        NonLinearStatic,
        NonLinearDynamic,
    };
    FEMinfo();
    FEMinfo(int FEMinfoId);

    FEMinfo(int FEMinfoId,AbstractFileReader *FileReader);
    ~FEMinfo();
    //析构函数

    FEMinfo* CreateCopy(int NewId);
    //复制并给出一份新的FEMinfo
    //注意：在这个函数里面会new一个新的FEMinfo出来
    //要在别的地方销毁

	int SetMatAndEPropAndVertexInElement();   //为单元设置Mat、EProp和Vertex指针
	int ComputeTotalDOF();

protected:
    //AbstractFileReader *FileReader;
    //仅在构造与复制时使用，其他时间均不使用
protected:

    int FEMinfoId;                      //id编号
	int dim;
    int AnalysisTypeData;
    //std::vector<Vertex *> VertexVec; // 存放顶点的容器
    //std::vector<Element *> EleVec; // 存放单元的容器
    //std::vector<Mat *> MatVec; //存放材料的容器
    //std::vector<EProp *> EPropVec; // 存放单元属性的容器
    //std::vector<Load *> LoadVec; //存放载荷的容器
    //std::vector<Constraint *> ConstraintVec; // 存放位移边界的容器

	map<int, Vertex*> VertexMap;
	map<int, Element*> EleMap;
	map<int, Mat*> MatMap;
	map<int, EProp*> EPropMap;
	map<int, Load*> LoadMap;
	map<int, Constraint*> ConstraintMap;



protected:
    

};

#endif // FEMINFO_H

#include "abstractmaterial.h"

/* 材料类最上层的抽象类，
 * 描述所有材料可以提供的方法
 */

Mat::Mat(int dim)
{
	this->dim = dim;
	/*matcate = MatCategory::None;
	mattype = MatType::None;
	matstatus = MatStatus::None;*/
}
Mat::~Mat()
{

}

int Mat::GetValue(MatVar SMP, double *Value)
{
    std::map<MatVar,double>::iterator it;
    it = MatPropd.find(SMP);
    if(it != MatPropd.end())
    {
        //找到了
        *Value = it->second;
        return 1;
    }
    else
    {
        //未找到
        *Value = 0.0;
        return 0;
    }
}

//int Mat::GetValue(MatVar SMP,int *Value)
//{
//    std::map<MatVar,int>::iterator it;
//    it = MatPropi.find(SMP);
//    if(it != MatPropi.end())
//    {
//        //找到了
//        *Value = it->second;
//        return 1;
//    }
//    else
//    {
//        *Value = 0;
//        return 0;
//    }
//}


int Mat::GetValue(MatVar SMP, Eigen::MatrixXd &Value)
{
	std::map<MatVar, Eigen::MatrixXd>::iterator it;
    it = MatPropdarray.find(SMP);
    if(it != MatPropdarray.end())
    {
        //找到了
        Value = it->second;
        return 1;
    }
    else
    {
        Value.resize(1,1);
        return 0;
    }
}

int Mat::SetValue(MatVar SMP, double Value)
{
	//首先检查是否存在此SMP
	if (hasProp(SMP) == 1)
	{
		//存在
		for (map<MatVar, double>::iterator it = MatPropd.begin();
			it != MatPropd.end();
			it++)
		{
			if (SMP == it->first)
			{
				it->second = Value;
				return 1;
			}
		}
	}
	else
	{
		//不存在
		MatPropd.insert(make_pair(SMP, Value));
		return 1;
	}
	
	//未知错误
	return 0;
}

//int Mat::GetValue(MatVar SMP, Eigen::ArrayXXi &Value)
//{
//    std::map<MatVar,Eigen::ArrayXXi>::iterator it;
//    it = MatPropiarray.find(SMP);
//    if(it != MatPropiarray.end())
//    {
//        //找到了
//        Value = it->second;
//        return 1;
//    }
//    else
//    {
//        Value.resize(1,1);
//        return 0;
//    }
//}

int Mat::hasProp(MatVar SMP)
{
	for (map<MatVar, double>::iterator it = MatPropd.begin();
		it != MatPropd.end();
		it++)
	{
		if (SMP == it->first)
		{
			return 1;
		}
	}

	for (map<MatVar, Eigen::MatrixXd>::iterator it = MatPropdarray.begin();
		it != MatPropdarray.end();
		it++)
	{
		if (SMP == it->first)
		{
			return 1;
		}
	}
	return 0;
}

int Mat::IsSolid()
{
	return matcate == Solid;
}

int Mat::IsLiquid()
{
	return matcate == Liquid;
}

int Mat::IsIsoMat()
{
	return mattype == Iso;
}

int Mat::IsOrthMat()
{
	return mattype == Orth;
}

int Mat::IsAnisoMat()
{
	return mattype == Aniso;
}

int Mat::IsPlaneStress()
{
	return (dim == 2) && (matstatus == PlaneStress);
}

int Mat::IsPlaneStrain()
{
	return (dim == 2) && (matstatus == PlaneStrain);
}

MatType Mat::GetMatType()
{
	return this->mattype;
}

MatStatus Mat::GetMatStatus()
{
	return this->matstatus;
}

#ifndef __NODELOAD_H__
#define __NODELOAD_H__

//集中载荷，作用于点上

#include "../TopAbstractClass/abstractload.h"

class NodeLoad :public Load
{
public:
	NodeLoad(int id, const Eigen::MatrixXi& NodeId_,
		const Eigen::MatrixXd Value_);
	~NodeLoad();

	int ComputeForce(FEMinfo* FEMInformation, vector<T_>& tripleList);

private:
	

};



#endif
#include "DirTrustHelper.h"

namespace ns3
{
namespace aodv
{


DirTrustHelper::DirTrustHelper()
{
		this->rreq = 1;
		this->rply = 1;
		this->err = 1;
		this->hello = 1;
		this->noOfDataPacketsForward = 1;
		this->noOfDataPacketsReceived = 1;
}


int DirTrustHelper::getNoOfRREQ()
{
	return this->rreq;
	//return 1;
}

int DirTrustHelper::getNoOfRPLY()
{
	return this->rply;
	//return 1;
}

int DirTrustHelper::getNoOfHELLO()
{
	return this->hello;
	//return 1;
}

int DirTrustHelper::getNoOfERR()
{
	return this->err;
	//return 1;
}

int DirTrustHelper::getNoOfSentDataPackets()
{
	return this->noOfDataPacketsForward;
	//return 2;
}

int DirTrustHelper::getNoOfReceivedDataPackets()
{
	return this->noOfDataPacketsReceived;
	//return 2;
}

NodeEntry * DirTrustHelper::getAllNeiNodes()
{
	NodeEntry* nodeArr = new NodeEntry[2];
	NodeEntry n1;
	n1.setNodeId("172.168.1.1");
	n1.setNodeName("B");
	nodeArr[0] = n1;

	NodeEntry n2;
	n2.setNodeId("172.168.1.2");
	n2.setNodeName("C");
	nodeArr[1] = n2;

	return nodeArr;
}



DirTrustHelper::~DirTrustHelper()
{
}

}
}

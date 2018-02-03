#include "DirTrustHelper.h"

namespace ns3
{
namespace aodv
{


DirTrustHelper::DirTrustHelper()
{
}


int DirTrustHelper::getNoOfRREQ(NodeEntry p_node)
{
	return 1;
}

int DirTrustHelper::getNoOfRPLY(NodeEntry p_node)
{
	return 1;
}

int DirTrustHelper::getNoOfHELLO(NodeEntry p_node)
{
	return 1;
}

int DirTrustHelper::getNoOfERR(NodeEntry p_node)
{
	return 1;
}

int DirTrustHelper::getNoOfSentDataPackets(NodeEntry p_node)
{
	return 2;
}

int DirTrustHelper::getNoOfReceivedDataPackets(NodeEntry p_node)
{
	return 2;
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

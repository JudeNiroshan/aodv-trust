#include "MetaDataToolkit.h"

namespace ns3
{
namespace aodv
{


MetaDataToolkit::MetaDataToolkit()
{
		this->rreq = 1;
		this->rply = 1;
		this->err = 1;
		this->hello = 1;
		this->noOfDataPacketsForward = 1;
		this->noOfDataPacketsReceived = 1;
}

void MetaDataToolkit::incRREQ()
{
	this->rreq = this->rreq + 1;
}

void MetaDataToolkit::incRPLY()
{
	this->rply = this->rply + 1;
}

void MetaDataToolkit::incERR()
{
	this->err = this->err + 1;
}

void MetaDataToolkit::incHELLO()
{
	this->hello = this->hello + 1;
}

void MetaDataToolkit::incNDF()
{
	this->noOfDataPacketsForward = this->noOfDataPacketsForward + 1;
}

void MetaDataToolkit::incNDR()
{
	this->noOfDataPacketsReceived = this->noOfDataPacketsReceived + 1;
}

int MetaDataToolkit::getNoOfRREQ()
{
	return this->rreq;
	//return 1;
}

int MetaDataToolkit::getNoOfRPLY()
{
	return this->rply;
	//return 1;
}

int MetaDataToolkit::getNoOfHELLO()
{
	return this->hello;
	//return 1;
}

int MetaDataToolkit::getNoOfERR()
{
	return this->err;
	//return 1;
}

int MetaDataToolkit::getNoOfSentDataPackets()
{
	return this->noOfDataPacketsForward;
	//return 2;
}

int MetaDataToolkit::getNoOfReceivedDataPackets()
{
	return this->noOfDataPacketsReceived;
	//return 2;
}

NodeEntry * MetaDataToolkit::getAllNeiNodes()
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



MetaDataToolkit::~MetaDataToolkit()
{
}

}
}

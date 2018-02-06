#include "MetaDataToolKit.h"

namespace ns3
{
namespace aodv
{


MetaDataToolKit::MetaDataToolKit()
{

	this->rreq = 1;
	this->rply = 1;
	this->err = 1;
	this->hello = 1;
	this->noOfDataPacketsForward = 1;
	this->noOfDataPacketsReceived = 1;
}

void MetaDataToolKit::incRREQ()
{
	this->rreq = this->rreq + 1;
}

void MetaDataToolKit::incRPLY()
{
	this->rply = this->rply + 1;
}

void MetaDataToolKit::incERR()
{
	this->err = this->err + 1;
}

void MetaDataToolKit::incHELLO()
{
	this->hello = this->hello +1;
}

void MetaDataToolKit::incNDF()
{
	this->noOfDataPacketsForward = this->noOfDataPacketsForward + 1;
}

void MetaDataToolKit::incNDR()
{
	this->noOfDataPacketsReceived = this->noOfDataPacketsReceived + 1;
}

int MetaDataToolKit::getHELLO()
{
	return this->hello;
}



int MetaDataToolKit::getERR()
{
	return this->err;
}

int MetaDataToolKit::getRREQ()
{
	return this->rreq;
}

int MetaDataToolKit::getRPLY()
{
	return this->rply;
}

int MetaDataToolKit::getNDF()
{
	return this->noOfDataPacketsForward;
}

int MetaDataToolKit::getNDR()
{
	return this->noOfDataPacketsReceived;
}


NodeEntry * MetaDataToolKit::getAllNeiNodes()
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

MetaDataToolKit::~MetaDataToolKit()
{
}

}
}

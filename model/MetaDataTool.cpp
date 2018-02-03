#include "MetaDataTool.h"

namespace ns3
{
namespace aodv
{


MetaDataTool::MetaDataTool()
{
}

void MetaDataTool::incRREQ()
{
	this->rreq = this->rreq + 1;
}

void MetaDataTool::incRPLY()
{
	this->rply = this->rply + 1;
}

void MetaDataTool::incERR()
{
	this->err = this->err + 1;
}

void MetaDataTool::incHELLO()
{
	this->hello = this->hello +1;
}

void MetaDataTool::incNDF()
{
	this->noOfDataPacketsForward = this->noOfDataPacketsForward + 1;
}

void MetaDataTool::incNDR()
{
	this->noOfDataPacketsReceived = this->noOfDataPacketsReceived + 1;
}

int MetaDataTool::getHELLO()
{
	return this->hello;
}



int MetaDataTool::getERR()
{
	return this->err;
}

int MetaDataTool::getRREQ()
{
	return this->rreq;
}

int MetaDataTool::getRPLY()
{
	return this->rply;
}

int MetaDataTool::getNDF()
{
	return this->noOfDataPacketsForward;
}

int MetaDataTool::getNDR()
{
	return this->noOfDataPacketsReceived;
}


MetaDataTool::~MetaDataTool()
{
}

}
}

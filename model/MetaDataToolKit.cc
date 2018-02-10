#include "MetaDataToolKit.h"

namespace ns3
{
namespace aodv
{


MetaDataToolKit::MetaDataToolKit()
{
	this->rreq = 0;
	this->rply = 0;
	this->err = 0;
	this->hello = 0;
	this->noOfDataPacketsForward = 0;
	this->noOfDataPacketsReceived = 0;
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
	this->hello = this->hello + 1;
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

MetaDataToolKit::~MetaDataToolKit()
{
}

}
}

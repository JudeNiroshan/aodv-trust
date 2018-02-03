#pragma once
#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{

class MetaDataTool
{
private:
	int rreq;
	int rply;
	int hello;
	int err;
	int noOfDataPacketsForward;
	int noOfDataPacketsReceived;
	int noOfControlPackets;
	int noOfDataPackets;
public:
	MetaDataTool();
	void incRREQ();
	void incRPLY();
	void incERR();
	void incHELLO();
	void incNDF();
	void incNDR();
	int getHELLO();
	int getERR();
	int getRREQ();
	int getRPLY();
	int getNDF();
	int getNDR();


	~MetaDataTool();
};

}
}


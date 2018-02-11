#pragma once
#include "NodeEntry.h"

namespace ns3 {
namespace aodv {

class MetaDataToolkit {
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
	MetaDataToolkit();
	void incRREQ();
	void incRPLY();
	void incERR();
	void incHELLO();
	void incNDF();
	void incNDR();
	int getNoOfRREQ();
	int getNoOfRPLY();
	int getNoOfHELLO();
	int getNoOfERR();
	int getNoOfSentDataPackets();
	int getNoOfReceivedDataPackets();
	NodeEntry* getAllNeiNodes();
	~MetaDataToolkit();

};

}
}

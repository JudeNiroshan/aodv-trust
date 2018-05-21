#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{


class DirTrustHelper
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
	DirTrustHelper();
	 int getNoOfRREQ();
	 int getNoOfRPLY();
	 int getNoOfHELLO();
	 int getNoOfERR();
	 int getNoOfSentDataPackets();
	 int getNoOfReceivedDataPackets();
	 NodeEntry* getAllNeiNodes();
	~DirTrustHelper();

};

}
}

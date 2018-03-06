#pragma once
#include <string>
#include <vector>
#include <list>
#include "ns3/ipv4-address.h"


namespace ns3
{
namespace aodv
{


class TRRTableEntry
{

private:

	Ipv4Address targetNodeId;
	Ipv4Address senderNodeId;
	double directTrust;
	double globalTrust;
	uint32_t sentTime;
	uint32_t receivedTime;

public:
	Ipv4Address getTargetNodeId();
	void setTargetNodeId(Ipv4Address neighborNodeId);
	Ipv4Address getSenderNodeId();
	void setSenderNodeId(Ipv4Address neighborNodeId);
	double getDirectTrust();
	void setDirectTrust(double DT);
	double getGlobalTrust();
	void setGlobalTrust(double DT);
	uint32_t getSentTime();
	void setSentTime(uint32_t sentTime);
	uint32_t getReceivedTime();
	void setReceivedTime(uint32_t receivedTime);
	TRRTableEntry();
	~TRRTableEntry();
};

}
}

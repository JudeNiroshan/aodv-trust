#pragma once
#include <string>
#include <vector>
#include <list>
#include "ns3/ipv4-address.h"
#include "ns3/nstime.h"


namespace ns3
{
namespace aodv
{


class TRRTableEntry
{

private:

	Ipv4Address targetNodeId;
	Ipv4Address senderNodeId;
	uint32_t directTrust;
	uint32_t globalTrust;
	Time sentTime;
	Time receivedTime;

public:
	Ipv4Address getTargetNodeId();
	void setTargetNodeId(Ipv4Address neighborNodeId);
	Ipv4Address getSenderNodeId();
	void setSenderNodeId(Ipv4Address neighborNodeId);
	uint32_t getDirectTrust();
	void setDirectTrust(uint32_t DT);
	uint32_t getGlobalTrust();
	void setGlobalTrust(uint32_t DT);
	Time getSentTime();
	void setSentTime(Time sentTime);
	Time getReceivedTime();
	void setReceivedTime(Time receivedTime);
	TRRTableEntry();
	~TRRTableEntry();
};

}
}

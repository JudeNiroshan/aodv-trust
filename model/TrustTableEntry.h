#pragma once
#include "ns3/ipv4-address.h"



namespace ns3
{
namespace aodv
{

class TrustTableEntry
{
private:
	Ipv4Address destinationNode;
	double dirTrust;
	double indTrust;
	double globalTrust;
	int interaction_count;
	int trustLevel;
	bool blacklist;
public:
	TrustTableEntry();
	void setInteractionCount(int i_count);
	int getInteractionCount();
	void setDestinationNode(Ipv4Address node);
	Ipv4Address getDestinationNode();
	void calculateGlobalTrust();
	double getGlobalTrust();
	void setDirectTrust(double dirTrust);
	double getDirectTrust();
	void setIndirectTrust(double indTrust);
	double getIndirectTrust();
	void updateIndirectTrust(double indTrust);
	void setTrustLevel(int trustLevel);
	int getTrustLevel();
	void setBlacklist(bool blacklist);
	bool getBlacklist();
	~TrustTableEntry();
};

}
}

#pragma once
#include "NodeEntry.h"


namespace ns3
{
namespace aodv
{

class TrustTableEntry
{
private:
	NodeEntry* destinationNode;
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
	void setDestinationNode(NodeEntry* node);
	NodeEntry* getDestinationNode();
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

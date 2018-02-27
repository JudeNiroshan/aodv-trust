#pragma once
#include <string>
#include <vector>
#include <list>
#include "NodeEntry.h"
#include "ns3/ipv4-address.h"


namespace ns3
{
namespace aodv
{


class RecommendationTableEntry
{

private:

	Ipv4Address neighborNodeId;
	Ipv4Address recommendingNodesList;
	double maturityLevel;
	bool blackList;
	double recommendationValue;

public:
	Ipv4Address getneighborNodeId();
	void setNeighborNodeId(Ipv4Address neighborNodeId);
	Ipv4Address getRecommendingNodes();
	double getrecValue();
	void setRecValue(double recommendationValue);
	int getMaturityLevel();
	void setMaturityLevel(double maturityLevel);
	RecommendationTableEntry();
	~RecommendationTableEntry();
};

}
}

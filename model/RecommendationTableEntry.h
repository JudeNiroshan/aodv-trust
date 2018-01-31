#pragma once
#include <string>
#include <vector>
#include <list>
#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{


class RecommendationTableEntry
{

private:

	std::string neighborNodeId;
	std::string neighborNodeName;
	std::vector<std::string> recommendingNodesList;
	double maturityLevel;
	bool blackList;
	double recommendationValue;

public:
	std::string getneighborNodeId();
	std::string getneighborNodeName();

	std::vector<std::string> getRecommendingNodesList();


	double getrecValue();
	void setRecValue(double recommendationValue);

	void setNeighborNodeId(std::string neighborNodeId);
	void setNeighborNodeName(std::string neighborNodeName);
	void setMaturityLevel(double maturityLevel);
	int getMaturityLevel();
	RecommendationTableEntry();
	~RecommendationTableEntry();
};

}
}

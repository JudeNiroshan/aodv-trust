//#include "stdafx.h"
#include "RecommendationTableEntry.h"
#include <string>

namespace ns3
{
namespace aodv
{

RecommendationTableEntry::RecommendationTableEntry()
{
}

Ipv4Address RecommendationTableEntry::getneighborNodeId()
{
	return this->neighborNodeId;
}

Ipv4Address RecommendationTableEntry::getRecommendingNodes()
{
	return this->recommendingNodesList;
}

void RecommendationTableEntry::setNeighborNodeId(Ipv4Address neighborNodeId)
{
	this->neighborNodeId = neighborNodeId;
}

void RecommendationTableEntry::setMaturityLevel(double maturityLevel)
{
	this->maturityLevel = maturityLevel;
}

int RecommendationTableEntry::getMaturityLevel()
{
	return this->maturityLevel;
}

void RecommendationTableEntry::setRecValue(double recommendationValue)
{
	this->recommendationValue = recommendationValue;
}

double RecommendationTableEntry::getrecValue()
{
	return this->recommendationValue;
}

RecommendationTableEntry::~RecommendationTableEntry()
{
}

}
}

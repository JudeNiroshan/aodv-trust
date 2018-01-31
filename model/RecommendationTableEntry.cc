//#include "stdafx.h"
#include "RecommendationTableEntry.h"

namespace ns3
{
namespace aodv
{

RecommendationTableEntry::RecommendationTableEntry()
{
}

string RecommendationTableEntry::getneighborNodeId()
{
	return this->neighborNodeId;
}

string RecommendationTableEntry::getneighborNodeName()
{
	return this->neighborNodeName;
}

std::vector<std::string> RecommendationTableEntry::getRecommendingNodesList()
{
	return this->recommendingNodesList;
}



void RecommendationTableEntry::setNeighborNodeId(string neighborNodeId)
{
	this->neighborNodeId = neighborNodeId;
}

void RecommendationTableEntry::setNeighborNodeName(string neighborNodeName)
{
	this->neighborNodeName = neighborNodeName;
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

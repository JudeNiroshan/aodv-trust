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

std::string RecommendationTableEntry::getneighborNodeId()
{
	return this->neighborNodeId;
}

std::string RecommendationTableEntry::getneighborNodeName()
{
	return this->neighborNodeName;
}

std::vector<std::string> RecommendationTableEntry::getRecommendingNodesList()
{
	return this->recommendingNodesList;
}



void RecommendationTableEntry::setNeighborNodeId(std::string neighborNodeId)
{
	this->neighborNodeId = neighborNodeId;
}

void RecommendationTableEntry::setNeighborNodeName(std::string neighborNodeName)
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

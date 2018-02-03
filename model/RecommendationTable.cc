//#include "stdafx.h"
#include "RecommendationTable.h"
#include <string>
#include <iostream>
#include <vector>

namespace ns3
{
namespace aodv
{


RecommendationTable* RecommendationTable::instance = NULL;

RecommendationTable::RecommendationTable()
{
	columnSeperator = " | ";
}

RecommendationTable * RecommendationTable::getInstance()
{
	if (instance == NULL) {
		instance = new RecommendationTable();
	}
	return instance;
}


void RecommendationTable::addRecommendationTableEntry(RecommendationTableEntry entry)
{
	recommendationTableRecords.push_back(entry);
}

void RecommendationTable::removeRecommendationTableEntry(RecommendationTableEntry entry)
{
	recommendationTableRecords.pop_back(); //need to change this
}

std::vector<RecommendationTableEntry>& RecommendationTable::getRecommendationTableEntries()
{
	return recommendationTableRecords;
}

std::vector<RecommendationTableEntry>& RecommendationTable::getRecommendedNodeEntries(std::string nodeId)
{
	// TODO: return the recommended node entry vector
	std::vector<RecommendationTableEntry>& test = this->getRecommendationTableEntries();

	// TODO: need to have a logic here.
	for (std::vector<RecommendationTableEntry>::iterator it = recommendationTableRecords.begin(); it != recommendationTableRecords.end(); it++)
	{
		if (it->getneighborNodeId() == nodeId) {
			test.push_back(*it);
		}
	}

	//need to do something(exception handling) for in all the calling functions
	return test;
}

void RecommendationTable::setRecommendationTable(std::vector<RecommendationTableEntry> newRecommendationTable)
{
	this->recommendationTableRecords = newRecommendationTable;
}

void RecommendationTable::printTable()
{
	//cout << "| " << "Neighbor Node" << columnSeperator << "Recommending Node" << columnSeperator << "Matuarity Level" << columnSeperator << "Blacklist" << endl;

	//for (RecommendationTableEntry &node : recommendationTableRecords) {
	//cout << "| " << "" << "\t\t" << columnSeperator << "" << "\t\t" << columnSeperator << "" << "\t\t" << columnSeperator << "" << "\t\t" << columnSeperator << endl;
	//}

	std::cout << "| " << "Neighbor Node" << columnSeperator << "Matuarity Level" << std::endl;
	for (std::vector<RecommendationTableEntry>::iterator it = recommendationTableRecords.begin(); it != recommendationTableRecords.end(); it++)
	{
		std::cout << "| " << it->getneighborNodeName() << "\t\t" <<columnSeperator << it->getMaturityLevel() << "\t\t" << columnSeperator << std::endl;
	}

}



RecommendationTable::~RecommendationTable()
{
}

}
}

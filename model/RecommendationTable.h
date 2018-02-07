#pragma once
#include <vector>
#include <string>
#include "RecommendationTableEntry.h"

namespace ns3
{
namespace aodv
{


class RecommendationTable
{
private:
	std::string columnSeperator;
	std::vector<RecommendationTableEntry> recommendationTableRecords;
public:
	RecommendationTable();
	void addRecommendationTableEntry(RecommendationTableEntry entry);
	void removeRecommendationTableEntry(RecommendationTableEntry entry);
	std::vector<RecommendationTableEntry>& getRecommendationTableEntries();
	std::vector<RecommendationTableEntry>& getRecommendedNodeEntries(std::string nodeId);
	void setRecommendationTable(std::vector<RecommendationTableEntry> newTrustTable);
	void printTable();

	~RecommendationTable();
};

}
}

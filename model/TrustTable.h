#pragma once
#include <vector>
#include "TrustTableEntry.h"

namespace ns3
{
namespace aodv
{

class TrustTable
{
private:
	TrustTable();
        std::string columnSeperator;
	std::vector<TrustTableEntry> trustTableRecords;
	static TrustTable* instance;
public:
	static TrustTable* getInstance();
	void addTrustTableEntry(TrustTableEntry entry);
	void removeTrustTableEntry(TrustTableEntry entry);
	TrustTableEntry getTrustTableEntryByNodeId(std::string nodeId);
	std::vector<TrustTableEntry> getBlacklistedTrustTableEntries();
	std::vector<TrustTableEntry>& getTrustTableEntries();
	void setTrustTable(std::vector<TrustTableEntry> newTrustTable);
	void printTable();
	~TrustTable();
};

}
}

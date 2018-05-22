#pragma once
#include <vector>
#include <string>
#include "ns3/ipv4-address.h"
#include "TRRTableEntry.h"

namespace ns3 {
namespace aodv {

class TRRTable {
private:
	std::string columnSeperator;
	std::vector<TRRTableEntry> trrTableRecords;
public:
	TRRTable();
	void addTrrTableEntry(TRRTableEntry entry);
	void removeTrrTableEntry(TRRTableEntry entry);
	std::vector<TRRTableEntry> getTrrTableEntriesCopy();
	std::vector<TRRTableEntry>& getTrrTableEntries();
	std::vector<TRRTableEntry>& getTrrNodeEntries(Ipv4Address nodeId);
	void setRecommendationTable(std::vector<TRRTableEntry> newTrustTable);
	void printTable();
	~TRRTable();
};

}
}

//#include "stdafx.h"
#include "TrustTable.h"
#include <iostream>

namespace ns3
{
namespace aodv
{


TrustTable::TrustTable()
{
	columnSeperator = " | ";
}

void TrustTable::addTrustTableEntry(TrustTableEntry entry)
{
	trustTableRecords.push_back(entry);
}

void TrustTable::removeTrustTableEntry(TrustTableEntry entry)
{
	trustTableRecords.pop_back(); //need to change this
}

TrustTableEntry TrustTable::getTrustTableEntryByNodeId(Ipv4Address nodeId)
{
	TrustTableEntry entry;
	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		if (it->getDestinationNode() == nodeId) {
			return *it;
		}
	}

	//need to do something(exception handling) for in all the calling functions
	return entry;
}

std::vector<TrustTableEntry> TrustTable::getBlacklistedTrustTableEntries()
{
	std::vector<TrustTableEntry> blacklistedVector;
	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		if (it->getBlacklist()) {
			blacklistedVector.push_back(*it);
		}
	}

	return blacklistedVector;
}

std::vector<TrustTableEntry>& TrustTable::getTrustTableEntries()
{
	return trustTableRecords;
}

void TrustTable::setTrustTable(std::vector<TrustTableEntry> newTrustTable)
{
	this->trustTableRecords = newTrustTable;
}

void TrustTable::printTable()
{
	std::cout << ">>>>>>>>>>>>>> Direct Trust Table <<<<<<<<<<<<<<<" << std::endl;
	std::cout << "| "<< "Destination Node"<< columnSeperator << "Direct Trust" << columnSeperator << "Indirect Trust" << columnSeperator << "Interactions" << columnSeperator << "Global Trust"<< columnSeperator << "Trust Level" << std::endl;
	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		std::cout << "| " << it->getDestinationNode() << "\t\t" << columnSeperator << it->getDirectTrust() << "\t\t" << columnSeperator << it->getIndirectTrust() << "\t\t" << columnSeperator << it->getInteractionCount() << "\t\t"<< columnSeperator << it->getGlobalTrust() << "\t\t" << columnSeperator << it->getTrustLevel() << std::endl;
	}
}


TrustTable::~TrustTable()
{
}

}
}

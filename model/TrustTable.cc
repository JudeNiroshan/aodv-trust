//#include "stdafx.h"
#include "TrustTable.h"
#include <iostream>

namespace ns3
{
namespace aodv
{


TrustTable* TrustTable::instance = NULL;

TrustTable::TrustTable()
{
	columnSeperator = " | ";
}

TrustTable * TrustTable::getInstance()
{
	if (instance == NULL) {
		instance = new TrustTable();
	}
	return instance;
}

void TrustTable::addTrustTableEntry(TrustTableEntry entry)
{
	trustTableRecords.push_back(entry);
}

void TrustTable::removeTrustTableEntry(TrustTableEntry entry)
{
	trustTableRecords.pop_back(); //need to change this
}

TrustTableEntry TrustTable::getTrustTableEntryByNodeId(std::string nodeId)
{
	TrustTableEntry entry;

	for (TrustTableEntry &node : trustTableRecords) {
		if (node.getDestinationNode()->getNodeId() == nodeId) {
			return node;
		}
	}
	//need to do something(exception handling) for in all the calling functions
	return entry;
}

std::vector<TrustTableEntry> TrustTable::getBlacklistedTrustTableEntries()
{
	std::vector<TrustTableEntry> blacklistedVector;
	for (TrustTableEntry &node : trustTableRecords) {
		if (node.getBlacklist()) {
			blacklistedVector.push_back(node);
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

	for (TrustTableEntry &node : trustTableRecords) {
		std::cout << "| " << node.getDestinationNode()->getNodeName() << "\t\t" << columnSeperator << node.getDirectTrust() << "\t\t" << columnSeperator << node.getIndirectTrust() << "\t\t" << columnSeperator << node.getInteractionCount() << "\t\t"<< columnSeperator << node.getGlobalTrust() << "\t\t" << columnSeperator << node.getTrustLevel() << std::endl;
	}
}


TrustTable::~TrustTable()
{
}

}
}

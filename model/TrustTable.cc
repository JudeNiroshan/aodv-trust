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

TrustTableEntry* TrustTable::getTrustTableEntryByNodeId(Ipv4Address nodeId)
{
	TrustTableEntry* entry = 0;
	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		if (it->getDestinationNode() == nodeId) {
			return &*it;
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
	std::cout << "| "<< "Destination Node"<< columnSeperator << "Direct Trust" << columnSeperator << "Indirect Trust" << columnSeperator << "Interactions" << columnSeperator << "Global Trust"<< columnSeperator << "Trust Level" << columnSeperator << "RREQ" << columnSeperator << "RPLY" << columnSeperator << "Hello" << columnSeperator <<  "ERR" << columnSeperator << "packetsRecieved" << columnSeperator  << "packetsForaward" << std::endl;
	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		std::cout << "| " << it->getDestinationNode() << "\t" << columnSeperator << it->getDirectTrust() << "\t" << columnSeperator << it->getIndirectTrust() << "\t" << columnSeperator << it->getInteractionCount() << "\t"<< columnSeperator << it->getGlobalTrust() << "\t" << columnSeperator << it->getTrustLevel() << "\t" << columnSeperator << it->getNoOfRREQ() << "\t" << columnSeperator << it->getNoOfRPLY() << "\t" << columnSeperator << it->getNoOfHELLO() << "\t" << columnSeperator << it->getNoOfERR() <<  "\t" << columnSeperator<<  it->getNoOfReceivedDataPackets() << "\t" << columnSeperator<< it->getNoOfSentDataPackets() << std::endl;
	}
}

void TrustTable::incrementAllHelloPacketsCount() {

	for (std::vector<TrustTableEntry>::iterator it = trustTableRecords.begin(); it != trustTableRecords.end(); it++)
	{
		it->incHELLO();
	}
}

TrustTable::~TrustTable()
{
}

}
}

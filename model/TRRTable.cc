//#include "stdafx.h"
#include "TRRTable.h"
#include <string>
#include <iostream>
#include <vector>

namespace ns3 {
namespace aodv {

TRRTable::TRRTable() {
	columnSeperator = " | ";
}

void TRRTable::addTrrTableEntry(TRRTableEntry entry) {
	trrTableRecords.push_back(entry);
}

void TRRTable::removeTrrTableEntry(TRRTableEntry entry) {
	trrTableRecords.pop_back(); //need to change this
}

std::vector<TRRTableEntry>& TRRTable::getTrrTableEntries() {
	return trrTableRecords;
}

std::vector<TRRTableEntry> TRRTable::getTrrTableEntriesCopy() {
	return trrTableRecords;
}

std::vector<TRRTableEntry>& TRRTable::getTrrNodeEntries(Ipv4Address nodeId) {
	// TODO: return the recommended node entry vector
	std::vector<TRRTableEntry>& test = this->getTrrTableEntries();

	// TODO: need to have a logic here.
	for (std::vector<TRRTableEntry>::iterator it = trrTableRecords.begin();
			it != trrTableRecords.end(); it++) {
		if (it->getTargetNodeId() == nodeId) {
			test.push_back(*it);
		}
	}

	//need to do something(exception handling) for in all the calling functions
	return test;
}

void TRRTable::setRecommendationTable(
		std::vector<TRRTableEntry> newRecommendationTable) {
	this->trrTableRecords = newRecommendationTable;
}

void TRRTable::printTable() {
	std::cout << "| " << "Target Node" << columnSeperator << "Sender Nodes"
			<< columnSeperator << "DT" << columnSeperator << "GT"
			<< columnSeperator << "SentTime" << columnSeperator
			<< "ReceivedTime" << std::endl;

	for (std::vector<TRRTableEntry>::iterator it = trrTableRecords.begin();
			it != trrTableRecords.end(); it++) {
		std::cout << "| " << it->getTargetNodeId() << "\t\t" << columnSeperator
				<< it->getSenderNodeId() << "\t\t" << columnSeperator
				<< it->getDirectTrust() << "\t\t" << columnSeperator
				<< it->getGlobalTrust() << "\t\t" << columnSeperator
				<< it->getSentTime() << columnSeperator << it->getReceivedTime()
				<< "\t\t" << columnSeperator << std::endl;
	}
}


/*
 void TRRTable::printTable() {
 std::cout << "| " << "Target Node" << columnSeperator << "Sender Nodes"
 << columnSeperator << "DT" << columnSeperator << "GT"
 << columnSeperator << "SentTime" << columnSeperator
 << "ReceivedTime" << std::endl;

 for (std::vector<TRRTableEntry>::iterator it = trrTableRecords.begin();
 it != trrTableRecords.end(); it++) {

 std::cout << "Outer " << "Target Node" << it->getTargetNodeId()
 << " Sender Node " << it->getSenderNodeId() << std::endl;

 for (std::vector<TRRTableEntry>::iterator it1 = trrTableRecords.begin();
 it1 != trrTableRecords.end(); it1++) {

 std::cout << "Inner " << "Target Node" << it1->getTargetNodeId()
 << " Sender Node " << it1->getSenderNodeId() << std::endl;
 std::cout << "| " << it1->getTargetNodeId() << "\t\t" << columnSeperator
 << it1->getSenderNodeId() << "\t\t" << columnSeperator
 << it1->getDirectTrust() << "\t\t" << columnSeperator
 << it1->getGlobalTrust() << "\t\t" << columnSeperator
 << it1->getSentTime() << columnSeperator << it1->getReceivedTime()
 << "\t\t" << columnSeperator << std::endl;
 }

 }
 }
 */

TRRTable::~TRRTable() {
}

}
}

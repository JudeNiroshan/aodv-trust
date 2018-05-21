//#include "stdafx.h"
#include "TrustTableEntry.h"
#include <iostream>

namespace ns3 {
namespace aodv {

TrustTableEntry::TrustTableEntry()
{
	this->rreq = 0;
	this->rply = 0;
	this->hello = 0;
	this->err = 0;
	this->noOfDataPacketsForward = 0;
	this->noOfDataPacketsReceived = 0;
	this->interaction_count = 0;
}

int TrustTableEntry::getInteractionCount() {
	return this->interaction_count;
}

void TrustTableEntry::setDestinationNode(Ipv4Address node) {
	this->destinationNode = node;
}

Ipv4Address TrustTableEntry::getDestinationNode() {
	return this->destinationNode;
}

void TrustTableEntry::calculateGlobalTrust() {
	this->globalTrust = this->dirTrust + this->indTrust;
	/*BackupTableEntry entry;
	 entry.setNeiNode(this->destinationNode);
	 entry.setTrustValue(this->globalTrust);
	 entry.setTimeDuration(2.5);

	 BackupTable::getInstance()->addBackupTableEntry(entry);
	 BackupTable::getInstance()->addToTrustList(this->globalTrust);*/
}

double TrustTableEntry::getGlobalTrust() {
	return this->globalTrust;
}

void TrustTableEntry::setDirectTrust(double dirTrust) {
	this->dirTrust = dirTrust;
}

double TrustTableEntry::getDirectTrust() {
	return this->dirTrust;
}

void TrustTableEntry::setIndirectTrust(double indTrust) {
	this->indTrust = indTrust;
}

double TrustTableEntry::getIndirectTrust() {
	return this->indTrust;
}

void TrustTableEntry::updateIndirectTrust(double indTrust) {
	this->indTrust = indTrust;
}

void TrustTableEntry::setTrustLevel(int trustLevel) {
	this->trustLevel = trustLevel;
}

int TrustTableEntry::getTrustLevel() {
	return this->trustLevel;
}

void TrustTableEntry::setBlacklist(bool blacklist) {
	this->blacklist = blacklist;
}

bool TrustTableEntry::getBlacklist() {
	return this->blacklist;
}

void TrustTableEntry::incRREQ() {
	this->rreq = this->rreq + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incRPLY() {
	this->rply = this->rply + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incERR() {
	this->err = this->err + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incHELLO() {
	this->hello = this->hello + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incNDF() {
	this->noOfDataPacketsForward = this->noOfDataPacketsForward + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incNDR() {
	this->noOfDataPacketsReceived = this->noOfDataPacketsReceived + 1;
	this->interaction_count = this->interaction_count + 1;
}

void TrustTableEntry::incInteractionCount() {
	this->interaction_count = this->interaction_count + 1;
}

int TrustTableEntry::getNoOfRREQ() {
	return this->rreq;
}

int TrustTableEntry::getNoOfRPLY() {
	return this->rply;
}

int TrustTableEntry::getNoOfHELLO() {
	return this->hello;
	//return 1;
}

int TrustTableEntry::getNoOfERR() {
	return this->err;
	//return 1;
}

int TrustTableEntry::getNoOfSentDataPackets() {
	return this->noOfDataPacketsForward;
	//return 2;
}

int TrustTableEntry::getNoOfReceivedDataPackets() {
	return this->noOfDataPacketsReceived;
	//return 2;
}

TrustTableEntry::~TrustTableEntry() {
}

}
}

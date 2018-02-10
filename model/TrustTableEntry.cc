//#include "stdafx.h"
#include "TrustTableEntry.h"
#include <iostream>


namespace ns3
{
namespace aodv
{


TrustTableEntry::TrustTableEntry()
{
}

void TrustTableEntry::setInteractionCount(int i_count)
{
	this->interaction_count = i_count;
}

int TrustTableEntry::getInteractionCount()
{
	return this->interaction_count;
}

void TrustTableEntry::setDestinationNode(Ipv4Address node)
{
	this->destinationNode = node;
}

Ipv4Address TrustTableEntry::getDestinationNode()
{
	return this->destinationNode;
}

void TrustTableEntry::calculateGlobalTrust()
{
	this->globalTrust = this->dirTrust + this->indTrust;
	/*BackupTableEntry entry;
	entry.setNeiNode(this->destinationNode);
	entry.setTrustValue(this->globalTrust);
	entry.setTimeDuration(2.5);

	BackupTable::getInstance()->addBackupTableEntry(entry);
	BackupTable::getInstance()->addToTrustList(this->globalTrust);*/
};

double TrustTableEntry::getGlobalTrust()
{
	return this->globalTrust;
}

void TrustTableEntry::setDirectTrust(double dirTrust)
{
	this->dirTrust = dirTrust;
}

double TrustTableEntry::getDirectTrust()
{
	return this->dirTrust;
}

void TrustTableEntry::setIndirectTrust(double indTrust)
{
	this->indTrust = indTrust;
}

double TrustTableEntry::getIndirectTrust()
{
	return this->indTrust;
}

void TrustTableEntry::updateIndirectTrust(double indTrust)
{
	this->indTrust = indTrust;
}

void TrustTableEntry::setTrustLevel(int trustLevel)
{
	this->trustLevel = trustLevel;
}

int TrustTableEntry::getTrustLevel()
{
	return this->trustLevel;
}

void TrustTableEntry::setBlacklist(bool blacklist)
{
	this->blacklist = blacklist;
}

bool TrustTableEntry::getBlacklist()
{
	return this->blacklist;
}

TrustTableEntry::~TrustTableEntry()
{
}

}
}

#include "BackupTableEntry.h"

namespace ns3
{
namespace aodv
{

BackupTableEntry::BackupTableEntry()
{
}

void BackupTableEntry::setNeiNode(Ipv4Address neiNode)
{
	this->neiNode = neiNode;
}

Ipv4Address BackupTableEntry::getNeiNode()
{
	return this->neiNode;
}

void BackupTableEntry::setTrustValue(double trustValue)
{
	this->trustValue = trustValue;
}

double BackupTableEntry::getTrustValue()
{
	return this->trustValue;
}

void BackupTableEntry::updateTrustValue(double trustValue)
{
	this->trustValue = trustValue;
}

void BackupTableEntry::setResult(std::string result)
{
	this->result = result;
}

void BackupTableEntry::updateResult(std::string result)
{
	this->result = result;
}

std::string BackupTableEntry::getResult()
{
	return this->result;
}

void BackupTableEntry::setTimeDuration(double timeDuration)
{
	this->timeDuration = timeDuration;
}

double BackupTableEntry::getTimeDuration()
{
	return this->timeDuration;
}

void BackupTableEntry::updateTimeDuration(double timeDuration)
{
	this->timeDuration = timeDuration;
}

BackupTableEntry::~BackupTableEntry()
{
}

}
}

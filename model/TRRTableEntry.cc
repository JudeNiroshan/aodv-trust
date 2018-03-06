//#include "stdafx.h"
#include "TRRTableEntry.h"
#include <string>

namespace ns3
{
namespace aodv
{

TRRTableEntry::TRRTableEntry()
{
}

Ipv4Address TRRTableEntry::getTargetNodeId()
{
	return this->targetNodeId;
}

void TRRTableEntry::setSenderNodeId(Ipv4Address targetNodeId)
{
	this->targetNodeId = targetNodeId;
}

Ipv4Address TRRTableEntry::getSenderNodeId()
{
	return this->senderNodeId;
}

void TRRTableEntry::setSenderNodeId(Ipv4Address senderNodeId)
{
	this->senderNodeId = senderNodeId;
}

double TRRTableEntry::getDirectTrust()
{
	return directTrust;
}
void TRRTableEntry::setDirectTrust(double directTrust)
{
	this->directTrust = directTrust;
}

double TRRTableEntry::getGlobalTrust()
{
	return globalTrust;
}
void TRRTableEntry::setGlobalTrust(double globalTrust)
{
	this->globalTrust = globalTrust;
}

uint32_t TRRTableEntry::getSentTime()
{
	return sentTime;
}

void TRRTableEntry::setSentTime(uint32_t sentTime)
{
	this->sentTime = sentTime;
}

uint32_t TRRTableEntry::getReceivedTime()
{
	return receivedTime;
}

void TRRTableEntry::setReceivedTime(uint32_t receivedTime)
{
	this->receivedTime = receivedTime;
}

RecommendationTableEntry::~RecommendationTableEntry()
{
}

}
}

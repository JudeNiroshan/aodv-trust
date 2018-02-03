//#include "stdafx.h"
#include "NodeEntry.h"

namespace ns3
{
namespace aodv
{

NodeEntry::NodeEntry()
{
}

void NodeEntry::setNodeId(std::string nodeId)
{
	this->nodeId = nodeId;
}

void NodeEntry::setNodeName(std::string nodeName)
{
	this->nodeName = nodeName;
}

std::string NodeEntry::getNodeId()
{
	return this->nodeId;
}

std::string NodeEntry::getNodeName()
{
	return this->nodeName;
}


NodeEntry::~NodeEntry()
{
}

}
}

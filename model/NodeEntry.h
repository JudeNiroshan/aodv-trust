#pragma once
#include <string>

namespace ns3
{
namespace aodv
{

class NodeEntry
{
private:
	std::string nodeId;
	std::string nodeName;
public:
	NodeEntry();
	void setNodeId(std::string nodeId);
	void setNodeName(std::string nodeName);
	std::string getNodeId();
	std::string getNodeName();
	~NodeEntry();
};

}
}

#include "TrustInfoReceiver.h"
#include <string>
#include "TrustTable.h"
#include "RecommendationTable.h"
#include <iostream>

namespace ns3
{
namespace aodv
{


TrustInfoReceiver::TrustInfoReceiver()
{
}

/**
* Description:	Executor method which runs once a broadcast request received a information about malicious node
* Returns:		void
* Parameter:	void
*/
void TrustInfoReceiver::validateReceivedTrustInfo()
{
/*	//TODO : below 2 lines needs to be removed and this nodeId value should extract out from the received broadcast message
	string nodeId;
	nodeId = "172.168.1.1";

	std::vector<TrustTableEntry> allNeighborNodesVector = TrustTable::getInstance()->getTrustTableEntries();
	for (TrustTableEntry &node : allNeighborNodesVector) {
		if (node.getDestinationNode()->getNodeId() == nodeId) {
			if (node.getBlacklist()) {
				TrustTable::getInstance()->removeTrustTableEntry(node);
			}
			else {
				node.setBlacklist(true);
			}
		}
	}

	NodeEntry* cmNode = TrustTable::getInstance()->getTrustTableEntryByNodeId(nodeId).getDestinationNode();
	sendMaliciousBroadcast(cmNode);

	std::vector<RecommendationTableEntry> recommendedNodes = RecommendationTable::getInstance()->getRecommendedNodeEntries(nodeId);
	for (RecommendationTableEntry &node : recommendedNodes) {
		//Calculate reduction factor
		//recalculate IT in trust table
	}*/
}

void TrustInfoReceiver::sendMaliciousBroadcast(Ipv4Address node)
{
	//TODO: implement the sending the broadcast packet which says the given node has identified as a malicious node
	
	std::cout << node << " is a pure malicious node. So please delete that node from your tables." << std::endl;
}


TrustInfoReceiver::~TrustInfoReceiver()
{
}

}
}

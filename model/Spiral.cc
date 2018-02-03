#include "Spiral.h"
#include "TrustInfoReceiver.h"
#include <iostream>

namespace ns3
{
namespace aodv
{

Spiral::Spiral()
{
}


void Spiral::addMaliciousCategory(double* past_global_trust_range, TrustTable* trustTable)
{
	std::vector<TrustTableEntry>& node_trust_entry_vector = trustTable->getTrustTableEntries();
	TrustInfoReceiver trustInfoReceiver;

	for (std::vector<TrustTableEntry>::iterator it = node_trust_entry_vector.begin(); it != node_trust_entry_vector.end(); it++) {

		double currentTrust = it->getGlobalTrust();

		if (past_global_trust_range[0] <= currentTrust && past_global_trust_range[1] >= currentTrust)
		{
			//cout << "pure" << endl;
			it->setTrustLevel(4);
			trustTable->removeTrustTableEntry(*it);
			trustInfoReceiver.sendMaliciousBroadcast(it->getDestinationNode());
		}
		else
		{
			//cout << "collaborative" << endl;
			it->setTrustLevel(5);
			it->setBlacklist(true);

			//neighbour_node_list = getRecommendedNodes(inputNode);
			//reduce_factor = calculateReduceFactor(input_node);
			//for (int i = 0; i<neighbour_node_array.length(); i++) {
			//  recalculateIndirectTrust(neighbour_node, reduce_factor);
			//	updateGlobalTrust(node);
			//}

			//Broadcast to the others that this is a collaborative malicious nodes
			trustInfoReceiver.sendMaliciousBroadcast(it->getDestinationNode());

			//broadcastToNeighbors(input_node,"Collaborative malicious node");
			// GOTO Identifying_trust_levels
		}


	}
}


double * Spiral::getMinMaxTrust(std::vector<double> trust_list)
{
	static double past_global_trust_range[2];

	double min = trust_list[0];
	for (unsigned int i = 0; i < trust_list.size(); i++)
	{
		if (trust_list[i] < min)
		{
			min = trust_list[i];
		}
	}
	past_global_trust_range[0] = min;
	double max = trust_list[0];
	for (unsigned int i = 0; i < trust_list.size(); i++)
	{
		if (trust_list[i] > max)
		{
			max = trust_list[i];
		}
	}
	past_global_trust_range[1] = max;

	return past_global_trust_range;

}


Spiral::~Spiral()
{
}
}
}

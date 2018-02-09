//#include "stdafx.h"
#include "TestValueGeneratorNew.h"
#include "NodeEntry.h"
#include <iostream>

namespace ns3
{
namespace aodv
{


TestValueGeneratorNew::TestValueGeneratorNew()
{
}

TrustTable* TestValueGeneratorNew::getDummyDirTrustTable()
{

	TrustTableEntry row1;
	row1.setDestinationNode("172.168.1.1");
	row1.setInteractionCount(10);

	TrustTableEntry row2;
	row2.setDestinationNode("172.168.1.2");
	row2.setInteractionCount(8);


	TrustTable* trustTable = TrustTable::getInstance();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}

TrustTable* TestValueGeneratorNew::getDummyTrustTable()
{

	TrustTableEntry row1;
	row1.setDestinationNode("192.168.1.1");
	row1.setDirectTrust(0.12);
	row1.setIndirectTrust(7.2);
	row1.setInteractionCount(2);
	row1.calculateGlobalTrust();

	TrustTableEntry row2;
	row2.setDestinationNode("192.168.1.1");
	row2.setDirectTrust(0.32);
	row2.setIndirectTrust(5.2);
	row2.setInteractionCount(3);
	row2.calculateGlobalTrust();

	TrustTable* trustTable = TrustTable::getInstance();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}


RecommendationTable * TestValueGeneratorNew::getDummyRecommendationTableByTrustTable(TrustTable* trustTable)
{

	std::vector<TrustTableEntry>& node_entry_vector = trustTable->getTrustTableEntries();
	RecommendationTable *recTable = RecommendationTable::getInstance();
	/*for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++)
		{

		}*/
	double matuarityLevel;
	double i_all = 0;
	int i_p_node;

	for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++)
	{
		i_p_node = it->getInteractionCount();

		for (std::vector<TrustTableEntry>::iterator it2 = node_entry_vector.begin(); it2 != node_entry_vector.end(); it2++) {
			i_all = i_all + it2->getInteractionCount();
		}

		matuarityLevel = i_p_node / i_all;


		NodeEntry *node;
		RecommendationTableEntry entry;
		node = it->getDestinationNode();
		entry.setNeighborNodeId(node->getNodeId());
		entry.setNeighborNodeName(node->getNodeName());
		entry.setMaturityLevel(matuarityLevel);

		recTable->addRecommendationTableEntry(entry);
	}

	return recTable;
}


TestValueGeneratorNew::~TestValueGeneratorNew()
{
}

}
}

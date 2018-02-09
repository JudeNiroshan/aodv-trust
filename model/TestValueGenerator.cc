//#include "stdafx.h"
#include "TestValueGenerator.h"
#include "RecommendationTable.h"
#include "IndTrustCal.h"
#include "NodeEntry.h"
#include <iostream>

namespace ns3
{
namespace aodv
{


TestValueGenerator::TestValueGenerator()
{
}


TrustTable* TestValueGenerator::getDummyTrustTable()
{
	TrustTableEntry row1;
	row1.setDestinationNode("192.168.2.1");
	row1.setDirectTrust(0.12);
	row1.setIndirectTrust(7.2);
	row1.setInteractionCount(2);
	row1.calculateGlobalTrust();

	TrustTableEntry row2;
	row2.setDestinationNode("192.168.2.2");
	row2.setDirectTrust(0.32);
	row2.setIndirectTrust(5.2);
	row2.setInteractionCount(3);
	row2.calculateGlobalTrust();

	TrustTable* trustTable = new TrustTable();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}

TrustTable * TestValueGenerator::getDummyDirTrustTable()
{
	TrustTableEntry row1;
	row1.setDestinationNode("172.168.1.1");
	row1.setInteractionCount(10);

	TrustTableEntry row2;
	row2.setDestinationNode("172.168.1.2");
	row2.setInteractionCount(8);


	TrustTable* trustTable = new TrustTable();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}


RecommendationTable * TestValueGenerator::getDummyRecommendationTableByTrustTable(TrustTable* trustTable)
{

	std::vector<TrustTableEntry>& node_entry_vector = trustTable->getTrustTableEntries();
	RecommendationTable *recTable = new RecommendationTable();
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


			RecommendationTableEntry entry;
			entry.setNeighborNodeId(it->getDestinationNode());
			entry.setMaturityLevel(matuarityLevel);

			recTable->addRecommendationTableEntry(entry);
	}

	return recTable;
}


TestValueGenerator::~TestValueGenerator()
{
}

}
}

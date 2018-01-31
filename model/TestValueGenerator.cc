//#include "stdafx.h"
#include "TestValueGenerator.h"
#include "RecommendationTable.h"
#include "IndTrustCal.h"
#include "Node.h"
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
	Node* node1 = new Node();
	node1->setNodeId("0");
	node1->setNodeName("Node A");

	Node* node2 = new Node();
	node2->setNodeId("1");
	node2->setNodeName("Node B");

	Node* node3 = new Node();
	node3->setNodeId("2");
	node3->setNodeName("Node C");

	TrustTableEntry row1;
	row1.setDestinationNode(node2);
	row1.setDirectTrust(0.12);
	row1.setIndirectTrust(7.2);
	row1.setInteractionCount(2);
	row1.calculateGlobalTrust();

	TrustTableEntry row2;
	row2.setDestinationNode(node3);
	row2.setDirectTrust(0.32);
	row2.setIndirectTrust(5.2);
	row2.setInteractionCount(3);
	row2.calculateGlobalTrust();

	TrustTable* trustTable = TrustTable::getInstance();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}

TrustTable * TestValueGenerator::getDummyDirTrustTable()
{
	Node* node1 = new Node();
	node1->setNodeId("172.168.1.1");
	node1->setNodeName("B");

	Node* node2 = new Node();
	node2->setNodeId("172.168.1.2");
	node2->setNodeName("C");

	TrustTableEntry row1;
	row1.setDestinationNode(node1);
	row1.setInteractionCount(10);

	TrustTableEntry row2;
	row2.setDestinationNode(node2);
	row2.setInteractionCount(8);


	TrustTable* trustTable = TrustTable::getInstance();
	trustTable->addTrustTableEntry(row1);
	trustTable->addTrustTableEntry(row2);

	return trustTable;
}

RecommendationTable * TestValueGenerator::getDummyRecommendationTable()
{
	return nullptr;
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
		

		for (TrustTableEntry& entryNode : node_entry_vector) {
			i_all = i_all + entryNode.getInteractionCount();
		}

		matuarityLevel = i_p_node / i_all;


		Node *node;
		RecommendationTableEntry entry;
		node = it->getDestinationNode();
		entry.setNeighborNodeId(node->getNodeId());
		entry.setNeighborNodeName(node->getNodeName());
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

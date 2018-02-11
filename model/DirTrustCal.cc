#include "DirTrustCal.h"
#include "MetaDataToolkit.h"
#include "TrustTableEntry.h"
#include <math.h>
#include <iostream>


namespace ns3
{
namespace aodv
{


DirTrustCal::DirTrustCal()
{
}


void DirTrustCal::calculateDirectTrust(TrustTable *trustTable)
{

	std::vector<TrustTableEntry>& node_entry_vector = trustTable->getTrustTableEntries();

	//MetaDataToolKit  metaDataTool;

	MetaDataToolkit metaDataToolkit;

	for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++)
	{

		double rreq = metaDataToolkit.getNoOfRREQ();
		double rply =  metaDataToolkit.getNoOfRPLY();
		double hello =  metaDataToolkit.getNoOfHELLO();
		double err =  metaDataToolkit.getNoOfERR();
		int sent =  metaDataToolkit.getNoOfSentDataPackets();
		int received =  metaDataToolkit.getNoOfReceivedDataPackets();

		/*

		double rreq = dirTrustHelper.getNoOfRREQ(*it->getDestinationNode());
		double rply =  dirTrustHelper.getNoOfRPLY(*it->getDestinationNode());
		double hello =  dirTrustHelper.getNoOfHELLO(*it->getDestinationNode());
		double err =  dirTrustHelper.getNoOfERR(*it->getDestinationNode());
		int sent =  dirTrustHelper.getNoOfSentDataPackets(*it->getDestinationNode());
		int received =  dirTrustHelper.getNoOfReceivedDataPackets(*it->getDestinationNode());
		 *

		int rreq = metaDataTool.getRREQ();
		int rply = metaDataTool.getRPLY();
		int hello = metaDataTool.getHELLO();
		int err = metaDataTool.getERR();
		int sent = metaDataTool.getNDF();
		int received = metaDataTool.getNDR();
*/

		double cp = (rreq + rply + hello + err) / 4;

		if (received == 0) {
			received = 1;
		}

		double dp = sent / received;

		double dt = cp + dp;

		double finaldt = calculateFinalDT(dt);

		it->setDirectTrust(finaldt);



	}

}

double DirTrustCal::calculateFinalDT(double directTrustValue)
{
	double scaledDT = 1 - (1 / pow(directTrustValue , 0.5));
	return scaledDT;
}

DirTrustCal::~DirTrustCal()
{
}

}
}

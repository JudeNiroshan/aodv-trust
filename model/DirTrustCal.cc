#include "DirTrustCal.h"
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


	for (std::vector<TrustTableEntry>::iterator it = node_entry_vector.begin(); it != node_entry_vector.end(); it++)
	{

		double rreq = it->getNoOfRREQ();
		double rply =  it->getNoOfRPLY();
		double hello =  it->getNoOfHELLO();
		double err =  it->getNoOfERR();
		int sent =  it->getNoOfSentDataPackets();
		int received =  it->getNoOfReceivedDataPackets();


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

#pragma once
#include "ns3/ipv4-address.h"
#include <string>

namespace ns3
{
namespace aodv
{

class BackupTableEntry
{
private:
	Ipv4Address neiNode;
	double trustValue;
	double timeDuration;
	std::string result;
public:
	BackupTableEntry();
	void setNeiNode(Ipv4Address neiNode);
	Ipv4Address getNeiNode();
	void setTrustValue(double trustValue);
	double getTrustValue();
	void updateTrustValue(double trustValue);
	void setResult(std::string result);
	void updateResult(std::string result);
	std::string getResult();
	void setTimeDuration(double timeDuration);
	double getTimeDuration();
	void updateTimeDuration(double timeDuration);
	~BackupTableEntry();
};

}
}

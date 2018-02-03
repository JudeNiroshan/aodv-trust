#include "NodeEntry.h"
#include <string>

namespace ns3
{
namespace aodv
{

class BackupTableEntry
{
private:
	NodeEntry * neiNode;
	double trustValue;
	double timeDuration;
	std::string result;
public:
	BackupTableEntry();
	void setNeiNode(NodeEntry* neiNode);
	NodeEntry* getNeiNode();
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

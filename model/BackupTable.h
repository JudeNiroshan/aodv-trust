#include "NodeEntry.h"
#include "BackupTableEntry.h"
#include <vector>

namespace ns3
{
namespace aodv
{

class BackupTable
{
private:
	BackupTable();
	std::string columnSeperator;
	std::vector<BackupTableEntry> backupTableRecords;
	std::vector<double> trustList;
	static BackupTable* instance;
public:
	static BackupTable* getInstance();
	void addBackupTableEntry(BackupTableEntry entry);
	std::vector<BackupTableEntry>& getBackupTableEntries();
	void printTable();
	void addToTrustList(double trustValue);
	std::vector<double>& getTrustList();
	~BackupTable();
};

}
}

#pragma once
#include <vector>
#include <string>
#include "BackupTableEntry.h"
#include "ns3/ipv4-address.h"

namespace ns3
{
namespace aodv
{

class BackupTable
{
private:
	std::string columnSeperator;
	std::vector<BackupTableEntry> backupTableRecords;
	std::vector<double> trustList;
public:
	BackupTable();
	void addBackupTableEntry(BackupTableEntry entry);
	std::vector<BackupTableEntry>& getBackupTableEntries();
	void printTable();
	void addToTrustList(double trustValue);
	std::vector<double>& getTrustList();
	~BackupTable();
};

}
}

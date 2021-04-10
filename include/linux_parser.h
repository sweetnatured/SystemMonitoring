#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include <fstream>
#include <regex>
#include <string>
#include <iomanip>
#include <sstream>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

const std::string filterProcesses{"processes"};
const std::string filterRunningProcesses{"procs_running"};
const std::string filterMemTotalString{"MemTotal:"};
const std::string filterMemFreeString{"MemFree:"};
const std::string filterBuffers{"Buffers:"};
const std::string filterCached{"Cached:"};
const std::string filterSlab{"Slab:"};
const std::string filterCpu{"cpu"};
const std::string filterUID{"Uid:"};
const std::string filterProcMem{"VmData:"};

template <typename T>
T findValueByKey(const std::string &keyFilter, std::string &filename);
template <typename T>
T findValueOfFile(std::string &filename);

// System
float MemoryUtilization();
long UpTime();
std::vector<int> Pids();
int TotalProcesses();
int RunningProcesses();
std::string OperatingSystem();
std::string Kernel();

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};

enum ProcStat {
  kUtime_ = 0,
  kStime_,
  kCUtime_,
  kCStime_,
  kStarttime_,
};

std::vector<std::string> CpuUtilization();
long Jiffies();
long ActiveJiffies();
long ActiveJiffies(int pid);
long IdleJiffies();

// Processes
std::vector<std::string> ProcessCpuUtilization(int pid);
std::string Command(int pid);
std::string Ram(int pid);
std::string Uid(int pid);
std::string User(int pid);
long int UpTime(int pid);
};  // namespace LinuxParser

#endif









#include "../../include/kernel/logging/Logger.hpp"
#include "../../include/shell/Commands.hpp"
#include "../../include/fileSystem/FileSystem.hpp"
#include <iostream>
#include <algorithm>
#include "../../include/process/Scheduler.hpp"
#include "../../include/utils/StringUtils.hpp"

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}


bool Commands::execute(const std::string &cmd, const std::vector<std::string> &args,
                       FileSystem& fs, ProcessManager& pm, Scheduler& scheduler) {

    std::string command = toLower(cmd);

    // 1. System Commands
    if (command == "exit" || command == "quit") return false;
    else if (command == "help")      cmdHelp();
    else if (command == "clear")     cmdClear();

    // 2. FileSystem Navigation
    else if (command == "ls" || command == "dir")  cmdLs(fs);
    else if (command == "pwd")       cmdPwd(fs);
    else if (command == "mkdir")     cmdMkdir(args, fs);
    else if (command == "touch")     cmdTouch(args, fs);
    else if (command == "cd")        cmdCd(args, fs);

    // 3. File Content Operations
    else if (command == "cat" || command == "read") cmdCat(args, fs);
    else if (command == "write")     cmdWrite(args, fs);
    else if (command == "rewrite")   cmdReWrite(args, fs);
    else if (command == "clean")     cmdClean(args, fs);
    else if (command == "run")       cmdRun(args, fs, pm, scheduler);

    // 4. Process Management
    else if (command == "ps")        cmdPs(pm);
    else if (command == "exec")      cmdExec(args, pm, scheduler);
    else if (command == "kill")      cmdKill(args, pm);

    // 5. Memory Management
    else if (command == "free" || command == "mem") cmdFree(pm);

    // Unknown Command
    else std::cout << "Unknown command: " << cmd << "\n";

    return true;
}


void Commands::cmdHelp() {
    std::cout << "\n================= MEMI-OS v0.1 Help =================\n";
    std::cout << "[System Commands]\n";
    std::cout << "  help, ?      : Show this help menu\n";
    std::cout << "  clear, cls   : Clear the screen\n";
    std::cout << "  exit, quit   : Shutdown the system\n";


    std::cout << "\n[File System]\n";
    std::cout << "  ls, dir      : List files and directories\n";
    std::cout << "  pwd          : Print working directory\n";
    std::cout << "  cd <path>    : Change directory (use .. to go back)\n";
    std::cout << "  mkdir <name> : Create a new directory\n";
    std::cout << "  touch <name> : Create a new empty file\n";
    std::cout << "  cat <name>   : Display file content\n";
    std::cout << "  write <name> <text> : Write text to a file\n";


    std::cout << "\n[Process Management]\n";
    std::cout << "  ps           : List all active processes\n";
    std::cout << "  exec <name>  : Run a new program (create process)\n";
    std::cout << "  kill <pid>   : Terminate a process by its ID\n";


    std::cout << "\n[Memory Management]\n";
    std::cout << "  free, mem            : Show memory usage statistics (Used/Free)\n";


    std::cout << "\n[File Content Operations]\n";
    std::cout << "  cat, read <name>     : Display file content\n";
    std::cout << "  write <name> <txt>   : Write text to a file\n";
    std::cout << "  rewrite <name> <txt> : Overwrite/Replace file content\n";
    std::cout << "  clean <name>         : Clean file content (See note below)\n";


    std::cout << "=====================================================\n";
}


void Commands::cmdClear() {
    std::cout << "\033[2J\033[1;1H";
}


void Commands::cmdLs(FileSystem& fs) {
    std::cout << fs.ls();
}


void Commands::cmdPwd(FileSystem& fs) {
    std::cout << fs.pwd() << "\n";
}


void Commands::cmdMkdir(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 2) std::cout << "Usage: mkdir <directory_name>\n";
    else std::cout << fs.mkdir(args[1]) << "\n";
}


void Commands::cmdTouch(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 2) std::cout << "Usage: touch <file_name>\n";
    else std::cout << fs.touch(args[1]) << "\n";
}


void Commands::cmdCd(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 2) std::cout << "Usage: cd <path>\n";
    else std::cout << fs.cd(args[1]) << "\n";
}


void Commands::cmdCat(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 2) std::cout << "Usage: cat <filename>\n";
    else std::cout << fs.readFile(args[1]) << "\n";
}

void Commands::cmdWrite(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 3) {
        std::cout << "Usage: write <filename> <text>\n";
        return;
    }
    std::string filename = args[1];
    std::string content = "";
    for (size_t i = 2; i < args.size(); ++i) {
        content += args[i];
        if (i < args.size() - 1) content += " ";
    }
    std::cout << fs.writeFile(filename, content) << "\n";
}


void Commands::cmdReWrite(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 3) {
        std::cout << "Usage: rewrite <filename> <text>\n";
        return;
    }
    std::string filename = args[1];
    std::string content = "";
    for (size_t i = 2; i < args.size(); ++i) {
        content += args[i];
        if (i < args.size() - 1) content += " ";
    }
    std::cout << fs.reWriteFile(filename, content) << "\n";
}



void Commands::cmdRun(const std::vector<std::string> &args,
                      FileSystem &fs, ProcessManager &pm, Scheduler &sch) {
    if (args.size() < 2) {
        std::cout << "Usage: run <script_file>\n";
        return;
    }
    std::string script = fs.readFile(args[1]);
    if (script.substr(0, 5) == "Error") {
        std::cout << "Script Error: Could not read file '" << args[1] << "'\n";
        return;
    }
    std::cout << "--- Starting Script Execution ---\n";
    std::vector<std::string> lines = StringUtils::split(script, '\n');
    for (std::string line : lines) {
        std::string cleanLine = StringUtils::trim(line);
        if (cleanLine.empty()) continue;
        if (cleanLine[0] == '#') continue;
        std::cout << ">> " << cleanLine << "\n";
        std::vector<std::string> tokens = StringUtils::split(cleanLine, ' ');
        if (!tokens.empty()) {
            execute(tokens[0], tokens, fs, pm, sch);
        }
    }
    std::cout << "--- Script Finished ---\n";
}


void Commands::cmdClean(const std::vector<std::string>& args, FileSystem& fs) {
    if (args.size() < 2) std::cout << "Usage: clean <filename>\n";
    else std::cout << fs.cleanFile(args[1]) << "\n";
}

// --- Process Management ---
void Commands::cmdPs(ProcessManager& pm) {
    std::cout << pm.listProcesses();
}


void Commands::cmdExec(const std::vector<std::string>& args, ProcessManager& pm, Scheduler& sch) {
    if (args.size() < 2) {
        std::cout << "Usage: exec <program_name>\n";
        return;
    }
    int pid = pm.createProcess(args[1]);
    Process* newProc = pm.getProcess(pid);
    sch.addProcess(newProc);
    std::cout << "Process created and scheduled (PID: " << pid << ")\n";
    Logger::log(LogLevel::INFO, "Executed program: " + args[1]);
}


void Commands::cmdKill(const std::vector<std::string>& args, ProcessManager& pm) {
    if (args.size() < 2) {
        std::cout << "Usage: kill <pid>\n";
        return;
    }
    try {
        int pid = std::stoi(args[1]);
        if (pm.killProcess(pid)) {
            std::cout << "Process " << pid << " killed successfully.\n";
            Logger::log(LogLevel::INFO, "Killed process PID: " + std::to_string(pid));
        } else {
            std::cout << "Error: Process " << pid << " not found.\n";
        }
    } catch (...) {
        std::cout << "Error: Invalid PID format.\n";
    }
}


void Commands::cmdFree(ProcessManager& pm) {
    std::cout << pm.getMemoryStatus() << "\n";
}


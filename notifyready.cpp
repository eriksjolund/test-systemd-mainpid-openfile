#include <format>
#include <systemd/sd-daemon.h>
#include <stdio.h>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
  pid_t pid;
  if((pid = fork()) == -1) {
    perror("fork");
    exit(1);
  }
  /* child process */
  if (pid == 0) {
    execl("/bin/sleep", "/bin/sleep", "3600", NULL);
    exit(0);
  }

  std::string pid_str = std::format("{}\n", pid);
  // Assume there is not other FDs passed from systemd than OpenFile
  write(SD_LISTEN_FDS_START, pid_str.c_str(), pid_str.length());
  close(SD_LISTEN_FDS_START);
  sd_notify(0, "READY=1");
  
  std::this_thread::sleep_for(std::chrono::seconds(1000));   
  return 0;
}

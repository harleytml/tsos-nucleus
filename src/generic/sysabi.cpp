#include <generic/sysabi.hpp>

extern "C"
{
  void callsyscall(syscall_t syscall)
  {
    switch (syscall)
    {
    case syscall_t::reboot:
      tsos->boot.reboot();
      break;
    case syscall_t::shutdown:
      tsos->boot.shutdown();
    default:
      tsos->process.kill(0);
    }
  }
}

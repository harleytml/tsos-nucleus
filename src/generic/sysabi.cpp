#include <generic/sysabi.hpp>

extern "C"
{
  void callsyscall(Syscall_info &syscall_info)
  {
    switch (syscall_info.syscall)
    {
    case syscall_t::reboot:
      tsos->boot.reboot();
      break;
    case syscall_t::shutdown:
      tsos->boot.shutdown();
      break;
    case syscall_t::fission:
      tsos->boot.fission((static_cast<char *>(syscall_info.input_data[0])));
      break;
    case syscall_t::getbytes:
      syscall_info.output_data[0] = static_cast<void *>(tsos->disk.getbytes(*(static_cast<uint32_t *>(syscall_info.input_data[0])),
                                                                            *(static_cast<uint16_t *>(syscall_info.input_data[1]))));
      break;
    case syscall_t::setbytes:
      tsos->disk.setbytes(*(static_cast<uint32_t *>(syscall_info.input_data[0])),
                          *(static_cast<uint16_t *>(syscall_info.input_data[1])),
                          (static_cast<uint8_t *>(syscall_info.input_data[2])));
      break;
    case syscall_t::getsectorsize:
      //return static_cast<void *>(tsos->disk.getsectorsize());
      break;
    case syscall_t::commitall:
      tsos->disk.commitall();

    default:
      break;
    }
    return;
  }
}

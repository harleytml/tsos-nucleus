#include <generic/sysabi.hpp>

extern "C"
{
  void callsyscall(Syscall_info &syscall_info)
  {
    if (syscall_info.inkernelmode)
    {
      return;
    }
    syscall_info.inkernelmode = true;
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

    case syscall_t::readdir:
      break;
    case syscall_t::rename:
      break;
    case syscall_t::open:
      break;
    case syscall_t::close:
      break;
    case syscall_t::read:
      break;
    case syscall_t::write:
      break;
    case syscall_t::readfile:
      break;
    case syscall_t::writefile:
      break;
    case syscall_t::appendfile:
      break;
    case syscall_t::exists:
      break;
    case syscall_t::mkdir:
      break;
    case syscall_t::rmdir:
      break;
    case syscall_t::access:
      break;
    case syscall_t::getkey:
      break;
    case syscall_t::waitkey:
      break;
    case syscall_t::spawn:
      break;
    case syscall_t::kill:
      break;
    case syscall_t::killall:
      break;
    case syscall_t::allocatememory:
      break;
    case syscall_t::freememory:
      break;
    case syscall_t::outbyte:
      break;
    case syscall_t::inbyte:
      break;
    case syscall_t::isdevicereadytoreceive:
      break;
    case syscall_t::isdevicereadytotransmit:
      break;
    case syscall_t::playtone:
      break;
    case syscall_t::killsound:
      break;
    case syscall_t::reset:
      break;
    case syscall_t::putchar:
      break;
    case syscall_t::putstring:
      break;
    case syscall_t::getscreenwidth:
      break;
    case syscall_t::getscreenheight:
      break;
    case syscall_t::setfont:
      break;
    case syscall_t::clear:
      break;
    case syscall_t::settextbackgroundcolor:
      break;
    case syscall_t::settextforegroundcolor:
      break;
    case syscall_t::in8:
      break;
    case syscall_t::out8:
      break;
    case syscall_t::in16:
      break;
    case syscall_t::out16:
      break;
    case syscall_t::in32:
      break;
    case syscall_t::out32:
      break;
    default:
      break;
    }
    syscall_info.inkernelmode = false;

    return;
  }
}

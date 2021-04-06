//By Tsuki Superior
#include <canon-a1100/canon-a1100_boot.hpp>

CANON_A1100_BOOT_quark::CANON_A1100_BOOT_quark(void)
{
  name = "Canon Powershot A1100 IS Boot";
}

CANON_A1100_BOOT_quark::~CANON_A1100_BOOT_quark(void)
{
}

bool CANON_A1100_BOOT_quark::detectsystem(void)
{
  return true;
}

void CANON_A1100_BOOT_quark::reset(void)
{
}

void CANON_A1100_BOOT_quark::reboot(void)
{
  //This, being a camera, has no actual need to reboot, so I'll just force it to shutdown
  shutdown();
}

// From the chdk project
void CANON_A1100_BOOT_quark::shutdown(void)
{
  volatile uint32_t *p = (uint32_t *)0xc022001c;

  __asm__ volatile(
      "mrs     r1, cpsr        \n"
      "and     r0, r1, #0x80   \n"
      "orr     r1, r1, #0x80   \n"
      "msr     cpsr_cf, r1     \n" ::
          : "r1", "r0");

  *p = 0x44; // power off.

  // Just sit here idle
  while (true)
  {
  }
}

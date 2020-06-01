#include <stdint.h>
#include <stdlib.h>

#ifdef __is_miku_libk
#include <libk.h>
#endif //__is_miku_libk
 
#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xe2dee396
#else
#define STACK_CHK_GUARD 0x595e9fbd94fda766
#endif
 
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;
 
__attribute__((noreturn))
void __stack_chk_fail(void)
{
#if __is_miku_libk
    libk_stack_chk_fail();
#else
    abort();
#endif
}
/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_LOG_CORE_H
#define Z_INCLUDE_SYSCALLS_LOG_CORE_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern void z_impl_z_log_string_from_user(uint32_t src_level_val, const char * str);

__pinned_func
static inline void z_log_string_from_user(uint32_t src_level_val, const char * str)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; uint32_t val; } parm0 = { .val = src_level_val };
		union { uintptr_t x; const char * val; } parm1 = { .val = str };
		(void) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_Z_LOG_STRING_FROM_USER);
		return;
	}
#endif
	compiler_barrier();
	z_impl_z_log_string_from_user(src_level_val, str);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define z_log_string_from_user(src_level_val, str) do { 	sys_port_trace_syscall_enter(K_SYSCALL_Z_LOG_STRING_FROM_USER, z_log_string_from_user, src_level_val, str); 	z_log_string_from_user(src_level_val, str); 	sys_port_trace_syscall_exit(K_SYSCALL_Z_LOG_STRING_FROM_USER, z_log_string_from_user, src_level_val, str); } while(false)
#endif
#endif


extern void z_impl_z_log_hexdump_from_user(uint32_t src_level_val, const char * metadata, const uint8_t * data, uint32_t len);

__pinned_func
static inline void z_log_hexdump_from_user(uint32_t src_level_val, const char * metadata, const uint8_t * data, uint32_t len)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; uint32_t val; } parm0 = { .val = src_level_val };
		union { uintptr_t x; const char * val; } parm1 = { .val = metadata };
		union { uintptr_t x; const uint8_t * val; } parm2 = { .val = data };
		union { uintptr_t x; uint32_t val; } parm3 = { .val = len };
		(void) arch_syscall_invoke4(parm0.x, parm1.x, parm2.x, parm3.x, K_SYSCALL_Z_LOG_HEXDUMP_FROM_USER);
		return;
	}
#endif
	compiler_barrier();
	z_impl_z_log_hexdump_from_user(src_level_val, metadata, data, len);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define z_log_hexdump_from_user(src_level_val, metadata, data, len) do { 	sys_port_trace_syscall_enter(K_SYSCALL_Z_LOG_HEXDUMP_FROM_USER, z_log_hexdump_from_user, src_level_val, metadata, data, len); 	z_log_hexdump_from_user(src_level_val, metadata, data, len); 	sys_port_trace_syscall_exit(K_SYSCALL_Z_LOG_HEXDUMP_FROM_USER, z_log_hexdump_from_user, src_level_val, metadata, data, len); } while(false)
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */

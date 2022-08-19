# This is a custom message that is used to keep track of the different
# subprocesses started with uavrt_supervisor.
# "msg/SubprocessStatus.msg"

# The correct data type for PIDs is pid_t since it's POSIX standard and
# compatible across all systems. However, I can't get the appropriate
# header files included in uavrt_interfaces. So I went with an unsigned int.
# The limit default limit for Linux is 32767 but this value can go up to
# 4,194,304 for 64 bit machines.
# https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_554.html
# http://www.linfo.org/pid.html
uint32 process_id

# The subprocess_id is a number from 1-255 (0 is reserved)
uint8 subprocess_id

# Currently supported for status: "alive", "dead"
string subprocess_status

# Currently supported for component_type: "netcat_airspyhf_component",
# "airspyhf_channelize_component"
string component_type

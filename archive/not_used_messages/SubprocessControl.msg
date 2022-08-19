# This is a custom message that is used to control the different subprocesses
# started with uavrt_supervisor.
# "msg/SubprocessControl.msg"

# Currently supported for component_type: "netcat_airspyhf_component",
# "airspyhf_channelize_component"
string component_type

# Currently supported for command: "start", "stop"
string command

# If this value is not necessary within a message, then the value should be
# set to 0.
float64 center_frequency

# If this value is not necessary within a message, then the value should be
# set to 0.
unit8 decimation_factor

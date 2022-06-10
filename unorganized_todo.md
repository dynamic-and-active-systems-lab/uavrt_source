### These TODOs don't following a particular order. 
### These TODOs don't include the major/obivious TODOs as those are covered in summer_2022_task_list

- TODO: Create launch logging configuration file. UNIQUE_LOG_BASE_PATH = '~/uavrt_ws/src/supervisor/log'
- TODO: Need to add unit testing eventually.
- TODO: Not sure how make it so import/from statments for Python are all in one file/organized/centralized
- TODO: Organize callbacks into a callback_group to ensure the proper order of callbacks and log messages.
- TODO: Organize nodes into a namespace(s) and domain_id(s)
- TODO: Figure out serial reset "command that would reset the serial port if I unplugged and then replugged in usb"
- TODO: I'm not sure why checkHeartbeat() works with connection but not supervisorNode.connection
- TODO: How do I catch BAD_DATA? Should I make a seperate except clause for it?
- TODO: I don't cover the case of when the user starts the system on UDP and plugs in a Pixhawk via serial. It should notice this and switch to serial.
- TODO: Weird bug with telemetry messages being printed twice when serial is connected.
- TODO: Implement Slerp for quaternion.
- TODO: Check if Px4 Gazebo docker file is needs Don's bug fix.
- TODO: Edit Cmake file for uavrt_interfaces to match uavrt_ml_enc_dec. 
- TODO: Update installation instrunctions in uavrt_source.
- TODO: Edit Basic operation, Documentation, System requirements, and Installaton sections of different packages. 
- TODO: Make a Gitbooks website to point to. Use READMEs in the meantime. 
- TODO: 

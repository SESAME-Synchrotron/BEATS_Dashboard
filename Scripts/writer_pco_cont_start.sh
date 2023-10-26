#!/bin/bash

# Launch a new xterm with the name "Writer" and run a command
xterm -T "Writer" -geometry 120x20 -e "tmux a -t PCO_WriterServerCont; bash" &
xterm_pid=$!
# Save the PID to a file
echo $xterm_pid > /home/control/DAQ/operation/BEATS_Dashboard/Scripts/xterm_pid.txt

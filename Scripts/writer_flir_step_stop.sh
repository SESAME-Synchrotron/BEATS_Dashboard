#!/bin/bash

# Kill all running xterm processes with the name "Writer"
#pkill -f "xterm -T Writer"

pid_file="/home/control/DAQ/operation/BEATS_Dashboard/Scripts/xterm_pid.txt"

# Check if the PID file exists
if [ -f "$pid_file" ]; then
    # Read the PID from the file
    xterm_pid=$(cat "$pid_file")

    # Check if the process with the stored PID exists
    if ps -p "$xterm_pid" > /dev/null; then
        # Forcefully kill the process with signal 9 (SIGKILL)
        kill -9 "$xterm_pid"
        echo "Forcefully killed xterm with PID $xterm_pid"
    else
        echo "xterm with PID $xterm_pid is not running"
    fi

    # Remove the PID file
    rm "$pid_file"
else
    echo "PID file $pid_file does not exist"
fi

# Optionally, you can add some additional commands or logic here

# Exit the script
exit 0



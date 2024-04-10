Usage:	VmmUpdater.exe [-s] [-v] [-q] [-txxxx.txt] [-gXn] [-ncxx] [-fr] [-fs] [-fd] [-fo] [-fa] [-ixxx.txt] firmware_file_path
	-s:	silent action
	-i:	xxx.txt is file includes all the system ID. Only update the firmware to the laptop which system ID is in the list
	-v:	get the current firmware version, the result will be saved on newer created file update.log
	-v0:	get the current firmware version and return the version number in bcd format
	-t:	Change the txt information show to the user. xxxx.txt is the file name of the txt file
	-px:	Change the default folder (current folder) used to save the update.log file
		-p1: save to C:\ProgramData\
		-p2: save to C:\
		-P3: save to C:\Program files
		-P4: save to C:\Windows
		Please note except -p1, the other -p options need run the tool as administrator
	-r:	Registry accessing control
		-r0: disable registry access
		-rp: save the result in HKLM\\SYSTEM\\CurrentControlSet\\Control\\MST\\Synaptics permanently
	-fr:	force reset hub chip after updating firmware succeed
	-fs:	force reboot the system after updating firmware succeed
	-fd:	force downgrade the firmware version even firmware version is same or less 
	-fo:	force override even product ID is not match
	-fa:	force search all data path of the GPU, and also search each TX port of the hub to the GPU port.
	-g:	Force connect to the hub with specifc source in case there are more GPUs on system
		The second character is the source type
		The third character is number means the order of the hub if there are more than one hub there. 0 is the default.
		-gA: AMD only
		-gN: NVIDIA only
		-gI: Intel only
		-gI: Access to the Alternate DDI port of the Intel GPU
		-gW: WiGig only
		-gG: graphics only (no WiGig)
		-gX1: the second hub, here the X can be 'A', 'N', 'I', 'W' or 'G' matching above specific source only.
		-gX2: the third hub
		By default, the hub is enumerated in the order of Intel, WiGig, Nvidia and AMD
	-n:	access to the SYNA hub chip in cascade mode
		c is the cascade count
		xx is the tx port number cross all the SYNA hub chip, each two bits point to one chip. Bit [c-1:c-2] is the tx port number of first SYNA hub chip connect to GPU side
		Below are some examples;
		HSW->hub0 (TX0)->hub1 (TX1)-> hub2->(TX1)->hub3->monitor
					       |--->(TX0)->hub4->monitor	
		Access to hub0: -n does not need, or -n00
		Access to hub1: -n100
		Access to hub2: -n201
		Access to hub3: -n305 
		Access to hub4: -n304
	firmware_fiel_path	here identify where to find the firmware 

Note:
	The update result will be saved on newer created file update.log, 0 means successful. 
	The result will be also saved to the registry HKCU\software\Synpatics\PriusTool\ unless use -r0 disable it
	The registry value is automatically deleted after system reboot to avoid incorrect information reported


Firmware return code:
0:	Successful
-1:	unknown error
-3:	AUX write fail
-4:	AUX read fail
0x10: 	The firmware is same, no need update
0x11:	Can't downgrade the firmware
0xF2:	The firmware is for different generation chip
0xF3:	The firmware is for different board
0xF4:	Access to VMM chip failed
0xF5:	There is another application tool running
0xF6:	Initialize the GPU library failed
0xF7:	Can't find so many hub devices 
0xMMNNBBBB: BCD format of current firmware version return code if -v0 argument is used


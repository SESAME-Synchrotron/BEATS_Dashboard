BEATS Dashboard 
===============================

To access the BEATS Dashboard: 
::

	$ BEATS_DAQ_Control_Monitor


the main GUI will appear: 

.. figure:: /images/BEATS_Dashboard.png
   :align: center
   :alt: BEATS_Dashboard GUI

   *Figure 1: BEATS Dashboard main window*

The BEATS Dashboard shown below is divided into three sections for controlling and three sections for monitoring:

.. figure:: /images/BEATS_DashboardSections.png
   :align: center
   :alt: BEATS_DashboardSections 

   *Figure 2: BEATS Dashboard sections*
   

Controlling Sections:
* 1) Common IOCs: These are the mandatory EPICS BEATS IOCs for scanning.
      -Shutter IOC.
      -Motor IOC.
      -TomoScan Support IOC.
      -Writer Support IOC.

* 2) Camera Type: The available detectors for the scanning.
      -Detector Status (indicate if the (hardware, Software) is connected or not (Power, Ethernet, IOc)).
      -Detector IOC.
      -Detector Driver.

* 3) Scanning Methodology: The available scanning techniques for BEATS beamline.
      -Step Scan:
         * TomoScan IOC.
         * Python Server.
         * writer Server.
         * MEDM (TomoScan)

      -Continuous Scan:
         * TomoScan IOC.
         * Python Server.
         * writer Server.
         * MEDM (TomoScan)


Monitoring Sections:
* A) The detector type and the scanning technique are chosen.
* B) The online logging (last log).
* C) The current camera chosen.

Selecting Process
------------------

The user has the option to choose the detector after opening the main window. Once the user has selected a detector, the *Current Chosen Camera* will display their selection.
Following that, the user has the option to choose the scanning technique. Once the user has selected a scanning method (started the Tomoscan IOC), the *detector type and scanning technique* will display their choice. Additionally, as shown below, the other types of detectors will be disabled and the other scanning techniques hidden.

.. figure:: /images/SelectingProcess.png
   :align: center
   :alt: BEATS_SelectingProcess 

   *Figure 3: Selecting Process of Scanning Technique*
   
To change the detector type or scanning technique, the current process (TomoScan) must be stopped.


.. warning:: There is an interlocking between (Start, Stop, Restart) for all operations, it depends on the status of the IOCs if it is running or not.

.. warning:: If one of the common IOCs is stopped, the other controlling sections will be disabled until all the common IOCs are running.

.. note:: In scanning techniques section, the python server (start button) is disabled until the tomoscan IOC is started. 

.. warning:: There is an interlocking between the scanning techniques, that means the first scanning will be halted automatically if every other scanning is started while the first is still running.

.. warning:: If the detector's IOC is stopped and you select any detector type, you cannot start the scan until the IOC is running.

.. note:: If the GUI is unexpectedly closed and then reopened, selecting one of the detectors will show the current choice if one of the other sections is hidden or disabled.


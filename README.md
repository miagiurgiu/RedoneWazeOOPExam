# RedoneWazeOOPExam
Waze-ing

Write an application which simulates the communication between drivers, as follows:

The information about all registered drivers is in a text file. Each driver has a name (string), a status (baby, grown-up, knight), a current location (latitude and longitude) and a score. This file is manually created and it is read when the application starts.

Another file contains road information (reports). Each Report has a description, the reporter (the name of the driver who reported it), the exact location (latitude and longitude) and whether it was validated or not. These are read when the application starts.

When the application is launched, a new window is created for each driver, having as title the driver’s name. The driver’s current location, score and status are also shown. The window will show all reports for the driver’s region of interest (radius = 10 units from the driver’s current location). The windows will be coloured differently according to the driver’s status. (1.25p)

Any driver can add a new report, by inputting the description and exact location. The reporter will automatically be the name of the driver who added the report. This operation fails if the description is empty, or if the report’s location is more than 20 units away from the driver’s location. (1p)

Drivers can validate reports, only if they were not validated yet. If a report is validated by 2 drivers other than the reporter, the report becomes valid and the reporter’s score increases by 1. When the score reaches 10, a baby driver becomes grown-up and when the score reaches 15, a driver becomes a knight. The user status and window colour will change accordingly. (1.25p)

Drivers can search reports in a specified radius, by using a QSlider. Its default value is 10 and as it is moved, the user’s window will show all reports within the given radius. (0.75p)

A driver can update his/her current location. This is achieved by clicking one of four buttons (north, east, south, west) and the location’s latitude/longitude updates accordingly (with 1 unit). In this case, the driver’s list of reports is also updated according to the value of the QSlider and the new location. (1p)

A new window will show the map, with all users. This is a rectangle and each driver’s location and name will be shown in the rectangle. This is shown when the application starts. (1p)

When a modification is made by any driver, all other drivers will see it automatically. The map will also be updated automatically. (2p)

When the application closes, the files containing drivers and reports will be updated. (0.75p)

Observations:

1p of
Use layered architecture.
If you do not read the data from file, you receive only 50% for functionalities 3, 4, 5 and 6.
Qt Designer allowed.
Only Qt docs, cppreference and cplusplus allowed.

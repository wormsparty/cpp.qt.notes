Testing if I can make a text editor in C++.

## Setup
- On Windows, run windows-setup.ps1 to open the URLs you need to install Qt.
- On Debian, run debian-setup.sh to install the necessary packages
- For others, please install your distribution's QtBase and make sure qmake is available.

## Build
- Windows: open the .sln on Visual Studio. Edit the project's include and library paths to include your Qt installation.
- Others: qmake6 && make && ./bin/notes

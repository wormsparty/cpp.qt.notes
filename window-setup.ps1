[system.Diagnostics.Process]::Start("msedge","https://www.qt.io/download-qt-installer-oss")
[system.Diagnostics.Process]::Start("msedge","https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2022")
 
echo "Use either Qt Creator or Visual Studio."
echo "For Visual Studio:"
echo "1. Open Visual Studio with the Qt extension installed."
echo "2. Extensions > Qt VS Tools > Open Qt Project File (.pro)"
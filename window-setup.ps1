echo "Don't forget you'll need to run 'windeployqt' the first time."

[system.Diagnostics.Process]::Start("msedge","https://www.qt.io/download-qt-installer-oss")
[system.Diagnostics.Process]::Start("msedge","https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools2022")
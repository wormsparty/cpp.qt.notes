if (Get-Command "vcpkg.exe" -ErrorAction SilentlyContinue) {
    echo "vcpkg.exe already installed, skipping."
} else {
    git clone https://github.com/Microsoft/vcpkg.git
    .\vcpkg\bootstrap-vcpkg.bat
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";$PWD\vcpkg", "Machine")
    vcpkg integrate install
}

vcpkg install curl
vcpkg install qt

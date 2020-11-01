## GUI-application
Simple QT GUI application that is used as example of how to create QT application with cmake

### Requirements:
``` bash
# QT5 dependencies:
sudo apt-get install -y qtbase5-dev qtdeclarative5-dev qtquickcontrols2-5-dev qml-module-qtquick2 qml-module-qtquick-controls

# Gstreamer dependencies:
sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

# Other dependencies:
sudo apt-get install -y build-essential cmake
```

### Build project:
``` bash
cd <Root of project>
./build.sh
```

### Run project:
``` bash
cd <Root of project>/build/install
./GUI-application
```
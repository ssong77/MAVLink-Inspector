# MAVLink Inspector

A cross-platform MAVLink protocol debugger and analyzer for drone developers.


##  What is this?

MAVLink Inspector is a developer tool for debugging and analyzing MAVLink communication in real-time. If you've ever struggled to understand what messages your drone is sending, or why QGC isn't responding correctly, this tool is for you.

**Key Features:**
-  Real-time MAVLink message capture (UDP/Serial)
-  Message filtering and search
-  Protocol statistics and timing analysis
-  Session recording and playback
-  Clean, modern Qt/QML interface

##  Why I built this

While developing QGroundControl plugins, I frequently encountered MAVLink communication issues (like the infamous message forwarding feedback loop). Existing tools like Wireshark are too generic, and MAVLink-specific analysis required tedious manual work. This tool fills that gap.

##  Screenshots

_Coming soon - currently in early development_

## Building

### Prerequisites
- Qt 6.5+
- CMake 3.20+
- C++17 compiler
- vcpkg (optional, for dependencies)

### Clone & Build
```bash
git clone --recursive https://github.com/yourusername/mavlink-inspector.git
cd mavlink-inspector
mkdir build && cd build
cmake ..
cmake --build .
```

##  Usage

1. Launch the application
2. Configure connection (UDP 14550 or Serial port)
3. Click "Connect"
4. Watch MAVLink messages flow in real-time
5. Use filters to focus on specific message types

##  Roadmap

- [x] Project setup
- [ ] UDP/Serial connection
- [ ] Message parsing and display
- [ ] Filtering UI
- [ ] Statistics panel
- [ ] Session save/load
- [ ] Message injection
- [ ] Protocol violation detection


##  Acknowledgments

- Built with Qt and QML
- Uses the official MAVLink C library
- Inspired by challenges faced while developing QGroundControl features

---

```

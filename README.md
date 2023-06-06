# test-systemd-mainpid-openfile
Just a test. It was not possible to set MAINPID with OpenFile=


```
podman run --rm -v ./:/src:Z localhost/gxx2 g++ -o /src/ready -lsystemd  -std=c++20 /src/notifyready.cpp && cp ready /tmp/ready
```
